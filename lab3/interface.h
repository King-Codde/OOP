#ifndef TINTERFACE_H
#define TINTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class TInterface : public QWidget
{
    Q_OBJECT

    QLabel* name_numerator_;
    QLabel* name_denumerator_;
    QLineEdit numerator_text_;
    QLineEdit denumerator_text_;
public:
    TInterface(QWidget *parent = nullptr);
    ~TInterface();
};
#endif // TINTERFACE_H
