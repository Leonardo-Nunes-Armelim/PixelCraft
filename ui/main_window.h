#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

#include <QGraphicsView>
#include <QGraphicsScene>

class CanvasScene;
class CanvasView;
class CanvasLayerItem;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    //QGraphicsView *view;
    //QGraphicsScene *scene;

    void setupCanvas();

    CanvasView *canvasView = nullptr;
    CanvasScene *canvasScene = nullptr;
    CanvasLayerItem *canvasLayer = nullptr;

protected:
    void mousePressEvent(QMouseEvent* event) override;
};
#endif // MAIN_WINDOW_H
