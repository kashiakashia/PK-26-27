# Laboratorium 08: wskaźniki, liczby pseudolosowe, funkcje i `enum`

Na tym laboratorium będziemy łączyć kilka poznanych wcześniej zagadnień i wykorzystywać je w bardziej modularnych programach.

Najważniejsze tematy:

- generowanie liczb pseudolosowych,
- `rand()` i `srand()`,
- ziarno generatora,
- operator modulo `%`,
- tablice jednowymiarowe,
- dostęp do elementów tablicy przez wskaźniki,
- arytmetyka wskaźników,
- przechodzenie po tablicy bez operatora `[]`,
- pętle `while` i `do...while`,
- przekazywanie tablic do funkcji jako `int*`,
- funkcje zwracające wartość,
- funkcje modyfikujące dane przekazane przez wskaźnik,
- wyszukiwanie maksimum i minimum,
- sumowanie elementów,
- liczby pierwsze,
- sprawdzanie własności liczby,
- typ wyliczeniowy `enum`.

Przykłady w tym materiale pokazują mechanizmy potrzebne do rozwiązania zadań. Nie są gotowymi rozwiązaniami zadań laboratoryjnych.

---

# Część I: liczby pseudolosowe

## 1. Co oznacza liczba pseudolosowa?

Komputer nie losuje liczb w taki sam sposób jak rzut kostką. Funkcja:

```cpp
rand()
```

generuje kolejne liczby według określonego algorytmu. Dlatego mówimy o liczbach pseudolosowych.

Dla tego samego ustawienia początkowego generator może wygenerować ten sam ciąg liczb.

---

## 2. `rand()` i `srand()`

Do korzystania z tych funkcji potrzebujemy:

```cpp
#include <cstdlib>
```

Funkcja:

```cpp
rand()
```

zwraca nieujemną liczbę całkowitą.

Natomiast:

```cpp
srand(ziarno);
```

ustawia stan początkowy generatora.

Przykład:

```cpp
srand(7);
```

---

## 3. Czym jest ziarno?

Ziarno, czyli `seed`, jest wartością początkową generatora liczb pseudolosowych.

Jeżeli program ponownie zostanie uruchomiony z tym samym ziarnem, w tym samym środowisku wykonawczym otrzymamy ten sam ciąg wartości.

To jest bardzo przydatne podczas testowania programu.

Schemat:

```text
ziarno
  ↓
srand(...)
  ↓
rand()
  ↓
kolejne liczby pseudolosowe
```

---

## 4. Losowanie z zakresu `[0, 100)`

Zapis:

```text
[0, 100)
```

oznacza:

```text
0 <= x < 100
```

czyli wartości:

```text
0, 1, 2, ..., 99
```

Możemy wykorzystać:

```cpp
rand() % 100
```

Reszta z dzielenia przez `100` może wynosić od `0` do `99`.

---

## 5. Losowanie z zakresu od `1` do `zakres`

Jeżeli chcemy wartości:

```text
1 ... zakres
```

używamy mechanizmu:

```cpp
rand() % zakres + 1
```

Najpierw:

```text
rand() % zakres
```

daje:

```text
0 ... zakres - 1
```

Po dodaniu `1`:

```text
1 ... zakres
```

---

## 6. Przykład dla zakresu 6

```cpp
rand() % 6
```

może dać:

```text
0 1 2 3 4 5
```

Natomiast:

```cpp
rand() % 6 + 1
```

może dać:

```text
1 2 3 4 5 6
```

---

## 7. Uwaga o modulo

Operator modulo jest tutaj używany zgodnie z treścią zadania.

Warto jednak wiedzieć, że:

```cpp
rand() % zakres
```

nie jest idealnym generatorem równomiernym dla każdego możliwego zakresu. Na tym laboratorium najważniejsze jest jednak zrozumienie działania `rand()`, `srand()` i `%`.

---

# Część II: tablica i wskaźnik

## 8. Nazwa tablicy jako adres pierwszego elementu

Dla:

```cpp
int tab[5];
```

nazwa:

```cpp
tab
```

może być używana jako adres pierwszego elementu tablicy.

Możemy to sobie wyobrazić:

