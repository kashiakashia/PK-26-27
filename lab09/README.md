# Laboratorium 09: napisy C-owe, `const char*`, zakresy typów, palindromy i argumenty programu

Na tym laboratorium pojawiają się nowe zagadnienia związane z:

- funkcjami zwracającymi tekst,
- typem `const char*`,
- napisami C-owymi zakończonymi znakiem `\0`,
- rozmiarem i zakresem typów całkowitych,
- operatorem `sizeof`,
- biblioteką `<limits>`,
- palindromami liczbowymi,
- argumentami programu `argc` i `argv`,
- otwieraniem plików,
- czytaniem plików linia po linii,
- wyszukiwaniem wzorca w tekście.

Przykłady pokazują mechanizmy potrzebne do wykonania zadań, ale nie są gotowymi rozwiązaniami zadań laboratoryjnych.

---

# Część I: funkcje zwracające tekst

## 1. `void` a funkcja zwracająca wartość

Funkcja:

```cpp
void pokaz(int x)
```

nie zwraca wartości. Może np. coś wypisać:

```cpp
cout << x;
```

Funkcja:

```cpp
int oblicz(int x)
```

może natomiast zakończyć się:

```cpp
return wynik;
```

i przekazać wartość do miejsca wywołania.

---

## 2. Funkcja może zwracać napis

Jednym ze sposobów zwracania tekstu jest typ:

```cpp
const char*
```

Przykład:

```cpp
const char* nazwaDnia(int nr) {

    if (nr == 1) {
        return "poniedzialek";
    }

    return "inny";
}
```

Tutaj funkcja nie wypisuje tekstu. Zwraca wskaźnik do napisu.

---

## 3. Co oznacza `const char*`?

Zapis:

```cpp
const char*
```

oznacza wskaźnik do znaków typu `char`, których nie modyfikujemy przez ten wskaźnik.

Przykład:

```cpp
const char* napis = "kot";
```

W pamięci napis wygląda logicznie tak:

```text
'k' 'o' 't' '\0'
```

Zmienna `napis` wskazuje na pierwszy znak.

---

## 4. Znak końca napisu `\0`

Napis C-owy kończy się specjalnym znakiem:

```cpp
'\0'
```

Dlatego zapis:

```cpp
"kot"
```

w pamięci zajmuje cztery znaki:

```text
k
o
t
\0
```

Ostatni znak informuje funkcje tekstowe, gdzie napis się kończy.

---

## 5. Dlaczego `const`?

Literału:

```cpp
"kot"
```

nie należy modyfikować.

Dlatego poprawny i bezpieczny zapis to:

```cpp
const char* napis = "kot";
```

---

## 6. Zwracanie jednego z kilku napisów

Funkcja może wybierać napis zależnie od argumentu:

```cpp
const char* opis(int x) {

    if (x == 0) {
        return "zero";
    }

    if (x == 1) {
        return "jeden";
    }

    return "inna wartosc";
}
```

`return` zwraca adres początku wybranego napisu.

---

# Część II: liczby słownie

## 7. Rozbijanie liczby na cyfry

Dla liczby:

```text
347
```

możemy osobno znaleźć:

```text
setki      3
dziesiątki 4
jedności   7
```

---

## 8. Jedności

Ostatnią cyfrę otrzymujemy przez:

```cpp
liczba % 10
```

Przykład:

```text
347 % 10 = 7
```

---

## 9. Dziesiątki

Cyfrę dziesiątek można otrzymać przez:

```cpp
(liczba / 10) % 10
```

Dla `347`:

```text
347 / 10 = 34
34 % 10 = 4
```

---

## 10. Setki

Dla liczby trzycyfrowej:

```cpp
liczba / 100
```

daje cyfrę setek.

```text
347 / 100 = 3
```

---

## 11. Liczby ujemne

Jeżeli:

```cpp
liczba < 0
```

trzeba uwzględnić słowo:

```text
minus
```

