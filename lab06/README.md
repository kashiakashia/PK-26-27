# Laboratorium 06: funkcje, `do...while` i rekurencja

Na tym laboratorium rozwijamy materiał dotyczący funkcji oraz poznajemy rekurencję.

Będziemy pracować przede wszystkim z:

- definiowaniem własnych funkcji,
- przekazywaniem argumentów do funkcji,
- zwracaniem wartości za pomocą `return`,
- funkcjami typu `void`,
- wywoływaniem funkcji z programu głównego,
- pętlą `do...while`,
- rozbijaniem większego problemu na mniejsze funkcje,
- rekurencyjnym wywoływaniem funkcji,
- przypadkiem bazowym rekurencji,
- ciągami liczbowymi,
- konwersją liczb pomiędzy systemami liczbowymi.

Przykłady poniżej pokazują mechanizmy potrzebne do rozwiązania zadań z laboratorium.

Przykłady są jednak celowo inne niż zadania do samodzielnego wykonania.

---

## 1. Po co tworzymy funkcje?

Funkcja pozwala wydzielić fragment programu, który wykonuje określone zadanie.

Zamiast umieszczać cały kod w:

```cpp
int main()
```

możemy podzielić program na mniejsze części.

Przykład:

```cpp
int podwoj(int x) {
    return 2 * x;
}
```

Funkcja `podwoj` przyjmuje jedną liczbę typu `int` i zwraca liczbę typu `int`.

Możemy jej użyć:

```cpp
int wynik = podwoj(7);

cout << wynik << endl;
```

Wynik:

```text
14
```

---

## 2. Budowa funkcji

Ogólny zapis:

```cpp
typ_zwracany nazwa_funkcji(parametry) {

    // instrukcje

    return wynik;
}
```

Przykład:

```cpp
int kwadrat(int liczba) {

    int wynik = liczba * liczba;

    return wynik;
}
```

Poszczególne elementy:

```text
int          typ zwracanej wartości
kwadrat      nazwa funkcji
int liczba   parametr funkcji
return       zwrócenie wyniku
```

---

## 3. Wywołanie funkcji

Samo napisanie funkcji nie powoduje jeszcze jej wykonania.

Funkcję trzeba wywołać.

```cpp
int kwadrat(int liczba) {
    return liczba * liczba;
}

int main() {

    int x = 6;

    int wynik = kwadrat(x);

    cout << wynik << endl;

    return 0;
}
```

W tym przypadku:

```cpp
kwadrat(x)
```

powoduje wykonanie funkcji.

---

## 4. Parametr i argument

Rozważmy:

```cpp
int potroj(int x) {
    return 3 * x;
}
```

W definicji:

```cpp
int x
```

jest **parametrem**.

Natomiast w:

```cpp
potroj(5)
```

wartość:

```text
5
```

jest **argumentem przekazanym do funkcji**.

---

## 5. Funkcja z kilkoma parametrami

Funkcja może przyjmować więcej niż jeden parametr.

```cpp
int suma(int a, int b) {
    return a + b;
}
```

Wywołanie:

```cpp
int wynik = suma(4, 7);
```

Wynik:

```text
11
```

---

## 6. Typ zwracany przez funkcję

Jeżeli funkcja ma zwracać liczbę całkowitą:

```cpp
int funkcja(...)
```

Jeżeli wynik ma być liczbą rzeczywistą:

```cpp
float funkcja(...)
```

lub:

```cpp
double funkcja(...)
```

Przykład:

```cpp
float srednia(float a, float b) {
    return (a + b) / 2.0f;
}
```

---

## 7. `return`

Instrukcja:

```cpp
return
```

zwraca wynik funkcji.

Przykład:

```cpp
int wieksza(int a, int b) {

    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}
```

Po wykonaniu `return` funkcja kończy działanie.

---

## 8. Funkcja typu `void`

Nie każda funkcja musi zwracać wartość.

