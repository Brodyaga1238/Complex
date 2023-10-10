﻿#include <iostream>
#include <cmath>
#include <stdexcept> 

class Complex 
{
    double real;
    double imag;

public:
    Complex() : real(0.0), imag(0.0) {}

    Complex(double r) : real(r), imag(0.0) {}

    Complex(double r, double i) : real(r), imag(i) {}

    const double getReal()
    {
        return real;
    }

    const double getImag()
    {
        return imag;
    }

    const  double abs()
    {
        return sqrt(real * real + imag * imag);
    }

    const Complex conjugate()
    {
        return Complex(real, -imag);
    }

    const Complex operator+(const Complex& other)
    {
        return Complex(real + other.real, imag + other.imag);
    }

    const Complex operator-(const Complex& other)
    {
        return Complex(real - other.real, imag - other.imag);
    }

    const Complex operator*(const Complex& other)
    {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    const Complex operator/(const Complex& other)
    {
        double denominator = other.real * other.real + other.imag * other.imag;
        if (denominator == 0) {
            throw std::runtime_error("Division by zero");
        }
        return Complex((real * other.real + imag * other.imag) / denominator,
            (imag * other.real - real * other.imag) / denominator);
    }

    Complex& operator+=(const Complex& other) 
    {
        real += other.real;
        imag += other.imag;
        return *this;
    }

    Complex& operator-=(const Complex& other) 
    {
        real -= other.real;
        imag -= other.imag;
        return *this;
    }

    Complex& operator*=(const Complex& other) {
        double temp_real = real * other.real - imag * other.imag;
        double temp_imag = real * other.imag + imag * other.real;
        real = temp_real;
        imag = temp_imag;
        return *this;
    }

    Complex& operator/=(const Complex& other) {
        double denominator = other.real * other.real + other.imag * other.imag;
        double temp_real = (real * other.real + imag * other.imag) / denominator;
        double temp_imag = (imag * other.real - real * other.imag) / denominator;
        real = temp_real;
        imag = temp_imag;
        return *this;
    }

    const bool operator==(const Complex& other)  {
        return (real == other.real && imag == other.imag);
    }

    const bool operator!=(const Complex& other)  {
        return !(*this == other);
    }
};

