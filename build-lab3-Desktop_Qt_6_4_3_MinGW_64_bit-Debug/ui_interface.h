/********************************************************************************
** Form generated from reading UI file 'interface.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACE_H
#define UI_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TInterface
{
public:
    QLineEdit *matrix_size_edit;
    QPushButton *transpose_button;
    QPushButton *det_button;
    QPushButton *rank_button;
    QLabel *matrix_size_label;
    QTableWidget *matrix_table;
    QLabel *matrix_size_label_2;
    QLineEdit *matrix_data_edit;
    QPushButton *new_matrix_button;
    QLabel *label;
    QLabel *result_text;
    QPushButton *close_button;

    void setupUi(QWidget *TInterface)
    {
        if (TInterface->objectName().isEmpty())
            TInterface->setObjectName("TInterface");
        TInterface->resize(796, 641);
        matrix_size_edit = new QLineEdit(TInterface);
        matrix_size_edit->setObjectName("matrix_size_edit");
        matrix_size_edit->setGeometry(QRect(150, 20, 131, 31));
        transpose_button = new QPushButton(TInterface);
        transpose_button->setObjectName("transpose_button");
        transpose_button->setGeometry(QRect(590, 130, 88, 34));
        det_button = new QPushButton(TInterface);
        det_button->setObjectName("det_button");
        det_button->setGeometry(QRect(590, 210, 88, 34));
        rank_button = new QPushButton(TInterface);
        rank_button->setObjectName("rank_button");
        rank_button->setGeometry(QRect(590, 290, 88, 34));
        matrix_size_label = new QLabel(TInterface);
        matrix_size_label->setObjectName("matrix_size_label");
        matrix_size_label->setGeometry(QRect(60, 20, 101, 21));
        matrix_table = new QTableWidget(TInterface);
        matrix_table->setObjectName("matrix_table");
        matrix_table->setEnabled(true);
        matrix_table->setGeometry(QRect(30, 80, 501, 451));
        matrix_table->setTabletTracking(false);
        matrix_table->setFocusPolicy(Qt::StrongFocus);
        matrix_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        matrix_table->setGridStyle(Qt::SolidLine);
        matrix_table->setSortingEnabled(false);
        matrix_table->setCornerButtonEnabled(true);
        matrix_table->setRowCount(0);
        matrix_table->setColumnCount(0);
        matrix_table->horizontalHeader()->setMinimumSectionSize(50);
        matrix_table->horizontalHeader()->setDefaultSectionSize(50);
        matrix_table->verticalHeader()->setMinimumSectionSize(50);
        matrix_table->verticalHeader()->setDefaultSectionSize(50);
        matrix_size_label_2 = new QLabel(TInterface);
        matrix_size_label_2->setObjectName("matrix_size_label_2");
        matrix_size_label_2->setGeometry(QRect(320, 20, 81, 21));
        matrix_data_edit = new QLineEdit(TInterface);
        matrix_data_edit->setObjectName("matrix_data_edit");
        matrix_data_edit->setGeometry(QRect(420, 20, 131, 31));
        new_matrix_button = new QPushButton(TInterface);
        new_matrix_button->setObjectName("new_matrix_button");
        new_matrix_button->setGeometry(QRect(590, 20, 88, 34));
        label = new QLabel(TInterface);
        label->setObjectName("label");
        label->setGeometry(QRect(550, 490, 41, 18));
        result_text = new QLabel(TInterface);
        result_text->setObjectName("result_text");
        result_text->setGeometry(QRect(600, 490, 161, 20));
        close_button = new QPushButton(TInterface);
        close_button->setObjectName("close_button");
        close_button->setGeometry(QRect(690, 590, 88, 34));

        retranslateUi(TInterface);
        QObject::connect(new_matrix_button, SIGNAL(clicked()), TInterface, SLOT(new_matrix()));
        QObject::connect(transpose_button, SIGNAL(clicked()), TInterface, SLOT(transpose()));
        QObject::connect(det_button, SIGNAL(clicked()), TInterface, SLOT(det()));
        QObject::connect(rank_button, SIGNAL(clicked()), TInterface, SLOT(rank()));
        QObject::connect(close_button, &QPushButton::clicked, TInterface, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(TInterface);
    } // setupUi

    void retranslateUi(QWidget *TInterface)
    {
        TInterface->setWindowTitle(QCoreApplication::translate("TInterface", "Lab work No. 3", nullptr));
        matrix_size_edit->setText(QString());
        transpose_button->setText(QCoreApplication::translate("TInterface", "Transpose", nullptr));
        det_button->setText(QCoreApplication::translate("TInterface", "Det", nullptr));
        rank_button->setText(QCoreApplication::translate("TInterface", "Rank", nullptr));
        matrix_size_label->setText(QCoreApplication::translate("TInterface", "Matrix size:", nullptr));
        matrix_size_label_2->setText(QCoreApplication::translate("TInterface", " Matrix data:", nullptr));
        matrix_data_edit->setText(QString());
        new_matrix_button->setText(QCoreApplication::translate("TInterface", "New matrix", nullptr));
        label->setText(QCoreApplication::translate("TInterface", "Result: ", nullptr));
        result_text->setText(QString());
        close_button->setText(QCoreApplication::translate("TInterface", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TInterface: public Ui_TInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_H
