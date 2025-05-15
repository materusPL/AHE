Zadania/Ćwiczenia z przedmiotu Podstawy Programowania I  


# Zadania 1


## Zadanie 1

Napisz program, który zapyta użytkownika o liczbę chłopców i dziewcząt zapisanych do klasy.  
Program powinien wyświetlać wartość procentową chłopców i dziewcząt w klasie.  

[C++](./Zadanie_1.1/zadanie1.cpp)  


## Zadanie 2

Kino przechowuje tylko pewien procent przychodu ze sprzedaży biletów. Reszta trafia do  
dystrybutora. Napisz program obliczający dochód kina i zysk kasy biletowej za dzień.  

Załóż, że kino zatrzymuje 20% zysku kasy biletowej  

Program powinien pytać ile zostało sprzedanych biletów dla dzieci i dorosłych. (Cena biletu dla  
dorosłych wynosi 10 zł, a dla dziecka 6 zł). Wyświetlony powinien zostać komunikat podobny do  
poniższego:  

    Sprzedane bilety dla dorosłych:
    
    Sprzedane bilety dla dzieci:
    
    Zysk kasy brutto:
    
    Zysk kasy netto:
    
    Kwota zapłacona dystrybutorowi: 

[C++](./Zadanie_1.1/zadanie2.cpp)  


## Zadanie 3

Zadeklarować trzy zmienne typu całkowitego. Wczytać dane. Obliczyć sumę tych liczb, ich średnią  
arytmetyczną i średnią harmoniczną. Wyświetlić wyniki.  

[C++](./Zadanie_1.1/zadanie3.cpp)  


## Zadanie 4

Rowerzysta pokonuje drogę o długości d w trzech etapach. Przez d oznaczono całą długość drogi  
przebytej przez rowerzystę. Przebyta droga i średnia prędkość w kolejnych etapach:  

    etap I 0,2 d 10 m/s
    
    etap II 0,5 d 5 m/s
    
    etap III 0,3 d 10 m/s

Należy napisać program obliczający całkowity czas jazdy rowerzysty. Wyniki przeliczyć na godziny,  
minuty, sekundy.  
Wczytać długość drogi d, wyświetlić wyniki.  

[C++](./Zadanie_1.1/zadanie4.cpp)  


# Zadania 2

Uwagi:  

-   Wszystkie zadania powinny być w jednym programie, kolejne zadania oddzielone liniami komentarza.
-   Program powinien czytelne wczytywanie danych i czytelne wypisywanie wyników.
-   W obliczeniach nie należy korzystać z  funkcji pow()
-   Stała pi – M<sub>PI</sub> należy dołączyć bibliotekę matematyczną #include <cmath>

[C++](./Zadanie_1.2/zadanie.cpp)  


## Zadanie 1

Wczytać dwie liczby typu całkowitego (x, y) i wypisać, która liczba jest większa a może są takie same.  
Sprawdzić czy x jest liczbą nieparzystą. Wypisać odpowiedni komunikat.  
Nie wykonywać działań, kiedy pierwsza wczytana liczba będzie zerem.  


## Zadanie 2

Obliczyć wartość funkcji określonej wzorem:  

