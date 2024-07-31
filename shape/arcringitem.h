#ifndef ARCRINGITEM_H
#define ARCRINGITEM_H

#include <QGraphicsItem>

class ArcRingItem final : public QGraphicsItem
{
public:
    ArcRingItem(double inside_radius, double outside_radius, double start_angle, double end_angle);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    double m_inside_radius;
    double m_outside_radius;
    double m_start_angle;
    double m_end_angle;
};

#endif // ARCRINGITEM_H
