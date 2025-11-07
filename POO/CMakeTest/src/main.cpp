#include <iostream>
#include "calcul.hpp"

int main() {
    double a = 3.0, b = 8.0;

    std::cout << "a + b = " << addition(a, b) << std::endl;
    std::cout << "a - b = " << soustraction(a, b) << std::endl;
    std::cout << "a * b = " << multiplication(a, b) << std::endl;
    std::cout << "a / b = " << division(a, b) << std::endl;

    return 0;
}
