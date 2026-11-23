# Zadania dodatkowe do ćwiczeń do Kolokwium 2

Poniższe zadania obejmują materiał z poprzedniego kolokwium oraz aktualnych laboratoriów.

Zestaw został przygotowany tak, aby przećwiczyć przede wszystkim:

- instrukcje warunkowe,
- pętle,
- funkcje,
- rekurencję,
- tablice jednowymiarowe i dwuwymiarowe,
- tablice dynamiczne,
- wskaźniki i arytmetykę wskaźników,
- `enum`,
- liczby pseudolosowe,
- napisy C-owe i `string`,
- podstawowe zagadnienia UTF-8,
- typy całkowitoliczbowe i `sizeof`,
- argumenty programu `argc` i `argv`,
- pliki tekstowe.

Nie są to zadania obowiązkowe. Służą do samodzielnego przećwiczenia materiału.

W zadaniach, w których podano wymaganą funkcję lub ograniczenie, należy go przestrzegać.

---

# Część I: funkcje i podstawowe algorytmy

## 1. Suma cyfr

Napisz program, który wczyta dodatnią liczbę całkowitą i obliczy sumę jej cyfr.

Obliczenie wykonaj w funkcji:

```cpp
int suma_cyfr(int liczba);
```

### Przykład

```text
Liczba: 5832
Suma cyfr: 18
```

---

## 2. Ile cyfr spełnia warunek?

Napisz program, który wczyta dodatnią liczbę całkowitą oraz cyfrę `d`.

Utwórz funkcję:

```cpp
int policz_cyfre(int liczba, int d);
```

która zwraca liczbę wystąpień cyfry `d` w podanej liczbie.

### Przykład

```text
Liczba: 1223122
Cyfra: 2
Liczba wystąpień: 4
```

---

## 3. Liczba doskonała

Napisz funkcję:

```cpp
bool czy_doskonala(int n);
```

Liczba doskonała jest równa sumie swoich dodatnich dzielników właściwych, czyli dzielników mniejszych od niej.

Przykład:

```text
6 = 1 + 2 + 3
```

Program powinien sprawdzić podaną przez użytkownika liczbę.

### Przykład

```text
N: 6
Liczba doskonała
```

```text
N: 10
Liczba nie jest doskonała
```

---

## 4. Największy wspólny dzielnik

Napisz program obliczający największy wspólny dzielnik dwóch dodatnich liczb całkowitych.

Obliczenie wykonaj w funkcji:

```cpp
int nwd(int a, int b);
```

Możesz zastosować algorytm Euklidesa.

### Przykład

```text
A: 84
B: 30
NWD: 6
```

---

# Część II: rekurencja

## 5. Suma liczb od 1 do N rekurencyjnie

Napisz funkcję rekurencyjną:

```cpp
int suma_rek(int n);
```

która oblicza:

```text
1 + 2 + 3 + ... + n
```

Nie wolno używać pętli wewnątrz funkcji.

### Przykład

```text
N: 5
Suma: 15
```

---

## 6. Potęga rekurencyjnie

Napisz funkcję:

```cpp
long long potega(int a, int n);
```

która rekurencyjnie oblicza:

```text
a^n
```

Zakładamy:

```text
n >= 0
```

Nie wolno korzystać z `pow()`.

### Przykład

```text
Podstawa: 3
Wykladnik: 4
Wynik: 81
```

---

## 7. Suma cyfr rekurencyjnie

Zmodyfikuj zadanie 1 tak, aby suma cyfr była obliczana rekurencyjnie.

Wymagana funkcja:

```cpp
int suma_cyfr_rek(int liczba);
```

Nie wolno używać pętli w tej funkcji.

### Przykład

```text
Liczba: 9047
Suma cyfr: 20
```

---

## 8. Odwracanie kolejności cyfr przez rekurencję

Napisz funkcję rekurencyjną, która wypisuje cyfry liczby w odwrotnej kolejności.

Przykładowa sygnatura:

