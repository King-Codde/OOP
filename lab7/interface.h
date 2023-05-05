#ifndef INTERFACE_H
#define INTERFACE_H
#include <QWidget>
#include <QLabel>
#include <QString>
#include <QPushButton>
#include <QGridLayout>
#include <QTextBlock>
#include <QFileDialog>
#include <QStringList>
#include "window_graph.h"
#include "directed_graph.h"

class interface_window : public QWidget {
    Q_OBJECT
public:
    interface_window();
    ~interface_window();
    void wread_file();
    bool data_checking(QString);
    void open_graph_window();
private:
    QWidget *interface;
    QLabel *result;
    QFileDialog *findfile;
    QFile *file;
    directed_graph *graph = nullptr;
    window_graph *w_graph = nullptr;
};




#endif // INTERFACE_H