a następnie przejść do analizy wartości dodatniej.

Schemat:

```text
-347
  ↓
minus
  ↓
347
  ↓
setki, dziesiątki, jedności
```

---

## 12. Szczególny przypadek: liczby 10-19

Liczby:

```text
10 11 12 13 14 15 16 17 18 19
```

nie powstają przez zwykłe połączenie nazwy dziesiątek i jedności.

Przykładowo:

```text
12 = dwanaście
```

a nie:

```text
dziesięć dwa
```

Dlatego ten zakres wymaga osobnego potraktowania.

---

## 13. Wersja z funkcjami `void`

W pierwszym zadaniu funkcje:

```cpp
void jednosci(int);
void dziesiatki(int);
void setki(int);
```

mają same wypisywać odpowiedni fragment liczby.

Schemat:

```text
argument
   ↓
funkcja wybiera właściwe słowo
   ↓
cout
```

---

## 14. Wersja z `const char*`

W drugim zadaniu funkcje:

```cpp
const char* jednosci(int);
const char* dziesiatki(int);
const char* setki(int);
```

nie powinny nic wypisywać.

Zamiast tego:

```text
argument
   ↓
funkcja wybiera właściwe słowo
   ↓
return
```

Dopiero kod wywołujący decyduje, kiedy i gdzie wynik wypisać.

---

## 15. Dlaczego zwracanie napisu jest bardziej uniwersalne?

Jeżeli funkcja wykonuje od razu:

```cpp
cout
```

jest związana z konsolą.

Jeżeli zwraca:

```cpp
const char*
```

wynik można:

- wypisać,
- przekazać dalej,
- wykorzystać w innym miejscu programu,
- połączyć z innym tekstem.

To jest przykład rozdzielenia logiki od prezentacji.

---

# Część III: czego nie wolno zwracać z funkcji

## 16. Lokalna tablica znaków

Błędny pomysł:

```cpp
const char* funkcja() {

    char tekst[20] = "test";

    return tekst;
}
```

`tekst` jest zmienną lokalną.

Po zakończeniu funkcji ta tablica przestaje istnieć.

Zwrócony wskaźnik wskazywałby więc na niepoprawny obszar pamięci.

---

## 17. Dlaczego można zwracać literały?

To jest bezpieczne:

```cpp
return "test";
```

Literał tekstowy istnieje przez cały czas działania programu.

Dlatego zwracanie wskaźnika do takiego napisu jest poprawne.

---

# Część IV: rozmiar typów całkowitych

## 18. Operator `sizeof`

Operator:

```cpp
sizeof
```

zwraca rozmiar typu lub zmiennej w bajtach.

Przykład:

```cpp
cout << sizeof(int);
```

albo:

```cpp
cout << sizeof(unsigned long long int);
```

---

## 19. Rozmiar może zależeć od platformy

Nie należy zakładać, że:

```text
long zawsze ma 8 bajtów
```

Rozmiar może zależeć od:

- systemu operacyjnego,
- kompilatora,
- architektury.

Dlatego w zadaniu trzeba korzystać z:

```cpp
sizeof
```

---

## 20. `signed` i `unsigned`

Typ:

```cpp
signed int
```

może przechowywać liczby ujemne i dodatnie.

Typ:

```cpp
unsigned int
```

przechowuje tylko wartości nieujemne.

---

## 21. Zakres typu bez znaku

Dla typu o `n` bitach:

```text
0 ... 2^n - 1
```

Przykład dla 8 bitów:

```text
0 ... 255
```

---

## 22. Zakres typu ze znakiem

Dla typowego zapisu uzupełnień do dwóch:

```text
-2^(n-1) ... 2^(n-1)-1
```

Dla 8 bitów:

```text
-128 ... 127
```

---

# Część V: `numeric_limits`

## 23. Biblioteka `<limits>`

Do sprawdzania granicznych wartości typów służy:

```cpp
#include <limits>
```

---

