#pragma once

class FuzzyNumber {       //робота з нечіткими числами
	double x, l, r;       //поля для представленння нечітких чисел
public:
	FuzzyNumber();                    //конструктор за умовчанням(без параметрів)
	FuzzyNumber(char*);				  //конструктор ініціалізації
	FuzzyNumber(FuzzyNumber&, int);   //конструктор копіювання

	void set_x(double value_x);   //встановлення значення поля "x"
	void set_l(double value_l);   //встановлення значення поля "l"
	void set_r(double value_r);   //встановлення значення поля "r"

	double get_x()const;   //отримання значення поля "x"
	double get_l()const;   //отримання значення поля "l"
	double get_r()const;   //отримання значення поля "r"

	friend std::ostream& operator << (std::ostream&, const FuzzyNumber&);        //вивід на екран(перевантаженння операції "виводу")
	friend std::istream& operator >> (std::istream&, FuzzyNumber&);              //введення з клавіатури(перевантаженння операції "вводу")
};