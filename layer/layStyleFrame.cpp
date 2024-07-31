#include "layStyleFrame.h"
#include "layStyleDialog.h"
#include "layInfo.h"
#include <QDebug>
#include <QPainter>

namespace ly
{
LayStyleFrame::LayStyleFrame(QWidget *parent, Qt::WindowFlags f) : QFrame(parent)
{
    setGeometry(50, 50, 200, 200);
    setFrameShape(QFrame::Box);
    setFrameShadow(QFrame::Plain);
    setLineWidth(2);
    setFrameStyle(QFrame::Box | QFrame::Plain);
}

LayStyleFrame::LayStyleFrame(LayerInfo style, QWidget *parent, Qt::WindowFlags f): QFrame(parent), m_style(style), m_old_style(style)
{
    setGeometry(50, 50, 200, 200);
    setFrameShape(QFrame::Box);
    setFrameShadow(QFrame::Plain);
    setLineWidth(2);
    setFrameStyle(QFrame::Box | QFrame::Plain);
    update();
}

LayStyleFrame::~LayStyleFrame()
{

}

void LayStyleFrame::setStyle(const LayerInfo &style)
{
    m_style = style;
}

LayerInfo LayStyleFrame::style() const
{
    return m_style;
}

LayerInfo LayStyleFrame::getOldStyle() const
{
    return m_old_style;
}

void LayStyleFrame::mouseDoubleClickEvent(QMouseEvent *event)
{
    LayStyleDialog dialog(m_style);
    if (dialog.exec() == QDialog::Accepted)
    {
        LayerInfo custom_style = dialog.getData();
        if (m_style != custom_style)
        {
            update();
            m_style = custom_style;
            emit dataChanged(custom_style);
        }
    }
}


void LayStyleFrame::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter border_painter(this);
    border_painter.setRenderHint(QPainter::Antialiasing);

    // 设置虚线的画笔
    // 获取颜色的RGB值
    int r = m_style.border_color().red();
    int g = m_style.border_color().green();
    int b = m_style.border_color().blue();

    QPen pen(QColor(r, g, b));  // 设置颜色
    switch (m_style.border_line())
    {
    case LayerInfo::SolidLine:
        pen.setStyle(Qt::SolidLine);
        break;
    case LayerInfo::DashLine:
        pen.setStyle(Qt::DashLine);
        break;
    case LayerInfo::DotLine:
        pen.setStyle(Qt::DotLine);
        break;
    case LayerInfo::DashDotLine:
        pen.setStyle(Qt::DashDotLine);
        break;
    case LayerInfo::DashDotDotLine:
        pen.setStyle(Qt::DashDotDotLine);
        break;
    default:
        break;
    }
    border_painter.setPen(pen);

    // 绘制矩形的边框
    border_painter.drawRect(rect());

    QPainter painter(this);

    // 设置画笔样式
    // 获取颜色的RGB值
    int red = m_style.fill_color().red();
    int green = m_style.fill_color().green();
    int blue = m_style.fill_color().blue();

    painter.setPen(QColor(red, green, blue));

    int gridSize = 5; // 网格大小
    int width = this->width();
    int height = this->height();
    int numLines = qMax( width, height)  / gridSize; // 计算线的数量，取宽高中的最大值

    switch (m_style.fill_line())
    {
    case LayerInfo::NotFill:

        break;
    case LayerInfo::HorizontalLine:
        // 绘制水平线条
        for (int y = 1; y < height; y += gridSize)
        {
            painter.drawLine(0, y, width, y);
        }
        break;
    case LayerInfo::VerticalLine:
        // 绘制垂直线条
        for (int x = 1; x < width; x += gridSize)
        {
            painter.drawLine(x, 0, x, height);
        }
        break;
    case LayerInfo::GridLine:
        // 绘制垂直线条
        for (int x = 1; x < width; x += gridSize)
        {
            painter.drawLine(x, 0, x, height);
        }

        // 绘制水平线条
        for (int y = 1; y < height; y += gridSize)
        {
            painter.drawLine(0, y, width, y);
        }
        break;
    case LayerInfo::LeftDiagonal:
        // int numLines = qMax( width,height)  / gridSize;
        for (int i = 1; i < numLines * 2; ++i)
        {
            int x1 = i * gridSize;
            int y1 = 0;
            int x2 = 0;
            int y2 = i * gridSize;

            painter.drawLine(x1, y1, x2, y2); // 绘制从左上到右下的斜线
        }
        break;
    case LayerInfo::RightDiagonal:
        // int numLines = qMax( width,height)  / gridSize;
        for (int i = 1; i < numLines * 2; ++i)
        {
            int x3 = 0;
            int y3 = height - i * gridSize;
            int x4 = i * gridSize;
            int y4 = height;
            painter.drawLine(x3, y3, x4, y4);
        }
        break;
    case LayerInfo::GridDiagonal:
        // int numLines = qMax( width,height)  / gridSize;
        for (int i = 1; i < numLines * 2; ++i)
        {
            int x1 = i * gridSize;
            int y1 = 0;
            int x2 = 0;
            int y2 = i * gridSize;

            painter.drawLine(x1, y1, x2, y2); // 绘制从左上到右下的斜线
            int x3 = 0;
            int y3 = height - i * gridSize;
            int x4 = i * gridSize;
            int y4 = height;
            painter.drawLine(x3, y3, x4, y4);
        }
        break;
    case LayerInfo::FullFill:

        break;
    default:
        break;
    }
}
}