```cpp
void odwroc(int liczba);
```

### Przykład

```text
Liczba: 12345
Odwrotnie: 54321
```

Nie używaj tablic ani `string`.

---

## 9. Liczba w systemie o zadanej podstawie

Napisz funkcję rekurencyjną:

```cpp
void wypisz_system(unsigned int n, int podstawa);
```

która wypisze liczbę w systemie o podstawie od `2` do `9`.

Nie wolno używać gotowych funkcji konwertujących ani tablic znaków.

### Przykład

```text
N: 100
Podstawa: 3
Wynik: 10201
```

---

## 10. Rekurencyjne wyszukiwanie maksimum w tablicy

Napisz funkcję:

```cpp
int maksimum_rek(int* tab, int n);
```

która rekurencyjnie znajduje największy element tablicy.

W funkcji nie wolno używać żadnej pętli.

### Przykład

```text
Tablica: 4 7 2 19 3
Maksimum: 19
```

---

## 11. Rekurencyjne przeszukiwanie binarne

Napisz program, który wczyta rosnąco uporządkowaną tablicę liczb całkowitych oraz szukaną wartość.

Utwórz rekurencyjną funkcję wyszukiwania binarnego.

Przykładowa sygnatura:

```cpp
int szukaj(int* tab, int lewy, int prawy, int szukana);
```

Funkcja powinna zwrócić indeks znalezionego elementu albo `-1`.

### Przykład

```text
N: 6
Tablica: 2 5 8 11 17 21
Szukana: 11
Indeks: 3
```

---

# Część III: wskaźniki

## 12. Tablica bez operatora `[]`

Napisz program, który tworzy dynamiczną tablicę `n` liczb całkowitych.

Program ma:

1. wczytać elementy,
2. wypisać je,
3. obliczyć ich sumę.

W programie nie wolno używać operatora:

```cpp
[]
```

do odwoływania się do elementów tablicy.

Do przechodzenia po elementach używaj wyłącznie wskaźnika i arytmetyki wskaźników.

---

## 13. Zamiana miejscami przez wskaźniki

Napisz funkcję:

```cpp
void zamien(int* a, int* b);
```

która zamienia wartości dwóch zmiennych.

### Przykład

```text
A: 5
B: 12
Po zamianie:
A: 12
B: 5
```

Nie wolno zwracać nowych wartości z funkcji.

---

## 14. Minimum i maksimum przez parametry wskaźnikowe

Napisz funkcję:

```cpp
void min_max(int* tab, int n, int* minimum, int* maksimum);
```

Funkcja ma jednocześnie wyznaczyć minimum i maksimum tablicy.

Nie zwracaj wyniku przez `return`.

### Przykład

```text
Tablica: 8 2 11 4 6
Minimum: 2
Maksimum: 11
```

---

## 15. Odwracanie tablicy wskaźnikami

Napisz program, który odwraca kolejność elementów dynamicznej tablicy.

Wymagania:

- nie wolno tworzyć drugiej tablicy,
- nie wolno korzystać z operatora `[]`,
- wykorzystaj dwa wskaźniki:
  - jeden zaczynający od początku,
  - drugi od końca tablicy.

### Przykład

```text
Przed: 1 2 3 4 5
Po:    5 4 3 2 1
```

---

## 16. Sąsiedzi większego elementu

Napisz program, który przechodzi po tablicy wyłącznie za pomocą wskaźników i wypisuje wszystkie pary sąsiadujących elementów, w których drugi element jest większy od pierwszego.

Nie wolno używać `[]`.

### Przykład

```text
Tablica: 3 7 5 8 10 4

Pary:
3 7
5 8
8 10
```

---

## 17. Kopiowanie tablicy przez wskaźniki

Napisz funkcję:

```cpp
void kopiuj(int* zrodlo, int* cel, int n);
```

która kopiuje wszystkie elementy jednej tablicy do drugiej.

W funkcji nie wolno używać `[]`.

