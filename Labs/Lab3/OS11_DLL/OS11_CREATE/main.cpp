#pragma comment(lib, "../x64/debug/OS11_HTAPI.lib")

#include "../OS11_HTAPI/pch.h"
#include "../OS11_HTAPI/HT.h"

using namespace std;

wchar_t* getWC(const char* c);

int main(int argc, char* argv[])
{
	if (argc < 6) {
		std::cout << "Not enough arguments provided" << std::endl;
		return 1;
	}

	ht::HtHandle* ht = ht::create(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), getWC(argv[5]));

	if (ht)
	{
		cout << "\n\t\t\t\tHT - Storage Created\t\t\t\t\n" << endl;
		wcout << "filename: " << ht->fileName << endl;
		cout << "secSnapshotInterval: " << ht->secSnapshotInterval << endl;
		cout << "capacity: " << ht->capacity << endl;
		cout << "maxKeyLength: " << ht->maxKeyLength << endl;
		cout << "maxPayloadLength: " << ht->maxPayloadLength << endl;
		cout << "\n\n" << endl;

		ht::close(ht);
	}
	else
		cout << "Failed to create hash-table" << endl;

}

wchar_t* getWC(const char* c)
{
	wchar_t* wc = new wchar_t[strlen(c) + 1];
	mbstowcs(wc, c, strlen(c) + 1);

	return wc;
}
