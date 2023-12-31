#include "tests.h"

using namespace std;

int main()
{
	ht = ht::create(1000, 3, 10, 256, L"./files/HTspace.ht");
	if (ht)
		cout << "Сreate is successful" << endl;
	else
		throw "Error in create";

	if (tests::test1(ht))
		cout << "Test1: success" << endl;
	else
		cout << "Test1: error" << endl;

	if (tests::test2(ht))
		cout << "Test2: success" << endl;
	else
		cout << "Test2: error" << endl;

	if (tests::test3(ht))
		cout << "Test3: success" << endl;
	else
		cout << "Test3: error" << endl;

	if (tests::test4(ht))
		cout << "Test4: success" << endl;
	else
		cout << "Test4: error" << endl;

	if (ht != nullptr)
		if (ht::close(ht))
			cout << "Close is successful" << endl;
		else
			throw "Error in close";
}