#include<iostream>

using namespace std;


int wiek (int r){
    int w;
    w = 2026 - r;
    return w;
}


int main() {
    int rok, wynik;
    cin >> rok;
    wynik = wiek(rok);
        

    cout << wynik << endl;

    return 0;
}