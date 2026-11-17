#include<iostream>

using namespace std;


void pokaz_tab (double** wsk_tab2D, int w, int k) {

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < k; j++) {
            cout << wsk_tab2D[i][j] << " ";
        }
        cout << endl;
    }
}

//void przyklad_zwroc_wsk (double** wsk_tab2D, int w, int k) {  
double** przyklad_zwroc_wsk (double** wsk_tab2D, int w, int k) {           // to może być void!!!

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < k; j++) {
             wsk_tab2D[i][j] = 1.0;
        }
    }

    return wsk_tab2D;
}




int main () {

    int x, y;
    cin >> x >> y;

    // macierz ktora moze przechowywać wart. ułamkowe
    double** arr = new double* [x];   // tablica wskaźników - wiersze
    for (int i = 0; i < x; i++) {
        arr[i] = new double[y];   // osobna tablica dla każdej kolumny
    }
    
    // wywołanie funkcji
    pokaz_tab(arr, x, y);
    double** a = przyklad_zwroc_wsk(arr, x, y);         // zamień typ funkcji przyklad_zwroc_wsk na void i przxetestuj działanie dla poniższego zakomentowanego wywołania
    //przyklad_zwroc_wsk(arr, x, y);
    pokaz_tab(a, x, y);



    // zadanie ze wskaźnikami - lab08
    int* tab = new int[x];      // tablica 1D o wymiarze x
    int* wsk = tab;
    int* koniec = tab + x;      // koniec tablicy
    // w pętli uzupełnij pseudolosowo
    
    *wsk = 2;       // przykład: chce wpisać akurat wart 2 do kom. tab
    wsk++;          // przesuniecie o jedna kom. pam. do przodu



    return 0;
}