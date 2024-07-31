#include <QToolBar>
#include <QDockWidget>
#include <QTreeWidget>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "layerMgr.h"
#include "layListItemWidget.h"
#include "layInfo.h"

namespace ly
{

LayerMgr::LayerMgr(QWidget *parent) : QWidget(parent), m_visible_count(3)
{
    // 解析图层配置文件
    int ret = parseCfgFile("layer_mgr.json");
    Q_ASSERT(ret == 0);

    QVBoxLayout *layout = new QVBoxLayout();
    mp_list_widget = new QListWidget();
    // 创建并添加自定义项到列表控件中
    for (int i = 0; i < 20; ++i)
    {
        QListWidgetItem *item = new QListWidgetItem(mp_list_widget);
        LayListItemWidget *listItemWidget = new LayListItemWidget(m_layers[QString("Layer%1").arg(i+1)], QString("Layer%1").arg(i+1));
        item->setSizeHint(listItemWidget->sizeHint()*1.5);
        mp_list_widget->setItemWidget(item, listItemWidget);
        item->setHidden(i >= m_visible_count);  // 初始化时只显示前3个
        connect(listItemWidget, &LayListItemWidget::styleChanged, this, LayerMgr::onItemStyleChanged);
    }

    QHBoxLayout *button_bottom = new QHBoxLayout();
    mp_new_layer_button = new QPushButton(QIcon(":/img/lay_new.png"), tr("新增"));
    mp_del_layer_button = new QPushButton(QIcon(":/img/lay_del.png"), tr("删除"));
    // 设置按钮的圆角矩形样式
    QString button_style = "QPushButton {"
                           "border: 2px solid #5F9EA0;"  // 边框颜色
                           "border-radius: 10px;"         // 圆角半径
                           "background-color: #ADD8E6;"   // 背景颜色
                           "padding: 5px 15px;"           // 内边距
                           "}";

    mp_new_layer_button->setStyleSheet(button_style);
    mp_new_layer_button->setEnabled(true);
    mp_del_layer_button->setStyleSheet(button_style);
    mp_del_layer_button->setEnabled(false);
    button_bottom->addWidget(mp_new_layer_button);
    button_bottom->addWidget(mp_del_layer_button);
    layout->addWidget(mp_list_widget);
    layout->addLayout(button_bottom);
    setLayout(layout);


    connect(mp_new_layer_button, &QPushButton::clicked, this, &LayerMgr::showMoreItems);
    connect(mp_del_layer_button, &QPushButton::clicked, this, &LayerMgr::removeItem);
    connect(mp_list_widget, &QListWidget::itemSelectionChanged, this, &LayerMgr::updateRemoveButtonState);
    updateButtonState();
}

void LayerMgr::showMoreItems()
{
    for (int i = 0; i < mp_list_widget->count(); ++i)
    {
        QListWidgetItem *item = mp_list_widget->item(i);
        if (item->isHidden())
        {
            item->setHidden(false);
            break;
        }
    }
    updateButtonState();
}

void LayerMgr::removeItem()
{
    QList<QListWidgetItem*> selectedItems = mp_list_widget->selectedItems();
    if (!selectedItems.isEmpty())
    {
        QListWidgetItem *item = selectedItems.first();
        item->setHidden(true);
        mp_list_widget->setCurrentItem(nullptr);
    }
    updateButtonState();
}

void LayerMgr::updateRemoveButtonState()
{
    mp_del_layer_button->setEnabled(!mp_list_widget->selectedItems().isEmpty());
}

void LayerMgr::onItemStyleChanged(const LayerInfo &style)
{
    auto it = m_layers.find(style.name());
    if (it != m_layers.end())
    {
        m_layers[style.name()] = style;
        writeCfgFile("layer_mgr.json");
    }
}

void LayerMgr::updateButtonState()
{
    bool hasHiddenItems = false;
    for (int i = 0; i < mp_list_widget->count(); ++i)
    {
        if (mp_list_widget->item(i)->isHidden())
        {
            hasHiddenItems = true;
            break;
        }
    }
    mp_new_layer_button->setEnabled(hasHiddenItems);
    mp_del_layer_button->setEnabled(!mp_list_widget->selectedItems().isEmpty());
}

int LayerMgr::parseCfgFile(const QString &filename)
{
    QFile file(filename);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file:" << filename;
        return -1;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(jsonData, &parseError);

    if (parseError.error != QJsonParseError::NoError)
    {
        qDebug() << "Failed to parse JSON:" << parseError.errorString();
        return -1;
    }

    if (!doc.isObject())
    {
        qDebug() << "JSON document is not an object.";
        return -1;
    }

    QJsonObject jsonObject = doc.object();

    if (!jsonObject.contains("LayerManager") || !jsonObject["LayerManager"].isArray())
    {
        qWarning() << "Invalid JSON structure - 'pdk' array not found or not an array.";
        return -1;
    }

    QJsonArray layer_array = jsonObject["LayerManager"].toArray();

    // Iterate through the array
    for (int i = 0; i < layer_array.size(); ++i)
    {
        LayerInfo layer_info;
        QJsonObject lay_obj = layer_array[i].toObject();
        layer_info.set_name(lay_obj["layerName"].toString());
        // Access style object
        QJsonObject style_obj = lay_obj["style"].toObject();
        layer_info.set_border_line(static_cast<LayerInfo::Border_Style>(style_obj["borderLine"].toInt()));
        layer_info.set_border_color(style_obj["borderColor"].toString().toInt(nullptr, 16));
        layer_info.set_fill_line(static_cast<LayerInfo::Fill_Style>(style_obj["fillLine"].toInt()));
        layer_info.set_fill_color(style_obj["fillColor"].toString().toInt(nullptr, 16));
        m_layers.insert(layer_info.name(), layer_info);
    }
    return 0;
}

int LayerMgr::writeCfgFile(const QString &filename)
{
    QJsonObject root_object;
    QJsonArray layer_info_array;

    foreach (const LayerInfo &info, m_layers)
    {
        QJsonObject layer_object;
        layer_object["layerName"] = info.name();

        QJsonObject style_object;
        style_object["borderLine"] = info.border_line();
        // style_object["borderColor"] = QString("0x%1").arg(info.border_color().rgb(), 6, 16, QLatin1Char('0'));
        style_object["borderColor"] = info.border_color().name().mid(1);
        style_object["fillLine"] = info.fill_line();
        // style_object["fillColor"] = QString("0x%1").arg(info.fill_color().rgb(), 6, 16, QLatin1Char('0'));
        style_object["fillColor"] = info.fill_color().name().mid(1);
        layer_object["style"] = style_object;

        layer_info_array.append(layer_object);
    }
    root_object["LayerManager"] = layer_info_array;

    QJsonDocument doc(root_object);

    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qWarning("Couldn't open save file.");
        return -1;
    }

    file.write(doc.toJson());
    file.close();
    return 0;
}

LayerMgr::~LayerMgr()
{
    delete mp_list_widget;
    delete mp_new_layer_button;
    delete mp_del_layer_button;
}


}