Jeżeli funkcja ma tylko wykonać pewne instrukcje, możemy użyć:

```cpp
void
```

Przykład:

```cpp
void powitanie() {
    cout << "Witaj!" << endl;
}
```

Wywołanie:

```cpp
powitanie();
```

---

## 9. Funkcja `void` z parametrem

Funkcja `void` może przyjmować parametry.

```cpp
void pokazLiczbe(int x) {
    cout << "Liczba: " << x << endl;
}
```

Wywołanie:

```cpp
pokazLiczbe(12);
```

Wynik:

```text
Liczba: 12
```

Funkcja niczego nie zwraca, ale wykonuje określone działanie.

---

## 10. Deklaracja funkcji przed `main`

Kompilator musi wiedzieć o istnieniu funkcji zanim zostanie ona wywołana.

Najprościej zdefiniować funkcję przed `main`:

```cpp
int podwoj(int x) {
    return 2 * x;
}

int main() {

    cout << podwoj(4) << endl;

    return 0;
}
```

---

## 11. Prototyp funkcji

Możemy również najpierw podać samą deklarację funkcji:

```cpp
int podwoj(int);
```

a definicję umieścić później.

Przykład:

```cpp
#include <iostream>

using namespace std;

int podwoj(int);

int main() {

    cout << podwoj(4) << endl;

    return 0;
}

int podwoj(int x) {

    return 2 * x;
}
```

Zapis:

```cpp
int podwoj(int);
```

nazywamy **prototypem funkcji**.

---

## 12. Dlaczego warto dzielić program na funkcje?

Funkcje pomagają:

- podzielić duży problem na mniejsze części,
- uniknąć powtarzania kodu,
- poprawić czytelność programu,
- łatwiej testować poszczególne fragmenty,
- oddzielić obliczenia od wyświetlania wyników.

Przykładowo zamiast jednego bardzo długiego `main()` możemy mieć:

```text
main()
 |
 +-- wczytaj dane
 |
 +-- wywołaj funkcję
 |
 +-- odbierz wynik
 |
 +-- wyświetl wynik
```

---

## 13. Pętla `do...while`

Pętla:

```cpp
do {

    // instrukcje

}
while (warunek);
```

najpierw wykonuje instrukcje, a dopiero potem sprawdza warunek.

Oznacza to, że wykona się przynajmniej jeden raz.

Przykład:

```cpp
int x = 1;

do {

    cout << x << endl;

    x++;

}
while (x <= 4);
```

Wynik:

```text
1
2
3
4
```

---

## 14. `do...while` wewnątrz funkcji

Pętla może znajdować się również wewnątrz funkcji.

Przykład:

```cpp
int pierwszaWiekszaWielokrotnosc(int liczba) {

    int wynik = 0;

    do {

        wynik += 4;

    }
    while (wynik <= liczba);

    return wynik;
}
```

Dla:

```text
liczba = 10
```

kolejne wartości to:

```text
4
8
12
```

Pierwszą wartością większą od `10` jest `12`.

Ten przykład pokazuje sam mechanizm wyszukiwania pierwszej wartości większej od podanej.

---

## 15. Aktualizacja dwóch poprzednich wartości

Niektóre ciągi liczbowe powstają na podstawie wcześniejszych elementów.

Możemy wtedy przechowywać dwie poprzednie wartości.

Przykładowy schemat:

```cpp
int poprzednia = ...;
int aktualna = ...;

int nastepna = poprzednia + aktualna;

poprzednia = aktualna;
aktualna = nastepna;
```

Kolejność przypisań ma znaczenie.

Najpierw obliczamy `nastepna`, a dopiero później przesuwamy wcześniejsze wartości.

---

## 16. Śledzenie wartości zmiennych

Przy bardziej złożonej pętli warto rozpisać kolejne kroki.

Załóżmy:

```text
a = 2
b = 3
```

