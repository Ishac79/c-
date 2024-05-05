#include "PencilDrawWidget.h"
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QPen>

PencilDrawWidget::PencilDrawWidget(QWidget *parent)
    : QGraphicsView(parent),
      scene(new QGraphicsScene(this)),
      currentLine(nullptr),
      drawing(false) {
    setScene(scene);
    setRenderHint(QPainter::Antialiasing, true);
    setDragMode(QGraphicsView::NoDrag);
    setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
}

void PencilDrawWidget::clearDrawing() {
    scene->clear();
}

void PencilDrawWidget::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        lastPoint = mapToScene(event->pos());
        drawing = true;
    }
}

void PencilDrawWidget::mouseMoveEvent(QMouseEvent *event) {
    if (drawing) {
        QPointF currentPoint = mapToScene(event->pos());
        QLineF newLine(lastPoint, currentPoint);
        QPen pen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
        scene->addLine(newLine, pen);
        lastPoint = currentPoint;
    }
}

void PencilDrawWidget::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton && drawing) {
        drawing = false;
    }
}
