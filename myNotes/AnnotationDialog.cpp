#include "AnnotationDialog.h"
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>

AnnotationDialog::AnnotationDialog(QWidget *parent)
    : QDialog(parent), lineEdit(new QLineEdit(this)) {
    auto layout = new QVBoxLayout(this);
    layout->addWidget(lineEdit);
    auto button = new QPushButton("OK", this);
    layout->addWidget(button);
    connect(button, &QPushButton::clicked, this, &AnnotationDialog::accept);
}

QString AnnotationDialog::annotationText() const {
    return lineEdit->text();
}

void AnnotationDialog::accept() {
    if (!lineEdit->text().isEmpty()) {
        QDialog::accept();
    }
}