i w każdym obiegu:

```cpp
c = a + b;
a = b;
b = c;
```

Otrzymujemy:

```text
a = 2, b = 3

c = 5
a = 3
b = 5

c = 8
a = 5
b = 8

c = 13
a = 8
b = 13
```

Takie ręczne prześledzenie zmiennych pomaga znaleźć błędy w algorytmie.

---

## 17. Funkcje mogą wykonywać różne działania na tych samych danych

Przykład:

```cpp
float maksimum(float a, float b) {

    if (a > b) {
        return a;
    }

    return b;
}

float minimum(float a, float b) {

    if (a < b) {
        return a;
    }

    return b;
}
```

Program główny może zdecydować, którą funkcję wywołać.

---

## 18. Wybór funkcji na podstawie znaku

Możemy połączyć `char` z instrukcją `switch`.

Przykład:

```cpp
char operacja;

cin >> operacja;

switch (operacja) {

    case 'A':
        // wywołanie pierwszej funkcji
        break;

    case 'B':
        // wywołanie drugiej funkcji
        break;

    default:
        cout << "Niepoprawny wybor" << endl;
        break;
}
```

---

## 19. Wczytywanie działania w postaci `a operator b`

Operator może być przechowywany jako `char`.

Przykład:

```cpp
float a;
float b;
char znak;

cin >> a >> znak >> b;
```

Dla wejścia:

```text
7.5 + 2.5
```

zmienne otrzymają:

```text
a     = 7.5
znak  = '+'
b     = 2.5
```

Dla wejścia:

```text
7.5+2.5
```

operator `>>` również poprawnie rozdzieli liczbę, znak i kolejną liczbę.

---

## 20. Funkcja wykonująca pojedynczą operację

Przykład:

```cpp
float roznica(float a, float b) {
    return a - b;
}
```

Możemy wykonać:

```cpp
float wynik = roznica(8.0f, 3.0f);
```

---

## 21. Rozbijanie liczby na cyfry

Operator:

```cpp
%
```

pozwala pobrać ostatnią cyfrę liczby.

Przykład:

```cpp
int liczba = 347;

int ostatnia = liczba % 10;
```

otrzymamy:

```text
7
```

---

## 22. Usuwanie ostatniej cyfry

Dzielenie całkowite przez `10` pozwala usunąć ostatnią cyfrę.

```cpp
int liczba = 347;

liczba = liczba / 10;
```

wynik:

```text
34
```

---

## 23. Cyfra jedności

Dla dodatniej liczby:

```cpp
jednosci = liczba % 10;
```

Przykład:

```text
347 % 10 = 7
```

---

## 24. Cyfra dziesiątek

Możemy użyć:

```cpp
(liczba / 10) % 10
```

Przykład:

```text
347 / 10 = 34
34 % 10 = 4
```

Cyfra dziesiątek to:

```text
4
```

---

## 25. Cyfra setek

Dla liczby trzycyfrowej:

```cpp
liczba / 100
```

daje cyfrę setek.

Przykład:

```text
347 / 100 = 3
```

---

## 26. Liczby ujemne

Jeżeli program ma analizować cyfry liczby ujemnej, wygodnie jest najpierw zapamiętać znak, a następnie pracować na wartości dodatniej.

```cpp
if (liczba < 0) {

    cout << "minus ";

    liczba = -liczba;
}
```

---

## 27. Jedna funkcja może odpowiadać za jedną część liczby

Możemy utworzyć kilka funkcji typu `void`.

```cpp
void pierwszaCzesc(int x) {
    // wypisanie odpowiedniej części
}

void drugaCzesc(int x) {
    // wypisanie odpowiedniej części
}
```

Program główny decyduje, kiedy należy wywołać daną funkcję.

---

## 28. Funkcja a zakres zmiennej

Zmienna utworzona wewnątrz funkcji jest lokalna.

```cpp
void test() {

    int x = 5;

    cout << x << endl;
}
```

