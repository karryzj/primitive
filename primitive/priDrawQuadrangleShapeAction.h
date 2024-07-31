#ifndef DRAWQUADRANGLESHAPEACTION_H
#define DRAWQUADRANGLESHAPEACTION_H

#include <priDrawShapeAction.h>

class PriDrawQuadrangleShapeAction final : public PriDrawShapeAction
{
public:
    explicit PriDrawQuadrangleShapeAction(QObject *parent = nullptr);
    ~PriDrawQuadrangleShapeAction(void) override;

public:
    void drawShape(void) override;  // TODO@leixunyong
};

#endif // DRAWQUADRANGLESHAPEACTION_H
