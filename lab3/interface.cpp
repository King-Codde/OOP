#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "interface.h"

TInterface::TInterface(QWidget *parent)
    : QWidget(parent) {
    setWindowTitle("Lab Work No. 3");
    setFixedSize(400, 400);

    name_numerator_ = new QLabel("numerator=", this);
    name_numerator_->setGeometry(50, 20, 30, 25);
    name_denumerator_ = new QLabel("enumerator=", this);
    name_denumerator_->setGeometry(50, 20, 30, 25);
}

TInterface::~TInterface() {
}

