//
// Created by matteo on 16/03/21.
//

#include <map>
#include "matrix.h"

matrix matrix::operator+(matrix B) {
    matrix R(side);
    for(int r=0; r < side; r++){
        R[r] = data[r] + B[r];
    }
    return R;
}

matrix matrix::operator-(matrix B) {
    matrix R(side);
    for(int r=0; r < side; r++){
        R[r] = data[r] - B[r];
    }
    return R;
}

void matrix::print() {
    for(int r=0;r<side;r++){
        for(int c=0;c<side;c++){
            cout << data[r][c] << '\t';
        }
        cout << '\n';
    }
    cout << '\n';
}

matrix matrix::operator*(matrix B) {
    if(side==1){
        return cell_matrix(data[0][0]*B[0][0]);
    }
    const matrix
            M1 = (sub(false, false)+sub(true, true))*(B.sub(false,false)+B.sub(true,true)),
            M2 = (sub(true,false)+sub(true,true))*B.sub(false,false),
            M3 = sub(false,false)*(B.sub(false,true)-B.sub(true,true)),
            M4 = sub(true,true)*(B.sub(true,false)-B.sub(false,false)),
            M5 = (sub(false,false)+sub(false,true))*B.sub(true,true),
            M6 = (sub(true,false)-sub(false,false))*(B.sub(false,false)+B.sub(false,true)),
            M7 = (sub(false,true)-sub(true,true))*(B.sub(true,false)+B.sub(true,true));
    return matrix(0, nullptr);
}

matrix matrix::sub(bool down, bool right) {
    const int halfSide = side/2;
    matrix res(halfSide);
    res.data = down? &data[halfSide]: data;
    for(int v=0;v<halfSide;v++)
        res.data[v] = res.data[v].split(right);
    return res;
}

int main(){
    matrix A(4), B(4);
    for(int r=0;r<4;r++)
        for(int c=0;c<4;c++){
            A[r][c] = B[r][c] = c+r*4;
        }
    A.print();
    B.print();
    (A+B).print();
    (A-B).print();
    A.sub(false, false).print();
    A.sub(false, true).print();
    A.sub(true, false).print();
    A.sub(true, true).print();

}