```text
tab
 |
 v
+----+----+----+----+----+
|    |    |    |    |    |
+----+----+----+----+----+
  0    1    2    3    4
```

---

## 9. Wskaźnik do tablicy

Możemy utworzyć:

```cpp
int* p = tab;
```

Wtedy `p` wskazuje na pierwszy element tablicy.

Zapis:

```cpp
*p
```

oznacza wartość znajdującą się pod adresem `p`.

---

## 10. Operator `*`

Przykład:

```cpp
int liczba = 10;
int* p = &liczba;
```

Wtedy:

```cpp
p
```

przechowuje adres, a:

```cpp
*p
```

oznacza wartość spod tego adresu, czyli `10`.

---

## 11. Arytmetyka wskaźników

Jeżeli:

```cpp
int* p = tab;
```

to:

```cpp
p + 1
```

wskazuje na następny element tablicy.

A:

```cpp
p + 2
```

wskazuje dwa elementy dalej.

Schemat:

```text
p
|
v
[10] [20] [30] [40]

     p+1
      |
      v
[10] [20] [30] [40]

          p+2
           |
           v
[10] [20] [30] [40]
```

---

## 12. Dostęp do elementu bez `[]`

Zapis:

```cpp
tab[i]
```

jest równoważny:

```cpp
*(tab + i)
```

Przykładowo:

```cpp
tab[3]
```

i:

```cpp
*(tab + 3)
```

odnoszą się do tego samego elementu.

---

## 13. Dlaczego `*(tab + i)` działa?

Najpierw:

```cpp
tab + i
```

przesuwa adres o `i` elementów.

Następnie:

```cpp
*(tab + i)
```

odczytuje wartość spod otrzymanego adresu.

Czyli:

```text
tab
↓
przesunięcie o i elementów
↓
tab + i
↓
odczyt wartości
↓
*(tab + i)
```

---

# Część III: przechodzenie po tablicy bez `[]` i bez `for`

## 14. Można przesuwać sam wskaźnik

Zamiast używać indeksu, możemy przesuwać wskaźnik.

Przykład idei:

```cpp
int* p = tab;
```

Pierwszy element:

```cpp
*p
```

Po:

```cpp
p++;
```

wskaźnik wskazuje na następny element.

---

## 15. `while` zamiast `for`

Jeżeli w zadaniu nie wolno używać pętli `for`, można zastosować:

```cpp
while
```

Przykładowy neutralny schemat:

```cpp
int licznik = 0;

while (licznik < n) {

    // operacje

    licznik++;
}
```

---

## 16. Początek i koniec tablicy

Jeżeli:

```cpp
int* poczatek = tab;
```

to:

```cpp
int* koniec = tab + n;
```

wskazuje adres znajdujący się tuż za ostatnim elementem.

```text
początek
   |
   v
[ ][ ][ ][ ][ ]
               ^
               |
             koniec
```

`koniec` nie wskazuje na element tablicy. Nie wolno odczytywać:

```cpp
*koniec
```

---

## 17. Przechodzenie wskaźnikiem

Ogólna idea:

```cpp
int* p = tab;

while (p < tab + n) {

    // użyj *p

    p++;
}
```

W każdym obiegu `*p` oznacza kolejny element tablicy.

---

# Część IV: sąsiadujące elementy

## 18. Co oznacza para sąsiadujących elementów?

Dla tablicy:

```text
10 20 30 40
```

sąsiadujące pary to:

```text
10 20
20 30
30 40
```

---

## 19. Ile jest par?

Jeżeli tablica ma `n` elementów, liczba sąsiadujących par wynosi:

```text
n - 1
```

Przykład:

```text
5 elementów -> 4 pary
```

---

## 20. Para przez wskaźniki

Jeżeli `p` wskazuje na pierwszy element pary, to:

```cpp
*p
```

jest pierwszym elementem, a:

```cpp
*(p + 1)
```

jego prawym sąsiadem.

---

## 21. Trzeba zatrzymać się wcześniej

Jeżeli używamy:

```cpp
*(p + 1)
```

nie możemy dopuścić, aby `p` wskazywał na ostatni element, ponieważ `p + 1` znajdowałoby się już za tablicą.

