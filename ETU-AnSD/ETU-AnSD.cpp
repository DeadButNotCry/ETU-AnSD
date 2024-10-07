// ETU-AnSD.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LabOne.h"
int main() {
    PolynomialMultiplication pm;
    int num1 = 132;
    int num2 = 257;

    int result = pm.multiply(num1, num2);

    std::cout << "Result of multiply  " << result << std::endl;

    return 0;
}