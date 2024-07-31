#ifndef LAYINFO_H
#define LAYINFO_H

#include <QObject>
#include <QColor>

QT_BEGIN_NAMESPACE
class QColor;
QT_END_NAMESPACE

namespace ly
{

class LayerInfo : public QObject
{
    Q_OBJECT

public:
    enum Border_Style { SolidLine, DashLine, DotLine, DashDotLine, DashDotDotLine};
    enum Fill_Style {NotFill, HorizontalLine, VerticalLine, GridLine, LeftDiagonal, RightDiagonal, GridDiagonal, FullFill};

    LayerInfo();

    // 拷贝构造函数
    LayerInfo(const LayerInfo& other);

    // 赋值运算符重载
    LayerInfo& operator=(const LayerInfo& other);

    inline bool operator==(const LayerInfo &rhs)
    {
        return m_border_style == rhs.m_border_style &&
               m_border_color == rhs.m_border_color &&
               m_fill_style == rhs.m_fill_style &&
               m_fill_color == rhs.m_fill_color;
    }

    inline bool operator!=(const LayerInfo &rhs)
    {
        return !(*this == rhs);
    }

    ~LayerInfo();

    // to do


    QString name() const;
    void set_name(const QString &name);

    Border_Style border_line() const;
    void set_border_line(Border_Style border_style);

    QColor border_color() const;
    void set_border_color(QColor border_color);


    Fill_Style fill_line() const;
    void set_fill_line(Fill_Style fill_style);

    QColor fill_color() const;
    void set_fill_color(QColor fill_color);

private:

    QString m_name;
    Border_Style m_border_style;
    QColor m_border_color;
    Fill_Style m_fill_style;
    QColor m_fill_color;

    int m_num;
};

}
#endif // LAYINFO_H
