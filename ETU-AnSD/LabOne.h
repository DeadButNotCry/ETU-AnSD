#pragma once

class PolynomialMultiplication {
public:
    int multiply(int num1, int num2) {
        // Преобразуем числа в многочлены
        int* poly1 = numberToPolynomial(num1);
        int* poly2 = numberToPolynomial(num2);

        int size1 = getPolynomialSize(num1);
        int size2 = getPolynomialSize(num2);

        int* resultPoly = multiplyPolynomials(poly1, size1, poly2, size2);

        int result = polynomialToNumber(resultPoly, size1 + size2 - 1);

        delete[] poly1;
        delete[] poly2;
        delete[] resultPoly;

        return result;
    }

private:
    int* numberToPolynomial(int num) {
        int size = getPolynomialSize(num);
        int* poly = new int[size];
        memset(poly, 0, size * sizeof(int));

        for (int i = 0; i < size; ++i) {
            poly[i] = num % 10;
            num /= 10;
        }

        return poly;
    }

    int getPolynomialSize(int num) {
        int size = 0;
        while (num > 0) {
            num /= 10;
            ++size;
        }
        return size;
    }

    int* multiplyPolynomials(const int* poly1, int size1, const int* poly2, int size2) {
        int resultSize = size1 + size2 - 1;
        int* result = new int[resultSize];
        memset(result, 0, resultSize * sizeof(int));

        for (int i = 0; i < size1; ++i) {
            for (int j = 0; j < size2; ++j) {
                result[i + j] += poly1[i] * poly2[j];
            }
        }

        return result;
    }

    // Метод для преобразования многочлена обратно в число
    int polynomialToNumber(const int* poly, int size) {
        int result = 0;
        int power = 1;

        for (int i = 0; i < size; ++i) {
            result += poly[i] * power;
            power *= 10;
        }

        return result;
    }
};