#include "application.h"
#include <iostream>
#include "number.h"
#include "matrix.h"


Tapplication::Tapplication()
{

}


int Tapplication::exec() const {
    int matrix_size = 2;
    Tmatrix new_matrix;
    while (true){
        int ch;
        ch = menu();

        switch (ch) {
            case 1:{
                std::cout << "matrix_size = ";
                std::cin >> matrix_size;
                Tmatrix m(matrix_size);
                std::cout << "New matrix:" << std::endl;
                std::cout << m;
                new_matrix = m;
                break;
            }
            case 2:
                std::cout << "det(matrix):" << new_matrix.det() << std::endl;
                break;
            case 3:{
                new_matrix.transepose();
                std::cout << "transpose(matrix):" << std::endl;
                std::cout << new_matrix;
                break;
            }
            case 4:{
                std::cout << "rank(matrix):" << new_matrix.rank() << std::endl;
                break;
            }
            case 5:{
                std::cout << new_matrix;
                break;
            }
            case 0:
                return 0;
            default:
                break;
        }
    }
}



int Tapplication::menu() const {
    std::cout << "1 - operation create(matrix)" << std::endl;
    std::cout << "2 - operation dict(matrix)" << std::endl;
    std::cout << "3 - operation transepose(matrix)" << std::endl;
    std::cout << "4 - operation rank(matrix)" << std::endl;
    std::cout << "5 - operation print(matrix)" << std::endl;
    std::cout << "0 - exit" << std::endl << "> ";
    int ch;
    std::cin >> ch;
    return ch;
}
