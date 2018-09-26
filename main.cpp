#include <iostream>
#include "Array.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Array<int> a;
    a.push_back(5);
    a.push_back(11);
    a.push_back(4);

    for(int i=0;i<a.size();i++){
        std::cout<<a[i]<<std::endl;
    }
    return 0;
}