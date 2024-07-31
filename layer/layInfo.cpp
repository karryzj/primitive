#include <QColor>


#include "layInfo.h"


namespace ly
{

LayerInfo::LayerInfo()
{

}

LayerInfo::LayerInfo(const LayerInfo& other)
{
    m_name = other.m_name;
    m_border_style = other.m_border_style;
    m_border_color = other.m_border_color;
    m_fill_style = other.m_fill_style;
    m_fill_color = other.m_fill_color;

}

LayerInfo& LayerInfo::operator=(const LayerInfo& other)
{
    if (this == &other) return *this; // 防止自我赋值

    m_name = other.m_name;
    m_border_style = other.m_border_style;
    m_border_color = other.m_border_color;
    m_fill_style = other.m_fill_style;
    m_fill_color = other.m_fill_color;

    return *this;
}

LayerInfo::~LayerInfo()
{

}

QString LayerInfo::name() const
{
    return m_name;
}

void LayerInfo::set_name(const QString &name)
{
    m_name = name;
}

LayerInfo::Border_Style LayerInfo::border_line() const
{
    return m_border_style;
}

void LayerInfo::set_border_line(Border_Style border_style)
{
    m_border_style = border_style;
}

QColor LayerInfo::border_color() const
{
    return m_border_color;
}

void LayerInfo::set_border_color(QColor border_color)
{
    m_border_color = border_color;
}

LayerInfo::Fill_Style LayerInfo::fill_line() const
{
    return m_fill_style;
}

void LayerInfo::set_fill_line(Fill_Style fill_style)
{
    m_fill_style = fill_style;
}

QColor LayerInfo::fill_color() const
{
    return m_fill_color;
}

void LayerInfo::set_fill_color(QColor fill_color)
{
    m_fill_color = fill_color;
}



}