---

# Część V: formatowanie wyniku

## 22. `setw(6)`

Do ustawiania szerokości pola używamy:

```cpp
#include <iomanip>
```

oraz:

```cpp
setw(6)
```

Przykład:

```cpp
cout << setw(6) << 25;
```

`setw(6)` działa tylko na następny wypisywany element.

---

# Część VI: tablice jako parametry funkcji

## 23. Dlaczego w funkcji pojawia się `int* tab`?

Dla funkcji:

```cpp
void wypisz(int* tab, int n)
```

parametr:

```cpp
int* tab
```

jest adresem początku tablicy, a:

```cpp
int n
```

mówi, ile elementów należy analizować.

---

## 24. Funkcja nie dostaje kopii całej tablicy

Funkcja operuje na pamięci istniejącej tablicy.

Dlatego może również zmieniać jej elementy.

Przykład neutralny:

```cpp
void wyzeruj(int* tab, int n) {

    int i = 0;

    while (i < n) {
        *(tab + i) = 0;
        i++;
    }
}
```

---

## 25. `int tab[]` i `int* tab`

W parametrze funkcji zapis:

```cpp
void funkcja(int tab[], int n)
```

jest w praktyce odpowiednikiem:

```cpp
void funkcja(int* tab, int n)
```

W obu przypadkach funkcja otrzymuje dostęp do początku tablicy.

---

## 26. Funkcja zwracająca jedną wartość

Jeżeli funkcja oblicza pojedynczy wynik, może go zwrócić przez `return`.

Przykład ogólnej idei:

```cpp
int policz(int* tab, int n) {

    int wynik = 0;

    // analiza tablicy

    return wynik;
}
```

---

# Część VII: maksimum, minimum i suma

## 27. Maksimum

Najbezpieczniej przyjąć pierwszy element jako aktualne maksimum.

Schemat:

```text
maksimum = pierwszy element

sprawdź kolejne elementy

jeżeli element > maksimum
    maksimum = element
```

Przykład:

```text
8 3 12 4 10
```

Kolejne wartości maksimum:

```text
8
8
12
12
12
```

---

## 28. Minimum

Analogicznie:

```text
minimum = pierwszy element

jeżeli element < minimum
    minimum = element
```

---

## 29. Suma

Do sumowania używamy akumulatora:

```cpp
int suma = 0;
```

Następnie dodajemy kolejne elementy.

Zaczynamy od `0`, ponieważ:

```text
0 + liczba = liczba
```

---

# Część VIII: liczby pierwsze

## 30. Definicja liczby pierwszej

Liczba pierwsza to liczba naturalna większa od `1`, która ma dokładnie dwa dodatnie dzielniki:

```text
1
```

i samą siebie.

Przykłady:

```text
2 3 5 7 11 13
```

---

## 31. `0` i `1` nie są pierwsze

To ważny przypadek szczególny:

```text
0 -> nie jest pierwsza
1 -> nie jest pierwsza
2 -> jest pierwsza
```

---

## 32. Jak sprawdzić pierwszość?

Szukamy dzielnika innego niż `1` i sama liczba.

Przykład dla `15`:

```text
15 % 2 != 0
15 % 3 == 0
```

Znaleźliśmy dzielnik `3`, więc `15` nie jest liczbą pierwszą.

---

## 33. Wystarczy sprawdzać do pierwiastka

Nie trzeba sprawdzać wszystkich liczb aż do `n - 1`.

Wystarczy sprawdzać potencjalne dzielniki do:

```text
sqrt(n)
```

Jeżeli liczba ma dzielnik większy od pierwiastka, drugi dzielnik musi być mniejszy od pierwiastka.

---

# Część IX: tablica wynikowa

## 34. Tablica źródłowa i wynikowa

Możemy mieć tablicę źródłową:

```text
tab
```

oraz drugą tablicę:

```text
pierwsze
```

Przykład idei:

```text
tab:
8 5 12 7 9 11

analiza
   ↓

pierwsze:
5 7 11
```

---

## 35. Po co osobny licznik?

Potrzebujemy wiedzieć, ile elementów zostało zapisanych do tablicy wynikowej.

