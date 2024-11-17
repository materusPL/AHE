/*
    Autor: Mateusz Slodkowicz
    Grupa: D3
    Numer Indeksu: 167675

    Opis: Program wczyta liczbe biletow dla dzieci i doroslych a nastepnie
          wypisze wyniki sprzedazy.
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    unsigned int dzieci = 0;
    unsigned int dorosli = 0;

    const float dlaKina=0.20;

    std::cout << "Podaj liczbe biletow dzieci: ";
    std::cin >> dzieci;
    std::cout << "Podaj liczbe biletow doroslych: ";
    std::cin >> dorosli;


    float brutto = (dzieci*6.0) + (dorosli*10.0);
    float netto = (brutto*dlaKina);
    float dystrybutor = brutto - netto;
    
    //Ustawienie 2 miejsc po przecinku
    std::cout << std::fixed;
    std::cout << std::setprecision(2);

    std::cout << "\nSprzedane bilety dla doroslych: " << dorosli << "\n";
    std::cout << "Sprzedane bilety dla dzieci: " << dzieci << "\n";
    std::cout << "Zysk kasy brutto: " << brutto << "zl\n";
    std::cout << "Zysk kasy netto: " << netto << "zl\n";
    std::cout << "Kwota zaplacona dystrybutorowi: " << dystrybutor << "zl" << std::endl;
    return 0;
}
