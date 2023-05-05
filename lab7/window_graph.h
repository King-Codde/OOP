#include <QWidget>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <cmath>
#include <QLine>
#include <QVector>
#include <QPolygonF>
#include "directed_graph.h"
#ifndef WINDOW_GRAPH_H
#define WINDOW_GRAPH_H




class window_graph : public QWidget {
     Q_OBJECT
public:
     window_graph(directed_graph*);
    ~window_graph();
     void point_in_elipse(QVector<QVector<double>>&, int, int, int, int);
private:
    QWidget *interface;
    directed_graph* graph;
protected:
    void paintEvent(QPaintEvent*);
};

#endif // WINDOW_GRAPH_H
