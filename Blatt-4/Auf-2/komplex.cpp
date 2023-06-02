#include <iostream>
using namespace std;
class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Überladung des Addition-Operators
    Complex operator+(const Complex& other) {
        Complex result;
        result.real = this->real + other.real;
        result.imag = this->imag + other.imag;
        return result;
    }

    // Überladung des Subtraktions-Operators
    Complex operator-(const Complex& other) {
        Complex result;
        result.real = this->real - other.real;
        result.imag = this->imag - other.imag;
        return result;
    }

    // Überladung des Multiplikations-Operators
    Complex operator*(const Complex& other) {
        Complex result;
        result.real = this->real * other.real - this->imag * other.imag;
        result.imag = this->real * other.imag + this->imag * other.real;
        return result;
    }

    // Getter-Methoden für Real- und Imaginärteil
    double getReal() const { return real; }
    double getImag() const { return imag; }
};

// Überladung des Ausgabeoperators (<<), um komplexe Zahlen auszugeben
ostream& operator<<(ostream& os, const Complex& complex) {
    os << complex.getReal() << " + " << complex.getImag() << "i";
    return os;
}

int main() {
    Complex a(2.0, 3.0);
    Complex b(4.0, 1.5);

    Complex sum = a + b;
    Complex difference = a - b;
    Complex product = a * b;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a + b = " << sum << endl;
    cout << "a - b = " << difference << endl;
    cout << "a * b = " << product << endl;

    return 0;
}
