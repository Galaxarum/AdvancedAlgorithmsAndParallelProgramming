//
// Created by matteo on 15/03/21.
//
#include <iostream>
#include <benchmark/benchmark.h>

using namespace std;
#define TEST

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

matrix operator+(const matrix &A, const matrix &B){
    const int size = A.size();
    matrix C(size);
    for(int r=0;r<A.size();r++){
        C[r] = vec(size);
        for(int c=0;c<size;c++)
            C[r][c]=A[r][c]+B[r][c];
    }
    return C;
}

matrix operator-(const matrix &A, const matrix &B){
    const int size = A.size();
    matrix C(size);
    for(int r=0;r<A.size();r++){
        C[r] = vec(size);
        for(int c=0;c<size;c++)
            C[r][c]=A[r][c]-B[r][c];
    }
    return C;
}

submatrices split(const matrix &A){
    const int size = A.size();
    const int newSize = size/2;
    matrix TL(newSize), TR(newSize), BL(newSize), BR(newSize);
    for(int r=0;r<newSize;r++) {
        TL[r] = vec(A[r].begin(), A[r].begin() + newSize);
        TR[r] = vec(A[r].begin() + newSize, A[r].end());
    }
    for(int r=0;r<newSize;r++){
        const int ra = r+newSize;
        BL[r] = vec(A[ra].begin(), A[ra].begin() + newSize);
        BR[r] = vec(A[ra].begin() + newSize, A[ra].end());
    }
    return submatrices(
            pair<matrix,matrix>(TL,TR),
            pair<matrix,matrix>(BL,BR)
            );
}


matrix join(matrix  TL,matrix TR,matrix BL,matrix BR){
    const int halfSize = TL.size();
    const int newSize = 2*halfSize;
    matrix A(newSize);
    for(int r=0;r<halfSize;r++){
        A[r] = TL[r];
        A[r].insert(A[r].end(),TR[r].begin(),TR[r].end());
    }
    for(int r=0;r<halfSize;r++){
        const int rn = r+halfSize;
        A[rn] = BL[r];
        A[rn].insert(A[rn].end(),BR[r].begin(),BR[r].end());
    }
    return A;
}
matrix join(const submatrices& As){
    matrix  TL=As.first.first,
            TR=As.first.second,
            BL=As.second.first,
            BR=As.second.second;
    return join(TL,TR,BL,BR);
}

matrix operator*(const matrix &A, const matrix &B){
    if(A.size()==1){
        matrix R(1);
        R[0] = vec({A[0][0]*B[0][0]});
        return R;
    }
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

static void BM_binary_search(benchmark::State& state) {
    int b = state.range(0);
    int e = state.range(1);
    for(auto _: state)
        power(b,e);
    state.SetComplexityN(e);
}

BENCHMARK(BM_binary_search)
->Ranges({{1e2,1e8},{1e2,1e8}})->Complexity();

BENCHMARK_MAIN();
#endif