#include <iostream>
#include "fft.hpp"

int main(){
    std::vector<vComp> X = { {0.3835,0.6944},{0.5319,0.0586},{0.9283,0.4466},{0.4586,0.8500}};
    //std::vector<vComp> X = { {0,0},{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0}};
    printVector(X);
    std::vector<vComp> Y;
    Y = fftIterative(X, 1);
    printVector(Y);

    std::vector<vComp> X_new = fftIterative(Y, -1);
    printVector(X_new);
    
    
    return 0;
}