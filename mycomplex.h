#ifndef _MY_COMPLEX_H_  // Защита от повторного включения заголовочного файла
#define _MY_COMPLEX_H_

#include <iostream>

using namespace std;

/**
 * @file mycomplex.h
 * @brief Определение класса Complex для работы с комплексными числами.
 */

/**
 * @class Complex
 * @brief Класс для представления и работы с комплексными числами.
 */
class Complex
{
    private:
        double Re; ///< Действительная часть комплексного числа.
        double Im; ///< Мнимая часть комплексного числа.

    public:
        /**
         * @brief Конструктор с параметрами для инициализации комплексного числа.
         * @param aRe Действительная часть числа (по умолчанию 0).
         * @param aIm Мнимая часть числа (по умолчанию 0).
         */
        Complex(double aRe = 0, double aIm = 0);

        /**
         * @brief Конструктор копирования.
         * @param other Ссылка на объект Complex для копирования.
         */
        Complex(const Complex& other);

        /**
         * @brief Деструктор.
         */
        ~Complex();

        /**
         * @brief Устанавливает значения действительной и мнимой части числа.
         * @param aRe Новое значение действительной части.
         * @param aIm Новое значение мнимой части (по умолчанию 0).
         */
        void Set(double aRe, double aIm = 0);

        /**
         * @brief Оператор преобразования типа для получения модуля числа.
         * @return Модуль (абсолютное значение) комплексного числа.
         */
        operator double();

        /**
         * @brief Вычисляет модуль комплексного числа.
         * @return Абсолютное значение комплексного числа.
         */
        double abs();

        /**
         * @brief Перегрузка оператора ввода для комплексного числа.
         * @param is Входной поток.
         * @param complex Объект Complex для заполнения данными.
         * @return Ссылка на входной поток.
         */
        friend istream& operator>>(istream& is, Complex& complex);

        /**
         * @brief Перегрузка оператора вывода для комплексного числа.
         * @param os Выходной поток.
         * @param complex Объект Complex для вывода.
         * @return Ссылка на выходной поток.
         */
        friend ostream& operator<<(ostream& os, Complex& complex);

        /**
         * @brief Оператор сложения двух комплексных чисел.
         * @param other Второе комплексное число.
         * @return Результат сложения.
         */
        Complex operator+(const Complex& other);

        /**
         * @brief Оператор вычитания двух комплексных чисел.
         * @param other Второе комплексное число.
         * @return Результат вычитания.
         */
        Complex operator-(const Complex& other);

        /**
         * @brief Оператор сложения с действительным числом.
         * @param value Действительное число.
         * @return Результат сложения.
         */
        Complex operator+(const double& value);

        /**
         * @brief Глобальный оператор сложения действительного числа и комплексного.
         * @param value Действительное число.
         * @param complex Комплексное число.
         * @return Результат сложения.
         */
        friend Complex operator+(const double& value, const Complex& complex);

        /**
         * @brief Оператор вычитания действительного числа из комплексного.
         * @param value Действительное число.
         * @return Результат вычитания.
         */
        Complex operator-(const double& value);

        /**
         * @brief Глобальный оператор вычитания действительного числа и комплексного.
         * @param value Действительное число.
         * @param complex Комплексное число.
         * @return Результат вычитания.
         */
        friend Complex operator-(const double& value, const Complex& complex);

        /**
         * @brief Оператор умножения двух комплексных чисел.
         * @param other Второе комплексное число.
         * @return Результат умножения.
         */
        Complex operator*(const Complex& other);

        /**
         * @brief Оператор умножения комплексного числа на действительное.
         * @param value Действительное число.
         * @return Результат умножения.
         */
        Complex operator*(const double& value);

        /**
         * @brief Глобальный оператор умножения действительного числа и комплексного.
         * @param value Действительное число.
         * @param complex Комплексное число.
         * @return Результат умножения.
         */
        friend Complex operator*(const double& value, const Complex& complex);

        /**
         * @brief Оператор деления комплексного числа на действительное.
         * @param value Действительное число.
         * @return Результат деления.
         */
        Complex operator/(const double& value);

        /**
         * @brief Оператор += для сложения с другим комплексным числом.
         * @param other Второе комплексное число.
         * @return Ссылка на изменённый объект.
         */
        Complex& operator+=(const Complex& other);

        /**
         * @brief Оператор -= для вычитания другого комплексного числа.
         * @param other Второе комплексное число.
         * @return Ссылка на изменённый объект.
         */
        Complex& operator-=(const Complex& other);

        /**
         * @brief Оператор *= для умножения на другое комплексное число.
         * @param other Второе комплексное число.
         * @return Ссылка на изменённый объект.
         */
        Complex& operator*=(const Complex& other);

        /**
         * @brief Оператор += для сложения с действительным числом.
         * @param value Действительное число.
         * @return Ссылка на изменённый объект.
         */
        Complex& operator+=(const double& value);

        /**
         * @brief Оператор -= для вычитания действительного числа.
         * @param value Действительное число.
         * @return Ссылка на изменённый объект.
         */
        Complex& operator-=(const double& value);

        /**
         * @brief Оператор *= для умножения на действительное число.
         * @param value Действительное число.
         * @return Ссылка на изменённый объект.
         */
        Complex& operator*=(const double& value);

        /**
         * @brief Оператор /= для деления на действительное число.
         * @param value Действительное число.
         * @return Ссылка на изменённый объект.
         */
        Complex& operator/=(const double& value);

        /**
         * @brief Оператор присваивания для копирования значений другого комплексного числа.
         * @param other Комплексное число для копирования.
         * @return Ссылка на изменённый объект.
         */
        Complex& operator=(const Complex& other);

        /**
         * @brief Оператор присваивания для установки значения из действительного числа.
         * @param value Действительное число.
         * @return Ссылка на изменённый объект.
         */
        Complex& operator=(const double& value);
};

#endif
