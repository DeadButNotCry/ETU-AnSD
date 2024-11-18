class Polynomial {
public:
	Polynomial() : coefficients(nullptr), size(0) {}

	Polynomial(int* coeffs, int sz) : size(sz) {
		coefficients = new int[size];
		std::memcpy(coefficients, coeffs, size * sizeof(int));
	}

	Polynomial(int num) {
		size = getPolynomialSize(num);
		coefficients = new int[size];
		for (int i = 0; i < size; ++i) {
			coefficients[i] = num % 10;
			num /= 10;
		}
	}

	~Polynomial() {
		delete[] coefficients;
	}

	Polynomial(const Polynomial& other) : size(other.size) {
		coefficients = new int[size];
		std::memcpy(coefficients, other.coefficients, size * sizeof(int));
	}


	Polynomial(const char* str) {
		size = strlen(str);
		coefficients = new int[size];
		for (int i = 0; i < size; ++i) {
			coefficients[i] = str[size - 1 - i] - '0';  // Преобразуем символ в цифру
		}
	}

	Polynomial& operator=(const Polynomial& other) {
		if (this != &other) {
			delete[] coefficients;
			size = other.size;
			coefficients = new int[size];
			std::memcpy(coefficients, other.coefficients, size * sizeof(int));
		}
		return *this;
	}


	friend std::ostream& operator<<(std::ostream& os, const Polynomial& poly) {
		for (int i = poly.size - 1; i >= 0; --i) {
			os << poly.coefficients[i];
		}
		return os;
	}

	

	int evaluate(int x) const {
		int result = 0;
		int power = 1;

		for (int i = 0; i < size; ++i) {
			result += coefficients[i] * power;
			power *= x;
		}

		return result;
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