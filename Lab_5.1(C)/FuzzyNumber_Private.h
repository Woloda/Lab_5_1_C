#pragma once

#include "FuzzyNumber.h"

class FuzzyNumber_Private : private FuzzyNumber {
public:
	FuzzyNumber_Private();                          //конструктор за умовчанням(без параметрів)
	FuzzyNumber_Private(char*);						//конструктор ініціалізації
	FuzzyNumber_Private(FuzzyNumber_Private&, int); //конструктор копіювання

	using FuzzyNumber::set_x;   //підключення метода встановлення значення "x"
	using FuzzyNumber::set_l;   //підключення метода встановлення значення "l"
	using FuzzyNumber::set_r;   //підключення метода встановлення значення "r"

	using FuzzyNumber::get_x;   //підключення метода отримання значення "x"
	using FuzzyNumber::get_l;   //підключення метода отримання значення "l"
	using FuzzyNumber::get_r;   //підключення метода отримання значення "r"

	FuzzyNumber_Private& operator =(const FuzzyNumber_Private&);  //перевантаження операції "присвоєння"
	operator std::string();						  //приведення типу – перетворення у літерний рядок

	FuzzyNumber_Private& operator ++ ();    //перевантаження операції "інкременту"(префіксна форма) --- x
	FuzzyNumber_Private& operator -- ();    //перевантаження операції "дикременту"(префіксна форма) --- l

	FuzzyNumber_Private operator ++ (int);  //перевантаження операції "інкременту"(постфіксна форма) --- r
	FuzzyNumber_Private operator -- (int);  //перевантаження операції "дикременту"(постфіксна форма) --- x

	friend std::ostream& operator << (std::ostream&, const FuzzyNumber_Private&);    //вивід на екран(перевантаженння операції "виводу")
	friend std::istream& operator >> (std::istream&, FuzzyNumber_Private&);          //введення з клавіатури(перевантаженння операції "вводу")

	friend FuzzyNumber_Private operator +(FuzzyNumber_Private, FuzzyNumber_Private);   //функція: дія --- додавання
	friend FuzzyNumber_Private operator *(FuzzyNumber_Private, FuzzyNumber_Private);   //функція: дія --- множення
};