## 24. Maksymalna wartość typu

Możemy użyć:

```cpp
numeric_limits<T>::max()
```

Przykład neutralny:

```cpp
cout << numeric_limits<unsigned char>::max();
```

W zadaniu zamiast `unsigned char` pojawią się inne typy całkowite.

---

## 25. Minimalna wartość

Analogicznie:

```cpp
numeric_limits<T>::min()
```

pozwala sprawdzić minimalną wartość typu.

---

# Część VI: palindrom liczbowy

## 26. Co to jest palindrom?

Liczba jest palindromem, jeżeli jej cyfry czytane od lewej do prawej i od prawej do lewej są takie same.

Przykłady:

```text
7
11
121
1331
12321
```

Nie są palindromami:

```text
12
123
1234
```

---

## 27. Porównywanie cyfr

Dla:

```text
12321
```

sprawdzamy:

```text
pierwsza  == ostatnia
druga     == przedostatnia
```

czyli:

```text
1 == 1
2 == 2
```

Środkowa cyfra nie wymaga pary.

---

## 28. Rozkład liczby na cyfry

Ostatnią cyfrę uzyskujemy przez:

```cpp
liczba % 10
```

Przykład:

```text
52725 % 10 = 5
```

A ostatnią cyfrę usuwamy przez:

```cpp
liczba / 10
```

czyli:

```text
52725 / 10 = 5272
```

---

## 29. Podejście z tablicą

Możemy zapisać cyfry w tablicy:

```text
52725
↓
5 2 7 2 5
```

a następnie porównywać elementy z dwóch końców.

---

## 30. Podejście z odwracaniem liczby

Inna możliwość:

```text
oryginał
   ↓
odwrócona liczba
   ↓
porównanie
```

Jeżeli:

```text
oryginał == odwrócona
```

liczba jest palindromem.

---

# Część VII: największy palindrom mieszczący się w typie

## 31. Co dokładnie szukamy?

Dla każdego typu chcemy znaleźć:

```text
największą liczbę <= maksymalnej wartości typu
```

która jest palindromem.

Czyli są dwa warunki:

```text
liczba mieści się w typie
```

oraz:

```text
liczba jest palindromem
```

---

## 32. Najprostszy pomysł

Można zacząć od:

```text
maksymalnej wartości typu
```

i sprawdzać kolejne liczby w dół.

To poprawna koncepcyjnie metoda, ale dla dużych typów może być bardzo wolna.

---

## 33. Lepsza obserwacja

Palindrom nie jest dowolną liczbą.

Dla parzystej liczby cyfr ma postać np.:

```text
abc|cba
```

Dla nieparzystej:

```text
abc|ba
```

Druga część wynika więc z pierwszej.

Można wykorzystać tę własność zamiast sprawdzać każdą kolejną liczbę.

---

## 34. Przykład konstrukcji

Z części:

```text
123
```

można zbudować:

```text
123321
```

lub:

```text
12321
```

zależnie od oczekiwanej liczby cyfr.

---

## 35. Przepełnienie

Przy dużych liczbach trzeba uważać na działania typu:

```text
wynik = wynik * 10 + cyfra
```

Jeżeli `wynik` jest już blisko maksimum typu, mnożenie przez `10` może spowodować przepełnienie.

---

# Część VIII: argumenty programu

## 36. Druga postać funkcji `main`

Zamiast:

```cpp
int main()
```

możemy napisać:

```cpp
int main(int argc, char* argv[])
```

---

## 37. `argc`

`argc` oznacza:

```text
argument count
```

czyli liczbę argumentów programu.

---

## 38. `argv`

`argv` oznacza:

```text
argument vector
```

i jest tablicą napisów.

Przykład:

```cpp
argv[0]
argv[1]
argv[2]
```

---

## 39. Przykład uruchomienia

Jeżeli program uruchamiamy:

```text
program.exe dane.txt kot pies
```

to:

```text
argc = 4
```

oraz:

