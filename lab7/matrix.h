
#ifndef MATRIX_H
#define MATRIX_H
#include <QVector>


template<class T>
class matrix{
public:
    matrix(int n){
        for (auto i = 0; i < n; i++){
            Matrix.push_back(QVector<T>());
            for(auto j = 0; j < n; j++){
                Matrix[i].push_back(0);
            }
        }
    }
    T get(int i, int j){return Matrix[i][j];}
    void set(T value, int i, int j){Matrix[i][j] = value;}
    int len(){return Matrix.size();}
private:
    QVector<QVector<T>> Matrix;
};
#endif // MATRIX_H
