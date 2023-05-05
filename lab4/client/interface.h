#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include "matrix.h"

namespace Ui {
class TInterface;
}

class TInterface : public QWidget
{
    Q_OBJECT

public:
    explicit TInterface(QWidget *parent = nullptr);
    ~TInterface();

public slots:
    void new_matrix();
    void det();
    void transpose();
    void rank();

private:
    Ui::TInterface *ui;
    Tmatrix matrix;
};

#endif // INTERFACE_H
