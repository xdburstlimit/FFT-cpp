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
        std::complex<double> a = pow(N,-1);
        std::vector<vComp> f_new;
        for(int i{}; i < F.size();++i){
            f_new.push_back(a*F[i]);
        }
        return f_new;
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
    int bitCount = __builtin_ctz(n);  // log2(n) assuming n is a power of 2

    for (int i = 0; i < n; ++i) {//reversed is the new index for index i
        int reversed = 0, temp = i;
        for (int j = 0; j < bitCount; ++j) {//logN times executed
            reversed = (reversed << 1) | (temp & 1);// 1 = 001, bit shift reversed once to the left,why?  | getting the least significant bit of temp,why? 
            temp >>= 1;//bit shift temp to the right       make space for new bits                    collecting bits from right to left of the current index i stored in temp
        }            //for new bit to be collected
        if (reversed > i) {
            std::swap(f[i], f[reversed]);
        }
    }
    return f;
}