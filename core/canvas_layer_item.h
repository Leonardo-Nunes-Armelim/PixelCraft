#ifndef CANVAS_LAYER_ITEM_H
#define CANVAS_LAYER_ITEM_H

#include <QGraphicsItem>
#include <QPixmap>

class CanvasLayerItem : public QGraphicsItem {
public:
    CanvasLayerItem(int width, int height);

    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

    void drawPixel(int x, int y, QColor color);

private:
    QPixmap m_pixmap;
};

#endif // CANVAS_LAYER_ITEM_H

