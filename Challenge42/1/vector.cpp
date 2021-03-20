//
// Created by matteo on 16/03/21.
//

#include "vector.h"

vector vector::operator+(vector v) {
    vector res(v.size);
    for (int i=0;i<size;i++)
        res[i] = this->data[i] + v[i];
    return res;
}

vector vector::operator-(vector v) {
    vector res(v.size);
    for (int i=0;i<size;i++)
        res[i] = this->data[i] - v[i];
    return res;
}

vector vector::split(bool right) {
    const int halfSize = size/2;
    if(right)
        return vector(halfSize,&data[halfSize+1]);
    else
        return vector(halfSize,data);
}