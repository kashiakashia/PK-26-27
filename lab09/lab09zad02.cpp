#include <iostream>
#include <limits>

using namespace std;

bool spr_czy_palindorm(unsigned long long x) {

	unsigned long long orginal = x;
	unsigned long long odrotnosc = 0;

	while (orginal > 0) {

		unsigned long long ostatnia_cyfra = orginal % 10;

		odrotnosc = odrotnosc * 10 + ostatnia_cyfra;
		orginal = orginal / 10;
	}

	return odrotnosc == x;
	
	/*
	if (odrotnosc == x) {
		return true;
	}
	else return false;
	*/
}

void palindrom_unsigned_short() {
	unsigned short liczba_typu_max = numeric_limits<unsigned short>::max();
	
	for (int i = liczba_typu_max; i >= 0; i--) {
		if (spr_czy_palindorm(i)) {             // f ma zwrócić true albo false
			cout << "Palindrom max na typie to " << i << endl;
			break;
        }						
	}
}


int main()
{
    cout << "Rozmiary typów w bajtach:" << endl;
    cout << "signed short int:        " << sizeof(signed short int) << " bajt" << endl;
    cout << "unsigned short int:      " << sizeof(unsigned short int) << " bajt" << endl;


    cout << "Zakres dla signed int: "
        << numeric_limits<signed int>::min() << " do "
        << numeric_limits<signed int>::max() << endl;
}