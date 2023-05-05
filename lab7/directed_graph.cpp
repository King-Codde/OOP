#include "directed_graph.h"

directed_graph::directed_graph(int n){
    m = new matrix(n);
}

directed_graph::~directed_graph(){
    delete m;
}
