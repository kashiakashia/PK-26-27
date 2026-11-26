#include <iostream>
#include <string>
using namespace std;

// ... dopisz dziesiątki, nastki, jednosci


// Funkcja zwraca nazwę setek
const char* setki(int liczba) {
    static const char* setki[] = { "", "sto", "dwieście", "trzysta", "czterysta", "pięćset",
                                   "sześćset", "siedemset", "osiemset", "dziewięćset" };
    return setki[liczba / 100]; // Indeks tablicy to wynik liczba / 100
}

int main() {
    int liczba, s;
    string wynik;

    cout << "Podaj liczbe: ";
    cin >> liczba;

    cout << "Debug: liczba / 100 = " << liczba / 100 << endl;

    s = liczba / 100;                       // Setki 

    if (s > 0) {
        wynik += setki(liczba);             // Wywołanie funkcji setki
        wynik += " ";
    }

    cout << wynik << endl;
    return 0;
}