#include <QApplication>
#include <QPushButton>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QPushButton button("Click me");
    QObject::connect(&button, &QPushButton::clicked, &app, [](){
        qDebug("Button clicked");
    });

    button.resize(200, 100);
    button.show();

    return app.exec();
}
