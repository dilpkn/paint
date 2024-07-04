#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scene(new QGraphicsScene(this))
    , graphicsView(new MyGraphicsView(scene, this))
    , lineColor(Qt::black)
    , fillColor(Qt::white)
{
    ui->setupUi(this);

    // Устанавливаем центральный виджет
    setCentralWidget(graphicsView);

    // Настройки сцены
    scene->setSceneRect(0, 0, 800, 600);
    graphicsView->setRenderHint(QPainter::Antialiasing);
    graphicsView->setMouseTracking(true);

    // Установка цвета фона сцены (пример)
    scene->setBackgroundBrush(Qt::white);

}

void MainWindow::on_actionRed_triggered()
{
    lineColor = QColor("#FF007F");
    graphicsView->setLineColor(lineColor);
}

void MainWindow::on_actionBlack_triggered()
{
    lineColor = Qt::black;
    graphicsView->setLineColor(lineColor);
}

void MainWindow::on_actionWhite_triggered()
{
    lineColor = Qt::white;
    graphicsView->setLineColor(lineColor);
}

void MainWindow::on_actionGreen_triggered()
{
    lineColor = QColor("#00FF00");
    graphicsView->setLineColor(lineColor);
}

void MainWindow::on_actionBlue_triggered()
{
    lineColor = QColor("#3399FF");
    graphicsView->setLineColor(lineColor);
}

void MainWindow::on_actionYellow_triggered()
{
    lineColor = QColor("#FFFF00");
    graphicsView->setLineColor(lineColor);
}

void MainWindow::on_actionFreehand_triggered()
{
    graphicsView->setDrawMode(MyGraphicsView::Freehand);
}

void MainWindow::on_actionRectangle_triggered()
{
    graphicsView->setDrawMode(MyGraphicsView::Rectangle);
}

void MainWindow::on_actionEllipse_triggered()
{
    graphicsView->setDrawMode(MyGraphicsView::Ellipse);
}

void MainWindow::on_actionTriangle_triggered()
{
    graphicsView->setDrawMode(MyGraphicsView::Triangle);
}

void MainWindow::on_actionClear_triggered()
{
    QList<QGraphicsItem *> items = scene->items();
    for (QGraphicsItem *item : items) {
        scene->removeItem(item);
        delete item;
    }
}


void MainWindow::on_actionFillColor_triggered()
{
    QColor color = QColorDialog::getColor(fillColor, this, "Select Fill Color");
    if (color.isValid()) {
        fillColor = color;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
