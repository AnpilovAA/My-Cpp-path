#include <iostream>
#include <cstdlib>


int main(){
    int n, s = 0;
    std::cout << "Upper boarder of sum: ";
    std::cin >> n;
    if (n > 0){
        while (n)
        {
            s += n * n;
            n--;
        }
        std::cout << "Sum of squares: " << s << std::endl;
    }
    else{
        std::cout << "Insert incorrect value!" << std::endl;
    }
    std::system("pause>nul");
    return 0;
}
