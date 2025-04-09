#include "canvas_layer_item.h"
#include <QPainter>

CanvasLayerItem::CanvasLayerItem(int width, int height)
    : m_pixmap(width, height)
{
    m_pixmap.fill(Qt::transparent);

    //setFlag(QGraphicsItem::ItemIsSelectable);         // útil pra seleção
    //setFlag(QGraphicsItem::ItemIsMovable);            // útil se quiser mover
    //setFlag(QGraphicsItem::ItemSendsGeometryChanges); // boa prática
    //setAcceptedMouseButtons(Qt::AllButtons);          // se quiser receber eventos depois

    //setVisible(true); // Garante que o item aparece
}

QRectF CanvasLayerItem::boundingRect() const {
    return QRectF(0, 0, m_pixmap.width(), m_pixmap.height());
}

void CanvasLayerItem::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) {
    painter->drawPixmap(0, 0, m_pixmap);

    painter->setBrush(Qt::red);
    //painter->drawRect(0, 0, 10, 10);
}

void CanvasLayerItem::drawPixel(int x, int y, QColor color) {
    QPainter p(&m_pixmap);
    p.setPen(color);
    p.drawPoint(x, y);
    update(QRectF(x, y, 5, 5));
}
