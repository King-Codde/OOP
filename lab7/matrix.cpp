
#include "matrix.h"

matrix::matrix(int n){
    for (auto i = 0; i < n; i++){
        vector.push_back(QVector<qint16>());
        for(auto j = 0; j < n; j++){
            vector[i].push_back(0);
        }
    }
    length = n;
}

qint16 matrix::get(int i, int j){
    return vector[i][j];
}

void matrix::set(qint16 value, int i, int j){
    vector[i][j] = value;
}

