#include "main_window.h"
#include "./ui_main_window.h"
//#include "core/canvas_layer_item.h"
//#include "ui/canvas_scene.h"
//#include "ui/canvas_view.h"
#include <QMouseEvent>
#include <QGraphicsRectItem>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene, this);
    view->setSceneRect(0, 0, 320, 240);
    view->setRenderHint(QPainter::Antialiasing, false);
    view->setDragMode(QGraphicsView::NoDrag);

    setCentralWidget(view);
    resize(400, 300);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
    QPoint viewPos = event->pos();
    QPointF scenePos = view->mapToScene(viewPos);

    int gridSize = 10;
    int x = static_cast<int>(scenePos.x()) / gridSize * gridSize;
    int y = static_cast<int>(scenePos.y()) / gridSize * gridSize;

    auto* rect = scene->addRect(x, y, gridSize, gridSize, QPen(Qt::black), QBrush(Qt::blue));
    rect->setZValue(1);
}

//auto* scene = new CanvasScene(this);
//auto* view = new CanvasView(this);
//view->setScene(scene);
//
//auto* layer = new CanvasLayerItem(128, 128);
//scene->addItem(layer);
//
//connect(scene, &CanvasScene::pixelDrawn, [=](int x, int y) {
//    layer->drawPixel(x, y, Qt::black);
//});