---

# Część IV: tablice dynamiczne i macierze

## 18. Suma każdego wiersza

Napisz program, który dynamicznie alokuje macierz `N x M`.

Elementy macierzy wczytaj od użytkownika.

Następnie wypisz sumę każdego wiersza.

Napisz osobne funkcje do:

- alokacji macierzy,
- wczytywania,
- wypisywania,
- zwalniania pamięci.

### Przykład

```text
N: 2
M: 3

1 2 3
4 5 6

Suma wiersza 0: 6
Suma wiersza 1: 15
```

---

## 19. Największy element w każdej kolumnie

Napisz program dla dynamicznej tablicy dwuwymiarowej.

Dla każdej kolumny wypisz jej największy element.

### Przykład

```text
Macierz:
1 8 3
7 2 9
4 5 6

Maksima kolumn:
7 8 9
```

---

## 20. Odbicie macierzy w poziomie

Napisz program, który dynamicznie tworzy macierz `N x M`, a następnie zamienia miejscami:

```text
pierwszy wiersz z ostatnim,
drugi z przedostatnim,
...
```

Nie twórz drugiej macierzy.

### Przykład

```text
Przed:

1 2 3
4 5 6
7 8 9

Po:

7 8 9
4 5 6
1 2 3
```

---

## 21. Obrót macierzy o 90 stopni

Napisz program, który tworzy dynamiczną macierz `A` o rozmiarze `N x M` i tworzy drugą macierz zawierającą obrót `A` o 90 stopni zgodnie z ruchem wskazówek zegara.

Najpierw rozrysuj ręcznie zależność między indeksami.

### Przykład

```text
A:

1 2 3
4 5 6

Po obrocie:

4 1
5 2
6 3
```

---

# Część V: liczby pseudolosowe, funkcje i `enum`

## 22. Statystyki losowej tablicy

Program pobiera:

```text
ziarno
N
zakres
```

i tworzy dynamiczną tablicę liczb pseudolosowych z zakresu:

```text
0 ... zakres - 1
```

Napisz osobne funkcje obliczające:

- sumę,
- średnią,
- liczbę elementów parzystych,
- liczbę elementów większych od średniej.

Tablicę przekazuj jako:

```cpp
int*
```

---

## 23. Filtrowanie według `enum`

Zdefiniuj:

```cpp
enum class Warunek {
    PARZYSTA,
    NIEPARZYSTA,
    DODATNIA,
    UJEMNA
};
```

Napisz funkcję:

```cpp
void wypisz_warunkowo(int* tab, int n, Warunek w);
```

która wypisuje tylko elementy spełniające wybrany warunek.

Program powinien wywołać tę samą funkcję dla wszystkich czterech wariantów.

---

## 24. Liczby trójkątne

Liczby trójkątne mają postać:

```text
1, 3, 6, 10, 15, 21, 28, ...
```

ponieważ:

```text
T(n) = 1 + 2 + ... + n
```

Napisz funkcję:

```cpp
bool czy_trojkatna(int x);
```

a następnie program, który w losowej tablicy wypisuje tylko liczby trójkątne.

---

# Część VI: tekst i napisy

## 25. Liczenie słów

Napisz program, który wczytuje całą linię tekstu i oblicza liczbę słów.

Zakładamy, że słowa są oddzielone pojedynczymi spacjami.

### Przykład

```text
Tekst: Ala ma kota i psa
Liczba slow: 5
```

---

## 26. Odwracanie słów, ale nie całego zdania

Napisz program, który odwraca kolejność znaków w każdym słowie, ale pozostawia kolejność słów bez zmian.

### Przykład

```text
Tekst: Ala ma kota
Wynik: alA am atok
```

Możesz użyć `string`.

---

## 27. Liczenie wielkich i małych liter

Napisz program, który wczyta linię tekstu i policzy osobno:

- małe litery ASCII,
- wielkie litery ASCII,
- cyfry,
- spacje.

