/*
    Autor: Mateusz Slodkowicz
    Grupa: D3
    Numer Indeksu: 167675
*/

#include <cmath>
#include <iomanip>
#include <iostream>

// ===========
//  ZADANIE 1
// ===========
void zadanie1()
{
    std::cout << "Zadanie 1" << std::endl;

    int x = 0;
    int y = 0;

    std::cout << "Podaj x: ";
    std::cin >> x;
    if (x == 0)
    {
        std::cout << "x jest rowne 0, nie mozna wykonac obliczen" << std::endl;
        return;
    }
    std::cout << "Podaj y: ";
    std::cin >> y;

    if (x > y)
        std::cout << "x jest wieksze od y\n";
    else if (x == y)
        std::cout << "x jest rowne y\n";
    else
        std::cout << "x yest mniejsze od y\n";

    std::cout << ((x % 2) ? "x jest nieparzyste" : "x jest parzyste") << std::endl;
}

// ===========
//  ZADANIE 2
// ===========
void zadanie2()
{
    std::cout << "\nZadanie 2" << std::endl;

    double x = 0;
    double y = 0;

    std::cout << "Podaj x: ";
    std::cin >> x;

    if (x >= -10.0 && x <= 0.0)
        y = (3.0 / 4.0) * (x * x * x) + (7.0 / 8.0) * x;
    else if (x > 0.0 && x <= 4.0)
        y = 1.0 / (sin(x) + 3.0);
    else
        y = (-2.0 * x) / 3.0;

    std::cout << "y = " << y << std::endl;
}

// ===========
//  ZADANIE 3
// ===========
void zadanie3()
{
    std::cout << "\nZadanie 3" << std::endl;

    unsigned short wybor = 0;
    double R = 0;
    double h = 0;

    std::cout << "Co chcesz obliczyc?\n"
                 "1. Objetosc kuli\n"
                 "2. Objetosc walca\n"
                 "3. Objetosc stozka\n";

    while (!(wybor >= 1 && wybor <= 3)) // Zapetlenie az nie zostanie wybrana odpowiedz z zakresu 1-3
    {
        std::cout << "Twoj wybor: ";
        std::cin >> wybor;
    }

    switch (wybor)
    {
    case 1:

        std::cout << "Podaj promien kuli: ";
        std::cin >> R;
        if (R <= 0)
            std::cout << "Promien musi byc wiekszy od zera!" << std::endl;
        else
            std::cout << "Objetosc kuli wynosi: " << ((4.0 / 3.0) * M_PI * R * R * R) << std::endl;
        break;
    case 2:

        std::cout << "Podaj promien podstawy walca: ";
        std::cin >> R;
        if (R <= 0)
        {
            std::cout << "Promien musi byc wiekszy od zera!" << std::endl;
            break;
        }

        std::cout << "Podaj wysokosc walca: ";
        std::cin >> h;
        if (h <= 0)
        {
            std::cout << "Wysokosc musi byc wieksza od zera!" << std::endl;
            break;
        }

        std::cout << "Objetosc walca: " << (M_PI * R * R * h) << std::endl;
        break;
    case 3:

        std::cout << "Podaj promien podstawy stozka: ";
        std::cin >> R;
        if (R <= 0)
        {
            std::cout << "Promien musi byc wiekszy od zera!" << std::endl;
            break;
        }

        std::cout << "Podaj wysokosc stozka: ";
        std::cin >> h;
        if (h <= 0)
        {
            std::cout << "Wysokosc musi byc wieksza od zera!" << std::endl;
            break;
        }

        std::cout << "Objetosc stozka: " << ((1.0 / 3.0) * M_PI * R * R * h) << std::endl;
        break;
    default:
        break;
    }
}

// ===========
//  ZADANIE 4
// ===========
void zadanie4()
{
    std::cout << "\nZadanie 4" << std::endl;

    double waga = 0;
    double odleglosc = 0;

    std::cout << "Podaj odleglosc w kilometrach: ";
    std::cin >> odleglosc;
    if (odleglosc <= 0)
    {
        // Nie ma podanej minimalnej odleglosci wiec zakladam ze musi byc jedynie wieksza od zera
        std::cout << "Odleglosc musi byc wieksza od zera!" << std::endl;
        return;
    }
    const int ILE = (ceil(odleglosc / 100.0)); // Zwiekszenie mnoznika co 100 km

    std::cout << "Podaj wage paczki w kilogramach w zakresie 0-20: ";
    std::cin >> waga;

    std::cout << std::fixed << std::setprecision(2);
    if (waga > 20.0 || waga <= 0)
    {
        std::cout << "Waga z poza zakresu!" << std::endl;
        return;
    }
    else if (waga <= 2.0)
        std::cout << "Cena: " << (5.30) * ILE << "zl" << std::endl;
    else if (waga <= 6.0)
        std::cout << "Cena: " << (6.20) * ILE << "zl" << std::endl;
    else if (waga <= 10.0)
        std::cout << "Cena: " << (7.70) * ILE << "zl" << std::endl;
    else if (waga <= 20.0)
        std::cout << "Cena: " << (10.80) * ILE << "zl" << std::endl;
}

// ======
//  MAIN
// ======
int main()
{
    zadanie1();
    zadanie2();
    zadanie3();
    zadanie4();
    return 0;
}
