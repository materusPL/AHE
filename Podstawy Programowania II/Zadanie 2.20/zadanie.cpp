/*
    Autor: Mateusz Słodkowicz
    Grupa: D3
    Numer Indeksu: 167675
*/

#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>

struct Punkt
{
    double x = 0, y = 0, odl = 0;
};
struct Cwiartki
{
    unsigned int I = 0, II = 0, III = 0, IV = 0, OS = 0;
};

Punkt losujPunt();
Cwiartki liczCwiartki(Punkt[], size_t);
void losujPunkty(Punkt[], size_t);
double odlegosc(double x, double y);
void wypiszPromien(Punkt[], size_t, double);

int main()
{
    srand(time(NULL));
    size_t N = 0;
    double R = 0; // Zakładam że okręg ma mieć środek w punkcie 0,0
    std::cout << "Wprowadz ile punktow wylosowac.\n";
    std::cout << "Ile puntkow: ";
    while (!(std::cin >> N) || N == 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ile puntkow: ";
    }

    Punkt *punkty = new Punkt[N];

    losujPunkty(punkty, N);
    Cwiartki cw = liczCwiartki(punkty, N);
    
    std::cout << "Ilosc punktow w cwiartkach ukladu:\n";
    printf("Cwiartka %4s: %i\n", "I", cw.I);
    printf("Cwiartka %4s: %i\n", "II", cw.II);
    printf("Cwiartka %4s: %i\n", "III", cw.III);
    printf("Cwiartka %4s: %i\n", "IV", cw.IV);
    printf("%12s: %i\n", "Punkty na osi", cw.OS);

    std::cout << "\nWprowadz promien okregu.\n";
    std::cout << "Promien: ";
    while (!(std::cin >> R) || R == 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Promien: ";
    }

    wypiszPromien(punkty,N,R);
    

    delete[] punkty;
    return 0;
}

void wypiszPromien(Punkt punkty[], size_t roz, double r)
{
    printf("\nPunkty w okregu o promieniu R=%.2f\n", r);
    for (size_t i = 0; i < roz; ++i)
    {
        if (punkty[i].odl < r)
            printf("X: %-6.2f | Y: %-6.2f | Odl: %-6.2f\n", punkty[i].x, punkty[i].y, punkty[i].odl);
    }
}
double odlegosc(double x, double y)
{
    return sqrt((x * x) + (y * y));
}
void losujPunkty(Punkt punkty[], size_t roz)
{
    for (size_t i = 0; i < roz; ++i)
    {
        punkty[i] = losujPunt();
    }
}

Cwiartki liczCwiartki(Punkt punkty[], size_t roz)
{
    Cwiartki cw;
    for (size_t i = 0; i < roz; ++i)
    {
        if (punkty[i].x > 0 && punkty[i].y > 0)
            ++cw.I;
        else if (punkty[i].x < 0 && punkty[i].y > 0)
            ++cw.II;
        else if (punkty[i].x < 0 && punkty[i].y < 0)
            ++cw.III;
        else if (punkty[i].x > 0 && punkty[i].y < 0)
            ++cw.IV;
        else
            ++cw.OS;
    }
    return cw;
}

Punkt losujPunt()
{
    Punkt p = {
        .x = double((rand() % 201) - 100) / 10.0,
        .y = double((rand() % 201) - 100) / 10.0
    };
    p.odl = odlegosc(p.x, p.y);
    return p;
}
