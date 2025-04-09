#ifndef CANVAS_VIEW_H
#define CANVAS_VIEW_H

#include <QGraphicsView>

class CanvasView : public QGraphicsView {
    Q_OBJECT

public:
    explicit CanvasView(QWidget* parent = nullptr);

protected:
    void wheelEvent(QWheelEvent* event) override;

public slots:
    void zoomIn();
    void zoomOut();
    void panBy(int dx, int dy);
};

#endif // CANVAS_VIEW_H

