#include <iostream>

#include "FuzzyNumber_Public.h"
#include "FuzzyNumber_Private.h"
#include "Me_Error_size_memorry.h"
#include "My_Error_Range.h"


int main(void) {
	using std::cout;

	std::cout << "\n\n////////////////////////////////////////////////////////////11111111\n";

	//визначається власний виняток
	try {	//захищений(контрольований) блок
	char* A_str = new char[] {"14 45 8"};
	char* B_str = new char[] {"12 1 6"};
	FuzzyNumber_Public A(A_str), B(B_str), C;

	cout << A;
	cout << B;

	cout << A.operator std::string();
	cout << B.operator std::string();

	C = A + B;
	cout << "\n\nAddit object A i B: ";
	cout << C.operator std::string();

	C = A * B;
	cout << "\n\nMulti object A i B: ";
	cout << C.operator std::string();
	}
	catch (My_Error_Range* a) {		//зловлює помилку "My_Error_Range"
		std::cout << a->What();
	}

	std::cout << "\n\n";
	system("pause");
	std::cout << "\n\n////////////////////////////////////////////////////////////////////2222222\n";

	//використання стандартного винятка
	try { //захищений(контрольований) блок
	FuzzyNumber_Private A_1, B_1, C_1;

	std::cin >> A_1;
	std::cin >> B_1;

	cout << A_1;
	cout << B_1;

	C_1 = A_1 + B_1;
	cout << "\n\nAddit object A_1 i B_1: ";
	cout << C_1.operator std::string();

	C_1 = A_1 * B_1;
	cout << "\n\nMulti object A_1 i B_1: ";
	cout << C_1.operator std::string();
	}
	catch (std::out_of_range obj_1) {		// зловлює помилку "out_of_range"
		std::cout << obj_1.what();
	}

	std::cout << "\n\n";
	system("pause");
	std::cout << "\n\n////////////////////////////////////////////////////////////////////3333333\n";

	//використання винятків - нащадки від стандартних винятків;
	try { //захищений(контрольований) блок
		int size(0);
		std::cout << "\n\nVvedit size masuva: ";  std::cin >> size;

		if ((size < 2) || (size > 80'000'000))
			throw Me_Error_size_memorry("!!!Incorrectly allocated memory!!!");		//генерування об'єкта винятка
		FuzzyNumber* masuv = new FuzzyNumber[size];
	}
	catch (Me_Error_size_memorry& obj_2) {		// зловлює помилку "Me_Error_size_memorry"
		std::cout << obj_2.What();
	}

	std::cout << "\n\n";
	system("pause");
	return 0;
}