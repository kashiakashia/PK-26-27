#include <iostream>
#include <fstream>
#include <string>

using namespace std;


// --------------------------- funkcje ------------------------------------------------

void wyszukajSlowaZLitera(ifstream& file) {
    char litera;
    string word;

    cout << "Podaj literę: ";
    cin >> litera;

    // ------ przygotowanie pliku do ponownego odczytu ------------
    file.clear();               // Reset flagi EOF (end of file) i reset flag błędów - po poprzednim czytaniu, mogła się ustawić, jeśli doszliśmy do końca plku.
                                // musimy ją zresetować, żeby było możliwe ponowne przejście przez plik
    file.seekg(0);              // ustawienie wskaźnika na początku pliku
    // -----------------------------------------------------------


    while (file >> word) {                      // operator '>>' pozwala nam na odczytywanie różnych typów znaków, domyślnym separatorem jest ' ' spacja. Czyli w praktyce,
                                                // każdy kolejny wyraz z linii pliku, będzie przechowywany w zmiennej word
        if (word.find(litera) != string::npos) {
            /* Funkcja find szuka pierwszego wystąpienia litery (lub ciągu znaków) w word
                jeśli litera zostanie znaleziona, funkcja zwraca indeks pierwszego wystąpienia tej litery w word
                jeśli litera nie zostanie znaleziona, funkcja zwraca wartość stałej string::npos (największa możliwa wartość w typie size_t) */
            cout << word << endl;
        }
    }
}



void wyszukajLinieZWyrazem(ifstream& file) {

}

// argc w skrócie, to liczba argumentów przy uruchomieniu programu
// ale tak naprawdę to jest tablica, której ROZMIAR jest równy liczbie argumentów
// ...dlaczego tak... ?
// bo char* argv, to jak widać tablica wskaźników do łańcucha znaków
// argv[0] to zawsze nazwa programu lub ścieżka do niego
// argv[0] w tym przypadku to ./szukacz.exe
// argv[1] to 'plik.txt'
// ...itd

int main(int argc, char* argv[]) {
//int main() {
    // przykład: 'szukacz.exe plik.txt coś_innego' -> argc > 2
    // przykład: 'szukacz.exe' - > argc = 1
    // przykład: 'szukacz.exe plik.txt' -> argc == 2

    if (argc < 3) {
        cerr << "Użycie: " << argv[0] << " <sciezka_do_pliku>\n";
        // cerr -> strumień do wypisywania błędów (bonus) 
        // *Jest niebuforowany, co oznacza, że dane są natychmiast wypisywane na ekran, 
        // bez oczekiwania na wypełnienie bufora.
        return 1;                       // zakończ program z błędem
    }

    // Otwieranie pliku
    ifstream file(argv[1]);
    
    // ---- jeśli nazwa pliku na sztywno - do deug np -------------------------
    /*ifstream file("C:\\Users\\kasia\\source\\repos\\szukacz\\x64\\Debug\\test.txt");
    if (!file.is_open()) {
        cerr << "Nie można otworzyć pliku test.txt" << endl;
        return 1;
    } */
   
     if (!file) {
        cerr << "Nie można otworzyć pliku: " << argv[1] << endl;
        return 1;
    }

    // Wczytywanie i wyświetlanie zawartości pliku
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

     // ----------------------------------------------------------------------
    char opcja;
    do {
        cout << "\nWybierz opcje:\n";
        cout << "1 - Wyszukaj slowa zawierajace litere\n";
        cout << "2 - Wyszukaj linie zawierajace wyraz\n";
        cout << "0 - Wyjscie\n";
        cin >> opcja;

        switch (opcja) {
        case '1':
            wyszukajSlowaZLitera(file);
            break;
        case '2':
            wyszukajLinieZWyrazem(file);
            break;
        case '0':
            cout << "Koniec programu.\n";
            break;
        default:
            cout << "Niepoprawna opcja, spróbuj ponownie.\n";
        }
    } while (opcja != '0');
// --------------------------------------------

    // Zamknięcie pliku
    file.close();
    return 0;
}
