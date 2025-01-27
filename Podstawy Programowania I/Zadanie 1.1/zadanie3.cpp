/*
    Autor: Mateusz Slodkowicz
    Grupa: D3
    Numer Indeksu: 167675
    
    Opis: Program wczyta 3 zmienne i wypisze sume, srednia i srednia harmoniczna.
*/
#include <iostream>

int main()
{
    int a = 0;
    int b = 0;
    int c = 0;

    std::cout << "Podaj pierwsza wartosc: ";
    std::cin >> a;
    std::cout << "Podaj druga wartosc: ";
    std::cin >> b;
    std::cout << "Podaj trzecia wartosc: ";
    std::cin >> c;

    std::cout << "\nSuma: " << a+b+c << "\n";
    std::cout << "Srednia arytmetyczna: " << (float)(a+b+c)/3.0f << "\n";
    std::cout << "Srednia harmoniczna: " << 3.0/(1.0/a + 1.0/b +1.0/c) << "\n";
    return 0;
}
