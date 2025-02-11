#include <iostream>
#include "fft.hpp"
#include "timer.hpp"

int main(){
    std::vector<vComp> X = { {0.3835,0.6944},{0.5319,0.0586},{0.9283,0.4466},{0.4586,0.8500}};
    printVector(X);
    std::vector<vComp> Y;
    {
        Timer timer;

        Y = fftIterative(X, 1);
    }
    printVector(Y);

    return 0;
}