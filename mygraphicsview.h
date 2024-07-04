#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGraphicsPathItem>
#include <QMouseEvent>
#include <QPainterPath>
#include <QColor>

class MyGraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    enum DrawMode { Freehand, Rectangle, Ellipse, Triangle };

    MyGraphicsView(QGraphicsScene *scene, QWidget *parent = nullptr);
    void setLineColor(const QColor &color);
    void setFillColor(const QColor &color);
    void setDrawMode(DrawMode mode);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    QGraphicsPathItem *currentPathItem;
    QColor lineColor;
    QColor fillColor;
    QPainterPath currentPath;
    QPointF lastPoint;
    DrawMode drawMode;
    bool drawingShape;
    QList<QPointF> shapePoints;
};

#endif // MYGRAPHICSVIEW_H
