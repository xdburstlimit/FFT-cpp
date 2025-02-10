#ifndef _FFT_
#define _FFT_
#include <vector>
#include "./constants.h"
#include <iostream>

std::vector<vComp> fftIterative(std::vector<vComp> &f, double lambda);
std::vector <vComp> bitreversePermute(std::vector<vComp> &f);
void printVector(std::vector <vComp> F);

#endif