```text
argv[0] -> "program.exe"
argv[1] -> "dane.txt"
argv[2] -> "kot"
argv[3] -> "pies"
```

---

## 40. `argv[0]` to nazwa programu

To bardzo ważne.

Pierwszym argumentem użytkownika jest:

```cpp
argv[1]
```

a nie:

```cpp
argv[0]
```

---

## 41. Najpierw sprawdź `argc`

Jeżeli program chce użyć:

```cpp
argv[1]
```

musi wcześniej sprawdzić, czy użytkownik rzeczywiście podał przynajmniej jeden argument.

---

# Część IX: otwieranie pliku

## 42. Biblioteka `<fstream>`

Do odczytu plików używamy:

```cpp
#include <fstream>
```

i typu:

```cpp
ifstream
```

---

## 43. Otwieranie pliku

Przykład:

```cpp
ifstream plik("dane.txt");
```

Jeżeli ścieżka pochodzi z argumentu:

```cpp
ifstream plik(argv[1]);
```

---

## 44. Sprawdzenie poprawności otwarcia

Należy sprawdzić:

```cpp
if (!plik) {
    // błąd otwarcia
}
```

Nie można zakładać, że podana ścieżka zawsze jest poprawna.

---

# Część X: czytanie pliku linia po linii

## 45. `getline`

Dla:

```cpp
string linia;
```

możemy wykonać:

```cpp
getline(plik, linia);
```

i odczytać całą linię.

---

## 46. Czytanie wszystkich linii

Typowy schemat:

```cpp
string linia;

while (getline(plik, linia)) {

    // analiza aktualnej linii
}
```

Pętla kończy się, gdy nie można wczytać następnej linii.

---

## 47. Dlaczego nie `plik >> linia`?

Operator:

```cpp
>>
```

zatrzymuje się na białym znaku.

Dla:

```text
Ala ma kota
```

odczytałby tylko:

```text
Ala
```

`getline` odczytuje całą linię.

---

# Część XI: wyszukiwanie tekstu

## 48. `string::find`

Jeżeli mamy:

```cpp
string linia;
string wzorzec;
```

możemy wykonać:

```cpp
linia.find(wzorzec)
```

---

## 49. `string::npos`

Jeżeli wzorca nie znaleziono, `find` zwraca:

```cpp
string::npos
```

Dlatego:

```cpp
if (linia.find(wzorzec) != string::npos) {
    // znaleziono
}
```

---

## 50. To jest wyszukiwanie fragmentu tekstu

Dla wzorca:

```text
kot
```

`find` znajdzie go również w:

```text
kotek
```

bo wyszukuje podciąg znaków.

---

# Część XII: wiele wzorców

## 51. Kolejne argumenty jako wzorce

Dla uruchomienia:

```text
program.exe tekst.txt dom kot las
```

mamy:

```text
argv[1] -> plik
argv[2] -> pierwszy wzorzec
argv[3] -> drugi wzorzec
argv[4] -> trzeci wzorzec
```

Czyli wzorce zaczynają się od:

```cpp
argv[2]
```

---

## 52. Jeden plik, wiele wyszukiwań

Jeżeli program ma szukać kilku wzorców, trzeba zdecydować:

```text
czy czytamy plik ponownie dla każdego wzorca?
```

czy:

```text
czy zapisujemy linie do pamięci i przeszukujemy je wielokrotnie?
```

---

## 53. Ograniczenia zadania

W treści wiadomo:

```text
maksymalnie 200 linii
```

oraz:

```text
maksymalnie 300 znaków w linii
```

To pozwala zaprojektować prostą strukturę danych do przechowywania zawartości pliku.

---

## 54. Tablica linii

Jedna z możliwości:

```cpp
string linie[200];
```

oraz osobny licznik rzeczywiście wczytanych linii.

Nie oznacza to, że plik zawsze ma 200 linii.

---

# Część XIII: `argv` i napisy C-owe

