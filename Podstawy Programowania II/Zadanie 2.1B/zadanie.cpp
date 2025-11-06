/*
    Autor: Mateusz Słodkowicz
    Grupa: D3
    Numer Indeksu: 167675

 */

#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <string>

using std::size_t;
using std::string;

void wczytajDane(int tab[], size_t roz);
void losujDane(int tab[], size_t roz);
void wypiszDane(int tab[], size_t roz);
int minimum(int tab[], size_t roz, unsigned int &ile);
double srednia(int tab[], size_t roz);
double odchylenie(int tab[], size_t roz);

int main()
{
    // Zadanie 1
    {
        const size_t roz = 9;
        int A[roz] = {0};
        std::cout << "Zadanie 1\n";
        wczytajDane(A, roz);
        std::cout << "Elementy w tablicy: ";
        wypiszDane(A, roz);
        unsigned int ile;
        int min = minimum(A, roz, ile);
        std::cout << "Najmniejszy element to " << min << " i powtarza sie " << ile
                  << ((ile == 1) ? " raz\n" : " razy\n");
    }

    // Zadanie 2
    {
        srand(time(NULL));
        const size_t roz = 15;
        int X[roz] = {0};
        losujDane(X, roz);

        std::cout << "\nZadanie 2\n"
                  << "Elementy w tablicy: ";
        wypiszDane(X, roz);
        std::cout << "Srednia elementow to: " << srednia(X, roz)
                  << "\nOdchylenie standardowe od sredniej to: " << odchylenie(X, roz) << std::endl;
    }

    // Zadanie 3
    {
        const string nazwy[] = {"Lagodny", "Ostry", "Kwasny", "Slodki", "Pikantny"};
        const size_t roz = sizeof(nazwy) / sizeof(string);
        int sprzedane[roz] = {0};
        std::cout << "\nZadanie 3\n";
        for (size_t i = 0; i < roz; ++i)
        {
            do
            {
                std::cout << "Wprowadz ilosc sprzedanych pojemnikow dla \"Sos " << nazwy[i] << "\": ";
                std::cin >> sprzedane[i];
                if (sprzedane[i] < 0)
                    std::cout << "Blad! Wprowadz liczbe nieujemna\n";
            } while (sprzedane[i] < 0);
        }
        std::cout << "\nSprzedane pojemniki\n";
        int lacznie = 0;
        for (size_t i = 0; i < roz; ++i)
        {
            lacznie += sprzedane[i];
            std::cout << "\"Sos " << nazwy[i] << "\": " << sprzedane[i] << "\n";
        }
        std::cout << "Lacznie: " << lacznie;
        int min = sprzedane[0];
        int max = sprzedane[0];
        for (size_t i = 1; i < roz; ++i)
        {
            if (sprzedane[i] > max)
            {
                max = sprzedane[i];
            }

            if (sprzedane[i] < min)
            {
                min = sprzedane[i];
            }
        }

        std::cout << "\nNajwiecej sprzedanych: ";
        for (size_t i = 0; i < roz; ++i)
        {
            if (sprzedane[i] == max)
                std::cout << "\"Sos " << nazwy[i] << "\" ";
        }

        std::cout << "w ilosci " << max << "\nNajmniej sprzedanych: ";
        for (size_t i = 0; i < roz; ++i)
        {
            if (sprzedane[i] == min)
                std::cout << "\"Sos " << nazwy[i] << "\" ";
        }
        std::cout << "w ilosci " << min << std::endl;
    }

    return 0;
}

void wczytajDane(int tab[], size_t roz)
{
    for (size_t i = 0; i < roz; ++i)
    {
        std::cout << "Podaj element tablicy o indeksie " << i << ": ";
        std::cin >> tab[i];
    }
}
void losujDane(int tab[], size_t roz)
{
    for (size_t i = 0; i < roz; ++i)
    {
        tab[i] = (rand() % 26) + 5;
    }
}

void wypiszDane(int tab[], size_t roz)
{
    for (size_t i = 0; i < roz; ++i)
    {
        std::cout << tab[i] << ((i != roz - 1) ? ", " : "\n");
    }
}

int minimum(int tab[], size_t roz, unsigned int &ile)
{
    ile = 1;
    int min = tab[0];
    for (size_t i = 1; i < roz; ++i)
    {
        if (tab[i] < min)
        {
            ile = 1;
            min = tab[i];
        }
        else if (tab[i] == min)
            ++ile;
    }
    return min;
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
double odchylenie(int tab[], size_t roz)
{
    double sr = srednia(tab, roz);
    double sigma = 0, tmp = 0;
    for (size_t i = 0; i < roz; ++i)
    {
        tmp = double(tab[i]) - sr;
        sigma += tmp * tmp;
    }
    return std::sqrt(sigma / roz);
}
