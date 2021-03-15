//
// Created by matteo on 15/03/21.
//
#include <iostream>
#include <benchmark/benchmark.h>
using namespace std;
#define TES

int binary_search(const int a[], const int target, const int b, const int e){
    if(e<=b)
        return -1;
    int i = b+(e-b)/2;
    int elem = a[i];
    if(elem==target)
        return i;
    else if(target<elem)
        return binary_search(a,target,b,i-1);
    else
        return binary_search(a,target,i+1,e);
}

#ifdef TEST
int main(){
    const int l = 64;
    int* a = new int[64];

    for(int i=0;i<l;i++)
        a[i]=i;

    for(int i=-10; i<1.5*l;i++){
        cout << i << '\t' << binary_search(a,i,0,l) << '\n';
    }
}
#else
#define MIN_L 1e4
#define MAX_L 1e7
int* construct_random_array(const int l){   //values in 0,2l
    int* a = new int[l];
    for(int i=0;i<l;i++)
        a[i]=rand()%(2*l);
    return a;
}

int* create_sorted_array(const int l){
    int* a = new int[l];
    for(int i=0;i<l;i++){
        a[i]=i;
    }
    return a;
}

const int* arr = create_sorted_array(MAX_L);
const int* targets = construct_random_array(MAX_L);

static void BM_binary_search(benchmark::State& state) {
    int l = state.range(0);
    for(auto _: state)
        binary_search(arr, targets[l], 0,l);
    state.SetComplexityN(l);
}

BENCHMARK(BM_binary_search)
->RangeMultiplier(4)->Range(MIN_L, MAX_L)->Complexity();

BENCHMARK_MAIN();
#endif