#include "canvas_view.h"
#include "qevent.h"

CanvasView::CanvasView(QWidget* parent)
    : QGraphicsView(parent)
{
    setRenderHint(QPainter::Antialiasing, false);
    setDragMode(QGraphicsView::RubberBandDrag);
    setTransformationAnchor(AnchorUnderMouse);
    setResizeAnchor(AnchorViewCenter);
}

void CanvasView::wheelEvent(QWheelEvent* event)
{
    if (event->angleDelta().y() > 0)
        zoomIn();
    else
        zoomOut();
}

void CanvasView::zoomIn() {
    scale(1.2, 1.2);
}

void CanvasView::zoomOut() {
    scale(1 / 1.2, 1 / 1.2);
}

void CanvasView::panBy(int dx, int dy) {
    translate(dx, dy);
}
