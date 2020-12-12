#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include "../lab9.1/lab9.1.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

struct student
{
	
	unsigned curs;

	int firstmark;
	int secondmark;
	union
	{
		int prog;
		int chmesod;
		int workjob;
	};
};
namespace lab91Testing
{
	TEST_CLASS(lab91Testing)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			student* pp = new student[3];
			count5(pp, 3);

		}
	};
}
