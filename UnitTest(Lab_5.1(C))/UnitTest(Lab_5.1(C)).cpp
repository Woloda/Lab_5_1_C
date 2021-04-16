#include "pch.h"
#include "CppUnitTest.h"

#include "../Lab_5.1(C)/FuzzyNumber.cpp"
#include "../Lab_5.1(C)/FuzzyNumber_Private.cpp"
#include "../Lab_5.1(C)/FuzzyNumber_Public.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab51C
{
	TEST_CLASS(UnitTestLab51C)
	{
	public:
		
		TEST_METHOD(Test_FuzzyNumber_Public)
		{
			FuzzyNumber_Public A("2 3 4"), B("2 3 4"), C;

			C = A + B;
			Assert::AreEqual(C.get_x(), -2.0);
		}

		TEST_METHOD(Test_FuzzyNumber_Private)
		{
			FuzzyNumber_Private A("2 3 4"), B("2 3 4"), C;

			C = A + B;
			Assert::AreEqual(C.get_r(), 12.0);
		}
	};
}