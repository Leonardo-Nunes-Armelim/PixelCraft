#include "main_window.h"
#include "./ui_main_window.h"

#include "../core/canvas_layer_item.h"
#include "canvas_scene.h"
#include "canvas_view.h"

#include <QMouseEvent>
#include <QGraphicsRectItem>
#include <QVBoxLayout>

//#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setupCanvas();

    //scene = new QGraphicsScene(this);
    //view = new QGraphicsView(scene, this);
    //view->setSceneRect(0, 0, 320, 240);
    //view->setRenderHint(QPainter::Antialiasing, false);
    //view->setDragMode(QGraphicsView::NoDrag);

    //setCentralWidget(view);
    //resize(400, 300);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupCanvas()
{
    canvasScene = new CanvasScene(this);
    canvasView = new CanvasView(this);
    canvasView->setScene(canvasScene);

    canvasView->setDragMode(QGraphicsView::NoDrag);

    canvasLayer = new CanvasLayerItem(512, 512);
    canvasScene->addItem(canvasLayer);

    // Conecta o sinal da cena com a ação de desenhar no layer
    connect(canvasScene, &CanvasScene::pixelDrawn, this, [=](int x, int y) {
        canvasLayer->drawPixel(x, y, Qt::black);
    });

    // Adiciona o canvasView à interface
    setCentralWidget(canvasView);
}


//void MainWindow::mousePressEvent(QMouseEvent* event)
//{
//    QPoint viewPos = event->pos();
//    QPointF scenePos = view->mapToScene(viewPos);
//
//    int gridSize = 10;
//    int x = static_cast<int>(scenePos.x()) / gridSize * gridSize;
//    int y = static_cast<int>(scenePos.y()) / gridSize * gridSize;
//
//    auto* rect = scene->addRect(x, y, gridSize, gridSize, QPen(Qt::black), QBrush(Qt::blue));
//    rect->setZValue(1);
//}
