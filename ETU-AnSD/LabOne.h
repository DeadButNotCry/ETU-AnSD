#pragma once
#include <vector>


class PolynomialMultiplication {
public:
    // Публичный метод для умножения двух чисел через умножение многочленов
    int multiply(int num1, int num2) {
        // Преобразуем числа в многочлены
        std::vector<int> poly1 = numberToPolynomial(num1);
        std::vector<int> poly2 = numberToPolynomial(num2);

        // Умножаем многочлены
        std::vector<int> resultPoly = multiplyPolynomials(poly1, poly2);

        // Преобразуем результат обратно в число
        int result = polynomialToNumber(resultPoly);

        return result;
    }

private:
    // Метод для преобразования числа в многочлен
    std::vector<int> numberToPolynomial(int num) {
        std::vector<int> poly;
        while (num > 0) {
            poly.push_back(num % 10);
            num /= 10;
        }
        return poly;
    }

    // Метод для умножения двух многочленов
    std::vector<int> multiplyPolynomials(const std::vector<int>& poly1, const std::vector<int>& poly2) {
        std::vector<int> result(poly1.size() + poly2.size() - 1, 0);

        for (size_t i = 0; i < poly1.size(); ++i) {
            for (size_t j = 0; j < poly2.size(); ++j) {
                result[i + j] += poly1[i] * poly2[j];
            }
        }
        for (int i = 0; i < result.size()-1; ++i)
        {
	        if(result[i] >= 10)
	        {
                result[i + 1] += result[i] / 10;
                result[i] = result[i] % 10;
	        }
        }
        return result;
    }

    // Метод для преобразования многочлена обратно в число
    int polynomialToNumber(const std::vector<int>& poly) {
        int result = 0;
        int power = 1;

        for (int coeff : poly) {
            result += coeff * power;
            power *= 10;
        }

        return result;
    }
};
