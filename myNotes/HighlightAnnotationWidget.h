#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QUndoStack>

class HighlightAnnotationWidget : public QGraphicsView {
    Q_OBJECT

public:
    HighlightAnnotationWidget(QWidget *parent = nullptr);
    void addHighlight(const QRectF &rect, const QColor &color);
    void addAnnotation(const QPointF &position, const QString &text);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;

private:
    QPixmap createAnnotationIcon();

    QGraphicsScene *scene;
    QRectF highlightRect;
    QGraphicsRectItem *currentRect;
    QList<QGraphicsRectItem *> highlights;
    QList<QGraphicsPixmapItem *> annotations;
    QUndoStack undoStack;
};
