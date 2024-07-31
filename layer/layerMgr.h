#ifndef LAYERMGR_H
#define LAYERMGR_H

#include <QMap>
#include <QWidget>
#include <QPushButton>
#include <QListWidget>

QT_BEGIN_NAMESPACE

QT_END_NAMESPACE

namespace ly
{

class LayerInfo;

class LayerMgr: public QWidget
{
    Q_OBJECT
public:
    explicit LayerMgr(QWidget *parent = nullptr);
    ~LayerMgr();

private:
    int parseCfgFile(const QString &file);
    int writeCfgFile(const QString &filename);
    void updateButtonState();

    QMap<QString, LayerInfo> m_layers;
    QListWidget *mp_list_widget;
    QPushButton *mp_new_layer_button;
    QPushButton *mp_del_layer_button;
    int m_visible_count;

private slots:
    void showMoreItems();
    void removeItem();
    void updateRemoveButtonState();
    void onItemStyleChanged(const LayerInfo &style);
};

}

#endif // LAYERMGR_H

