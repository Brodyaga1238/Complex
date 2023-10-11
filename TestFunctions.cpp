    #include <iostream>
    #include <random>
    #include "TestFunctions.h"
    void test()
    {
        const int n = 100;
        int i;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> dis(-100.0, 100.0);
        // Тестовый случай 1: Сложение
        for (i = 0; i < n; i++)
        {
            double re_a = dis(gen);
            double im_a = dis(gen);
            double re_b = dis(gen);
            double im_b = dis(gen);

            Complex a(re_a, im_a);
            Complex b(re_b, im_b);
            Complex sum = a + b;

            if (sum.getReal() == re_a + re_b && sum.getImag() == im_a + im_b)
            {
                if (i == n - 1) std::cout << "test 1 passed\n";
            }
            else
            {
                std::cerr << "test 1 failed\n";
                break;
            }
        }

        // Тестовый случай 2: Вычитание
        for (i = 0; i < n; i++) {
            double re_a = dis(gen);
            double im_a = dis(gen);
            double re_b = dis(gen);
            double im_b = dis(gen);

            Complex a(re_a, im_a);
            Complex b(re_b, im_b);
            Complex difference = a - b;

            if ((difference.getReal() == re_a - re_b) && (difference.getImag() == im_a - im_b))
            {
                if (i == n - 1) std::cout << "test 2 passed\n";
            }
            else {
                std::cerr << "test 2 failed\n";
                break;
            }
        }
        // Тестовый случай 3: Умножение
        for (i = 0; i < n; i++) {
            double re_a = dis(gen);
            double im_a = dis(gen);
            double re_b = dis(gen);
            double im_b = dis(gen);

            Complex a(re_a, im_a);
            Complex b(re_b, im_b);
            Complex product = a * b;

            if ((product.getReal() == re_a * re_b - im_a * im_b) && (product.getImag() == re_a * im_b + im_a * re_b))
            {
                if (i == n - 1) std::cout << "test 3 passed\n";
            }
            else
            {
                std::cerr << "test 3 failed\n";
                break;
            }
        }

        // Тестовый случай 4: Деление
        for (i = 0; i < n; i++) {
            double re_a = dis(gen);
            double im_a = dis(gen);
            double re_b = dis(gen);
            double im_b = dis(gen);



            Complex a(re_a, im_a);
            Complex b(re_b, im_b);
            Complex quotient = a / b;


            if ((quotient.getReal() == (re_a * re_b + im_a * im_b) / (re_b * re_b + im_b * im_b)) && (quotient.getImag() == (im_a * re_b - re_a * im_b) / (re_b * re_b + im_b * im_b)))
            {
                if (i == n - 1) std::cout << "test 4 passed\n";
            }
            else {
                std::cerr << "test 4 failed\n";
                break;
            }
        }

        // Тестовый случай 5: Модуль
        for (i = 0; i < n; i++) {
            double re_a = dis(gen);
            double im_a = dis(gen);

            Complex c(re_a, im_a);

            if ((c.abs() == sqrt(re_a * re_a + im_a * im_a)))
            {
                if (i == n - 1) std::cout << "test 5 passed\n";
            }
            else {
                std::cerr << "test 5 failed\n";
                break;
            }
        }
        // Тестовый случай 6: Сравнение
        for (i = 0; i < n; i++) 
        {
            double re_a = dis(gen);
            double im_a = dis(gen);

            Complex c(re_a, im_a);
            Complex d(-re_a, -im_a);

            if (c!=d) std::cout << "test 5 passed\n";
            else 
            {
                std::cerr << "test 5 failed\n";
                break;
            }
        }

    }