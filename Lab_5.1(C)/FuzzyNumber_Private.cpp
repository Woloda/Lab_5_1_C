#include <sstream>
#include <iostream>

#include "FuzzyNumber_Private.h"


FuzzyNumber_Private::FuzzyNumber_Private() :FuzzyNumber() {} //конструктор за умовчанням(без параметрів)

FuzzyNumber_Private::FuzzyNumber_Private(char* str) : FuzzyNumber(str) {}   //конструктор ініціалізації

FuzzyNumber_Private::FuzzyNumber_Private(FuzzyNumber_Private& obj, int) : FuzzyNumber(obj, 0) {}  //конструктор копіювання

FuzzyNumber_Private& FuzzyNumber_Private::operator =(const FuzzyNumber_Private& obj) {   //перевантаження операції "присвоєння"
	set_x(obj.get_x());
	set_l(obj.get_l());
	set_r(obj.get_r());

	return *this;
}

FuzzyNumber_Private::operator std::string() {   //приведення типу – перетворення у літерний рядок
	std::stringstream sout;
	sout << "\n\nZnachenuya danoho obyekta: ";
	sout << "\nznachenie x: " << get_x();
	sout << "\nznachenie l: " << get_l();
	sout << "\nznachenie r: " << get_r();

	return sout.str();
}

//вивід на екран(перевантаженння операції "виводу")
std::ostream& operator << (std::ostream& out, const FuzzyNumber_Private& obj) {
	out << "\nZnachenuya danoho nechitkoho chusla: ( " << obj.get_x() - obj.get_l() << ", " << obj.get_x() << ", " << obj.get_x() + obj.get_r() << " )";
	return out;
}

//введення з клавіатури(перевантаженння операції "вводу")
std::istream& operator >> (std::istream& in, FuzzyNumber_Private& obj) {
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

	obj.set_x(a);
	obj.set_l(b);
	obj.set_r(c);

	return in;
}

FuzzyNumber_Private& FuzzyNumber_Private::operator ++ () {   //перевантаження операції "інкременту"(префіксна форма) --- x
	set_x(get_x() + 1);
	return *this;
}

FuzzyNumber_Private& FuzzyNumber_Private::operator -- () {   //перевантаження операції "дикременту"(префіксна форма) --- l
	set_l(get_l() - 1);
	return *this;
}

FuzzyNumber_Private FuzzyNumber_Private::operator ++ (int) {  //перевантаження операції "інкременту"(постфіксна форма) --- r
	FuzzyNumber_Private a(*this);
	set_r(get_r() + 1);
	return a;
}

FuzzyNumber_Private FuzzyNumber_Private::operator -- (int) {  //перевантаження операції "дикременту"(постфіксна форма) --- x
	FuzzyNumber_Private a(*this);
	set_x(get_x() - 1);
	return a;
}

FuzzyNumber_Private operator +(FuzzyNumber_Private obj_A, FuzzyNumber_Private obj_B) {    //функція: дія --- додавання
	FuzzyNumber_Private obj_addit;
	obj_addit.set_x(obj_A.get_x() + obj_B.get_x() - obj_A.get_l() - obj_B.get_l());
	obj_addit.set_l(obj_A.get_x() + obj_B.get_x());
	obj_addit.set_r(obj_A.get_x() + obj_B.get_x() + obj_A.get_r() + obj_B.get_r());

	return obj_addit;
}

FuzzyNumber_Private operator *(FuzzyNumber_Private obj_A, FuzzyNumber_Private obj_B) {	  //функція: дія --- множення
	FuzzyNumber_Private obj_multi;
	obj_multi.set_x(obj_A.get_x() * obj_B.get_x() - obj_B.get_x() * obj_A.get_l() - obj_A.get_x() * obj_B.get_l() - obj_A.get_l() * obj_B.get_l());
	obj_multi.set_l(obj_A.get_x() * obj_B.get_x());
	obj_multi.set_r(obj_A.get_x() * obj_B.get_x() + obj_B.get_x() * obj_A.get_r() + obj_A.get_r() * obj_B.get_r() + obj_A.get_r() * obj_B.get_r());

	return obj_multi;
}