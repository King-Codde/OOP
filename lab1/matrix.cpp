#include "matrix.h"
#include "number.h"
#include <vector>

Tmatrix::Tmatrix()
{
    matrix = new number*[matrix_size];
    for(int i=0; i<matrix_size; i++) {
        matrix[i] = new number [matrix_size];
        for(int j=0; j<matrix_size; j++) {
            matrix[i][j] = 1;
        }
    }
}


Tmatrix::Tmatrix(int size) : matrix_size(size)
{
    number ** temp_matrix = new number*[matrix_size];

    for(int i=0; i < matrix_size; i++) {
        temp_matrix[i] = new number [matrix_size];
        for(int j=0; j< matrix_size; j++) {
            temp_matrix[i][j] = 1;
        }
    }
    matrix = temp_matrix;
}


Tmatrix::Tmatrix(const Tmatrix & ref_matrix) {
    number ** temp_matrix = new number*[ref_matrix.matrix_size];

    for (int i = 0; i < ref_matrix.matrix_size; i++){
        temp_matrix[i] = new number [ref_matrix.matrix_size];
        for (int j = 0; j < ref_matrix.matrix_size; j++){
            temp_matrix[i][j] = ref_matrix.matrix[i][j];
        }
    }

    matrix = temp_matrix;
    matrix_size = ref_matrix.matrix_size;
}


Tmatrix& Tmatrix::operator= (const Tmatrix& ref_matrix) {
    if(this == &ref_matrix)
        return *this;


    if(ref_matrix.matrix_size != matrix_size) {

        for (int i = 0; i < matrix_size; i++){
            delete [] matrix [i];
        }
        delete [] matrix;

        matrix = new number*[ref_matrix.matrix_size];
        for (int i = 0; i < ref_matrix.matrix_size; i++){
            matrix[i] = new number [ref_matrix.matrix_size];
        }
    }


    for (int i = 0; i < ref_matrix.matrix_size; i++){
        for (int j = 0; j < ref_matrix.matrix_size; j++){
            matrix[i][j] = ref_matrix.matrix[i][j];
        }
    }
    matrix_size = ref_matrix.matrix_size;
    return *this;
}

std::ostream& operator<< (std::ostream& os, const Tmatrix& m) {
    for(int i=0; i<m.matrix_size; i++){
        for(int j=0; j<m.matrix_size; j++){
            os << m.matrix[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}


void Tmatrix::copy(number** mass)
{
    for (int i = 0; i < matrix_size; i++)
    {
        for (int j = 0; j < matrix_size; j++)
        {
            matrix[i][j] = mass[i][j];
        }
    }
}





number Tmatrix::det() const{
    if ( matrix_size == 1)
        return matrix[0][0];
    else if ( matrix_size == 2)
    {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    else {
        number d = 0;
        for (int k = 0; k < matrix_size; k++) {
            number** m = new number*[ matrix_size-1];
            for (int i = 0; i <  matrix_size - 1; i++) {
               m[i] = new number[ matrix_size - 1];
            }

            for (int i = 1; i <  matrix_size; i++) {
               int t = 0;
               for (int j = 0; j <  matrix_size; j++) {
                   if (j == k)
                       continue;
                   m[i-1][t] = matrix[i][j];
                   t++;
               }
            }
            Tmatrix Minor(matrix_size-1);
            Minor.copy(m);

            d = d + pow(-1, k + 2) * matrix[0][k] * Minor.det();
            for (int i = 0; i <  matrix_size-1; i++)
            {
                delete[] m[i];
            }
            delete [] m;
        }
        return d;
    }
}




void Tmatrix::transpose() {
    number ** temp_matrix = new number*[matrix_size];
    for(int i=0; i < matrix_size; i++) {
        temp_matrix[i] = new number [matrix_size];
        for(int j=0; j<matrix_size; j++) {
            temp_matrix[i][j] = matrix[j][i];
        }
    }

    matrix = temp_matrix;
}



int Tmatrix::rank() const {

    number** temp_matrix = new number*[matrix_size];
    for(int i=0; i < matrix_size; i++) {
        temp_matrix[i] = new number [matrix_size];
        for(int j=0; j<matrix_size; j++) {
            temp_matrix[i][j] = matrix[i][j];
        }
    }

    for (int i = 0; i < matrix_size; i++)
    {
        if (temp_matrix[i][i] == 0)
        {
            for (int j = i + 1; j < matrix_size; j++)
            {
                if (temp_matrix[j][i] != 0)
                {
                    std::swap(temp_matrix[i], temp_matrix[j]);
                    break;
                }
            }
        }


        if (temp_matrix[i][i] != 0)
        {
            for (int j = i + 1; j < matrix_size; j++)
            {
                int c = temp_matrix[j][i] / temp_matrix[i][i];
                for (int k = i; k < matrix_size; k++)
                {
                    temp_matrix[j][k] -= c * temp_matrix[i][k];
                }
            }
        }
    }

    int rank = 0;
    for (int i = 0; i < matrix_size; i++)
    {
        bool nonzero = false;
        for (int j = 0; j < matrix_size; j++)
        {
            if (temp_matrix[i][j] != 0)
            {
                nonzero = true;
                break;
            }
        }
        if (nonzero) rank++;
    }

    for (int i = 0; i < matrix_size; i++){
        delete [] temp_matrix[i];
    }
    delete [] temp_matrix;

    return rank;
}

Tmatrix::~Tmatrix(){
    for (int i = 0; i < matrix_size; i++){
        delete [] matrix[i];
    }
    delete [] matrix;
}
