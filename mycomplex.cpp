#include <iostream>
#include <cmath>
#include "mycomplex.h"
using namespace std;
//изминение для make с двумя изминениями
// Конструкторы

// Конструктор с двумя параметрами для инициализации комплексного числа
Complex::Complex(double aRe, double aIm) : Re(aRe), Im(aIm) {}

// Конструктор копирования для создания копии комплексного числа
Complex::Complex(const Complex& aRval) : Re(aRval.Re), Im(aRval.Im) {}

// Деструктор, который сбрасывает значения действительной и мнимой части
Complex::~Complex() {
    Re = 0.0;
    Im = 0.0;
}

// Методы

// Метод для установки значений действительной и мнимой части
void Complex::Set(double aRe, double aIm) {
    Re = aRe;
    Im = aIm;
}

// Преобразование объекта Complex в тип double (вычисление модуля числа)
Complex::operator double() {
    return abs(); // Возвращаем абсолютное значение комплексного числа
}

// Метод для вычисления модуля комплексного числа (абсолютной величины)
double Complex::abs() {
    return std::sqrt(Re * Re + Im * Im);
}

// Операторы

// Оператор сложения для двух комплексных чисел
Complex Complex::operator+(const Complex& aRval) {
    Complex result;
    result.Re = Re + aRval.Re;
    result.Im = Im + aRval.Im;
    return result;
}

// Оператор вычитания для двух комплексных чисел
Complex Complex::operator-(const Complex& aRval) {
    Complex result;
    result.Re = Re - aRval.Re;
    result.Im = Im - aRval.Im;
    return result;
}

// Оператор сложения с добавлением числа (сложение с действительным числом)
Complex Complex::operator+(const double& aVal) {
    Complex result;
    result.Re = Re + aVal;
    result.Im = Im;
    return result;
}

// Оператор вычитания с вычитанием числа (вычитание из действительной части)
Complex Complex::operator-(const double& aVal) {
    Complex result(*this); // Создаем копию текущего объекта
    result.Re = Re - aVal;
    return result;
}

// Оператор умножения для двух комплексных чисел
Complex Complex::operator*(const Complex& aRval) {
    Complex result;
    result.Re = Re * aRval.Re - Im * aRval.Im;
    result.Im = Re * aRval.Im + Im * aRval.Re;
    return result;
}

// Оператор умножения на число (умножение комплексного числа на действительное)
Complex Complex::operator*(const double& aVal) {
    Complex result;
    result.Re = Re * aVal;
    result.Im = Im * aVal;
    return result;
}


// Оператор деления комплексного числа на число
Complex Complex::operator/(const double& aVal) {
    Complex result;
    result.Re = Re / aVal;
    result.Im = Im / aVal;
    return result;
}

// Оператор += для сложения двух комплексных чисел (прибавление комплексного числа)
Complex& Complex::operator+=(const Complex& aRval) {
    Re += aRval.Re;
    Im += aRval.Im;
    return *this;
}

// Оператор -= для вычитания двух комплексных чисел (вычитание комплексного числа)
Complex& Complex::operator-=(const Complex& aRval) {
    Re -= aRval.Re;
    Im -= aRval.Im;
    return *this;
}

// Оператор *= для умножения двух комплексных чисел (умножение на комплексное число)
Complex& Complex::operator*=(const Complex& aRval) {
    double tmpRe = Re;
    Re = Re * aRval.Re - Im * aRval.Im;
    Im = Im * aRval.Re + tmpRe * aRval.Im;
    return *this;
}

// Оператор += для прибавления числа к комплексному числу
Complex& Complex::operator+=(const double& aVal) {
    Re += aVal;
    return *this;
}

// Оператор -= для вычитания числа из комплексного числа
Complex& Complex::operator-=(const double& aVal) {
    Re -= aVal;
    return *this;
}

// Оператор *= для умножения комплексного числа на число
Complex& Complex::operator*=(const double& aVal) {
    Re *= aVal;
    Im *= aVal;
    return *this;
}

// Оператор /= для деления комплексного числа на число
Complex& Complex::operator/=(const double& aVal) {
    Re /= aVal;
    Im /= aVal;
    return *this;
}

// Оператор присваивания для копирования комплексного числа
Complex& Complex::operator=(const Complex& aRval) {
    Re = aRval.Re;
    Im = aRval.Im;
    return *this;
}

// Оператор присваивания для присваивания числа комплексному числу
Complex& Complex::operator=(const double& aVal) {
    Re = aVal;
    Im = 0.0;
    return *this;
}

// Потоковые операторы

// Перегрузка оператора ввода для комплексного числа
std::istream& operator>>(std::istream& stream, Complex& a) {
    char tmp[256]; // Временная переменная для пропуска символа (например, 'i')
    stream >> a.Re >> a.Im >> tmp;  // Вводим действительную и мнимую части
    return stream;  // Возвращаем поток
}

// Перегрузка оператора вывода для комплексного числа
std::ostream& operator<<(std::ostream& stream, Complex& a) {
    stream << a.Re;  // Выводим действительную часть
    if (!(a.Im < 0)) {
        stream << '+';  // Если мнимая часть не отрицательная, выводим '+'
    }
    stream << a.Im << 'i';  // Выводим мнимую часть и символ 'i'
    return stream;  // Возвращаем поток
}

// Глобальные операторы

// Глобальный оператор сложения для числа и комплексного числа
Complex operator+(const double& aLval, const Complex& aRval) {
    Complex result;
    result.Re = aLval + aRval.Re;
    result.Im = aRval.Im;
    return result;
}

// Глобальный оператор вычитания для числа и комплексного числа
Complex operator-(const double& aLval, const Complex& aRval) {
    Complex result;
    result.Re = aLval - aRval.Re;
    result.Im = -aRval.Im;
    return result;
}

// Глобальный оператор умножения для числа и комплексного числа
Complex operator*(const double& aLval, const Complex& a) {
    Complex result;
    result.Re = aLval * a.Re;
    result.Im = aLval * a.Im;
    return result;
}
