#include <QApplication>
#include "HighlightAnnotationWidget.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    HighlightAnnotationWidget widget;
    widget.setWindowTitle("Highlight and Annotation Widget");
    widget.resize(800, 600);
    widget.show();

    return app.exec();
}
