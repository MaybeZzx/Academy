#include <iostream>

struct ComplexNumber {
    double real;
    double imag;

    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    ComplexNumber operator+(const ComplexNumber& right) const {
        return ComplexNumber(real + right.real, imag + right.imag);
    }

    ComplexNumber operator-(const ComplexNumber& right) const {
        return ComplexNumber(real - right.real, imag - right.imag);
    }

    ComplexNumber operator*(const ComplexNumber& right) const {
        return ComplexNumber(real * right.real - imag * right.imag, real * right.imag + imag * right.real);
    }

    ComplexNumber operator/(const ComplexNumber& right) const {
        double del = right.real * right.real + right.imag * right.imag;
        return ComplexNumber((real * right.real + imag * right.imag) / del, (imag * right.real - real * right.imag) / del);
    }
};

std::ostream& operator<<(std::ostream& out, const ComplexNumber& c) {
    out << c.real << (c.imag >= 0 ? "+" : "") << c.imag << "i";
    return out;
}

int main() {
    setlocale(LC_ALL, "rus");
    ComplexNumber a(4.0, 3.0);
    ComplexNumber b(2.0, -1.0);

    std::cout << "Сумма: " << a + b << std::endl;
    std::cout << "Разность: " << a - b << std::endl;
    std::cout << "Умножение: " << a * b << std::endl;
    std::cout << "Деление: " << a / b << std::endl;

    return 0;
}
