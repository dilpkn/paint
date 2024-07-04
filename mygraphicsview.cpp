#include "mygraphicsview.h"

MyGraphicsView::MyGraphicsView(QGraphicsScene *scene, QWidget *parent)
    : QGraphicsView(scene, parent), currentPathItem(nullptr), lineColor(Qt::black), fillColor(Qt::white), drawMode(Freehand), drawingShape(false)
{
    setRenderHint(QPainter::Antialiasing);
    setMouseTracking(true);
}

void MyGraphicsView::setLineColor(const QColor &color)
{
    lineColor = color;
}

void MyGraphicsView::setFillColor(const QColor &color)
{
    fillColor = color;
}

void MyGraphicsView::setDrawMode(DrawMode mode)
{
    drawMode = mode;
}

void MyGraphicsView::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        lastPoint = mapToScene(event->pos());
        currentPath = QPainterPath();
        currentPath.moveTo(lastPoint);
        currentPathItem = new QGraphicsPathItem(currentPath);
        currentPathItem->setPen(QPen(lineColor, 2));
        scene()->addItem(currentPathItem);

        if (drawMode != Freehand) {
            drawingShape = true;
            shapePoints.clear();
            shapePoints.append(lastPoint);
        }
    }
}

void MyGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        QPointF currentPoint = mapToScene(event->pos());

        if (drawMode == Freehand) {
            currentPath.lineTo(currentPoint);
            currentPathItem->setPath(currentPath);
        } else if (drawingShape) {
            currentPath = QPainterPath();
            currentPath.moveTo(shapePoints.first());
            switch (drawMode) {
            case Rectangle:
                currentPath.addRect(QRectF(shapePoints.first(), currentPoint));
                break;
            case Ellipse:
                currentPath.addEllipse(QRectF(shapePoints.first(), currentPoint));
                break;
            case Triangle:
                if (shapePoints.size() == 2) {
                    currentPath.lineTo(shapePoints[1]);
                    currentPath.lineTo(currentPoint);
                    currentPath.closeSubpath();
                } else {
                    shapePoints.append(currentPoint);
                }
                break;
            default:
                break;
            }
            currentPathItem->setPath(currentPath);
        }
    }
}

void MyGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        if (drawMode != Freehand && drawingShape) {
            QPointF currentPoint = mapToScene(event->pos());
            shapePoints.append(currentPoint);
            if (drawMode == Triangle && shapePoints.size() == 3) {
                currentPath = QPainterPath();
                currentPath.moveTo(shapePoints[0]);
                currentPath.lineTo(shapePoints[1]);
                currentPath.lineTo(shapePoints[2]);
                currentPath.closeSubpath();
                currentPathItem->setPath(currentPath);
                drawingShape = false;
            }
        }
    }
}
