#include <QApplication>
#include <QVector>
#include <iostream>
#include "interface.h"
#include "matrix.h"
#include "window_graph.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //window_graph w1;
    //w1.show();

    interface_window w;
    w.show();
    return a.exec();
}
