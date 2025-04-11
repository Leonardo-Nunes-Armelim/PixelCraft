#include "main_window.h"
#include "./ui_main_window.h"

#include "../core/canvas_layer_item.h"
#include "canvas_scene.h"
#include "canvas_view.h"

#include <QMouseEvent>
#include <QGraphicsRectItem>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QSplitter>
#include <QPushButton>

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
    // Configuring centralwidget
    QVBoxLayout *layout = new QVBoxLayout(ui->centralwidget);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    // Contextual toolbar
    QWidget *tool_context_bar = new QWidget(this);
    tool_context_bar->setFixedHeight(50);
    tool_context_bar->setStyleSheet("background-color: gray;");

    // Horizontal block

    QSplitter *splitter = new QSplitter(Qt::Horizontal, this);
    QWidget *leftPane = new QWidget();
    QPushButton *btn_1 = new QPushButton("btn 1");
    QPushButton *btn_2 = new QPushButton("btn 2");
    QPushButton *btn_3 = new QPushButton("btn 3");
    QVBoxLayout *leftLayout = new QVBoxLayout(leftPane);
    leftLayout->addWidget(btn_1);
    leftLayout->addWidget(btn_2);
    leftLayout->addWidget(btn_3);

    canvasScene = new CanvasScene(this);
    canvasView = new CanvasView(this);
    canvasView->setScene(canvasScene);
    canvasView->setDragMode(QGraphicsView::NoDrag);
    canvasLayer = new CanvasLayerItem(128, 128);
    canvasScene->addItem(canvasLayer);

    splitter->addWidget(leftPane);
    splitter->addWidget(canvasView);

    connect(canvasScene, &CanvasScene::pixelDrawn, this, [=](int x, int y) {
        canvasLayer->drawPixel(x, y, Qt::black);
    });

    layout->addWidget(tool_context_bar);
    layout->addWidget(splitter);


    //draw_frame = new QWidget(this);

    //canvasView->setParent(ui->frame);
    //canvasView->setGeometry(ui->frame->rect());
    //canvasView->show();

//    QSplitter *splitter = new QSplitter(Qt::Horizontal, this);
//
//    QWidget *leftPane = new QWidget();
//    QVBoxLayout *leftLayout = new QVBoxLayout(leftPane);
//    leftLayout->addWidget(ui->pushButton);
//    leftLayout->addWidget(ui->pushButton_2);
//
//    CanvasView *canvasView = new CanvasView(this);
//    canvasView->setScene(canvasScene);
//
//    splitter->addWidget(leftPane);     // Lado esquerdo (botões)
//    splitter->addWidget(canvasView);   // Lado direito (canvas)
//
//    setCentralWidget(splitter);

    layout->addStretch();

}

void MainWindow::mousePressEvent(QMouseEvent* event)
{

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
