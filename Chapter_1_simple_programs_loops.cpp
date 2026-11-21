#include <iostream>
#include <cstdlib>

// Цикл вычисления суммы квадратов натуральных чисел

void example1(){
    int n=10, s = 0, k = 1;
    while(k <= n){
        s = s + k * k;
        k++;
    }

    std::cout << "Sum of squares from 1 to " << n << ": "<< s << std::endl;
    std::system("pause>nul");
}


void example2(){
    int n, s = 0;
    std::cout << "Upper border of sum: ";
    std::cin >> n;
    while (n){
        s += n*n;
        n--;
    }
    std::cout << "Sum of squares: " << s << std::endl;
}


int main(){
    example2();
    std::system("pause>nul");
    return 0;
}