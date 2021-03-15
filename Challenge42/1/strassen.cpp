//
// Created by matteo on 15/03/21.
//
#include <iostream>
#include <benchmark/benchmark.h>
#include <cmath>

using namespace std;
#define TES

typedef vector<vector<int>> matrix;
typedef vector<int> vec;
typedef pair<pair<matrix,matrix>, pair<matrix,matrix>> submatrices;

void print(const matrix& A){
    const int size = A.size();
    for(int r=0;r<size;r++) {
        for (int c = 0; c < size; c++)
            cout << A[r][c] << '\t';
        cout << '\n';
    }
    cout << '\n';
}

vec operator+(const vec &v1, const vec &v2) {
    const int size = v1.size();
    vec r = vec(size);
    for(int i=0;i<size;i++)
        r[i]=v1[i]+v2[i];
    return r;
}

vec operator-(const vec &v1, const vec &v2) {
    const int size = v1.size();
    vec r = vec(size);
    for(int i=0;i<size;i++)
        r[i]=v1[i]-v2[i];
    return r;
}

matrix operator+(const matrix &A, const matrix &B){
    const int size = A.size();
    matrix C(size);
    for(int r=0;r<A.size();r++)
        C[r]=A[r]+B[r];
    return C;
}

matrix operator-(const matrix &A, const matrix &B){
    const int size = A.size();
    matrix C(size);
    for(int r=0;r<A.size();r++)
        C[r]=A[r]-B[r];
    return C;
}

submatrices split(const matrix &A){
    const int size = A.size();
    const int newSize = size/2;
    matrix TL(newSize), TR(newSize), BL(newSize), BR(newSize);
    for(int r=0,ra=newSize;r<newSize;r++,ra++) {
        TL[r] = vec(A[r].begin(), A[r].begin() + newSize);
        TR[r] = vec(A[r].begin() + newSize, A[r].end());
        BL[r] = vec(A[ra].begin(), A[ra].begin() + newSize);
        BR[r] = vec(A[ra].begin() + newSize, A[ra].end());
    }
    return submatrices(
            pair<matrix,matrix>(TL,TR),
            pair<matrix,matrix>(BL,BR)
            );
}


matrix join(const matrix& TL,const matrix& TR,const matrix& BL,const matrix& BR){
    const int halfSize = TL.size();
    const int newSize = 2*halfSize;
    matrix A(newSize);
    for(int r=0,rn=halfSize;r<halfSize;r++,rn++){
        A[r].reserve(newSize);
        A[r].insert(A[r].end(),TL[r].begin(),TL[r].end());
        A[r].insert(A[r].end(),TR[r].begin(),TR[r].end());
        A[rn].reserve(newSize);
        A[rn].insert(A[rn].end(),BL[r].begin(),BL[r].end());
        A[rn].insert(A[rn].end(),BR[r].begin(),BR[r].end());
    }
    return A;
}
matrix join(const submatrices& As){
    return join(As.first.first, As.first.second, As.second.first, As.second.second);
}

matrix operator*(const matrix &A, const matrix &B){
    if(A.size()==1) //
        return matrix({vec({A[0][0]*B[0][0]})});
    const submatrices As = split(A), Bs = split(B);
    const matrix
        M1 = (As.first.first+As.second.second)*(Bs.first.first+Bs.second.second),
        M2 = (As.second.first+As.second.second)*Bs.first.first,
        M3 = As.first.first*(Bs.first.second-Bs.second.second),
        M4 = As.second.second*(Bs.second.first-Bs.first.first),
        M5 = (As.first.first+As.first.second)*Bs.second.second,
        M6 = (As.second.first-As.first.first)*(Bs.first.first+Bs.first.second),
        M7 = (As.first.second-As.second.second)*(Bs.second.first+Bs.second.second);
    return join(
            M1+M4-M5+M7,    M3+M5,
            M2+M4,          M1-M2+M3+M6
            );
}

#ifdef TEST
int main(){
    matrix A(4);
    A[0] = vec({1,2,3,4});
    A[1] = vec({5,6,7,8});
    A[2] = vec({9,10,11,12});
    A[3] = vec({13,14,15,16});
    matrix B(4);
    B[0] = vec({1,2,3,4});
    B[1] = vec({5,6,7,8});
    B[2] = vec({9,10,11,12});
    B[3] = vec({13,14,15,16});
    print(A);
    print(B);
    print(A+B);
    print(A-B);
    submatrices As = split(A);
    print(As.first.first);
    print(join(As));
    print(join(A,B,B,A));
    print(A*B);
}
#else

static void BM_strassen(benchmark::State& state) {
    int side = state.range(0);
    matrix A(side), B(side);
    for(int r=0; r < side; r++){
        A[r]=vec(side);
        B[r]=vec(side);
    }
    for(auto _: state)
        A*B;
    state.SetComplexityN(side);
}

BENCHMARK(BM_strassen)
->RangeMultiplier(2)->DenseRange(1,10)->DenseRange(50,200,50)->DenseRange(300,500,100)->DenseRange(1000,3000,1000)
->Complexity([](benchmark::IterationCount n)->double{return pow(n,log2(7));});

BENCHMARK_MAIN();
#endif