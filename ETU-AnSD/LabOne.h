class Polynomial {
public:
    // Конструктор по умолчанию
    Polynomial() : coefficients(nullptr), size(0) {}

    // Конструктор с инициализацией коэффициентов
    Polynomial(int* coeffs, int sz) : size(sz) {
        coefficients = new int[size];
        std::memcpy(coefficients, coeffs, size * sizeof(int));
    }

    // Конструктор из числа
    Polynomial(int num) {
        size = getPolynomialSize(num);
        coefficients = new int[size];
        for (int i = 0; i < size; ++i) {
            coefficients[i] = num % 10;
            num /= 10;
        }
    }

    // Деструктор
    ~Polynomial() {
        delete[] coefficients;
    }

    // Копирующий конструктор
    Polynomial(const Polynomial& other) : size(other.size) {
        coefficients = new int[size];
        std::memcpy(coefficients, other.coefficients, size * sizeof(int));
    }

    // Оператор присваивания
    Polynomial& operator=(const Polynomial& other) {
        if (this != &other) {
            delete[] coefficients;
            size = other.size;
            coefficients = new int[size];
            std::memcpy(coefficients, other.coefficients, size * sizeof(int));
        }
        return *this;
    }

    // Перегрузка оператора сложения
    Polynomial operator+(const Polynomial& other) const {
        int maxSize = std::max(size, other.size);
        int* resultCoeffs = new int[maxSize];
        std::memset(resultCoeffs, 0, maxSize * sizeof(int));

        for (int i = 0; i < size; ++i) {
            resultCoeffs[i] += coefficients[i];
        }

        for (int i = 0; i < other.size; ++i) {
            resultCoeffs[i] += other.coefficients[i];
        }

        // Обработка переносов
        for (int i = 0; i < maxSize - 1; ++i) {
            if (resultCoeffs[i] >= 10) {
                resultCoeffs[i + 1] += resultCoeffs[i] / 10;
                resultCoeffs[i] %= 10;
            }
        }

        return Polynomial(resultCoeffs, maxSize);
    }

    // Перегрузка оператора вычитания
    Polynomial operator-(const Polynomial& other) const {
        int maxSize = std::max(size, other.size);
        int* resultCoeffs = new int[maxSize];
        std::memset(resultCoeffs, 0, maxSize * sizeof(int));

        for (int i = 0; i < size; ++i) {
            resultCoeffs[i] += coefficients[i];
        }

        for (int i = 0; i < other.size; ++i) {
            resultCoeffs[i] -= other.coefficients[i];
        }

        // Обработка заимствований
        for (int i = 0; i < maxSize - 1; ++i) {
            if (resultCoeffs[i] < 0) {
                resultCoeffs[i + 1] -= 1;
                resultCoeffs[i] += 10;
            }
        }

        // Удаление ведущих нулей
        while (maxSize > 1 && resultCoeffs[maxSize - 1] == 0) {
            --maxSize;
        }

        return Polynomial(resultCoeffs, maxSize);
    }

    // Перегрузка оператора умножения
    Polynomial operator*(const Polynomial& other) const {
        int resultSize = size + other.size - 1;
        int* resultCoeffs = new int[resultSize];
        std::memset(resultCoeffs, 0, resultSize * sizeof(int));

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < other.size; ++j) {
                resultCoeffs[i + j] += coefficients[i] * other.coefficients[j];
            }
        }

        // Обработка переносов
        for (int i = 0; i < resultSize - 1; ++i) {
            if (resultCoeffs[i] >= 10) {
                resultCoeffs[i + 1] += resultCoeffs[i] / 10;
                resultCoeffs[i] %= 10;
            }
        }

        return Polynomial(resultCoeffs, resultSize);
    }

    // Метод для преобразования многочлена обратно в число
    int toNumber() const {
        int result = 0;
        int power = 1;

        for (int i = 0; i < size; ++i) {
            result += coefficients[i] * power;
            power *= 10;
        }

        return result;
    }

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& poly) {
        for (int i = poly.size - 1; i >= 0; --i) {
            os << poly.coefficients[i];
        }
        return os;
    }

private:
    int* coefficients;
    int size;

    int getPolynomialSize(int num) const {
        int size = 0;
        while (num > 0) {
            num /= 10;
            ++size;
        }
        return size;
    }
};