#include <iostream>
#include "TestFunctions.h"
int main()
{
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


        std::cout << "a + b = " << sum.getReal() << " + " << sum.getImag() << "i\n";
        std::cout << "a - b = " << difference.getReal() << " + " << difference.getImag() << "i\n";
        std::cout << "a * b = " << product.getReal() << " + " << product.getImag() << "i\n";


        try {
            quotient = a / b;
            std::cout << "a / b = " << quotient.getReal() << " + " << quotient.getImag() << "i\n";
        }
        catch (const std::runtime_error& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        std::cout << "Enter the real part of complex number c to take conjugate and absolute value: ";
        std::cin >> re;
        std::cout << "Enter the imaginary part of complex number c: ";
        std::cin >> im;
        Complex c(re, im);
        Complex conjugate_c = c.conjugate();
        double c_abs = c.abs();

        std::cout << "Conjugate of c = " << conjugate_c.getReal() << " + " << conjugate_c.getImag() << "i\n";
        std::cout << "Absolute value of c = " << c_abs << "\n";

        std::cout << "Want to repeat? \n";
        std::cin >> contin;
        if (contin == 0) break;
    }
    test();
    
    return 0;
}
