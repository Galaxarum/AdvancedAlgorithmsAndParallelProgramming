//
// Created by matteo on 16/03/21.
//

#ifndef COMPLEXITY_MATRIX_H
#define COMPLEXITY_MATRIX_H
#include "vector.h"
#include <iostream>
using namespace std;


class matrix {
vector* data;
int side;
static matrix cell_matrix(int val){
    return matrix(1,new vector[1]{vector(1,new int[1]{val})});
}

public:
matrix(int side, vector* data){
    this->side=side;
    this->data = data;
}
explicit matrix(int side){
    this->side = side;
    data = new vector[side];
    for(int i=0;i<side;i++)
        data[i] = vector(side);
};

vector& operator[](int i){
    return data[i];
}

matrix operator+(matrix B);
matrix operator-(matrix B);
matrix operator*(matrix B);

matrix sub(bool down, bool right);

void print();
};


#endif //COMPLEXITY_MATRIX_H