Schemat:

```text
ile = 0

znaleziono wartość
↓
zapisz do tablicy wynikowej
↓
ile++
```

Na końcu funkcja może zwrócić:

```cpp
return ile;
```

---

## 36. Co oznacza sygnatura funkcji zapisującej wyniki?

Jeżeli funkcja ma postać:

```cpp
int funkcja(int* tab, int n, int* wynik)
```

to może jednocześnie:

```text
1. czytać tablicę tab
2. zapisywać wybrane wartości do tablicy wynik
3. zwrócić liczbę zapisanych wartości
```

To jest ważne rozróżnienie:

```text
tablica wynikowa -> przechowuje znalezione wartości
return            -> mówi, ile ich znaleziono
```

---

# Część X: `enum`

## 37. Co to jest `enum`?

`enum` to typ wyliczeniowy.

Pozwala nadać czytelne nazwy określonym wariantom.

Przykład:

```cpp
enum Kierunek {
    LEWO,
    PRAWO,
    GORA,
    DOL
};
```

Możemy później utworzyć:

```cpp
Kierunek kierunek;
```

---

## 38. Po co `enum`?

Zamiast zapisywać:

```text
0 = opcja pierwsza
1 = opcja druga
2 = opcja trzecia
```

możemy użyć nazw.

Kod jest wtedy bardziej czytelny i mniej podatny na pomyłki.

---

## 39. `enum` i `switch`

Typ wyliczeniowy dobrze współpracuje z instrukcją:

```cpp
switch
```

Ogólny schemat:

```cpp
switch (w) {

    case OPCJA_A:
        // działanie A
        break;

    case OPCJA_B:
        // działanie B
        break;
}
```

---

# Część XI: sprawdzanie własności liczby

## 40. Kwadraty liczb naturalnych

Kwadraty:

```text
0 1 4 9 16 25 36 49 64 81 100 ...
```

Przykład:

```text
25 = 5²
```

Liczba `26` nie jest kwadratem liczby naturalnej.

---

## 41. Jak sprawdzić kwadrat?

Można wykorzystać pierwiastek:

```text
sqrt(x)
```

Jeżeli pierwiastek jest liczbą całkowitą, `x` jest kwadratem.

Do `sqrt()` potrzebujemy:

```cpp
#include <cmath>
```

Można też generować kolejne:

```text
0², 1², 2², 3², ...
```

i porównywać z badaną liczbą.

---

## 42. Sześciany

Sześciany liczb naturalnych:

```text
0 1 8 27 64 125 ...
```

Przykład:

```text
27 = 3³
```

Można generować kolejne wartości:

```text
k * k * k
```

i sprawdzać, czy otrzymamy badaną liczbę.

---

## 43. Silnie

Początkowe wartości:

```text
0! = 1
1! = 1
2! = 2
3! = 6
4! = 24
5! = 120
```

Aby sprawdzić, czy liczba jest silnią, można generować kolejne wartości:

```text
1
2
6
24
120
...
```

Jeżeli trafimy na badaną wartość, liczba jest silnią.

Jeżeli ją przekroczymy, nie jest.

---

## 44. Przykład sprawdzania silni

Dla:

```text
24
```

kolejne iloczyny:

```text
1
1 * 2 = 2
2 * 3 = 6
6 * 4 = 24
```

więc:

```text
24 = 4!
```

Dla `20` przejdziemy z `6` do `24`, więc `20` nie jest silnią.

---

# Część XII: Fibonacci

## 45. Ciąg Fibonacciego

Początek:

```text
0 1 1 2 3 5 8 13 21 34 55 89 ...
```

Każdy kolejny element jest sumą dwóch poprzednich.

---

## 46. Jak sprawdzić, czy liczba należy do ciągu?

Jedna z prostych metod:

```text
zacznij od 0 i 1
↓
generuj kolejne elementy
↓
porównuj z badaną liczbą
```

Jeżeli trafimy dokładnie na badaną wartość, liczba należy do ciągu.

Jeżeli kolejny wyraz stanie się większy, liczba nie należy do ciągu.

---

## 47. Przykład

Sprawdzamy `34`:

