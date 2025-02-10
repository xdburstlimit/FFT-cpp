#include "./fft.hpp"
std::complex<double> I(0,1);
std::vector<vComp> fftIterative(std::vector<vComp> &f, double lambda){ //f has a size that is a power of 2.
    
    int N = f.size();
    std::vector<vComp> F;
    if(f.size() == 1){
        std::cout << "F returned\n";
        F.push_back(f[0]);
        return F;
    }
    F = bitreversePermute(f);         
    vComp theta = (2*PI*I)*(lambda/N);
    std::vector<vComp> w;
    for(int i{}; i < N/2; ++i){
        w.push_back(exp(double(i)*theta));
    }


    int currN = 2;
  
    while(currN <= N){
        int halfcurrN = currN/2;
        int tablestep = N/currN;
        for(int i{}; i <= N - currN; i+=currN){
            int k = 0;
            for(int j{i}; j < i + halfcurrN;++j){
                int index{j+halfcurrN};
                vComp temp = w[k]*F[index];
                F[index] = F[j] - temp;
                F[j] = F[j] + temp;
                k = k + tablestep;
            }
        }
        currN = 2*currN;
    }
    if(lambda== -1){
        std::complex<double> a = 0.25;
        for(int i{}; i < F.size();++i){
            F[i] = a*F[i];
        }
    }
    
    return F;
}

void printVector(std::vector <vComp> F){
    for(auto& f: F){
        std::cout << f << ' ';
    }
    std::cout << '\n';
}

std::vector <vComp> bitreversePermute(std::vector<vComp> &f){
    int n = f.size();
    int logN = __builtin_ctz(n);  // log2(n) assuming n is a power of 2

    for (int i = 0; i < n; ++i) {
        int reversed = 0, temp = i;
        for (int j = 0; j < logN; ++j) {
            reversed = (reversed << 1) | (temp & 1);
            temp >>= 1;
        }
        if (reversed > i) {
            std::swap(f[i], f[reversed]);
        }
    }
    return f;
}