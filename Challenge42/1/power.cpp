//
// Created by matteo on 15/03/21.
//
#include <iostream>
#include <benchmark/benchmark.h>
using namespace std;
#define TES

int power(const int b, const int e){
    if(e==0)
        return 1;
    if(e%2==0) {
        int sub = power(b, e/2);
        return sub*sub;
    }else
        return b*power(b,e-1);
}

#ifdef TEST
int main(){
    const int l = 10;
    int* a = new int[l];

    for(int i=0;i<l;i++)
        a[i]=i;

    for(int b=0; b < l; b++){
        for(int e=0;e<l;e++) {
            cout << b << ',' << e << '\t' << power(b,e) << '\n';
        }
    }
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