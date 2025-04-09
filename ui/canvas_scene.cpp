#include "canvas_scene.h"
#include <QGraphicsSceneMouseEvent>


CanvasScene::CanvasScene(QObject* parent)
    : QGraphicsScene(parent)
{
}

void CanvasScene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    QPointF pos = event->scenePos();
    emit pixelDrawn(pos.x(), pos.y());
    QGraphicsScene::mousePressEvent(event);
}

void CanvasScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    if (event->buttons() & Qt::LeftButton) {
        QPointF pos = event->scenePos();
        emit pixelDrawn(pos.x(), pos.y());
    }
    QGraphicsScene::mouseMoveEvent(event);
}
