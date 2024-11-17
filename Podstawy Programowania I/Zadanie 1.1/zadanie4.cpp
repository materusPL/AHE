/*
    Autor: Mateusz Slodkowicz
    Grupa: D3
    Numer Indeksu: 167675

    Opis: Program wczyta dlugosc trasy rowerzysty w metrach oraz
          wypisze w jakim czasie przebyl odcinek trasy na danym etapie.
*/

#include <iostream>

int main()
{
    float d = 0;
    std::cout << "Podaj odleglosc trasy w metrach: ";
    std::cin >> d;

    float czas = ((d * 0.2f) / 10) + ((d * 0.5f) / 5) +((d * 0.3f) / 10);
    int godziny = czas/3600;
    int minuty = (czas - godziny*3600)/60;
    int sekundy = (czas - godziny*3600 - minuty*60);
    std::cout << "Trasa przejechana w:\n";
    std::cout << godziny <<" godz. "
        << minuty <<" min. "
        << sekundy << " sek." <<std::endl;

    return 0;
}
