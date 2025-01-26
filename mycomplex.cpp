/**
 * @file mycomplex.cpp
 * @brief ���������� ������ Complex ��� ������ � ������������ �������.
 *
 * @details ���� ���� �������� ���������� ������� � ���������� ������ Complex, �������
 * ������� �������������� ��������, �������������� �����, � ����� ��������� ��������� �����/������.
 *
 * @author ����� ���������
 * @date 25.01.2025
 */

#include <iostream>
#include <cmath>
#include "mycomplex.h"
using namespace std;


//��������� ��� make � ����� �����������
//��������� ��� make � ��������� makefile1 � ����� �����������



/**
 * @file mycomplex.cpp
 * @brief ���������� ������� ������ Complex ��� ������ � ������������ �������.
 */





// ������������

/**
 * @brief ����������� � �����������.
 * @param aRe �������������� ����� ������������ �����.
 * @param aIm ������ ����� ������������ �����.
 */
Complex::Complex(double aRe, double aIm) : Re(aRe), Im(aIm) {}

/**
 * @brief ����������� �����������.
 * @param aRval ������ �� ������ ������ Complex ��� �����������.
 */
Complex::Complex(const Complex& aRval) : Re(aRval.Re), Im(aRval.Im) {}

/**
 * @brief ����������. �������� �������� �������������� � ������ �����.
 */
Complex::~Complex() {
    Re = 0.0;
    Im = 0.0;
}

// ������

/**
 * @brief ������������� �������� �������������� � ������ �����.
 * @param aRe ����� �������� �������������� �����.
 * @param aIm ����� �������� ������ �����.
 */
void Complex::Set(double aRe, double aIm) {
    Re = aRe;
    Im = aIm;
}

/**
 * @brief �������������� ������� Complex � double.
 * @return ������ ������������ �����.
 */
Complex::operator double() {
    return abs();
}

/**
 * @brief ��������� ������ ������������ �����.
 * @return ���������� �������� ������������ �����.
 */
double Complex::abs() {
    return std::sqrt(Re * Re + Im * Im);
}

// ���������

/**
 * @brief �������� ��������.
 * @param aRval ����������� ����� ��� ��������.
 * @return ��������� ��������.
 */
Complex Complex::operator+(const Complex& aRval) {
    Complex result;
    result.Re = Re + aRval.Re;
    result.Im = Im + aRval.Im;
    return result;
}

/**
 * @brief �������� ���������.
 * @param aRval ����������� ����� ��� ���������.
 * @return ��������� ���������.
 */
Complex Complex::operator-(const Complex& aRval) {
    Complex result;
    result.Re = Re - aRval.Re;
    result.Im = Im - aRval.Im;
    return result;
}

/**
 * @brief �������� �������� � �������������� ������.
 * @param aVal �������������� ����� ��� ��������.
 * @return ��������� ��������.
 */
Complex Complex::operator+(const double& aVal) {
    Complex result;
    result.Re = Re + aVal;
    result.Im = Im;
    return result;
}

/**
 * @brief �������� ��������� � �������������� ������.
 * @param aVal �������������� ����� ��� ���������.
 * @return ��������� ���������.
 */
Complex Complex::operator-(const double& aVal) {
    Complex result(*this);
    result.Re = Re - aVal;
    return result;
}

/**
 * @brief �������� ���������.
 * @param aRval ����������� ����� ��� ���������.
 * @return ��������� ���������.
 */
Complex Complex::operator*(const Complex& aRval) {
    Complex result;
    result.Re = Re * aRval.Re - Im * aRval.Im;
    result.Im = Re * aRval.Im + Im * aRval.Re;
    return result;
}

/**
 * @brief �������� ��������� �� �������������� �����.
 * @param aVal �������������� ����� ��� ���������.
 * @return ��������� ���������.
 */
Complex Complex::operator*(const double& aVal) {
    Complex result;
    result.Re = Re * aVal;
    result.Im = Im * aVal;
    return result;
}

/**
 * @brief �������� ������� �� �������������� �����.
 * @param aVal �������������� ����� ��� �������.
 * @return ��������� �������.
 */
Complex Complex::operator/(const double& aVal) {
    Complex result;
    result.Re = Re / aVal;
    result.Im = Im / aVal;
    return result;
}

/**
 * @brief �������� += ��� �������� � ����������� ������.
 * @param aRval ����������� ����� ��� ��������.
 * @return ������ �� ��������� ������.
 */
Complex& Complex::operator+=(const Complex& aRval) {
    Re += aRval.Re;
    Im += aRval.Im;
    return *this;
}

