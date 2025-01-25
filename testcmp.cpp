#include <iostream>
#include "mycomplex.h"

int main() {
    // ������������ ������ ����������� �����
    Complex a, b(-4), c(23.0, 45.9);

    // ����� ��������� ��������
    std::cout << "Initial values:\n";
    std::cout << "A = " << a << ", B = " << b << ", C = " << c << std::endl;

    // �������� ��������
    a = b + c;
    std::cout << "A = B + C, A = " << a << std::endl;

    // �������� ���������
    Complex m = b - c;
    std::cout << "M = B - C, M = " << m << std::endl;

    // ��������� � �������
    std::cout << "M * A = " << m * a << std::endl;
    std::cout << "M / 4.45 = " << m / 4.45 << std::endl;

    // ���� ����� �������������
    Complex d;
    std::cout << "Enter complex number D: ";
    std::cin >> d;

    // �������� ����������
    a += c + d;
    std::cout << "D = " << d << "\nA = " << a << std::endl;

    return 0;
}
