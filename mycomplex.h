#ifndef _MY_COMPLEX_H_  // Защита от повторного включения заголовочного файла
#define _MY_COMPLEX_H_

#include <iostream>

using namespace std;

// Класс Complex, представляющий комплексное число
class Complex
{
    private:
        double Re;
        double Im;

    public:
        // Конструктор с параметрами для инициализации комплексного числа
        Complex(double aRe = 0, double aIm = 0);

        // Конструктор копирования для создания копии комплексного числа
        Complex(const Complex&);

        // Деструктор (не требует дополнительных действий)
        ~Complex(    );

        // Метод для установки значений действительной и мнимой части
        void Set(double aRe, double aIm = 0);

        // Оператор преобразования типа для получения модуля комплексного числа
        operator double();

        // Метод для вычисления модуля (абсолютной величины) комплексного числа
        double abs();

        // Перегрузка оператора ввода для комплексного числа (считывание данных)
        friend istream& operator>>(istream&, Complex&) ;

        // Перегрузка оператора вывода для комплексного числа (вывод данных)
        friend ostream& operator<<(ostream&, Complex&);

        // Операторы для выполнения арифметических операций с комплексными числами
        Complex operator+(const Complex&);
        Complex operator-(const Complex&);
        Complex operator+(const double&);
        friend Complex operator+(const double&, const Complex&);
        Complex operator-(const double&);
        friend Complex operator-(const double&, const Complex&);

        Complex operator*(const Complex&);
        Complex operator*(const double&);
        friend Complex operator*(const double&, const Complex&);

        Complex operator/(const double&);

        // Операторы присваивания и модификации комплексного числа
        Complex& operator+=(const Complex&);
        Complex& operator-=(const Complex&);
        Complex& operator*=(const Complex&);
        Complex& operator+=(const double&);
        Complex& operator-= (const double&);
        Complex& operator*=(const double  & );
        Complex& operator/=( const   double & );

        // Операторы присваивания для копирования значений
        Complex& operator = (const Complex&);
        Complex& operator = (const double&);
};

#endif
