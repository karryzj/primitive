#ifndef DRAWELLIPSESHAPEACTION_H
#define DRAWELLIPSESHAPEACTION_H

#include <PriDrawShapeAction.h>

class PriDrawEllipseShapeAction final : public PriDrawShapeAction
{
public:
    explicit PriDrawEllipseShapeAction(QObject *parent = nullptr);
    ~PriDrawEllipseShapeAction(void) override;

public:
    void drawShape(void) override;  // TODO@leixunyong
};

#endif // DRAWELLIPSESHAPEACTION_H
