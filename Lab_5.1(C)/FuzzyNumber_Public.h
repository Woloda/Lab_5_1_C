#pragma once

#include "FuzzyNumber.h"

class FuzzyNumber_Public : public FuzzyNumber {
public:
	FuzzyNumber_Public();                          //конструктор за умовчанням(без параметрів)
	FuzzyNumber_Public(char *);					   //конструктор ініціалізації
	FuzzyNumber_Public(FuzzyNumber_Public&, int);  //конструктор копіювання

	FuzzyNumber_Public& operator =(const FuzzyNumber_Public&);  //перевантаження операції "присвоєння"
	operator std::string();	     //приведення типу – перетворення у літерний рядок

	FuzzyNumber_Public& operator ++ ();    //перевантаження операції "інкременту"(префіксна форма) --- x
	FuzzyNumber_Public& operator -- ();    //перевантаження операції "дикременту"(префіксна форма) --- l

	FuzzyNumber_Public operator ++ (int);  //перевантаження операції "інкременту"(постфіксна форма) --- r
	FuzzyNumber_Public operator -- (int);  //перевантаження операції "дикременту"(постфіксна форма) --- x

	friend FuzzyNumber_Public operator +(FuzzyNumber_Public, FuzzyNumber_Public);   //функція: дія --- додавання
	friend FuzzyNumber_Public operator *(FuzzyNumber_Public, FuzzyNumber_Public);	//функція: дія --- множення
};