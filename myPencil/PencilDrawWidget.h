#include <QGraphicsView>
#include <QGraphicsLineItem>

class PencilDrawWidget : public QGraphicsView {
    Q_OBJECT

public:
    PencilDrawWidget(QWidget *parent = nullptr);
    void clearDrawing();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    QGraphicsScene *scene;
    QGraphicsLineItem *currentLine;
    QPointF lastPoint;
    bool drawing;
};
