/**
 * @file mycomplex.cpp
 * @brief Реализация класса Complex для работы с комплексными числами.
 *
 * @details Этот файл содержит реализацию методов и операторов класса Complex, включая
 * базовые арифметические операции, преобразования типов, а также потоковые операторы ввода/вывода.
 *
 * @author Дарья Трофимова
 * @date 25.01.2025
 */

#include <iostream>
#include <cmath>
#include "mycomplex.h"
using namespace std;


//изминение для make с двумя изминениями
//изминение для make с измененым makefile1 с двумя изминениями



/**
 * @file mycomplex.cpp
 * @brief Реализация методов класса Complex для работы с комплексными числами.
 */





// Конструкторы

/**
 * @brief Конструктор с параметрами.
 * @param aRe Действительная часть комплексного числа.
 * @param aIm Мнимая часть комплексного числа.
 */
Complex::Complex(double aRe, double aIm) : Re(aRe), Im(aIm) {}

/**
 * @brief Конструктор копирования.
 * @param aRval Ссылка на объект класса Complex для копирования.
 */
Complex::Complex(const Complex& aRval) : Re(aRval.Re), Im(aRval.Im) {}

/**
 * @brief Деструктор. Обнуляет значения действительной и мнимой части.
 */
Complex::~Complex() {
    Re = 0.0;
    Im = 0.0;
}

// Методы

/**
 * @brief Устанавливает значения действительной и мнимой части.
 * @param aRe Новое значение действительной части.
 * @param aIm Новое значение мнимой части.
 */
void Complex::Set(double aRe, double aIm) {
    Re = aRe;
    Im = aIm;
}

/**
 * @brief Преобразование объекта Complex в double.
 * @return Модуль комплексного числа.
 */
Complex::operator double() {
    return abs();
}

/**
 * @brief Вычисляет модуль комплексного числа.
 * @return Абсолютное значение комплексного числа.
 */
double Complex::abs() {
    return std::sqrt(Re * Re + Im * Im);
}

// Операторы

/**
 * @brief Оператор сложения.
 * @param aRval Комплексное число для сложения.
 * @return Результат сложения.
 */
Complex Complex::operator+(const Complex& aRval) {
    Complex result;
    result.Re = Re + aRval.Re;
    result.Im = Im + aRval.Im;
    return result;
}

/**
 * @brief Оператор вычитания.
 * @param aRval Комплексное число для вычитания.
 * @return Результат вычитания.
 */
Complex Complex::operator-(const Complex& aRval) {
    Complex result;
    result.Re = Re - aRval.Re;
    result.Im = Im - aRval.Im;
    return result;
}

/**
 * @brief Оператор сложения с действительным числом.
 * @param aVal Действительное число для сложения.
 * @return Результат сложения.
 */
Complex Complex::operator+(const double& aVal) {
    Complex result;
    result.Re = Re + aVal;
    result.Im = Im;
    return result;
}

/**
 * @brief Оператор вычитания с действительным числом.
 * @param aVal Действительное число для вычитания.
 * @return Результат вычитания.
 */
Complex Complex::operator-(const double& aVal) {
    Complex result(*this);
    result.Re = Re - aVal;
    return result;
}

/**
 * @brief Оператор умножения.
 * @param aRval Комплексное число для умножения.
 * @return Результат умножения.
 */
Complex Complex::operator*(const Complex& aRval) {
    Complex result;
    result.Re = Re * aRval.Re - Im * aRval.Im;
    result.Im = Re * aRval.Im + Im * aRval.Re;
    return result;
}

/**
 * @brief Оператор умножения на действительное число.
 * @param aVal Действительное число для умножения.
 * @return Результат умножения.
 */
Complex Complex::operator*(const double& aVal) {
    Complex result;
    result.Re = Re * aVal;
    result.Im = Im * aVal;
    return result;
}

/**
 * @brief Оператор деления на действительное число.
 * @param aVal Действительное число для деления.
 * @return Результат деления.
 */
Complex Complex::operator/(const double& aVal) {
    Complex result;
    result.Re = Re / aVal;
    result.Im = Im / aVal;
    return result;
}

/**
 * @brief Оператор += для сложения с комплексным числом.
 * @param aRval Комплексное число для сложения.
 * @return Ссылка на изменённый объект.
 */
Complex& Complex::operator+=(const Complex& aRval) {
    Re += aRval.Re;
    Im += aRval.Im;
    return *this;
}

