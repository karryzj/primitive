#ifndef LAYLISTITEMWIDGET_H
#define LAYLISTITEMWIDGET_H

#include <QObject>
#include <QWidget>
#include <layInfo.h>

namespace ly
{
class LayStyleFrame;

class LayListItemWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LayListItemWidget(const LayerInfo &style, const QString &text, QWidget *parent = nullptr);

    ~LayListItemWidget();
private:
    LayStyleFrame *mp_frame;
private slots:
    void onStyleFrameChanged(const LayerInfo &style);

signals:
    void styleChanged(const LayerInfo &style);
};
}

#endif // LAYLISTITEMWIDGET_H
