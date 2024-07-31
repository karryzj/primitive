#ifndef DRAWSECTORSHAPEACTION_H
#define DRAWSECTORSHAPEACTION_H

#include <PriDrawShapeAction.h>

class PriDrawSectorShapeAction final : public PriDrawShapeAction
{
public:
    explicit PriDrawSectorShapeAction(QObject *parent = nullptr);
    ~PriDrawSectorShapeAction(void) override;

public:
    void drawShape(void) override;  // TODO@leixunyong
};

#endif // DRAWSECTORSHAPEACTION_H
