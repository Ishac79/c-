#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include "PencilDrawWidget.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    QVBoxLayout *layout = new QVBoxLayout(&window);

    PencilDrawWidget *drawingWidget = new PencilDrawWidget();
    layout->addWidget(drawingWidget);

    QPushButton *clearButton = new QPushButton("Clear");
    layout->addWidget(clearButton);

    window.setWindowTitle("Pencil Draw");
    window.resize(800, 600);
    window.show();

    QObject::connect(clearButton, &QPushButton::clicked, drawingWidget, &PencilDrawWidget::clearDrawing);

    return app.exec();
}