## 55. Dlaczego `argv` ma typ `char*[]`?

Argumenty programu są przekazywane jako napisy C-owe zakończone:

```cpp
'\0'
```

Dlatego:

```cpp
argv[i]
```

jest wskaźnikiem do pierwszego znaku odpowiedniego argumentu.

---

## 56. Zamiana argumentu na `string`

Jeżeli chcemy używać metod klasy `string`, możemy zrobić:

```cpp
string wzorzec = argv[i];
```

---

# Część XIV: typowe błędy

## 57. Zwracanie adresu lokalnej tablicy

Nie zwracaj:

```cpp
char tekst[20];
return tekst;
```

z funkcji, bo ta tablica przestaje istnieć po zakończeniu funkcji.

---

## 58. Pomylenie `char*` i `const char*`

Dla literałów tekstowych używaj:

```cpp
const char*
```

---

## 59. Zgubienie oryginalnej liczby przy odwracaniu

Jeżeli wykonujesz:

```cpp
liczba /= 10;
```

niszczysz jej aktualną wartość.

Jeżeli później potrzebujesz oryginału, zachowaj kopię.

---

## 60. Za mały typ pomocniczy

Jeżeli analizujesz:

```cpp
unsigned long long int
```

a pomocniczy wynik zapisujesz w:

```cpp
int
```

wartość może się nie zmieścić.

---

## 61. Za mało argumentów programu

Zawsze sprawdzaj:

```cpp
argc
```

przed użyciem odpowiednich elementów:

```cpp
argv
```

---

## 62. Nieudane otwarcie pliku

Program powinien obsłużyć sytuację:

```text
plik nie istnieje
```

lub:

```text
ścieżka jest błędna
```

---

# Część XV: jak podejść do zadań

## 63. Zadanie „liczby słownie”

Najpierw odpowiedz:

1. Jak wyciągnąć setki?
2. Jak wyciągnąć dziesiątki?
3. Jak wyciągnąć jedności?
4. Jak obsłużyć minus?
5. Jak obsłużyć liczby `10-19`?
6. Co ma robić każda z trzech funkcji?

---

## 64. Wersja z `const char*`

Pomyśl:

```text
co funkcja ma zwracać?
```

oraz:

```text
czy funkcja powinna sama wypisywać wynik?
```

W tej wersji odpowiedź na drugie pytanie brzmi:

```text
nie
```

---

## 65. Zadanie z palindromami

Podziel problem:

```text
1. sprawdź rozmiar typu
2. sprawdź maksimum typu
3. znajdź największy palindrom nie większy od maksimum
4. wypisz wynik
```

Najpierw przetestuj algorytm na małych wartościach.

---

## 66. Zadanie z plikiem

Schemat:

```text
sprawdź argc
    ↓
pobierz ścieżkę z argv[1]
    ↓
otwórz plik
    ↓
wczytaj linie
    ↓
dla każdego wzorca:
    przeszukaj linie
    wypisz pasujące
```

---

# Podsumowanie

Po tym laboratorium warto rozumieć:

### `const char*`

```cpp
const char* tekst = "abc";
```

to wskaźnik na napis C-owy zakończony `\0`.

### Funkcja zwracająca napis

```cpp
const char* funkcja(int x);
```

może zwracać jeden z gotowych napisów.

### `sizeof`

```cpp
sizeof(T)
```

informuje, ile bajtów zajmuje typ.

### `numeric_limits`

```cpp
numeric_limits<T>::max()
```

pozwala sprawdzić maksymalną wartość typu.

### Palindrom

Liczba jest palindromem, jeśli jej cyfry czytane w obu kierunkach są identyczne.

### Argumenty programu

```cpp
int main(int argc, char* argv[])
```

pozwala odczytać argumenty podane przy uruchamianiu programu.

### Pliki

```cpp
ifstream
```

służy do odczytu pliku.

### Wyszukiwanie wzorca

```cpp
linia.find(wzorzec)
```

