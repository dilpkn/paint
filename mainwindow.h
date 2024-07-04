#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QColorDialog>
#include <QMainWindow>
#include <QGraphicsScene>
#include "mygraphicsview.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionRed_triggered();
    void on_actionBlack_triggered();
    void on_actionWhite_triggered();
    void on_actionGreen_triggered();
    void on_actionBlue_triggered();
    void on_actionYellow_triggered();
    void on_actionFreehand_triggered();
    void on_actionRectangle_triggered();
    void on_actionEllipse_triggered();
    void on_actionTriangle_triggered();
    void on_actionClear_triggered();
    void on_actionFillColor_triggered();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    MyGraphicsView *graphicsView;
    QColor lineColor;
    QColor fillColor;
};

#endif // MAINWINDOW_H