Skorzystaj z funkcji z `<cctype>`.

---

## 28. Zamiana wybranych polskich znaków UTF-8

Napisz program pracujący na tablicy:

```cpp
char tekst[1000];
```

Program ma zamieniać:

```text
ł -> Ł
ą -> Ą
ć -> Ć
```

pozostawiając pozostałe znaki bez zmian.

Załóż kodowanie UTF-8.

W tym zadaniu należy świadomie analizować kolejne bajty napisu.

---

# Część VII: `const char*`

## 29. Nazwa miesiąca

Napisz funkcję:

```cpp
const char* miesiac(int nr);
```

która dla numeru `1-12` zwraca nazwę miesiąca.

Dla wartości spoza zakresu zwróć:

```text
"nieprawidlowy"
```

Funkcja nie może wykonywać `cout`.

---

## 30. Ocena słownie

Napisz funkcję:

```cpp
const char* ocena(int n);
```

która dla wartości:

```text
2, 3, 4, 5
```

zwraca odpowiednio nazwę oceny słownie.

Nie używaj `string` jako typu zwracanego.

---

## 31. Dzień tygodnia z przesunięciem

Napisz funkcję:

```cpp
const char* dzien(int nr);
```

oraz program, który pobiera numer dnia tygodnia i przesunięcie `k`.

Program ma wypisać nazwę dnia występującego `k` dni później.

Przećwicz:

- `const char*`,
- modulo,
- funkcje.

---

# Część VIII: palindromy i typy całkowite

## 32. Palindrom bez tablicy

Napisz funkcję:

```cpp
bool czy_palindrom(unsigned long long int n);
```

Nie używaj:

- `string`,
- tablic znaków,
- tablic cyfr.

Wykorzystaj działania arytmetyczne.

---

## 33. Największy palindrom mniejszy od N

Program pobiera dodatnią liczbę `N` typu:

```cpp
unsigned long long int
```

i wyszukuje największy palindrom:

```text
< N
```

### Przykład

```text
N: 1300
Palindrom: 1221
```

---

## 34. Rozmiar i zakres typu

Napisz program wypisujący dla typów:

```cpp
signed char
unsigned char
signed short
unsigned short
signed int
unsigned int
```

następujące informacje:

```text
rozmiar w bajtach
minimum
maksimum
```

Skorzystaj z:

```cpp
sizeof
```

oraz:

```cpp
numeric_limits
```

---

# Część IX: argumenty programu i pliki

## 35. Wypisywanie argumentów programu

Napisz program, który wypisze:

- liczbę argumentów `argc`,
- każdy argument wraz z jego numerem.

Przykładowe uruchomienie:

```text
./program jeden dwa trzy
```

Program powinien pokazać również:

```cpp
argv[0]
```

---

## 36. Liczba linii w pliku

Ścieżkę do pliku pobierz jako:

```cpp
argv[1]
```

Program ma policzyć liczbę linii w pliku.

Uwzględnij:

- za małą liczbę argumentów,
- błąd otwarcia pliku.

---

## 37. Najdłuższa linia pliku

Program pobiera ścieżkę do pliku jako argument programu.

Wypisz:

- numer najdłuższej linii,
- jej długość,
- jej treść.

Zakładamy maksymalnie 300 znaków w linii.

---

## 38. Wyszukiwanie jednego wzorca

Uruchomienie:

```text
./program plik.txt wzorzec
```

Program wypisuje numery wszystkich linii zawierających podany wzorzec.

### Przykładowy format

```text
Znaleziono w liniach:
3
8
11
```

---

## 39. Wyszukiwanie wielu wzorców

Rozszerz poprzednie zadanie tak, aby program obsługiwał dowolną liczbę wzorców:

```text
./program plik.txt kot pies dom
```

Dla każdego wzorca wypisz osobną sekcję z pasującymi liniami.

---

## 40. Statystyka słowa w pliku

Program przyjmuje:

```text
argv[1] -> plik
argv[2] -> wzorzec
```

