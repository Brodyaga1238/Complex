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
        if (sum.getReal() == 0 && sum.getImag()==0 )  std::cout << "a + b = " << 0<< "\n";
        else
            if (sum.getReal() == 0)  std::cout << "a + b = " << sum.getImag() << "i\n";
            else
                if (sum.getImag() == 0)  std::cout << "a + b = " << sum.getReal()<<"\n";
                else
                    std::cout << "a + b = " << sum.getReal() << " + " << sum.getImag() << "i\n";
        if (difference.getReal() == 0 && difference.getImag() == 0)  std::cout << "a - b = " << 0 << "\n";
        else
            if (difference.getReal() == 0)  std::cout << "a - b  = " << difference.getImag() << "i\n";
            else
                if (difference.getImag() == 0)  std::cout << "a - b = " << difference.getReal() << "\n";
                else
                    std::cout << "a - b = " << difference.getReal() << " + " << difference.getImag() << "i\n";
        if (product.getReal() == 0 && product.getImag() == 0)  std::cout << "a * b = " << 0 << "\n";
        else
            if (product.getReal() == 0)  std::cout << "a * b  = " << product.getImag() << "i\n";
            else
                if (product.getImag() == 0)  std::cout << "a *b = " << product.getReal() << "\n";
                else
                    std::cout << "a * b = " << product.getReal() << " + " << product.getImag() << "i\n";
        


        try {
            quotient = a / b;
            if (quotient.getReal() == 0 && quotient.getImag() == 0)  std::cout << "a / b = " << 0 << "\n";
            else
                if (quotient.getReal() == 0)  std::cout << "a / b  = " << quotient.getImag() << "i\n";
                else
                    if (quotient.getImag() == 0)  std::cout << "a / b = " << quotient.getReal() << "\n";
                    else
                        std::cout << "a / b = " << quotient.getReal() << " + " << quotient.getImag() << "i\n";
        }
        catch (const std::runtime_error& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        if (a==b)
        std::cout << "a=b true"<<"\n";
        else std::cout << "a=b false" << "\n";

        Complex conjugate_a = a.conjugate();
        double a_abs = a.abs();
        Complex conjugate_b = b.conjugate();
        double b_abs = b.abs();

        if (conjugate_a.getReal() == 0 && conjugate_a.getImag() == 0)  std::cout << "Conjugate of a = " << 0 << "\n";
        else
            if (conjugate_a.getReal() == 0)  std::cout << "Conjugate of a  = " << conjugate_a.getImag() << "i\n";
            else
                if (conjugate_a.getImag() == 0)  std::cout << "Conjugate of a = " << conjugate_a.getReal() << "\n";
                else
                    std::cout << "Conjugate of a = " << conjugate_a.getReal() << " + " << conjugate_a.getImag() << "i\n";
        std::cout << "Absolute value of a = " << a_abs << "\n";

        if (conjugate_b.getReal() == 0 && conjugate_b.getImag() == 0)  std::cout << "Conjugate of b = " << 0 << "\n";
        else
            if (conjugate_b.getReal() == 0)  std::cout << "Conjugate of b  = " << conjugate_b.getImag() << "i\n";
            else
                if (conjugate_b.getImag() == 0)  std::cout << "Conjugate of b = " << conjugate_b.getReal() << "\n";
                else
                    std::cout << "Conjugate of b = " << conjugate_b.getReal() << " + " << conjugate_b.getImag() << "i\n";
        std::cout << "Absolute value of b = " << b_abs << "\n";

        std::cout << "Want to repeat? \n";
        std::cin >> contin;
        if (contin == 0) break;
    }
    test();
    
    return 0;
}
