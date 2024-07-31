#include <QLabel>
#include <QHBoxLayout>
#include "layListItemWidget.h"
#include "layStyleFrame.h"
#include "layInfo.h"

namespace ly
{

LayListItemWidget::LayListItemWidget(const LayerInfo &style, const QString &text, QWidget *parent)
    : QWidget(parent)
{
    // 创建一个前置的QFrame
    mp_frame = new LayStyleFrame(style, this);
    mp_frame->setFrameShape(QFrame::Box);
    mp_frame->setFixedSize(80, 40); // 设置frame的大小

    // 创建一个后置的QLabel
    QLabel *label = new QLabel(text, this);

    // 创建水平布局
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(mp_frame);
    layout->addWidget(label);
    layout->setContentsMargins(5, 5, 5, 5); // 设置边距
    layout->setSpacing(10); // 设置控件之间的间距

    setLayout(layout);

    connect(mp_frame, &LayStyleFrame::dataChanged, this, &LayListItemWidget::onStyleFrameChanged);
}

void LayListItemWidget::onStyleFrameChanged(const LayerInfo &style)
{
    if (mp_frame->getOldStyle() != style)
    {
        emit styleChanged(style);
    }
}

LayListItemWidget::~LayListItemWidget()
{
    delete mp_frame;
}

}