Następnie oblicza:

- ile linii zawiera wzorzec,
- ile łącznie razy wzorzec występuje w całym pliku.

Uwaga:

Jedna linia może zawierać ten sam wzorzec kilka razy.

---

# Część X: zadania przekrojowe

## 41. Analiza dynamicznej tablicy

Napisz program, który:

1. pobiera `N`,
2. dynamicznie tworzy tablicę,
3. wczytuje jej elementy,
4. przez osobne funkcje wyznacza:
   - minimum,
   - maksimum,
   - sumę,
   - liczbę liczb pierwszych,
5. rekurencyjnie znajduje maksimum drugi raz,
6. wypisuje wyniki.

Wymaganie:

Wszystkie funkcje analizujące tablicę mają przyjmować:

```cpp
int* tab
```

---

## 42. Rekurencja + wskaźniki

Napisz funkcję:

```cpp
int suma_rek(int* p, int n);
```

która rekurencyjnie sumuje `n` kolejnych elementów tablicy zaczynając od elementu wskazywanego przez `p`.

Nie używaj:

- `[]`,
- żadnej pętli.

---

## 43. Rekurencyjne wypisywanie tablicy od końca

Napisz funkcję:

```cpp
void wypisz_od_konca(int* tab, int n);
```

która rekurencyjnie wypisuje elementy tablicy w odwrotnej kolejności.

Nie wolno:

- modyfikować tablicy,
- tworzyć drugiej tablicy,
- używać pętli.

---

## 44. Macierz i wskaźniki

Dynamicznie utwórz macierz `N x M`.

Napisz funkcję:

```cpp
int suma_przekatnej(int** tab, int n);
```

dla macierzy kwadratowej.

Następnie napisz drugą funkcję obliczającą sumę drugiej przekątnej.

---

## 45. Mini-projekt: analiza pliku liczbowego

Program otrzymuje jako argument ścieżkę do pliku.

W pliku znajduje się maksymalnie 200 liczb całkowitych, po jednej w każdym wierszu.

Program powinien:

1. wczytać liczby do dynamicznej tablicy,
2. wypisać minimum i maksimum,
3. policzyć sumę,
4. policzyć liczby pierwsze,
5. wypisać palindromy,
6. rekurencyjnie obliczyć sumę wszystkich elementów.

Podziel program na funkcje.

---

# Zadania szczególnie polecane przed kolokwium

Jeżeli nie masz czasu zrobić całego zestawu, wykonaj przynajmniej:

```text
4   NWD
6   Potęga rekurencyjnie
7   Suma cyfr rekurencyjnie
10  Maksimum rekurencyjnie
11  Wyszukiwanie binarne rekurencyjnie
12  Tablica bez []
14  Minimum i maksimum przez wskaźniki
15  Odwracanie tablicy wskaźnikami
18  Dynamiczna macierz
22  Statystyki losowej tablicy
23  enum
28  UTF-8
29  const char*
32  Palindrom
34  sizeof i numeric_limits
38  Wyszukiwanie wzorca w pliku
42  Rekurencja + wskaźniki
```

---

# Wskazówki organizacyjne

Przy każdym zadaniu warto najpierw odpowiedzieć sobie na pytania:

```text
Jakie dane muszę wczytać?
Jakiego typu powinny być zmienne?
Czy potrzebuję tablicy?
Czy rozmiar tablicy znam przed uruchomieniem programu?
Czy zadanie wymaga dynamicznej pamięci?
Czy funkcja ma coś zwrócić przez return?
Czy wynik powinien zostać przekazany przez wskaźnik?
Jaki jest przypadek bazowy rekurencji?
Czy każde wywołanie rekurencyjne zbliża się do przypadku bazowego?
Czy mogę wyjść poza zakres tablicy?
Czy muszę zwolnić pamięć przez delete[]?
```

W zadaniach z automatycznym testerem należy również zwracać uwagę na dokładny format wejścia i wyjścia.
