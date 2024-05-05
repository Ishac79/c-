#include <QDialog>
#include <QLineEdit>

class AnnotationDialog : public QDialog {
    Q_OBJECT

public:
    AnnotationDialog(QWidget *parent = nullptr);
    QString annotationText() const;

private slots:
    void accept() override;

private:
    QLineEdit *lineEdit;
};
