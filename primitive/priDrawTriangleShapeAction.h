#ifndef DRAWTRIANGLESHAPEACTION_H
#define DRAWTRIANGLESHAPEACTION_H

#include <PriDrawShapeAction.h>


class PriDrawTriangleShapeAction final: public PriDrawShapeAction
{
public:
    explicit PriDrawTriangleShapeAction(QObject *parent = nullptr);
    ~PriDrawTriangleShapeAction(void) override;

public:
    void drawShape(void) override;  // TODO@leixunyong
};

#endif // DRAWTRIANGLESHAPEACTION_H
