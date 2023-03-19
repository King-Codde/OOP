#include "matrix.h"
#include "number.h"
#include <vector>

using namespace std;
Tmatrix::Tmatrix()
{
    matrix = new number*[matrix_size];
    for(int i=0; i<matrix_size; i++) {
        matrix[i] = new number [matrix_size];
        for(int j=0; j<matrix_size; j++) {
            matrix[i][j] = {1, 0};
        }
    }
}


Tmatrix::Tmatrix(int size) : matrix_size(size)
{
    number ** temp_matrix = new number*[matrix_size];

    for(int i=0; i < matrix_size; i++) {
        temp_matrix[i] = new number [matrix_size];
        for(int j=0; j< matrix_size; j++) {
            number temp_num;
            std::cin >> temp_num;
            temp_matrix[i][j] = temp_num;
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
    for (int i = 0; i < matrix_size; i++){
        for (int j = 0; j < matrix_size; j++){
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




number Tmatrix::det() const {
    TComplex EPS = {1E-9, 1E-9};

    number** temp_matrix = new number*[matrix_size];
    for(int i=0; i < matrix_size; i++) {
        temp_matrix[i] = new number [matrix_size];
        for(int j=0; j<matrix_size; j++) {
            temp_matrix[i][j] = matrix[i][j];
        }
    }


    TComplex det = 1;

    for (int i=0; i<matrix_size; ++i) {
        int k = i;
        for (int j=i+1; j<matrix_size; ++j)
            if (abs (temp_matrix[j][i]) > abs (temp_matrix[k][i]))
                k = j;
        if (abs (temp_matrix[k][i]) < EPS) {
            det = 0;
            break;
        }
        std::swap (temp_matrix[i], temp_matrix[k]);
        if (i != k)
            det = -det;
        det = temp_matrix[i][i] * det;
        for (int j=i+1; j<matrix_size; ++j)
            temp_matrix[i][j] = temp_matrix[i][i] / temp_matrix[i][j];
        for (int j=0; j<matrix_size; ++j)
            if (j != i && abs(temp_matrix[j][i]) > EPS)
                for (int k=i+1; k<matrix_size; ++k)
                    temp_matrix[j][k] = temp_matrix[j][k] - temp_matrix[i][k] * temp_matrix[j][i];
    }

    for (int i = 0; i < matrix_size; i++){
        delete [] temp_matrix[i];
    }
    delete [] temp_matrix;

    return det;
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

int Tmatrix::rankMatrix(){
    number** temp_matrix = new number*[matrix_size];
    for(int i=0; i < matrix_size; i++) {
        temp_matrix[i] = new number [matrix_size];
        for(int j=0; j<matrix_size; j++) {
            temp_matrix[i][j] = matrix[i][j];
        }
    }


    for (int i = 0; i < 4; i++)
    {
        if (temp_matrix[i][i] == 0)
        {
            for (int j = i + 1; j < 4; j++)
            {
                if (temp_matrix[j][i] != 0)
                {
                    swap(temp_matrix[i], temp_matrix[j]);
                    break;
                }
            }
        }

        if (temp_matrix[i][i] != 0)
        {
            for (int j = i + 1; j < 4; j++)
            {
                int c = temp_matrix[j][i] / temp_matrix[i][i];
                for (int k = i; k < 4; k++)
                {
                    temp_matrix[j][k] -= c * temp_matrix[i][k];
                }
            }
        }
    }

    int rank = 0;
    for (int i = 0; i < 4; i++)
    {
        bool nonzero = false;
        for (int j = 0; j < 4; j++)
        {
            if (temp_matrix[i][j] != 0)
            {
                nonzero = true;
                break;
            }
        }
        if (nonzero) rank++;
    }

    return rank;
}

int Tmatrix::rank() const {
    TComplex EPS = {1E-9, 1E-9};

    number** temp_matrix = new number*[matrix_size];
    for(int i=0; i < matrix_size; i++) {
        temp_matrix[i] = new number [matrix_size];
        for(int j=0; j<matrix_size; j++) {
            temp_matrix[i][j] = matrix[i][j];
        }
    }

    int rank = matrix_size;
    std::vector<char> line_used (matrix_size);
    for (int i=0; i<matrix_size; ++i) {

        int j;

        for (j=0; j<matrix_size; ++j)
            if (!line_used[j] && abs(temp_matrix[j][i]) > EPS)
                break;

        if (j == matrix_size)
            --rank;
        else {
            line_used[j] = true;

            for (int p=i+1; p<matrix_size; ++p)
                temp_matrix[j][p] = temp_matrix[j][p] / temp_matrix[j][i];

            for (int k=0; k<matrix_size; ++k)
                if (k != j && abs(temp_matrix[k][i]) > EPS)
                    for (int p=i+1; p<matrix_size; ++p)
                        temp_matrix[k][p] = temp_matrix[k][p] - temp_matrix[j][p] * temp_matrix[k][i];

        }
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
