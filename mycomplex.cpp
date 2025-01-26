#include <iostream>
#include <cmath>
#include "mycomplex.h"
using namespace std;
//��������� ��� make � ����� �����������
// ������������

// ����������� � ����� ����������� ��� ������������� ������������ �����
Complex::Complex(double aRe, double aIm) : Re(aRe), Im(aIm) {}

// ����������� ����������� ��� �������� ����� ������������ �����
Complex::Complex(const Complex& aRval) : Re(aRval.Re), Im(aRval.Im) {}

// ����������, ������� ���������� �������� �������������� � ������ �����
Complex::~Complex() {
    Re = 0.0;
    Im = 0.0;
}

// ������

// ����� ��� ��������� �������� �������������� � ������ �����
void Complex::Set(double aRe, double aIm) {
    Re = aRe;
    Im = aIm;
}

// �������������� ������� Complex � ��� double (���������� ������ �����)
Complex::operator double() {
    return abs(); // ���������� ���������� �������� ������������ �����
}

// ����� ��� ���������� ������ ������������ ����� (���������� ��������)
double Complex::abs() {
    return std::sqrt(Re * Re + Im * Im);
}

// ���������

// �������� �������� ��� ���� ����������� �����
Complex Complex::operator+(const Complex& aRval) {
    Complex result;
    result.Re = Re + aRval.Re;
    result.Im = Im + aRval.Im;
    return result;
}

// �������� ��������� ��� ���� ����������� �����
Complex Complex::operator-(const Complex& aRval) {
    Complex result;
    result.Re = Re - aRval.Re;
    result.Im = Im - aRval.Im;
    return result;
}

// �������� �������� � ����������� ����� (�������� � �������������� ������)
Complex Complex::operator+(const double& aVal) {
    Complex result;
    result.Re = Re + aVal;
    result.Im = Im;
    return result;
}

// �������� ��������� � ���������� ����� (��������� �� �������������� �����)
Complex Complex::operator-(const double& aVal) {
    Complex result(*this); // ������� ����� �������� �������
    result.Re = Re - aVal;
    return result;
}

// �������� ��������� ��� ���� ����������� �����
Complex Complex::operator*(const Complex& aRval) {
    Complex result;
    result.Re = Re * aRval.Re - Im * aRval.Im;
    result.Im = Re * aRval.Im + Im * aRval.Re;
    return result;
}

// �������� ��������� �� ����� (��������� ������������ ����� �� ��������������)
Complex Complex::operator*(const double& aVal) {
    Complex result;
    result.Re = Re * aVal;
    result.Im = Im * aVal;
    return result;
}


// �������� ������� ������������ ����� �� �����
Complex Complex::operator/(const double& aVal) {
    Complex result;
    result.Re = Re / aVal;
    result.Im = Im / aVal;
    return result;
}

// �������� += ��� �������� ���� ����������� ����� (����������� ������������ �����)
Complex& Complex::operator+=(const Complex& aRval) {
    Re += aRval.Re;
    Im += aRval.Im;
    return *this;
}

// �������� -= ��� ��������� ���� ����������� ����� (��������� ������������ �����)
Complex& Complex::operator-=(const Complex& aRval) {
    Re -= aRval.Re;
    Im -= aRval.Im;
    return *this;
}

// �������� *= ��� ��������� ���� ����������� ����� (��������� �� ����������� �����)
Complex& Complex::operator*=(const Complex& aRval) {
    double tmpRe = Re;
    Re = Re * aRval.Re - Im * aRval.Im;
    Im = Im * aRval.Re + tmpRe * aRval.Im;
    return *this;
}

// �������� += ��� ����������� ����� � ������������ �����
Complex& Complex::operator+=(const double& aVal) {
    Re += aVal;
    return *this;
}

// �������� -= ��� ��������� ����� �� ������������ �����
Complex& Complex::operator-=(const double& aVal) {
    Re -= aVal;
    return *this;
}

// �������� *= ��� ��������� ������������ ����� �� �����
Complex& Complex::operator*=(const double& aVal) {
    Re *= aVal;
    Im *= aVal;
    return *this;
}

// �������� /= ��� ������� ������������ ����� �� �����
Complex& Complex::operator/=(const double& aVal) {
    Re /= aVal;
    Im /= aVal;
    return *this;
}

// �������� ������������ ��� ����������� ������������ �����
Complex& Complex::operator=(const Complex& aRval) {
    Re = aRval.Re;
    Im = aRval.Im;
    return *this;
}

// �������� ������������ ��� ������������ ����� ������������ �����
Complex& Complex::operator=(const double& aVal) {
    Re = aVal;
    Im = 0.0;
    return *this;
}

// ��������� ���������

// ���������� ��������� ����� ��� ������������ �����
std::istream& operator>>(std::istream& stream, Complex& a) {
    char tmp[256]; // ��������� ���������� ��� �������� ������� (��������, 'i')
    stream >> a.Re >> a.Im >> tmp;  // ������ �������������� � ������ �����
    return stream;  // ���������� �����
}

// ���������� ��������� ������ ��� ������������ �����
std::ostream& operator<<(std::ostream& stream, Complex& a) {
    stream << a.Re;  // ������� �������������� �����
    if (!(a.Im < 0)) {
        stream << '+';  // ���� ������ ����� �� �������������, ������� '+'
    }
    stream << a.Im << 'i';  // ������� ������ ����� � ������ 'i'
    return stream;  // ���������� �����
}

// ���������� ���������

// ���������� �������� �������� ��� ����� � ������������ �����
Complex operator+(const double& aLval, const Complex& aRval) {
    Complex result;
    result.Re = aLval + aRval.Re;
    result.Im = aRval.Im;
    return result;
}

// ���������� �������� ��������� ��� ����� � ������������ �����
Complex operator-(const double& aLval, const Complex& aRval) {
    Complex result;
    result.Re = aLval - aRval.Re;
    result.Im = -aRval.Im;
    return result;
}

// ���������� �������� ��������� ��� ����� � ������������ �����
Complex operator*(const double& aLval, const Complex& a) {
    Complex result;
    result.Re = aLval * a.Re;
    result.Im = aLval * a.Im;
    return result;
}
