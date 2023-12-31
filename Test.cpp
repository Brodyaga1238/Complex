#include <iostream>
#include "TestFunctions.h"

void printComplex(const Complex& num, const std::string& operation) {
    double real = num.getReal();
    double imag = num.getImag();
    std::cout << operation << " = ";
    if (real == 0 && imag == 0) {
        std::cout << "0" << "\n";
    }
    else if (real == 0) {
        std::cout << imag << "i" << "\n";
    }
    else if (imag == 0) {
        std::cout << real << "\n";
    }
    else {
        std::cout << real << " + " << imag << "i" << "\n";
    }
}

int main() {
    while (true) {
        bool contin;
        double re = 0.0;
        double im = 0.0;
        std::cout << "Enter the real part of complex number a: ";
        std::cin >> re;
        std::cout << "Enter the imaginary part of complex number a: ";
        std::cin >> im;
        Complex a(re, im);
        std::cout << "Enter the real part of complex number b: ";
        std::cin >> re;
        std::cout << "Enter the imaginary part of complex number b: ";
        std::cin >> im;
        Complex b(re, im);

        Complex sum = a + b;
        Complex difference = a - b;
        Complex product = a * b;
        Complex quotient;

        printComplex(sum, "a + b");
        printComplex(difference, "a - b");
        printComplex(product, "a * b");

        try {
            quotient = a / b;
            printComplex(quotient, "a / b");
        }
        catch (const std::runtime_error& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }

        std::cout << "a == b " << (a == b ? "true" : "false") << "\n";

        printComplex(a.conjugate(), "Conjugate of a");
        printComplex(a.abs(), "Absolute value of a");

        printComplex(b.conjugate(), "Conjugate of b");
        printComplex(b.abs(), "Absolute value of b");
        b++;
        printComplex(b, "b++");
        ++b;
        printComplex(b, "++b");
        b--;
        printComplex(b, "b--");
        --b;
        printComplex(b, "--b");
        std::cout << "Want to repeat? " << "\n";
        std::cin >> contin;
        if (contin == 0) break;
    }
    test();

    return 0;
}
