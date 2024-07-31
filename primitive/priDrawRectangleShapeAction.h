#ifndef DRAWRECTANGLESHAPEACTION_H
#define DRAWRECTANGLESHAPEACTION_H

#include <PriDrawShapeAction.h>


class PriDrawRectangleShapeAction final: public PriDrawShapeAction
{
public:
    explicit PriDrawRectangleShapeAction(QObject *parent = nullptr);
    ~PriDrawRectangleShapeAction(void) override;

public:
    void drawShape(void) override;  // TODO@leixunyong

};

#endif // DRAWRECTANGLESHAPEACTION_H
