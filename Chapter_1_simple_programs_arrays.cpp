#include <iostream>
#include <cstdlib>
#include <vector>


int main(){
    // Const valume array
    const int n = 10;
    // create array
    std::vector<int> bnm(n+1);
    //indexing of a variable
    int k = 0;
    auto firstIndex = bnm.begin();
    firstIndex = bnm.insert(firstIndex, 1);
    std::cout << bnm[0] << std::endl;

    while (k < n)
    {
        bnm.at(k+1) = bnm[k] * (n-k) / (k + 1);
        std::cout << " " << bnm[k+1]<< std::endl;
        k++;
    }

    

    std::system("pause>nul");
    return 0;
}