Poza funkcją `test()` zmienna `x` nie jest dostępna.

---

## 29. Rekurencja

Funkcja rekurencyjna to funkcja, która wywołuje samą siebie.

Przykład:

```cpp
void odliczanie(int n) {

    cout << n << endl;

    if (n > 0) {
        odliczanie(n - 1);
    }
}
```

Wywołanie:

```cpp
odliczanie(3);
```

powoduje:

```text
3
2
1
0
```

---

## 30. Przypadek bazowy

Każda poprawna funkcja rekurencyjna musi mieć warunek zakończenia.

Nazywamy go **przypadkiem bazowym**.

Przykład:

```cpp
int sumaDo(int n) {

    if (n == 0) {
        return 0;
    }

    return n + sumaDo(n - 1);
}
```

Przypadkiem bazowym jest:

```cpp
if (n == 0) {
    return 0;
}
```

Bez niego funkcja wywoływałaby samą siebie bez końca.

---

## 31. Jak działa rekurencja?

Dla:

```cpp
sumaDo(3)
```

otrzymujemy:

```text
sumaDo(3)
= 3 + sumaDo(2)

= 3 + 2 + sumaDo(1)

= 3 + 2 + 1 + sumaDo(0)

= 3 + 2 + 1 + 0

= 6
```

---

## 32. Rekurencja a stos wywołań

Każde wywołanie funkcji musi poczekać na wynik kolejnego wywołania.

```text
funkcja(3)
   ↓
funkcja(2)
   ↓
funkcja(1)
   ↓
funkcja(0)
```

Po osiągnięciu przypadku bazowego funkcje zaczynają zwracać wyniki w odwrotnej kolejności.

---

## 33. Rekurencyjne mnożenie kolejnych liczb

Ogólny przykład:

```cpp
long long iloczynDo(int n) {

    if (n == 1) {
        return 1;
    }

    return n * iloczynDo(n - 1);
}
```

Dla:

```text
n = 4
```

otrzymamy:

```text
4 * 3 * 2 * 1
```

---

## 34. Szczególny przypadek `0`

Przy algorytmach rekurencyjnych należy dokładnie sprawdzić przypadki graniczne.

Jeżeli dziedzina zadania obejmuje `0`, przypadek bazowy musi go poprawnie obsłużyć.

Nie należy zakładać automatycznie, że rekurencja zawsze kończy się na:

```cpp
n == 1
```

Czasem poprawnym przypadkiem bazowym będzie:

```cpp
n == 0
```

---

## 35. Rekurencyjny ciąg

Jeżeli element ciągu zależy od poprzednich elementów, funkcja może wywoływać się dla wcześniejszych indeksów.

Ogólny schemat:

```cpp
int ciag(int n) {

    if (n == 0) {
        return wartosc0;
    }

    if (n == 1) {
        return wartosc1;
    }

    return ciag(n - 1) + ciag(n - 2);
}
```

Potrzebujemy tutaj dwóch przypadków bazowych.

---

## 36. Dlaczego potrzebujemy dwóch przypadków bazowych?

Jeżeli wzór używa:

```cpp
n - 1
```

oraz:

```cpp
n - 2
```

musimy znać co najmniej dwa pierwsze elementy ciągu.

---

## 37. Koszt rekurencji

Rekurencja jest często bardzo czytelna, ale nie zawsze najbardziej wydajna.

Jeżeli funkcja wywołuje:

```cpp
funkcja(n - 1)
```

oraz:

```cpp
funkcja(n - 2)
```

liczba wywołań może szybko rosnąć.

Na tym etapie najważniejsze jest zrozumienie mechanizmu rekurencji i przypadku bazowego.

---

## 38. Systemy liczbowe

Liczbę możemy zapisać w różnych systemach pozycyjnych.

Przykładowe podstawy:

