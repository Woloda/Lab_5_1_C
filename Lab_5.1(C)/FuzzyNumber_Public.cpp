#include <sstream>

#include "FuzzyNumber_Public.h"


FuzzyNumber_Public::FuzzyNumber_Public() :FuzzyNumber() {} //конструктор за умовчанням(без параметрів)

FuzzyNumber_Public::FuzzyNumber_Public(char * str) : FuzzyNumber(str) {}   //конструктор ініціалізації

FuzzyNumber_Public::FuzzyNumber_Public(FuzzyNumber_Public& obj, int) : FuzzyNumber(obj, 1) {}  //конструктор копіювання

FuzzyNumber_Public& FuzzyNumber_Public::operator =(const FuzzyNumber_Public& obj) {   //перевантаження операції "присвоєння"
	set_x(obj.get_x());
	set_l(obj.get_l());
	set_r(obj.get_r());

	return *this;
}

FuzzyNumber_Public::operator std::string() {   //приведення типу – перетворення у літерний рядок
	std::stringstream sout;
	sout << "\n\nZnachenuya danoho obyekta: ";
	sout << "\nznachenie x: " << get_x();
	sout << "\nznachenie l: " << get_l();
	sout << "\nznachenie r: " << get_r();

	return sout.str();
}

FuzzyNumber_Public& FuzzyNumber_Public::operator ++ () {   //перевантаження операції "інкременту"(префіксна форма) --- x
	set_x(get_x() + 1);
	return *this;
}

FuzzyNumber_Public& FuzzyNumber_Public::operator -- () {   //перевантаження операції "дикременту"(префіксна форма) --- l
	set_l(get_l() - 1);
	return *this;
}

FuzzyNumber_Public FuzzyNumber_Public::operator ++ (int) {  //перевантаження операції "інкременту"(постфіксна форма) --- r
	FuzzyNumber_Public a(*this);
	set_r(get_r() + 1);
	return a;
}

FuzzyNumber_Public FuzzyNumber_Public::operator -- (int) {  //перевантаження операції "дикременту"(постфіксна форма) --- x
	FuzzyNumber_Public a(*this);
	set_x(get_x() - 1);
	return a;
}

FuzzyNumber_Public operator +(FuzzyNumber_Public obj_A, FuzzyNumber_Public obj_B) {    //функція: дія --- додавання
	FuzzyNumber_Public obj_addit;
	obj_addit.set_x(obj_A.get_x() + obj_B.get_x() - obj_A.get_l() - obj_B.get_l());
	obj_addit.set_l(obj_A.get_x() + obj_B.get_x());
	obj_addit.set_r(obj_A.get_x() + obj_B.get_x() + obj_A.get_r() + obj_B.get_r());

	return obj_addit;
}

FuzzyNumber_Public operator *(FuzzyNumber_Public obj_A, FuzzyNumber_Public obj_B) {	  //функція: дія --- множення
	FuzzyNumber_Public obj_multi;
	obj_multi.set_x(obj_A.get_x() * obj_B.get_x() - obj_B.get_x() * obj_A.get_l() - obj_A.get_x() * obj_B.get_l() - obj_A.get_l() * obj_B.get_l());
	obj_multi.set_l(obj_A.get_x() * obj_B.get_x());
	obj_multi.set_r(obj_A.get_x() * obj_B.get_x() + obj_B.get_x() * obj_A.get_r() + obj_A.get_r() * obj_B.get_r() + obj_A.get_r() * obj_B.get_r());

	return obj_multi;
}