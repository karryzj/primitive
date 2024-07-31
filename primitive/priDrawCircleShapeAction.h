#ifndef DRAWCIRCLESHAPEACTION_H
#define DRAWCIRCLESHAPEACTION_H

#include <PriDrawShapeAction.h>

class PriDrawCircleShapeAction final : public PriDrawShapeAction
{
public:
    explicit PriDrawCircleShapeAction(QObject *parent = nullptr);
    ~PriDrawCircleShapeAction(void) override;

public:
    void drawShape(void) override;  // TODO@leixunyong
};

#endif // DRAWCIRCLESHAPEACTION_H