```text
2    system binarny
5    system piątkowy
7    system siódemkowy
8    system ósemkowy
10   system dziesiętny
16   system szesnastkowy
```

W systemie o podstawie `p` dostępne cyfry mają wartości od:

```text
0
```

do:

```text
p - 1
```

Przykładowo:

```text
system dwójkowy:       0, 1
system piątkowy:       0, 1, 2, 3, 4
system ósemkowy:       0, 1, 2, 3, 4, 5, 6, 7
system dziesiętny:     0, 1, 2, 3, 4, 5, 6, 7, 8, 9
system szesnastkowy:   0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F
```

---

## 39. Zamiana z systemu dziesiętnego na inny system

Aby zamienić liczbę dziesiętną na system o podstawie `p`:

1. dzielimy liczbę całkowicie przez `p`,
2. zapisujemy resztę z dzielenia,
3. otrzymany iloraz ponownie dzielimy przez `p`,
4. powtarzamy, aż iloraz będzie równy `0`,
5. zapisane reszty czytamy **od dołu do góry**.

Schemat:

```text
liczba / podstawa = iloraz, reszta
iloraz / podstawa = nowy iloraz, reszta
...
```

W C++ odpowiadają temu operacje:

```cpp
liczba / podstawa
```

oraz:

```cpp
liczba % podstawa
```

---

## 40. Przykład: system dziesiętny → system dwójkowy

Zamieńmy:

```text
45₁₀
```

na system dwójkowy.

Dzielimy kolejno przez `2`:

```text
45 / 2 = 22 reszty 1
22 / 2 = 11 reszty 0
11 / 2 =  5 reszty 1
 5 / 2 =  2 reszty 1
 2 / 2 =  1 reszty 0
 1 / 2 =  0 reszty 1
```

Reszty powstały w kolejności:

```text
1 0 1 1 0 1
```

ale należy je przeczytać **od dołu do góry**:

```text
1 0 1 1 0 1
```

czyli:

```text
45₁₀ = 101101₂
```

### Sprawdzenie

Każda pozycja w systemie dwójkowym odpowiada kolejnej potędze liczby `2`:

```text
101101₂
```

czyli:

```text
1 * 2⁵ +
0 * 2⁴ +
1 * 2³ +
1 * 2² +
0 * 2¹ +
1 * 2⁰
```

Obliczamy:

```text
1 * 32 +
0 * 16 +
1 * 8 +
1 * 4 +
0 * 2 +
1 * 1
```

czyli:

```text
32 + 8 + 4 + 1 = 45
```

Zatem:

```text
101101₂ = 45₁₀
```

---

## 41. Przykład: system dziesiętny → system piątkowy

Zamieńmy:

```text
83₁₀
```

na system o podstawie `5`.

Dzielimy przez `5`:

```text
83 / 5 = 16 reszty 3
16 / 5 =  3 reszty 1
 3 / 5 =  0 reszty 3
```

Reszty czytamy od dołu:

```text
313
```

czyli:

```text
83₁₀ = 313₅
```

### Sprawdzenie

```text
313₅
=
3 * 5² +
1 * 5¹ +
3 * 5⁰
```

czyli:

```text
3 * 25 + 1 * 5 + 3 * 1
= 75 + 5 + 3
= 83
```

---

## 42. Przykład: system dziesiętny → system ósemkowy

Zamieńmy:

```text
83₁₀
```

na system ósemkowy.

```text
83 / 8 = 10 reszty 3
10 / 8 =  1 reszty 2
 1 / 8 =  0 reszty 1
```

Czytamy reszty od końca:

```text
123
```

więc:

```text
83₁₀ = 123₈
```

Sprawdzenie:

```text
123₈
=
1 * 8² +
2 * 8¹ +
3 * 8⁰
```

czyli:

```text
64 + 16 + 3 = 83
```

---

## 43. Przykład: system dziesiętny → system szesnastkowy

