#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H
#include <matrix.h>



class directed_graph
{
public:
    directed_graph(int n){m = new matrix<qint16>(n);}
    ~directed_graph(){delete m;}
public:
    matrix<qint16> *m;
};

#endif // DIRECTED_GRAPH_H
