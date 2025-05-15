/*
    Autor: Mateusz Słodkowicz
    Grupa: D3
    Numer Indeksu: 167675

*/

#include <cstdio>
#include <iostream>

void wypisz_tabliczke(const unsigned int);
double srednia(const int, const unsigned int);
double suma(const int);

// =========
//   MAIN
// =========

int main()
{
    // Zadania w main'ie podzieliłem na mniejsze scopy aby mieć możliwość zwijania w edytorze.

    // Zadanie 1
    {
        unsigned int n = 0;
        std::cout << "Zadanie 1\n";
        while (n < 1 || n > 10)
        {
            std::cout << "Podaj wielkosc tabliczki: ";
            std::cin >> n;
        }
        wypisz_tabliczke(n);
    }

    // Zadanie 2
    // W zadaniu nie widzę żeby było określone czy wczytywanie wartości ma być w funkcji czy w main'ie więc założyłem że
    // w mainie, funkcja jedynie wylicza średnią
    {
        std::cout << "\nZadanie 2\n"
                     "Podawaj liczby do wyliczenia sredniej, podaj 0 by zakonczyc (0 nie zostatnie uwzglednione przy "
                     "obliczeniach)\n";
        int suma = 0;
        unsigned int ile = 0;
        int last = 0;
        do
        {
            std::cout << "Podaj liczbe: ";
            std::cin >> last;
            if (last)
            {
                ++ile;
                suma += last;
            }

        } while (last);
        std::cout << "Srednia: " << srednia(suma, ile) << "\n";
    }

    // Zadanie 3
    {
        std::cout << "\nZadanie 3\n";
        int m = -1;
        while (m < 0)
        {
            std::cout << "Podaj m wieksze lub rowne 0: ";
            std::cin >> m;
        }
        std::cout << "Suma: " << suma(m) << "\n";
    }

    // Zadanie 4
    // Piętra zaczynam liczyć od parteru więc w przypadku podania jednego piętra będzie to jedynie parter (piętro 0).
    //
    // Zakładam że w przypadku "pominięcia" piętra powinno być dodane kolejne aby w przypadku podania na przykład 14
    // pięter było ich faktycznie parter + 13 pięter mimo braku piętra 13 (zamiast piętra 13 będzie piętro 14).
    //
    // Używam string dla nazwy hotelu, w uwagach
    // jest informacja aby nie używać tablic jednak zakładam że w tym wypadku string jest dopuszczalny.
    {
        std::cout << "\nZadanie 4\n";
        std::string nazwa;
        unsigned int pietra = 0;
        unsigned int aktualne_pietro = 0;

        unsigned int liczba_pokoi = 0, liczba_zajetych = 0;

        std::cout << "Podaj nazwe hotelu: ";
        std::cin >> nazwa;
        while (pietra < 1)
        {
            std::cout << "Podaj ilosc pieter: ";
            std::cin >> pietra;
        }
        std::cout << "Liczba pokoi na pietro powinna byc nie mniejsza niz 5\n"
                     "Liczba zajetych nie moze byc wieksza niz liczba pokoi na pietrze\n";
        while (pietra > 0)
        {
            if (aktualne_pietro == 13) // Pominięcie "pechowego" piętra
            {
                aktualne_pietro++;
                continue;
            }

            unsigned int akt_pok = 0, akt_zaj = 0;
            while (akt_pok < 5)
            {
                if (!aktualne_pietro)
                    std::cout << "Podaj liczbe pokoi na parterze: ";
                else
                    std::cout << "Podaj liczbe pokoi na pietrze " << aktualne_pietro << ": ";
                std::cin >> akt_pok;
            }

            do
            {
                std::cout << "Podaj liczbe zajetych pokoi (calkowita ilosc pokoi " << akt_pok << "): ";
                std::cin >> akt_zaj;
            } while (akt_zaj > akt_pok);
            liczba_pokoi += akt_pok;
            liczba_zajetych += akt_zaj;
            pietra--;
            aktualne_pietro++;
        }
        std::cout << "\nNAZWA HOTELU: " << nazwa << "\nILOSC POKOI: " << liczba_pokoi
                  << "\nILOSC WOLNYCH POKOI: " << liczba_pokoi - liczba_zajetych
                  << "\nILOSC ZAJETYCH POKOI: " << liczba_zajetych
                  << "\nPROCENT ZAJETYCH: " << (double(liczba_zajetych) / double(liczba_pokoi)) * 100.0 << "%"
                  << std::endl;
    }

    return 0;
}

// =========
//  FUNKCJE
// =========

void wypisz_tabliczke(const unsigned int wielkosc)
{
    // Nagłówek
    std::cout << "    |";

    for (int i = 1; i <= wielkosc; ++i)
    {
        std::printf("%4i", i); // Używam printf zamiast cout z uwagi na łatwiejsze/bardziej czytelne formatowanie
                               // Formatowanie na 4 znaki jako że max wielkość to 10
    }

    std::cout << "\n----+";
    for (int i = 1; i <= wielkosc; ++i)
    {
        std::cout << "----"; // 4 myślniki na liczbę dla zgodności z formatowaniem, może wyglądać niepoprawnie w
                             // przypadku używania czcionki o różnej szerokości znaków.
    }

    // Właściwa tabela
    for (int i = 1; i <= wielkosc; ++i)
    {
        std::printf("\n%-4i|", i);

        for (int j = 1; j <= wielkosc; ++j)
        {
            std::printf("%4i", i * j);
        }
    }

    std::cout << std::endl;
}

double srednia(const int suma, const unsigned int ile)
{
    if (!ile)
        return 0;
    else
        return double(suma) / double(ile);
}

double suma(const int m)
{
    double S = 0;
    for (int j = 0; j <= m; ++j)
    {
        S += (1.0 + j) / (2 * (j * j * j) + 3);
    }
    return S;
}
