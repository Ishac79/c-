#include "HighlightAnnotationWidget.h"
#include "AnnotationDialog.h"
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>
#include <QDialog>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>

HighlightAnnotationWidget::HighlightAnnotationWidget(QWidget *parent)
    : QGraphicsView(parent),
      scene(new QGraphicsScene(this)),
      currentRect(nullptr) {
    setScene(scene);
    setRenderHint(QPainter::Antialiasing, true);
    setDragMode(QGraphicsView::NoDrag);
    setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
}

void HighlightAnnotationWidget::addHighlight(const QRectF &rect, const QColor &color) {
    auto highlight = new QGraphicsRectItem(rect);
    highlight->setBrush(QBrush(color));
    highlight->setOpacity(0.5);
    scene->addItem(highlight);
    highlights.append(highlight);
}

QPixmap HighlightAnnotationWidget::createAnnotationIcon() {
    QPixmap pixmap(32, 32);
    pixmap.fill(Qt::transparent);

    QPainter painter(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing);

    QPen pen(Qt::black, 2);
    painter.setPen(pen);
    painter.setBrush(Qt::yellow);

    QRectF circle(2, 2, 28, 28);
    painter.drawEllipse(circle);

    painter.setFont(QFont("Arial", 14));
    painter.drawText(circle, Qt::AlignCenter, "A");

    return pixmap;
}

void HighlightAnnotationWidget::addAnnotation(const QPointF &position, const QString &text) {
    QPixmap annotationPixmap = createAnnotationIcon();
    auto annotationIcon = new QGraphicsPixmapItem(annotationPixmap);
    annotationIcon->setPos(position);
    annotationIcon->setToolTip(text);
    scene->addItem(annotationIcon);
    annotations.append(annotationIcon);
}

void HighlightAnnotationWidget::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        highlightRect.setTopLeft(mapToScene(event->pos()));
        highlightRect.setBottomRight(mapToScene(event->pos()));
        currentRect = new QGraphicsRectItem(highlightRect);
        currentRect->setBrush(QBrush(Qt::yellow));
        currentRect->setOpacity(0.5);
        scene->addItem(currentRect);
    }
}

void HighlightAnnotationWidget::mouseMoveEvent(QMouseEvent *event) {
    if (currentRect) {
        highlightRect.setBottomRight(mapToScene(event->pos()));
        currentRect->setRect(highlightRect);
    }
}

void HighlightAnnotationWidget::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton && currentRect) {
        highlights.append(currentRect);
        currentRect = nullptr;
    }
}

void HighlightAnnotationWidget::mouseDoubleClickEvent(QMouseEvent *event) {
    QPointF scenePos = mapToScene(event->pos());
    foreach (QGraphicsRectItem *highlight, highlights) {
        if (highlight->contains(scenePos)) {
            AnnotationDialog dialog;
            if (dialog.exec() == QDialog::Accepted) {
                addAnnotation(scenePos, dialog.annotationText());
            }
            break;
        }
    }
}
