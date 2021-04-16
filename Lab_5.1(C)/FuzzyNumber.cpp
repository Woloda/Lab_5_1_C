#include <stdexcept>
#include <sstream>
#include <iostream>
#include <string>

#include "My_Error_Range.h"
#include "FuzzyNumber.h"


FuzzyNumber::FuzzyNumber() {  //конструктор за умовчанням(без параметрів)
	x = 0;
	l = 0;
	r = 0;
}

FuzzyNumber::FuzzyNumber(char *str) throw(My_Error_Range) {	//конструктор ініціалізації
	double value_x = atof(str);
	str = strchr(str, ' ');
	double value_l = atof(str);
	str = strchr(str + 1, ' ');
	double value_r = atof(str);

	if (((value_x - value_l) > value_x) || (value_x > (value_x + value_r)))
		throw new My_Error_Range("\n\n!!!Incorrectly entered data!!!");		//генерування об'єкта винятка

	x = value_x;
	l = value_l;
	r = value_r;
}

FuzzyNumber::FuzzyNumber(FuzzyNumber& obj, int) {  //конструктор копіювання
	x = obj.x;
	l = obj.l;
	r = obj.r;
}

void FuzzyNumber::set_x(double value_x) { x = value_x; } //встановлення значення поля "x"
void FuzzyNumber::set_l(double value_l) { l = value_l; } //встановлення значення поля "l" 
void FuzzyNumber::set_r(double value_r) { r = value_r; } //встановлення значення поля "r"

double FuzzyNumber::get_x()const { return x; } //отримання значення поля "x" 
double FuzzyNumber::get_l()const { return l; }  //отримання значення поля "l"  
double FuzzyNumber::get_r()const { return r; } //отримання значення поля "r"

//вивід на екран(перевантаженння операції "виводу")
std::ostream& operator << (std::ostream& out, const FuzzyNumber& obj) {
	out << "\nZnachenuya danoho nechitkoho chusla: ( " << obj.x - obj.l << ", " << obj.x << ", " << obj.x + obj.r << " )";
	return out;
}

//введення з клавіатури(перевантаженння операції "вводу")
std::istream& operator >> (std::istream& in, FuzzyNumber& obj) throw (std::out_of_range) {
	double a{}, b{}, c{};

	std::cout << "\nVvedit dani(value) object : ";
	std::cout << "\n\nVvedit znachenie x: "; in >> a;
	std::cout << "Vvedit znachenie l: "; in >> b;
	std::cout << "Vvedit znachenie r: "; in >> c;

	/*Використання стандартного винятка
	Успадкований від std :: logic_error.
	Визначає виняток, яке повинно бути кинуто в тому випадку,
	коли відбувається вихід за межі допустимого діапазону значень об'єкта*/
	if (((a - b) > a) || (a > (a + c)))
		throw std::out_of_range{ "\n\n!!!Data entered incorrectly!!!" };	//генерування об'єкта винятка

	obj.x = a;
	obj.l = b;
	obj.r = c;

	return in;
}