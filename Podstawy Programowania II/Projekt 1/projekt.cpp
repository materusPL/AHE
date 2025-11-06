/*
    Autor: Mateusz Słodkowicz
    Grupa: D3
    Numer Indeksu: 167675
 */

#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

void losujTablice(int[], size_t, size_t);
void wypiszTablice(int[], size_t);
double srednia(int[], size_t);
void bombel(int[], size_t);
double mediana(int[], size_t);
void policzOsoby(int[],int[],size_t,size_t);
std::string maxOcena(int[], size_t);
void histogram(int[], size_t);

int main()
{
    const size_t N = 60;
    const size_t OO = 20;
    
    int oceny[N] = {0};
    int ileOsob[OO] = {0};

    srand(time(NULL));

    losujTablice(oceny, N, OO);
    std::cout << "Oceny: ";
    wypiszTablice(oceny, N);
    bombel(oceny, N);
    std::cout << "Oceny posortowane: ";
    wypiszTablice(oceny, N);


    
    std::cout << "Srednia: " << srednia(oceny, N) << "\n";
    std::cout << "Mediana: " << mediana(oceny, N) << "\n";
    policzOsoby(oceny, ileOsob, N, OO);
    
    std::cout << "Najwiecej wystepuje ocena/y: " << maxOcena(ileOsob, OO) << "\n";
    histogram(ileOsob, OO);
    return 0;
}

void losujTablice(int tab[], size_t roz, size_t max)
{
    for (size_t i = 0; i < roz; ++i)
    {
        tab[i] = rand() % max;
    }
}
void wypiszTablice(int tab[], size_t roz)
{
    for (size_t i = 0; i < roz; ++i)
    {
        std::cout << tab[i] << ((i + 1 == roz) ? "\n" : " ");
    }
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
void bombel(int tab[], size_t roz)
{
    int tmp;
    for (size_t i = 0; i < roz; ++i)
    {
        for (size_t j = 0; j < roz; ++j)
        {
            if (tab[j] > tab[i])
            {
                tmp = tab[j];
                tab[j] = tab[i];
                tab[i] = tmp;
            }
        }
    }
}
double mediana(int tab[], size_t roz)
{
    return (roz % 2 == 0)
           ? ((double(tab[roz / 2]) + double(tab[(roz / 2) - 1])) / 2.0)
           : double((tab[roz / 2]));
}
void policzOsoby(int oceny[], int osoby[], size_t roz, size_t maxOcena)
{
    for (size_t i = 0; i < maxOcena; ++i)
    {
        osoby[i] = 0;
    }
    for (size_t i = 0; i < roz; ++i)
    {
        osoby[oceny[i]] += 1;
    }
}

std::string maxOcena(int ileOsob[], size_t maxOcena)
{
    std::string ret = "";
    int max = -1;
    for (size_t i = 0; i < maxOcena; ++i)
    {
        if (ileOsob[i] > max){
            max = ileOsob[i];
            ret = std::to_string(i);
        }
        else if (ileOsob[i] == max)
            ret += ", " + std::to_string(i);
    }
    return ret;
}
void histogram(int ileOsob[], size_t maxOcena)
{
    for(size_t i = 0; i<maxOcena;++i)
    {
        printf("Ocena %2zu: ",i);
        for(size_t j = 0; j<ileOsob[i];++j)
        {
            std::cout << "*";
        }
        
        std::cout << "\n";
    }
}
