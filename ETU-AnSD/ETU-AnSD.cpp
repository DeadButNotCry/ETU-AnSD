// ETU-AnSD.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LabOne.h"
int main() {
    int num1 = 132;
    int num2 = 257;
    Polynomial poly1(num1);
    Polynomial poly2(num2);

    Polynomial sum = poly1 + poly2;
    Polynomial diff = poly1 - poly2;
    Polynomial prod = poly1 * poly2;

    std::cout << "poly1: " << poly1 << std::endl;
    std::cout << "poly2: " << poly2 << std::endl;
    std::cout << "sum: " << sum << std::endl;
    std::cout << "diff: " << diff << std::endl;
    std::cout << "prod: " << prod << std::endl;

    std::cout << "sum as number: " << sum.toNumber() << std::endl;
    std::cout << "diff as number: " << diff.toNumber() << std::endl;
    std::cout << "prod as number: " << prod.toNumber() << std::endl;

    return 0;

    return 0;
}