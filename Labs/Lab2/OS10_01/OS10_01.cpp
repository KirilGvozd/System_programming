#include "HT.h"

using namespace std;

int main()
{
	ht::HtHandle* ht = nullptr;
	try
	{
		ht = ht::create(1000, 3, 10, 256, L"./files/HTspace.ht");
		if (ht)
			cout << "Сreate is successful" << endl;
		else
			throw "Error in create";
	
		if (ht::insert(ht, new ht::Element("key", 4, "payload", 8)))
			cout << "Insert is successful" << endl;
		else
			throw "Error in insert";

		ht::Element* hte = ht::get(ht, new ht::Element("key", 4));
		if (hte)
			cout << "Get is successful" << endl;
		else
			throw "Error in get";
	
		ht::print(hte);

		if (ht::update(ht, hte, "newPayload", 11))
			cout << "Update is successful" << endl;
		else
			throw "Error in update";

		if (ht::snap(ht))
			cout << "SnapSync is successful" << endl;
		else
			throw "Error in snap";

		hte = ht::get(ht, new ht::Element("key", 4));
		if (hte)
			cout << "Get is successful" << endl;
		else
			throw "Error in get";

		ht::print(hte);

		SleepEx(3000, TRUE);	

		if (ht::remove(ht, hte))
			cout << "Remove is successful" << endl;
		else
			throw "Error in remove";

		hte = ht::get(ht, new ht::Element("key", 4));
		if (hte)
			cout << "Get is successful" << endl;
		else
			throw "Error in get";
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	
		if (ht != nullptr)
			cout << ht::getLastError(ht) << endl;
	}

	try
	{
		if (ht != nullptr)
			if (ht::close(ht))
				cout << "Close is successful" << endl;
			else
				throw "Error in close";
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
}