#include "interface.h"
#include "ui_interface.h"

#include <sstream>

TInterface::TInterface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TInterface)
{
    ui->setupUi(this);
}

TInterface::~TInterface()
{
    delete ui;
}

void TInterface::new_matrix() {
    int new_size = ui->matrix_size_edit->text().toInt();
    matrix = Tmatrix(new_size);
    ui->matrix_table->setRowCount(new_size);
    ui->matrix_table->setColumnCount(new_size);
    auto text = ui->matrix_data_edit->text().toStdString();
    std::istringstream stream;
    stream.str(text);
    for(int i=0; i < new_size; i++) {
        for(int j=0; j< new_size; j++) {
            number temp_num;
            stream >> temp_num;
            matrix.set(i,j,temp_num);
            std::ostringstream extract;
            extract << temp_num;
            QTableWidgetItem* newItem = new QTableWidgetItem(extract.str().data());
            ui->matrix_table->setItem(i, j, newItem);
        }
    }
}

void TInterface::transpose() {
    int size = matrix.size();
    matrix.transpose();
    for(int i=0; i < size; i++) {
        for(int j=0; j< size; j++) {
            std::stringstream extract;
            extract << matrix.get(i, j);
            ui->matrix_table->item(i, j)->setText(extract.str().data());
        }
    }
}

void TInterface::rank() {
    ui->result_text->setText(QVariant(matrix.rank()).toString());
}

void TInterface::det() {
    std::stringstream stream;
    stream << matrix.det();
    ui->result_text->setText(stream.str().data());
}