W systemie szesnastkowym mamy więcej niż 10 cyfr.

Stosujemy oznaczenia:

```text
10 -> A
11 -> B
12 -> C
13 -> D
14 -> E
15 -> F
```

Zamieńmy:

```text
123₁₀
```

na system szesnastkowy.

Dzielimy przez `16`:

```text
123 / 16 = 7 reszty 11
  7 / 16 = 0 reszty 7
```

Reszta:

```text
11
```

w systemie szesnastkowym jest zapisywana jako:

```text
B
```

Czytamy więc od dołu:

```text
7B
```

czyli:

```text
123₁₀ = 7B₁₆
```

### Sprawdzenie

```text
7B₁₆
=
7 * 16¹ +
B * 16⁰
```

Ponieważ:

```text
B = 11
```

otrzymujemy:

```text
7 * 16 + 11 * 1
= 112 + 11
= 123
```

---

## 44. Zamiana z dowolnego systemu na system dziesiętny

Konwersję możemy wykonywać również w drugą stronę.

Jeżeli liczba jest zapisana w systemie o podstawie `p`, każdą cyfrę mnożymy przez odpowiednią potęgę podstawy.

Pozycje liczymy od prawej strony, zaczynając od potęgi `0`.

Przykładowo dla liczby:

```text
abc
```

w systemie o podstawie `p`:

```text
abcₚ
=
a * p² +
b * p¹ +
c * p⁰
```

---

## 45. Przykład: system dwójkowy → system dziesiętny

Zamieńmy:

```text
11010₂
```

na system dziesiętny.

Rozpisujemy kolejne potęgi:

```text
1 * 2⁴ +
1 * 2³ +
0 * 2² +
1 * 2¹ +
0 * 2⁰
```

czyli:

```text
1 * 16 +
1 * 8 +
0 * 4 +
1 * 2 +
0 * 1
```

otrzymujemy:

```text
16 + 8 + 2 = 26
```

Zatem:

```text
11010₂ = 26₁₀
```

---

## 46. Przykład: system siódemkowy → system dziesiętny

Zamieńmy:

```text
234₇
```

na system dziesiętny.

```text
234₇
=
2 * 7² +
3 * 7¹ +
4 * 7⁰
```

czyli:

```text
2 * 49 +
3 * 7 +
4 * 1
```

otrzymujemy:

```text
98 + 21 + 4 = 123
```

Zatem:

```text
234₇ = 123₁₀
```

---

## 47. Przykład: system szesnastkowy → system dziesiętny

Zamieńmy:

```text
2F₁₆
```

na system dziesiętny.

Pamiętamy, że:

```text
F = 15
```

Zatem:

```text
2F₁₆
=
2 * 16¹ +
15 * 16⁰
```

czyli:

```text
2 * 16 + 15
= 32 + 15
= 47
```

więc:

```text
2F₁₆ = 47₁₀
```

---

## 48. Dlaczego przy konwersji używamy `%` i `/`?

Dla liczby:

```cpp
liczba
```

i podstawy:

```cpp
podstawa
```

operacja:

```cpp
liczba % podstawa
```

daje ostatnią cyfrę liczby w nowym systemie.

Natomiast:

```cpp
liczba / podstawa
```

usuwa tę ostatnią część i pozwala przejść do kolejnego kroku.

Przykład dla:

```text
23₁₀ -> system piątkowy
```

pierwszy krok:

```text
23 % 5 = 3
23 / 5 = 4
```

drugi krok:

```text
4 % 5 = 4
4 / 5 = 0
```

Dostajemy reszty:

```text
3, 4
```

a wynik czytamy od końca:

```text
43₅
```

---

## 49. Dlaczego rekurencja dobrze pasuje do konwersji?

Przy kolejnych dzieleniach reszty otrzymujemy w odwrotnej kolejności.

Dla:

```text
23₁₀ -> 43₅
```

najpierw otrzymujemy:

```text
3
```

