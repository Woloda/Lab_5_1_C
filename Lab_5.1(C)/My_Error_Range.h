#include <string>


class My_Error_Range {		//клас винятків "My_Error_Range"	
	std::string message;	//поле для відображення типа помилки в вигляді літерного рядка
public:
	My_Error_Range(const std::string& value)	//конструктор ініціалізації
		:message(value) {};

	std::string What() { return message; }		//отримання значення поля "message"
};