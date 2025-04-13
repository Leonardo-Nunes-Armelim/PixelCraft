#include "main_window.h"

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
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>

//#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(1280, 720);
    //this->showMaximized();

    // ========== Menu Bar ==========
    QMenuBar *menu_bar = new QMenuBar(this);

    // File
    QMenu *file_menu = new QMenu("File", this);
    QAction *new_action = new QAction("New", this);
    QAction *open_action = new QAction("Open", this);
    QAction *save_action = new QAction("Save", this);
    QAction *exit_action = new QAction("Exit", this);
    connect(exit_action, &QAction::triggered, this, &QMainWindow::close);

    file_menu->addAction(new_action);
    file_menu->addAction(open_action);
    file_menu->addAction(save_action);
    file_menu->addSeparator();
    file_menu->addAction(exit_action);

    // Edit
    QMenu *edit_menu = new QMenu("Edit", this);
    QAction *undo_action = new QAction("Undo", this);
    QAction *redo_action = new QAction("Redo", this);
    edit_menu->addAction(undo_action);
    edit_menu->addAction(redo_action);

    // Help
    QMenu *help_menu = new QMenu("Help", this);
    QAction *about_action = new QAction("About", this);
    help_menu->addAction(about_action);

    menu_bar->addMenu(file_menu);
    menu_bar->addMenu(edit_menu);
    menu_bar->addMenu(help_menu);

    this->setMenuBar(menu_bar);

    // ========== Status Bar ==========
    QStatusBar *status_bar = new QStatusBar(this);
    status_bar->showMessage("Ready");
    this->setStatusBar(status_bar);

    // ========== Central Widget ==========
    QWidget *central_widget = new QWidget(this);
    this->setCentralWidget(central_widget);

    // ========== Configuring Central Widget ==========
    QVBoxLayout *layout = new QVBoxLayout(central_widget);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    // ========== Contextual tool bar ==========
    QWidget *context_tool_bar = new QWidget(this);
    context_tool_bar->setFixedHeight(50);
    context_tool_bar->setStyleSheet("background-color: gray;");

    // ========== Center left widget ==========
    QWidget *tools_and_canvas_parent_widget = new QWidget();
    QHBoxLayout *tools_and_canvas_layout = new QHBoxLayout(tools_and_canvas_parent_widget);
    QWidget *tool_bar = new QWidget(this);
    tool_bar->setFixedWidth(100);
    tool_bar->setStyleSheet("background-color: red;");
    tools_and_canvas_layout->addWidget(tool_bar);

    // Canvas
    CanvasScene *canvas_scene = new CanvasScene(this);
    CanvasView *canvas_view = new CanvasView(this);
    canvas_view->setScene(canvas_scene);
    canvas_view->setDragMode(QGraphicsView::NoDrag);
    CanvasLayerItem *canvas_layer = new CanvasLayerItem(128, 128);
    canvas_scene->addItem(canvas_layer);

    connect(canvas_scene, &CanvasScene::pixelDrawn, this, [=](int x, int y) {
        canvas_layer->drawPixel(x, y, Qt::black);
    });

    tools_and_canvas_layout->addWidget(canvas_view);

    // ========== Lower bar splitter ==========

    // Animations panel
    QWidget *animations = new QWidget();
    animations->setMinimumWidth(200);
    animations->setMinimumHeight(200);
    animations->setStyleSheet("background-color: green;");
    //QPushButton *btn_1 = new QPushButton("btn 1");
    //QPushButton *btn_2 = new QPushButton("btn 2");
    //QPushButton *btn_3 = new QPushButton("btn 3");
    //QVBoxLayout *leftLayout = new QVBoxLayout(leftPane);
    //leftLayout->addWidget(btn_1);
    //leftLayout->addWidget(btn_2);
    //leftLayout->addWidget(btn_3);

    // Frame Edit panel
    QWidget *frame_edit = new QWidget();
    frame_edit->setMinimumWidth(200);
    frame_edit->setMinimumHeight(200);

    // Playback panel
    QWidget *playback = new QWidget();
    playback->setMinimumWidth(200);
    playback->setMinimumHeight(200);
    playback->setStyleSheet("background-color: green;");

    QSplitter *lower_bar_splitter = new QSplitter(Qt::Horizontal, this);
    lower_bar_splitter->addWidget(animations);
    lower_bar_splitter->addWidget(frame_edit);
    lower_bar_splitter->addWidget(playback);
    lower_bar_splitter->setCollapsible(0, false);
    lower_bar_splitter->setCollapsible(1, false);
    lower_bar_splitter->setCollapsible(3, false);

    // ========== Center splitter ==========
    QSplitter *center_splitter = new QSplitter(Qt::Vertical, this);
    center_splitter->addWidget(tools_and_canvas_parent_widget);
    center_splitter->addWidget(lower_bar_splitter);

    // ========== Right side panel splitter ==========
    QWidget *preview_panel = new QWidget();
    preview_panel->setMinimumHeight(100);
    preview_panel->setMinimumWidth(200);
    preview_panel->setStyleSheet("background-color: red;");
    QWidget *palette_panel = new QWidget();
    palette_panel->setMinimumHeight(100);
    palette_panel->setStyleSheet("background-color: green;");
    QWidget *tiles_panel = new QWidget();
    tiles_panel->setMinimumHeight(100);
    tiles_panel->setStyleSheet("background-color: blue;");
    QWidget *layers_panel = new QWidget();
    layers_panel->setMinimumHeight(100);
    layers_panel->setStyleSheet("background-color: red;");
    QWidget *info_panel = new QWidget();
    info_panel->setMinimumHeight(100);
    info_panel->setStyleSheet("background-color: blue;");

    QSplitter *right_side_panel_splitter = new QSplitter(Qt::Vertical, this);
    right_side_panel_splitter->addWidget(preview_panel);
    right_side_panel_splitter->addWidget(palette_panel);
    right_side_panel_splitter->addWidget(tiles_panel);
    right_side_panel_splitter->addWidget(layers_panel);
    right_side_panel_splitter->addWidget(info_panel);
    right_side_panel_splitter->setCollapsible(0, false);
    right_side_panel_splitter->setCollapsible(1, false);
    right_side_panel_splitter->setCollapsible(2, false);
    right_side_panel_splitter->setCollapsible(3, false);
    right_side_panel_splitter->setCollapsible(4, false);

    // ========== Main splitter ==========
    QSplitter *main_splitter = new QSplitter(Qt::Horizontal, this);
    main_splitter-> addWidget(center_splitter);
    main_splitter->addWidget(right_side_panel_splitter);
    main_splitter->setCollapsible(0, false);
    main_splitter->setCollapsible(1, false);

    layout->addWidget(context_tool_bar);
    layout->addWidget(main_splitter);
}

MainWindow::~MainWindow()
{

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