```text
0 1 1 2 3 5 8 13 21 34
```

Otrzymaliśmy `34`, więc liczba należy do ciągu.

Dla `30`:

```text
... 21 34
```

przechodzimy z wartości mniejszej od `30` do większej, więc `30` nie należy do ciągu.

---

# Część XIII: jedna funkcja, różne warunki

## 48. Idea funkcji warunkowej

Funkcja może otrzymać:

```text
tablicę
rozmiar
warunek
```

i dla każdego elementu sprawdzić inny rodzaj własności.

Ogólny schemat:

```cpp
void funkcja(int* tab, int n, Warunek w) {

    // przejdź po elementach
    // sprawdź warunek w
    // wypisz tylko pasujące wartości
}
```

---

## 49. Warto tworzyć małe funkcje sprawdzające

Przykład neutralny:

```cpp
bool czyParzysta(int liczba) {
    return liczba % 2 == 0;
}
```

Typ:

```cpp
bool
```

zwraca:

```text
true
```

albo:

```text
false
```

Taki podział może znacznie poprawić czytelność większego programu.

---

# Część XIV: organizacja programu

## 50. Nie wszystko powinno znajdować się w `main`

W większym programie warto rozdzielić obowiązki.

Schemat:

```text
main
 |
 +-- wczytanie danych
 |
 +-- przygotowanie tablic
 |
 +-- wywołanie funkcji
 |
 +-- prezentacja wyników
 |
 +-- zwolnienie pamięci
```

---

## 51. Prototypy funkcji

Jeżeli funkcję definiujemy pod `main`, przed `main` umieszczamy prototyp.

Przykład:

```cpp
int policz(int* tab, int n);
```

Później funkcję można wywołać w `main`, a jej pełną definicję umieścić niżej.

---

# Część XV: dynamiczna tablica

## 52. Rozmiar znany dopiero podczas działania programu

Jeżeli użytkownik podaje `n`, możemy utworzyć tablicę dynamicznie:

```cpp
int* tab = new int[n];
```

Po zakończeniu korzystania z tablicy:

```cpp
delete[] tab;
```

---

## 53. Druga tablica na wyniki

Jeżeli druga tablica ma przechowywać wybrane elementy pierwszej tablicy, jej maksymalny potrzebny rozmiar nie będzie większy od liczby elementów źródłowych.

Warto zawsze zadać sobie pytanie:

```text
jaki jest największy możliwy rozmiar wyniku?
```

---

# Część XVI: najczęstsze błędy

## 54. `rand()` i `srand()`

Sprawdź:

- czy `srand()` jest wywołane przed `rand()`,
- czy zakres jest zgodny z treścią zadania,
- czy dla `[0,100)` nie dodajesz `1`,
- czy dla `1 ... zakres` pamiętasz o `+1`.

---

## 55. Wskaźniki

Sprawdź:

- czy wskaźnik wskazuje na poprawny element,
- czy nie przeszedłeś poza koniec tablicy,
- czy `*p` oznacza wartość, a `p` adres,
- czy `p++` przesuwa wskaźnik na kolejny element,
- czy nie dereferencjonujesz `tab + n`.

---

## 56. Pary sąsiadów

Dla tablicy `n` elementów istnieje:

```text
n - 1
```

par.

Nie twórz pary z ostatniego elementu i pamięci znajdującej się za tablicą.

---

## 57. Maksimum i minimum

Nie inicjalizuj ich bezmyślnie wartością `0`.

Najbezpieczniej zacząć od pierwszego elementu analizowanej tablicy.

---

## 58. Liczby pierwsze

Pamiętaj:

```text
0 -> nie
1 -> nie
2 -> tak
```

Znalezienie jednego właściwego dzielnika wystarcza do odrzucenia liczby.

---

## 59. Kwadraty, sześciany i silnie

Nie wpisuj na sztywno listy możliwych wartości.

Program powinien wynikać z definicji matematycznej:

```text
kwadrat  -> k * k
sześcian -> k * k * k
silnia   -> iloczyn kolejnych liczb
```

---

## 60. Funkcje

Sprawdź:

