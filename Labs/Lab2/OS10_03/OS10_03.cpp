#ifdef _WIN64
#pragma comment(lib, "../x64/debug/OS10_HTAPI.lib")
#else
#pragma comment(lib, "../debug/OS10_HTAPI.lib")
#endif

#include "../OS10_HTAPI/pch.h"
#include "../OS10_HTAPI/HT.h"

using namespace std;

int main()
{
	ht::HtHandle* ht1 = nullptr;
	ht::HtHandle* ht2 = nullptr;

	#pragma region ht1

	try
	{
		cout << "\t\t\tHt1" << endl;
		ht1 = ht::create(1000, 3, 10, 256, L"./files/HTspace.ht");
		if (ht1)
			cout << "Сreate is successful" << endl;
		else
			throw "Error in create";

		cout << "Ht1: " << ht1->addr << endl;

		if (ht::insert(ht1, new ht::Element("key", 4, "payload", 8)))
			cout << "Insert is successful" << endl;
		else
			throw "Error in insert";
	}
	catch (const char* msg)
	{
		cout << msg << endl;

		if (ht1 != nullptr)
			cout << ht::getLastError(ht1) << endl;
	}

	#pragma endregion

	#pragma region ht2

	try
	{
		cout << "\n\t\t\tHt2" << endl;
		ht2 = ht::open(L"./files/HTspace.ht", true);
		if (ht2)
			cout << "Сreate is successful" << endl;
		else
			throw "Error in create";

		cout << "ht2: " << ht2->addr << endl;

		ht::Element* hte = ht::get(ht1, new ht::Element("key", 4));
		if (hte)
			cout << "Get is succesful" << endl;
		else
			throw "Error in get";

		ht::print(hte);
	}
	catch (const char* msg)
	{
		cout << msg << endl;

		if (ht1 != nullptr)
			cout << ht::getLastError(ht1) << endl;
	}

	#pragma endregion

	try
	{
		if (ht1 != nullptr)
			if (ht::close(ht1))
				cout << "Close is succesful (ht1)" << endl;
			else
				throw "Error in close (ht1)";

		if (ht2 != nullptr)
			if (ht::close(ht2))
				cout << "Close is succesful (ht2)" << endl;
			else
				throw "Error in close (ht2)";
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
}