a dopiero potem:

```text
4
```

Gdybyśmy wypisywali reszty od razu, otrzymalibyśmy:

```text
34
```

zamiast:

```text
43
```

Rekurencja pozwala najpierw przejść do kolejnych ilorazów, a dopiero podczas powrotu wypisać reszty.

Schemat:

```text
23
↓ dziel przez 5
4
↓ dziel przez 5
0

powrót:
4
3
```

czyli:

```text
43
```

---

## 50. Rekurencyjny schemat konwersji

Ogólna idea może wyglądać tak:

```cpp
void wypisz(int liczba, int podstawa) {

    if (liczba >= podstawa) {
        wypisz(liczba / podstawa, podstawa);
    }

    int reszta = liczba % podstawa;

    // wypisanie reszty
}
```

Najważniejsza kolejność jest taka:

```text
najpierw wywołanie rekurencyjne
potem wypisanie reszty
```

Dzięki temu cyfry pojawiają się we właściwej kolejności.

---

## 51. Cyfry większe niż `9` bez użycia tablic

Dla podstaw mniejszych lub równych `10` możemy po prostu wypisać resztę:

```cpp
cout << reszta;
```

W systemie szesnastkowym wartości od `10` do `15` trzeba przedstawić za pomocą liter:

```text
10 -> A
11 -> B
12 -> C
13 -> D
14 -> E
15 -> F
```

Ponieważ na tym etapie nie korzystamy jeszcze z tablic, możemy użyć `switch`.

Przykład funkcji pomocniczej:

```cpp
void wypiszCyfre(int cyfra) {

    if (cyfra < 10) {
        cout << cyfra;
    }
    else {

        switch (cyfra) {

            case 10:
                cout << 'A';
                break;

            case 11:
                cout << 'B';
                break;

            case 12:
                cout << 'C';
                break;

            case 13:
                cout << 'D';
                break;

            case 14:
                cout << 'E';
                break;

            case 15:
                cout << 'F';
                break;
        }
    }
}
```

Funkcja ta odpowiada tylko za zamianę pojedynczej wartości:

```text
0 ... 15
```

na właściwy znak.

---

## 52. Jedna funkcja może obsługiwać wiele podstaw

Jeżeli algorytm zależy tylko od:

```text
liczby
```

oraz:

```text
podstawy
```

możemy przekazywać podstawę jako parametr funkcji.

Przykładowy prototyp:

```cpp
void wypiszSystem(int liczba, int podstawa);
```

Dzięki temu ten sam mechanizm można wykorzystać dla różnych podstaw.

Na przykład:

```text
podstawa = 2
podstawa = 5
podstawa = 7
podstawa = 8
podstawa = 16
```

Nie oznacza to, że trzeba pisać pięć osobnych algorytmów.

---

## 53. Funkcja iteracyjna a rekurencyjna

Ten sam problem często można rozwiązać na różne sposoby.

Iteracyjnie:

```cpp
for (...)
while (...)
do...while (...)
```

albo rekurencyjnie:

```cpp
funkcja(...)
{
    ...
    funkcja(...);
}
```

W zadaniu należy stosować metodę wymaganą w treści.

---

## 54. Najczęstsze błędy w funkcjach

Sprawdź:

- czy typ zwracany funkcji jest poprawny,
- czy liczba parametrów się zgadza,
- czy typy parametrów są właściwe,
- czy funkcja zwracająca wartość posiada `return`,
- czy nie próbujesz przypisać wyniku funkcji `void`,
- czy funkcja jest zadeklarowana przed użyciem,
- czy przekazujesz argumenty w odpowiedniej kolejności.

---

## 55. Najczęstsze błędy w rekurencji

Sprawdź:

- czy istnieje przypadek bazowy,
- czy rekurencja rzeczywiście zbliża się do przypadku bazowego,
- czy argument kolejnego wywołania jest mniejszy lub prostszy,
- czy poprawnie obsługujesz `0`,
- czy nie wywołujesz funkcji dla wartości niedozwolonych,
- czy wynik jest zwracany za pomocą `return`.

