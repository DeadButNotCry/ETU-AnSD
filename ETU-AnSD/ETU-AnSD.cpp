// ETU-AnSD.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LabOne.h"
int main() {
    Polynomial poly1("132");
    Polynomial poly2(257);

    Polynomial sum = poly1 + poly2;
    Polynomial diff = poly1 - poly2;
    Polynomial prod = poly1 * poly2;


    std::cout << "sum as number: " << sum.toNumber() << std::endl;
    std::cout << "diff as number: " << diff.toNumber() << std::endl;
    std::cout << "prod as number: " << prod.toNumber() << std::endl;



    return 0;

    return 0;
}