- czy sygnatura jest zgodna z treścią zadania,
- czy typ zwracany pasuje do `return`,
- czy `void` nie próbuje zwracać wartości,
- czy funkcja zna rozmiar tablicy,
- czy tablica wynikowa ma odpowiedni rozmiar.

W zadaniach testowanych automatycznie nazwa i sygnatura funkcji mogą mieć znaczenie.

---

# Część XVII: jak podejść do zadania pierwszego

## 61. Najpierw wypisz ograniczenia

W zadaniu nie wolno używać:

```text
[]
```

ani:

```text
for
```

To sugeruje użycie:

```text
wskaźników
+
while lub do...while
```

---

## 62. Podziel problem na etapy

```text
1. wczytaj ziarno
2. wczytaj N
3. utwórz tablicę
4. wypełnij ją liczbami pseudolosowymi
5. wypisz całą tablicę
6. wypisz sąsiadujące pary
7. zwolnij pamięć
```

---

## 63. Pytania kontrolne

Przed kodowaniem odpowiedz:

1. Jak utworzyć tablicę o rozmiarze podanym przez użytkownika?
2. Jak ustawić ziarno?
3. Jak uzyskać zakres `[0,100)`?
4. Jak przejść po tablicy bez `[]`?
5. Jak przejść bez `for`?
6. Jak odczytać aktualny element przez wskaźnik?
7. Jak odczytać sąsiada?
8. Kiedy zatrzymać pętlę przy parach?
9. Jak zastosować `setw(6)`?
10. Kiedy wykonać `delete[]`?

---

# Część XVIII: jak podejść do zadania drugiego

## 64. Zacznij od sygnatur funkcji

Treść zadania podaje konkretne funkcje.

Najpierw warto wypisać ich prototypy i dla każdej odpowiedzieć:

```text
co funkcja otrzymuje?
co funkcja zmienia?
co funkcja zwraca?
```

---

## 65. Funkcje testuj osobno

Najpierw sprawdź na małej tablicy:

```text
czy maksimum działa?
czy minimum działa?
czy suma działa?
czy sprawdzanie liczby pierwszej działa?
```

Dopiero później połącz wszystko w jeden program.

---

## 66. Funkcja zapisująca liczby pierwsze ma dwa wyniki

Taka funkcja może:

```text
1. zapisać znalezione liczby do tablicy wynikowej
2. zwrócić liczbę znalezionych elementów
```

To nie są te same informacje.

Przykład idei:

```text
pierwsze -> [5, 7, 11, ...]
return   -> 3
```

---

## 67. `enum` oddziela decyzję od przechodzenia po tablicy

Nie trzeba pisać czterech prawie identycznych pętli do przechodzenia po tablicy.

Można przejść po elementach w jednym miejscu, a różnicę ograniczyć do pytania:

```text
jaki warunek sprawdzamy dla aktualnej liczby?
```

---

# Podsumowanie

Po tym laboratorium warto rozumieć przede wszystkim:

### Generator pseudolosowy

```cpp
srand(ziarno);
rand();
```

oraz ograniczanie wyniku przez `%`.

### Tablica i wskaźnik

```cpp
tab[i]
```

można zapisać jako:

```cpp
*(tab + i)
```

### Przejście wskaźnikiem

```cpp
*p
p++
```

pozwala przechodzić po kolejnych elementach bez `[]`.

### Sąsiedzi

Jeżeli `p` wskazuje na pierwszy element pary, to:

```cpp
*p
```

i:

```cpp
*(p + 1)
```

są sąsiadami.

### Funkcje z tablicą

```cpp
void funkcja(int* tab, int n);
```

otrzymuje adres początku tablicy oraz jej rozmiar.

### Tablica wynikowa

Funkcja może zapisywać wyniki przez wskaźnik i jednocześnie zwrócić przez `return` liczbę zapisanych elementów.

### `enum`

Pozwala nazwać różne warianty działania programu i wygodnie połączyć je z `switch`.

### Warunki matematyczne

Program może rozpoznawać liczby na podstawie definicji:

```text
liczba pierwsza
kwadrat
sześcian
silnia
element ciągu Fibonacciego
```

Najlepiej wydzielać takie sprawdzenia do małych, czytelnych funkcji.