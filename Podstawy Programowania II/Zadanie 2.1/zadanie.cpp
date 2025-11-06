/*
    Autor: Mateusz Słodkowicz
    Grupa: D3
    Numer Indeksu: 167675

 */

#include <cstddef>
#include <iostream>

void wczytajDane(int tab[], size_t roz);
void wypiszDane(int tab[], size_t roz);
int iloczyn(int tab[], size_t roz);
double srednia(int tab[], size_t roz);
int maksimum(int tab[], size_t roz, size_t &maxId);

// Rozmiar tablic
const size_t n = 4;

int main()
{
    // W zadaniu nie widzę jakiego typu ma być tablica, używam więc int.
    int A[n] = {0}, B[n] = {0};

    std::cout << "Podaj dane dla tablicy A\n";
    wczytajDane(A, n);
    std::cout << "Podaj dane dla tablicy B\n";
    wczytajDane(B, n);

    std::cout << "\nDane tablicy A:\n";
    wypiszDane(A, n);
    std::cout << "Dane tablicy B:\n";
    wypiszDane(B, n);

    std::cout << "\nIloczyn elementow roznych od zera dla tablicy A: " << iloczyn(A, n) << std::endl;
    std::cout << "\nSrednia elementow dla tablicy B: " << srednia(B, n) << std::endl;

    size_t maxId;
    std::cout << "\nNajwiekszy element dla tablicy A ma wartosc: " << maksimum(A, n, maxId)
    << "\nIndeks tej wartosci to: " << maxId << std::endl;

    return 0;
}

void wczytajDane(int tab[], size_t roz)
{
    for (size_t i = 0; i < roz; ++i)
    {
        std::cout << "Podaj wartosc dla elementu " << i + 1 << ": ";
        std::cin >> tab[i];
    }
}

void wypiszDane(int tab[], size_t roz)
{
    for (size_t i = 0; i < roz; ++i)
    {
        std::cout << tab[i] << ((i != roz - 1) ? " " : "\n");
    }
}

int iloczyn(int tab[], size_t roz)
{
    int wynik = 0;
    for (size_t i = 0; i < roz; ++i)
    {
        if (wynik == 0 && tab[i] != 0)
            wynik = tab[i];
        else if (tab[i] != 0)
            wynik *= tab[i];
    }
    return wynik;
}
double srednia(int tab[], size_t roz)
{
    int suma = 0;
    for (size_t i = 0; i < roz; ++i)
    {
        suma += tab[i];
    }
    return double(suma) / double(roz);
}

int maksimum(int tab[], size_t roz, size_t &maxId)
{
    maxId = 0;
    for (size_t i = 1; i < roz; ++i)
    {
        if (tab[maxId] < tab[i])
            maxId = i;
    }
    return tab[maxId];
}
