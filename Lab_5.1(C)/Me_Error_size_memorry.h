#include <string>
#include <exception>


class Me_Error_size_memorry : public std::exception {		//клас винятків "Me_Error_size_memorry"
	std::string message;	//поле для відображення типа помилки в вигляді літерного рядка
public:
	Me_Error_size_memorry(const std::string& value)		//конструктор ініціалізації
		:message(value) {};

	std::string What() { return message; }		//отримання значення поля "message"
};