/**
 * @brief Оператор -= для вычитания комплексного числа.
 * @param aRval Комплексное число для вычитания.
 * @return Ссылка на изменённый объект.
 */
Complex& Complex::operator-=(const Complex& aRval) {
    Re -= aRval.Re;
    Im -= aRval.Im;
    return *this;
}

/**
 * @brief Оператор *= для умножения на комплексное число.
 * @param aRval Комплексное число для умножения.
 * @return Ссылка на изменённый объект.
 */
Complex& Complex::operator*=(const Complex& aRval) {
    double tmpRe = Re;
    Re = Re * aRval.Re - Im * aRval.Im;
    Im = Im * aRval.Re + tmpRe * aRval.Im;
    return *this;
}

/**
 * @brief Оператор += для сложения с действительным числом.
 * @param aVal Действительное число для сложения.
 * @return Ссылка на изменённый объект.
 */
Complex& Complex::operator+=(const double& aVal) {
    Re += aVal;
    return *this;
}

/**
 * @brief Оператор -= для вычитания действительного числа.
 * @param aVal Действительное число для вычитания.
 * @return Ссылка на изменённый объект.
 */
Complex& Complex::operator-=(const double& aVal) {
    Re -= aVal;
    return *this;
}

/**
 * @brief Оператор *= для умножения на действительное число.
 * @param aVal Действительное число для умножения.
 * @return Ссылка на изменённый объект.
 */
Complex& Complex::operator*=(const double& aVal) {
    Re *= aVal;
    Im *= aVal;
    return *this;
}

/**
 * @brief Оператор /= для деления на действительное число.
 * @param aVal Действительное число для деления.
 * @return Ссылка на изменённый объект.
 */
Complex& Complex::operator/=(const double& aVal) {
    Re /= aVal;
    Im /= aVal;
    return *this;
}

/**
 * @brief Оператор присваивания для копирования комплексного числа.
 * @param aRval Комплексное число для копирования.
 * @return Ссылка на изменённый объект.
 */
Complex& Complex::operator=(const Complex& aRval) {
    Re = aRval.Re;
    Im = aRval.Im;
    return *this;
}

/**
 * @brief Оператор присваивания для присваивания числа комплексному числу.
 * @param aVal Действительное число для присваивания.
 * @return Ссылка на изменённый объект.
 */
Complex& Complex::operator=(const double& aVal) {
    Re = aVal;
    Im = 0.0;
    return *this;
}

// Потоковые операторы

/**
 * @brief Перегрузка оператора ввода для комплексного числа.
 * @param stream Входной поток.
 * @param a Ссылка на объект Complex для ввода.
 * @return Ссылка на входной поток.
 */
std::istream& operator>>(std::istream& stream, Complex& a) {
    char tmp[256];
    stream >> a.Re >> a.Im >> tmp;
    return stream;
}

/**
 * @brief Перегрузка оператора вывода для комплексного числа.
 * @param stream Выходной поток.
 * @param a Ссылка на объект Complex для вывода.
 * @return Ссылка на выходной поток.
 */
std::ostream& operator<<(std::ostream& stream, Complex& a) {
    stream << a.Re;
    if (!(a.Im < 0)) {
        stream << '+';
    }
    stream << a.Im << 'i';
    return stream;
}

// Глобальные операторы

/**
 * @brief Глобальный оператор сложения для числа и комплексного числа.
 * @param aLval Действительное число.
 * @param aRval Комплексное число.
 * @return Результат сложения.
 */
Complex operator+(const double& aLval, const Complex& aRval) {
    Complex result;
    result.Re = aLval + aRval.Re;
    result.Im = aRval.Im;
    return result;
}

/**
 * @brief Глобальный оператор вычитания для числа и комплексного числа.
 * @param aLval Действительное число.
 * @param aRval Комплексное число.
 * @return Результат вычитания.
 */
Complex operator-(const double& aLval, const Complex& aRval) {
    Complex result;
    result.Re = aLval - aRval.Re;
    result.Im = -aRval.Im;
    return result;
}

/**
 * @brief Глобальный оператор умножения для числа и комплексного числа.
 * @param aLval Действительное число.
 * @param a Комплексное число.
 * @return Результат умножения.
 */
Complex operator*(const double& aLval, const Complex& a) {
    Complex result;
    result.Re = aLval * a.Re;
    result.Im = aLval * a.Im;
    return result;
}
