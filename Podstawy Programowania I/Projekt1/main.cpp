/*
    Autor: Mateusz Słodkowicz
    Grupa: D3
    Numer Indeksu: 167675

    Opis: Gra w Papier, Kamień, Nożyce.
          Program zapyta do ilu wygranych chcesz zagrać.
          Remis nie liczy się jako wygrana bądź przegrana.
          Gra trwa do uzyskania przez kogoś wyniku podanego na początku, po zakończeniu gra wypisze kto wygrał "mecz"
          oraz umożliwia rozpoczęcię kolejnego "meczu".
          Aby zakończyć program należy przy wyborze "do ilu" podać zero.

          Plik źródłowy powinien być zapisany z kodowaniem UTF-8.
*/

#include <chrono>
#include <iostream>
#include <random>
#include <string>

#ifdef _WIN32 // Dodatkowe nagłówki dla windows'a
#include <cstdlib>
#include <windows.h>
// Nieco jaśniejszy niż domyślny biały
#define DEFAULT_COLOR (FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY)
#endif

void wypiszCzerwony(std::string tekst)
{
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // "Uchwyt" wyjścia konsoli
    std::cout << std::flush; // Flush aby przypadkiem program nie zmienił koloru poprzedniego tekstu
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); // Ustawienie czerwonego koloru
    std::cout << tekst << std::flush; // Flush aby program na pewno wypisał tekst przed ustawienie domyślnego koloru

    SetConsoleTextAttribute(hConsole, DEFAULT_COLOR);

#else
    std::cout << "\033[31m" << tekst << "\033[0m";
#endif
}
void wypiszZielony(std::string tekst)
{
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout << std::flush;
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    std::cout << tekst << std::flush;
    SetConsoleTextAttribute(hConsole, DEFAULT_COLOR);
#else
    std::cout << "\033[32m" << tekst << "\033[0m";
#endif
}

void czyscEkran()
{
#ifdef _WIN32
    system("cls"); // Wywołanie "cls" dla wyczyczenia ekranu konsoli na windowsie
#else
    std::cout << "\033[2J\033[1;1H"; // Sekwencja czyszczenia dla terminala ANSI
#endif
}

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8); // Ustawienie kodowania UTF-8 dla wyjścia konsoli, pozwala wyświetlić polskie znaki.
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, DEFAULT_COLOR);
#endif
    // Generator liczb
    auto seed = std::chrono::system_clock::now().time_since_epoch().count(); // większa dokładność czasu niż time(0)
    std::mt19937 rng(seed);                                                  // Generator licz losowych
    std::uniform_int_distribution<char> dist('1', '3');                      // Zakres liczb (znaków) losowych
    // Zmienne
    unsigned int wybor = 0;
    unsigned int wygraneGracza = 0;
    unsigned int wygraneKomputera = 0;
    unsigned char ostatniaRunda = 0;
    unsigned char ostatniMecz = 0;

    char gracz = 0, komputer = 0;

    // Główna pętla gry
    while (true)
    {
        czyscEkran();
        // Wypisanie wyniku ostatniego meczu
        if (ostatniMecz != 0)
            std::cout << "Ostatni mecz: ";
        if (ostatniMecz == 1)
            wypiszZielony("Wygrana gracza\n");
        else if (ostatniMecz == 2)
            wypiszCzerwony("Wygrana komputera\n");

        // Reset zmiennych
        wygraneKomputera = 0;
        wygraneGracza = 0;

        ostatniaRunda = 0;
        ostatniMecz = 0;

        wybor = 0;
        // Wybór do ilu wygranych
        std::cout << "Do ilu wygranych chcesz zagrać?\n"
                     "Wprowadź 0 aby wyjść z programu\n"
                     "Ile: ";

        while (!(std::cin >> wybor))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            wypiszCzerwony("Błąd, wprowadź jeszcze raz.\n");
            std::cout << "Ile: ";
        }
        if (!wybor)
            break;

        // Pętla do czasu wygranej gracza lub komputera
        while (wygraneGracza != wybor && wygraneKomputera != wybor)
        {
            czyscEkran();
            gracz = 0;
            komputer = dist(rng);
            // Wypisanie wyniku ostatniej rundy
            if (ostatniaRunda != 0)
                std::cout << "Ostatnia runda: ";
            if (ostatniaRunda == 1)
                wypiszZielony("Wygrana gracza\n");
            else if (ostatniaRunda == 2)
                wypiszCzerwony("Wygrana komputera\n");
            else if (ostatniaRunda == 3)
                std::cout << "Remis\n";

            // Wypisanie danych aktualnego meczu
            std::cout << "Gra do: " << wybor << "\n\n"
                      << "GRACZ ";
            wypiszZielony(std::to_string(wygraneGracza));
            std::cout << " - ";
            wypiszCzerwony(std::to_string(wygraneKomputera));
            std::cout << " KOMPUTER\n\n";

            // Menu wyboru
            std::cout << "1. Papier\n"
                         "2. Kamień\n"
                         "3. Nożyce\n";

            while (gracz < '1' || gracz > '3')
            {
                std::cout << "Wybór: ";
                while (!(std::cin >> gracz))
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            // Remis
            if (gracz == komputer)
                ostatniaRunda = 3;
            // Switch z wyborem gracza, porównanie do komputera
            else
                switch (gracz)
                {
                case '1':                // Gracz wybrał papier
                    if (komputer == '2') // Komputer wybrał kamień
                    {
                        ++wygraneGracza;
                        ostatniaRunda = 1;
                    }
                    else if (komputer == '3') // Komputer wybrał nożyce
                    {
                        ++wygraneKomputera;
                        ostatniaRunda = 2;
                    }
                    break;
                case '2':                // Gracz wybrał kamień
                    if (komputer == '3') // Komputer wybrał nożyce
                    {
                        ++wygraneGracza;
                        ostatniaRunda = 1;
                    }
                    else if (komputer == '1') // Komputer wybrał papier
                    {
                        ++wygraneKomputera;
                        ostatniaRunda = 2;
                    }
                    break;
                case '3':                // Gracz wybrał nożyce
                    if (komputer == '1') // Komputer wybrał papier
                    {
                        ++wygraneGracza;
                        ostatniaRunda = 1;
                    }
                    else if (komputer == '2') // Komputer wybrał kamień
                    {
                        ++wygraneKomputera;
                        ostatniaRunda = 2;
                    }
                    break;
                }
        }
        // Ustawienie wyniku meczu
        if (wygraneGracza == wybor)
            ostatniMecz = 1;
        else
            ostatniMecz = 2;
    };
    czyscEkran();
    std::cout << "Dziękujemy za grę!";

    return 0;
}