/**
 * @brief �������� -= ��� ��������� ������������ �����.
 * @param aRval ����������� ����� ��� ���������.
 * @return ������ �� ��������� ������.
 */
Complex& Complex::operator-=(const Complex& aRval) {
    Re -= aRval.Re;
    Im -= aRval.Im;
    return *this;
}

/**
 * @brief �������� *= ��� ��������� �� ����������� �����.
 * @param aRval ����������� ����� ��� ���������.
 * @return ������ �� ��������� ������.
 */
Complex& Complex::operator*=(const Complex& aRval) {
    double tmpRe = Re;
    Re = Re * aRval.Re - Im * aRval.Im;
    Im = Im * aRval.Re + tmpRe * aRval.Im;
    return *this;
}

/**
 * @brief �������� += ��� �������� � �������������� ������.
 * @param aVal �������������� ����� ��� ��������.
 * @return ������ �� ��������� ������.
 */
Complex& Complex::operator+=(const double& aVal) {
    Re += aVal;
    return *this;
}

/**
 * @brief �������� -= ��� ��������� ��������������� �����.
 * @param aVal �������������� ����� ��� ���������.
 * @return ������ �� ��������� ������.
 */
Complex& Complex::operator-=(const double& aVal) {
    Re -= aVal;
    return *this;
}

/**
 * @brief �������� *= ��� ��������� �� �������������� �����.
 * @param aVal �������������� ����� ��� ���������.
 * @return ������ �� ��������� ������.
 */
Complex& Complex::operator*=(const double& aVal) {
    Re *= aVal;
    Im *= aVal;
    return *this;
}

/**
 * @brief �������� /= ��� ������� �� �������������� �����.
 * @param aVal �������������� ����� ��� �������.
 * @return ������ �� ��������� ������.
 */
Complex& Complex::operator/=(const double& aVal) {
    Re /= aVal;
    Im /= aVal;
    return *this;
}

/**
 * @brief �������� ������������ ��� ����������� ������������ �����.
 * @param aRval ����������� ����� ��� �����������.
 * @return ������ �� ��������� ������.
 */
Complex& Complex::operator=(const Complex& aRval) {
    Re = aRval.Re;
    Im = aRval.Im;
    return *this;
}

/**
 * @brief �������� ������������ ��� ������������ ����� ������������ �����.
 * @param aVal �������������� ����� ��� ������������.
 * @return ������ �� ��������� ������.
 */
Complex& Complex::operator=(const double& aVal) {
    Re = aVal;
    Im = 0.0;
    return *this;
}

// ��������� ���������

/**
 * @brief ���������� ��������� ����� ��� ������������ �����.
 * @param stream ������� �����.
 * @param a ������ �� ������ Complex ��� �����.
 * @return ������ �� ������� �����.
 */
std::istream& operator>>(std::istream& stream, Complex& a) {
    char tmp[256];
    stream >> a.Re >> a.Im >> tmp;
    return stream;
}

/**
 * @brief ���������� ��������� ������ ��� ������������ �����.
 * @param stream �������� �����.
 * @param a ������ �� ������ Complex ��� ������.
 * @return ������ �� �������� �����.
 */
std::ostream& operator<<(std::ostream& stream, Complex& a) {
    stream << a.Re;
    if (!(a.Im < 0)) {
        stream << '+';
    }
    stream << a.Im << 'i';
    return stream;
}

// ���������� ���������

/**
 * @brief ���������� �������� �������� ��� ����� � ������������ �����.
 * @param aLval �������������� �����.
 * @param aRval ����������� �����.
 * @return ��������� ��������.
 */
Complex operator+(const double& aLval, const Complex& aRval) {
    Complex result;
    result.Re = aLval + aRval.Re;
    result.Im = aRval.Im;
    return result;
}

/**
 * @brief ���������� �������� ��������� ��� ����� � ������������ �����.
 * @param aLval �������������� �����.
 * @param aRval ����������� �����.
 * @return ��������� ���������.
 */
Complex operator-(const double& aLval, const Complex& aRval) {
    Complex result;
    result.Re = aLval - aRval.Re;
    result.Im = -aRval.Im;
    return result;
}

/**
 * @brief ���������� �������� ��������� ��� ����� � ������������ �����.
 * @param aLval �������������� �����.
 * @param a ����������� �����.
 * @return ��������� ���������.
 */
Complex operator*(const double& aLval, const Complex& a) {
    Complex result;
    result.Re = aLval * a.Re;
    result.Im = aLval * a.Im;
    return result;
}