pozwala sprawdzić, czy linia zawiera podany tekst.

# Największy palindrom mieszczący się w typie

## Cel zadania

Dla każdego z podanych typów całkowitoliczbowych program ma wypisać:

- rozmiar typu w bajtach,
- największą liczbę, która mieści się w tym typie i jest palindromem.

Badane typy to: `signed short int`, `unsigned short int`, `signed int`, `unsigned int`, `signed long int`, `unsigned long int`, `signed long long int` i `unsigned long long int`.

Dla typów ze znakiem szukamy największej wartości dodatniej. Jej granicę pobieramy przez `numeric_limits<T>::max()`.

## Pomysł na rozwiązanie

Nie sprawdzamy po kolei każdej liczby od maksimum w dół. Dla typów 64-bitowych taka pętla mogłaby wykonywać się bardzo długo. Zamiast tego tworzymy największego możliwego palindroma na podstawie cyfr maksimum.

W kodzie cyfry są przechowywane w zwykłych tablicach. Nie używamy szablonów funkcji.

## Krok 1. Pobranie maksimum typu

Funkcja `sprawdzTyp` otrzymuje maksimum jako `unsigned long long`. Maksimum każdego z badanych typów mieści się w tym typie, a dla typów ze znakiem przekazujemy ich największą dodatnią wartość.

Przykładowo:

```cpp
numeric_limits<signed int>::max()
```

zwraca największą wartość typu `signed int`.

## Krok 2. Zapisanie cyfr maksimum w tablicy

W pętli pobieramy ostatnią cyfrę przez resztę z dzielenia przez 10:

```cpp
cyfry[len++] = temp % 10;
temp /= 10;
```

Cyfry trafiają do tablicy od końca. Dla liczby `1385` początkowo tablica zawiera:

```text
5, 8, 3, 1
```

Następna pętla zamienia kolejność cyfr, aby odpowiadała zapisowi liczby:

```text
1, 3, 8, 5
```

## Krok 3. Utworzenie kandydata

Kopiujemy cyfry maksimum do tablicy `kandydat`. Następnie odbijamy pierwszą połowę na drugą:

```cpp
for (int i = 0; i < len / 2; ++i) {
    kandydat[len - 1 - i] = kandydat[i];
}
```

Dla cyfr `1, 3, 8, 5` otrzymujemy kandydata `1331`.

## Krok 4. Porównanie kandydata z maksimum

Porównujemy cyfry od lewej strony. Dla liczb o tej samej liczbie cyfr pierwsza różna cyfra rozstrzyga, która liczba jest większa.

Jeśli kandydat nie przekracza maksimum, jest wynikiem.

## Krok 5. Zmniejszenie kandydata, jeśli jest za duży

Jeżeli kandydat przekracza maksimum, zmniejszamy środkową cyfrę lub cyfry. Jeśli napotkamy zero, zamieniamy je na 9 i przenosimy zmniejszenie w lewo. Na końcu ponownie odbijamy pierwszą połowę na drugą.

Przykład dla maksimum `1990`:

1. Odbicie cyfr daje `1991`, czyli liczbę za dużą.
2. Zmniejszamy środkową część.
3. Po ponownym odbiciu otrzymujemy `1881`.

### Szczególny przypadek: pierwsza cyfra zmieniła się na zero

Dla maksimum `1000` odbicie daje `1001`, czyli za dużo. Zmniejszanie prowadzi do cyfr `0, 9, 9, 0`. Ponieważ liczba zaczyna się od zera, skracamy ją o jedną cyfrę i wypełniamy dziewiątkami:

```text
0990 -> 999
```

## Krok 6. Odtworzenie liczby

Gdy cyfry kandydata są już gotowe, składamy z nich liczbę. W każdej iteracji przesuwamy dotychczasowy wynik o jedno miejsce dziesiętne i dodajemy kolejną cyfrę:

```cpp
wynik = wynik * 10 + kandydat[i];
```