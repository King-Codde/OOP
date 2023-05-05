#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H
#include <matrix.h>



class directed_graph
{
public:
    directed_graph(int);
    ~directed_graph();
public:
    matrix *m;
};

#endif // DIRECTED_GRAPH_H
