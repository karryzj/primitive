#ifndef DRAWSHAPEACTION_H
#define DRAWSHAPEACTION_H

#include <QAction>

class PriDrawShapeAction : public QAction
{
public:
    explicit PriDrawShapeAction(QObject *parent = nullptr);
    ~PriDrawShapeAction() override;

public:
    virtual void drawShape(void) = 0;
};

#endif // DRAWSHAPEACTION_H
