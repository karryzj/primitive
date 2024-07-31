#include "arcringitem.h"

#include <qpainter.h>

ArcRingItem::ArcRingItem(double inside_radius, double outside_radius, double start_angle, double end_angle)
    :m_inside_radius(inside_radius)
    ,m_outside_radius(outside_radius)
    ,m_start_angle(start_angle)
    ,m_end_angle(end_angle)

{

}

QRectF ArcRingItem::boundingRect() const
{
    return QRectF(-m_outside_radius, -m_outside_radius,  m_outside_radius*2,  m_outside_radius*2);
}

void ArcRingItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setRenderHint(QPainter::Antialiasing);

    // 绘制外圆弧
    QPainterPath outerPath;
    outerPath.arcMoveTo(-m_outside_radius, -m_outside_radius, 2 * m_outside_radius, 2 * m_outside_radius, m_start_angle);
    outerPath.arcTo(-m_outside_radius, -m_outside_radius, 2 * m_outside_radius, 2 * m_outside_radius, m_start_angle, m_end_angle);

    // 绘制内圆弧
    QPainterPath innerPath;
    innerPath.arcMoveTo(-m_inside_radius, -m_inside_radius, 2 * m_inside_radius, 2 * m_inside_radius, m_start_angle + m_end_angle);
    innerPath.arcTo(-m_inside_radius, -m_inside_radius, 2 * m_inside_radius, 2 * m_inside_radius, m_start_angle + m_end_angle, -m_end_angle);

    // 连接内外圆弧
    outerPath.connectPath(innerPath);
    outerPath.closeSubpath();

    // 填充扇环
    painter->setBrush(Qt::blue);
    painter->drawPath(outerPath);
}
