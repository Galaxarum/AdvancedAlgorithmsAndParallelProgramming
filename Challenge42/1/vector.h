//
// Created by matteo on 16/03/21.
//

#ifndef COMPLEXITY_VECTOR_H
#define COMPLEXITY_VECTOR_H

#include <utility>
using namespace std;

class vector {
    int* data;
    int size;
public:
    vector(int size, int* data){
        this->size=size;
        this->data=data;
    }
    explicit vector(int size):vector(size,new int[size]){};
    vector():vector(0){};

    int& operator[](int i){
        return data[i];
    }

    vector operator+(vector v);
    vector operator-(vector v);
    vector split(bool right);
};


#endif //COMPLEXITY_VECTOR_H