Błędny przykład:

```cpp
int funkcja(int n) {
    return funkcja(n);
}
```

Argument się nie zmienia, więc funkcja nigdy nie osiągnie końca.

---

## 56. Dokładny format wyjścia

Tak jak na wcześniejszych laboratoriach, zadania mogą być sprawdzane automatycznie.

Znaczenie mogą mieć:

- wielkie i małe litery,
- polskie znaki,
- spacje,
- dwukropki,
- liczba miejsc po przecinku,
- kolejność wypisywania danych,
- dokładna treść komunikatu.

---

## 57. Schemat programu wykorzystującego funkcję

```cpp
#include <iostream>

using namespace std;

int oblicz(int);

int main() {

    int x;

    cin >> x;

    int wynik = oblicz(x);

    cout << wynik << endl;

    return 0;
}

int oblicz(int x) {

    // obliczenia

    return x;
}
```

---

## 58. Schemat funkcji rekurencyjnej

```cpp
int funkcja(int n) {

    if (warunek_bazowy) {
        return wartosc_bazowa;
    }

    return /* działanie */ funkcja(/* prostszy argument */);
}
```

Najważniejsze są dwa elementy:

```text
przypadek bazowy
+
wywołanie dla prostszego problemu
```

---

## 59. Schemat pracy nad zadaniem z funkcją

Przed napisaniem kodu zastanów się:

1. Co funkcja ma otrzymać?
2. Jakiego typu są parametry?
3. Czy funkcja ma coś zwrócić?
4. Jaki powinien być typ zwracany?
5. Czy funkcja ma tylko coś wypisać?
6. Czy lepsze będzie `void`?
7. Gdzie funkcja zostanie wywołana?
8. Czy potrzebny jest prototyp?
9. Czy dane wymagają walidacji przed wywołaniem funkcji?
10. Czy zadanie wymaga konkretnej pętli?

---

## 60. Schemat pracy nad zadaniem rekurencyjnym

Przed napisaniem rekurencji odpowiedz na pytania:

1. Jaki jest najprostszy przypadek problemu?
2. Jaki wynik znam bez dalszych obliczeń?
3. To będzie przypadek bazowy.
4. Jak zmniejszyć problem?
5. Jak wywołać tę samą funkcję dla prostszego przypadku?
6. Czy każde kolejne wywołanie zbliża się do przypadku bazowego?
7. Co funkcja powinna zwrócić podczas powrotu?

Możemy myśleć:

```text
duży problem
    ↓
mniejszy problem
    ↓
jeszcze mniejszy problem
    ↓
przypadek bazowy
    ↓
powrót z wynikami
```

---

## 61. Co warto zapamiętać po tym laboratorium?

### Funkcja

```cpp
int funkcja(int x) {
    return ...;
}
```

przyjmuje argument i zwraca wynik.

### Funkcja `void`

```cpp
void funkcja(int x) {
    ...
}
```

wykonuje instrukcje, ale nie zwraca wartości.

### Pętla `do...while`

```cpp
do {
    ...
}
while (warunek);
```

wykona się co najmniej jeden raz.

### Rekurencja

```cpp
funkcja(n)
```

może wewnątrz wywołać:

```cpp
funkcja(n - 1)
```

ale musi istnieć przypadek bazowy.

### Rozbijanie liczby

```cpp
liczba % 10
```

pobiera ostatnią cyfrę, a:

```cpp
liczba / 10
```

usuwa ostatnią cyfrę.

### Zmiana systemu liczbowego

Korzystamy z:

```cpp
liczba % podstawa
```

oraz:

```cpp
liczba / podstawa
```

Rekurencja pozwala wypisać otrzymane cyfry w odpowiedniej kolejności.