$$
\large y(x) = \begin{cases} 
  \frac{3}{4} \cdot x^{3} \cdot \frac{7}{8} x & \text{dla x ∈ <-10, 0>} \\\\
  \frac{1}{sin(x) + 3} & \text{dla x ∈ (0, 4>} \\\\
  -2x/3  & \text{dla pozostałych}
\end{cases}
$$  

Dane: x – typu rzeczywistego  


## Zadanie 3

Napisać program pozwalający obliczyć  

1.  Objętość kuli (dane: R – promień kuli)
2.  Objętość walca (dane: promień podstawy walca, h – wysokość walca)
3.  Objętość stożka (dane: R – promień podstawy stożka, h – wysokość stożka)

W programie należy użyć struktury wielokrotnego wyboru switch.  
Obliczoną wartość wypisać na ekranie.  


## Zadanie 4

Firma kurierska pobiera opłaty zgodnie z poniższym cennikiem:  

<table border="2" cellspacing="0" cellpadding="6" rules="groups" frame="hsides">


<colgroup>
<col  class="org-left" />

<col  class="org-left" />
</colgroup>
<thead>
<tr>
<th scope="col" class="org-left">Waga paczki</th>
<th scope="col" class="org-left">Opłata za każde 100 km (zł)</th>
</tr>
</thead>
<tbody>
<tr>
<td class="org-left">2 kg lub mniej</td>
<td class="org-left">5,30</td>
</tr>

<tr>
<td class="org-left">Powyżej 2 kg, lecz nie więcej niż 6 kg</td>
<td class="org-left">6,20</td>
</tr>

<tr>
<td class="org-left">Powyżej 6 kg, lecz nie więcej niż 10 kg</td>
<td class="org-left">7,70</td>
</tr>

<tr>
<td class="org-left">Powyżej 10 kg, lecz nie więcej niż 20 kg</td>
<td class="org-left">10,80</td>
</tr>
</tbody>
</table>

Napisz program, który prosi o wpisanie wagi paczki i odległości, jaką musi przebyć przesyłka, a następnie wyświetli cenę.  
Weryfikacja poprawności wprowadzanych danych: program nie powinien przyjmować wagi paczki mniejszej lub równej 0 kg ani powyżej 20 kg (to największa waga paczki, jaką może przyjąć firma).  


# Zadania 3

Uwagi:  

-   Wszystkie punkty powinny być realizowane w jednym programie.
-   W programie należy użyć pętli for, while, do while. Nie powinno być w programie pętli nieskończonych. Nie  
    należy używać tablic. Nie używać funkcji pow
-   Czytelność komunikatów. Komunikaty powinny być krótkie, ale tak sformułowane, żeby nie było  
    wątpliwości, które zadanie jest wykonywane.

[C++](./Zadanie_1.3/zadanie.cpp)  


## Zadanie 1

Funkcja, który wyświetli tabliczkę mnożenia liczb od 1 do n w następującej postaci  

<table border="2" cellspacing="0" cellpadding="6" rules="groups" frame="hsides">


<colgroup>
<col  class="org-right" />

<col  class="org-right" />

<col  class="org-right" />

<col  class="org-right" />
</colgroup>
<thead>
<tr>
<th scope="col" class="org-right">&#xa0;</th>
<th scope="col" class="org-right">1</th>
<th scope="col" class="org-right">2</th>
<th scope="col" class="org-right">3</th>
</tr>
</thead>
<tbody>
<tr>
<td class="org-right">1</td>
<td class="org-right">1</td>
<td class="org-right">2</td>
<td class="org-right">3</td>
</tr>

<tr>
<td class="org-right">2</td>
<td class="org-right">2</td>
<td class="org-right">4</td>
<td class="org-right">6</td>
</tr>

<tr>
<td class="org-right">3</td>
<td class="org-right">3</td>
<td class="org-right">6</td>
<td class="org-right">9</td>
</tr>
</tbody>
</table>

n – należy wczytać, n <1, 10>.  
W tym przypadku n = 3.  


## Zadanie 2

Funkcja, która oblicza i zwraca średnią kilku liczb całkowitych przy założeniu, że ostatnia wczytana wartość  
jest znacznikiem 0. Przykładowa seria wejściowa może być  

    10 8 11 7 9 0

wskazując, że ma być wyliczona średnia wartości poprzedzających 0.  


## Zadanie 3

Funkcja, który oblicza i zwraca sumę S określoną wzorem:  

$$
\large {S = \sum^{m}_{k=0}} \frac{1+j}{2j^3 + 3}
$$  

Dane: m  


## Zadanie 4

Ten punkt powinien działać w pętli, bez funkcji  
Napisz program obliczający obłożenie hotelu. Program powinien wystartować, pytając użytkownika o  
nazwę hotelu i liczbę pięter w hotelu. Pętla powinna iterować raz na każde piętro. W każdej iteracji pętla  
powinna zapytać użytkownika o liczbę pokoi na piętrze i liczbę pokoi zajętych.  
Po wszystkich iteracjach program powinien wyświetlić, ile pokoi ma hotel, ile z nich jest zajętych, a ile wolnych oraz procent, jaki  
stanowią zajęte pokoje.  
UWAGA. Zdarza się, że w część hoteli nie ma trzynastego piętra (może to być inny numer piętra).  
Pętla w tym programie powinna pomijać iteracje na tym piętrze.  
Weryfikacja poprawności wprowadzanych danych: Nie akceptuj liczby mniejszej niż 1 dla liczby pięter.  
Nie akceptuj liczby mniejszej niż 5 dla liczby pokoi na piętrze.  


# Projekt 1

Napisz program, który pozwala użytkownikowi zagrać z komputerem w grę kamień, papier, nożyce.  
Użytkownik powinien mieć możliwość rozegrania kilku rund.  
Program powinien działać następująco:  

1.  Kiedy program zostaje uruchomiony, generowana jest liczba losowa od 1 do 3. Jeśli tą liczbą  
    jest 1, to oznacza, że komputer wybrał kamień. Jeśli tą liczbą jest 2, to komputer wybrał  
    papier. Jeśli tą liczbą jest 3,to komputer wybrał nożyce (nie wyświetlaj jeszcze wyboru  
    komputera).
2.  Użytkownik wprowadza swój wybór: „kamień”, „papier” albo „nożyce” na klawiaturze.
3.  Wyświetlany jest wybór komputera.
4.  Zwycięzca jest wybierany na podstawie następujących zasad:  
    -   Jeśli jeden gracz wybierze kamień, a drugi nożyce, to wygrywa kamień  
        (kamień tępi nożyce).
    -   Jeśli jeden gracz wybierze nożyce, a drugi papier, to wygrywają nożyce  
        (nożyce przecinają papier).
    -   Jeśli jeden gracz wybierze papier, a drugi kamień, to wygrywa papier  
        (papier owija kamień).
    -   Jeśli obaj gracze wybiorą ten sam ruch, to rozgrywka musi zostać powtórzona, aby  
        wyłonić zwycięzcę.

Program powinien być napisany z wykorzystaniem poznanych instrukcji języka.  
Program można rozbudować, dodając nowe opcje lub dokonać innych zmian. Należy wtedy dołączyć  
krótki opis programu.  

[C++](./Projekt1/main.cpp)   

