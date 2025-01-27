/*
    Autor: Mateusz Slodkowicz
    Grupa: D3
    Numer Indeksu: 167675

    Opis: Program wczyta liczbe dziewczat i chlopcow w klasie a nastepnie
          wypisze ich wartosc procentowa w klasie.

*/

#include <iostream>



int main()
{
    unsigned int dziewczyny = 0;
    unsigned int chlopcy = 0;

    std::cout << "Podaj liczbe dziewczat: ";
    std::cin >> dziewczyny;
    std::cout << "Podaj liczbe chlopcow: ";
    std::cin >> chlopcy;

    unsigned int razem = dziewczyny+chlopcy;
    if(razem>0)
    {
        std::cout << "\nProcent chlopcow: " << (100*((float)chlopcy/razem)) << "%";
        std::cout << "\nProcent dziewczat: " << (100*((float)dziewczyny/razem)) << "%" << std::endl;
    }
    else
        std::cout << "Brak osob w klasie" << std::endl;
    return 0;
}
