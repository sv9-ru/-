#include <iostream>
#include "mycomplex.h"

int main() {
    // Тестирование класса комплексных чисел
    Complex a, b(-4), c(23.0, 45.9);

    // Вывод начальных значений
    std::cout << "Initial values:\n";
    std::cout << "A = " << a << ", B = " << b << ", C = " << c << std::endl;

    // Операция сложения
    a = b + c;
    std::cout << "A = B + C, A = " << a << std::endl;

    // Операция вычитания
    Complex m = b - c;
    std::cout << "M = B - C, M = " << m << std::endl;

    // Умножение и деление
    std::cout << "M * A = " << m * a << std::endl;
    std::cout << "M / 4.45 = " << m / 4.45 << std::endl;

    // Ввод числа пользователем
    Complex d;
    std::cout << "Enter complex number D: ";
    std::cin >> d;

    // Итоговые вычисления
    a += c + d;
    std::cout << "D = " << d << "\nA = " << a << std::endl;

    return 0;
}
