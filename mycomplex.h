#ifndef _MY_COMPLEX_H_  // ������ �� ���������� ��������� ������������� �����
#define _MY_COMPLEX_H_

#include <iostream>

using namespace std;

/**
 * @file mycomplex.h
 * @brief ����������� ������ Complex ��� ������ � ������������ �������.
 */

/**
 * @class Complex
 * @brief ����� ��� ������������� � ������ � ������������ �������.
 */
class Complex
{
    private:
        double Re; ///< �������������� ����� ������������ �����.
        double Im; ///< ������ ����� ������������ �����.

    public:
        /**
         * @brief ����������� � ����������� ��� ������������� ������������ �����.
         * @param aRe �������������� ����� ����� (�� ��������� 0).
         * @param aIm ������ ����� ����� (�� ��������� 0).
         */
        Complex(double aRe = 0, double aIm = 0);

        /**
         * @brief ����������� �����������.
         * @param other ������ �� ������ Complex ��� �����������.
         */
        Complex(const Complex& other);

        /**
         * @brief ����������.
         */
        ~Complex();

        /**
         * @brief ������������� �������� �������������� � ������ ����� �����.
         * @param aRe ����� �������� �������������� �����.
         * @param aIm ����� �������� ������ ����� (�� ��������� 0).
         */
        void Set(double aRe, double aIm = 0);

        /**
         * @brief �������� �������������� ���� ��� ��������� ������ �����.
         * @return ������ (���������� ��������) ������������ �����.
         */
        operator double();

        /**
         * @brief ��������� ������ ������������ �����.
         * @return ���������� �������� ������������ �����.
         */
        double abs();

        /**
         * @brief ���������� ��������� ����� ��� ������������ �����.
         * @param is ������� �����.
         * @param complex ������ Complex ��� ���������� �������.
         * @return ������ �� ������� �����.
         */
        friend istream& operator>>(istream& is, Complex& complex);

        /**
         * @brief ���������� ��������� ������ ��� ������������ �����.
         * @param os �������� �����.
         * @param complex ������ Complex ��� ������.
         * @return ������ �� �������� �����.
         */
        friend ostream& operator<<(ostream& os, Complex& complex);

        /**
         * @brief �������� �������� ���� ����������� �����.
         * @param other ������ ����������� �����.
         * @return ��������� ��������.
         */
        Complex operator+(const Complex& other);

        /**
         * @brief �������� ��������� ���� ����������� �����.
         * @param other ������ ����������� �����.
         * @return ��������� ���������.
         */
        Complex operator-(const Complex& other);

        /**
         * @brief �������� �������� � �������������� ������.
         * @param value �������������� �����.
         * @return ��������� ��������.
         */
        Complex operator+(const double& value);

        /**
         * @brief ���������� �������� �������� ��������������� ����� � ������������.
         * @param value �������������� �����.
         * @param complex ����������� �����.
         * @return ��������� ��������.
         */
        friend Complex operator+(const double& value, const Complex& complex);

        /**
         * @brief �������� ��������� ��������������� ����� �� ������������.
         * @param value �������������� �����.
         * @return ��������� ���������.
         */
        Complex operator-(const double& value);

        /**
         * @brief ���������� �������� ��������� ��������������� ����� � ������������.
         * @param value �������������� �����.
         * @param complex ����������� �����.
         * @return ��������� ���������.
         */
        friend Complex operator-(const double& value, const Complex& complex);

        /**
         * @brief �������� ��������� ���� ����������� �����.
         * @param other ������ ����������� �����.
         * @return ��������� ���������.
         */
        Complex operator*(const Complex& other);

        /**
         * @brief �������� ��������� ������������ ����� �� ��������������.
         * @param value �������������� �����.
         * @return ��������� ���������.
         */
        Complex operator*(const double& value);

        /**
         * @brief ���������� �������� ��������� ��������������� ����� � ������������.
         * @param value �������������� �����.
         * @param complex ����������� �����.
         * @return ��������� ���������.
         */
        friend Complex operator*(const double& value, const Complex& complex);

        /**
         * @brief �������� ������� ������������ ����� �� ��������������.
         * @param value �������������� �����.
         * @return ��������� �������.
         */
        Complex operator/(const double& value);

        /**
         * @brief �������� += ��� �������� � ������ ����������� ������.
         * @param other ������ ����������� �����.
         * @return ������ �� ��������� ������.
         */
        Complex& operator+=(const Complex& other);

        /**
         * @brief �������� -= ��� ��������� ������� ������������ �����.
         * @param other ������ ����������� �����.
         * @return ������ �� ��������� ������.
         */
        Complex& operator-=(const Complex& other);

        /**
         * @brief �������� *= ��� ��������� �� ������ ����������� �����.
         * @param other ������ ����������� �����.
         * @return ������ �� ��������� ������.
         */
        Complex& operator*=(const Complex& other);

        /**
         * @brief �������� += ��� �������� � �������������� ������.
         * @param value �������������� �����.
         * @return ������ �� ��������� ������.
         */
        Complex& operator+=(const double& value);

        /**
         * @brief �������� -= ��� ��������� ��������������� �����.
         * @param value �������������� �����.
         * @return ������ �� ��������� ������.
         */
        Complex& operator-=(const double& value);

        /**
         * @brief �������� *= ��� ��������� �� �������������� �����.
         * @param value �������������� �����.
         * @return ������ �� ��������� ������.
         */
        Complex& operator*=(const double& value);

        /**
         * @brief �������� /= ��� ������� �� �������������� �����.
         * @param value �������������� �����.
         * @return ������ �� ��������� ������.
         */
        Complex& operator/=(const double& value);

        /**
         * @brief �������� ������������ ��� ����������� �������� ������� ������������ �����.
         * @param other ����������� ����� ��� �����������.
         * @return ������ �� ��������� ������.
         */
        Complex& operator=(const Complex& other);

        /**
         * @brief �������� ������������ ��� ��������� �������� �� ��������������� �����.
         * @param value �������������� �����.
         * @return ������ �� ��������� ������.
         */
        Complex& operator=(const double& value);
};

#endif
