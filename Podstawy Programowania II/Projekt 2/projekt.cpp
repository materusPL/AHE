/*
    Autor: Mateusz Słodkowicz
    Grupa: D3
    Numer Indeksu: 167675

    Uwagi: Kod źródłowy powinien być zapisany z kodowaniem UTF-8
*/


#include <fstream>
#include <limits>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

struct STUDENT
{
    std::string imie_nazwisko;
    int oceny[6];
    double srednia;
    std::string ocena_koncowa;
};

void czysc();
void menu(std::vector<STUDENT> &studenci);
void wypisz_wszystkich(std::vector<STUDENT> &studenci);
void wypisz_najlepszych(std::vector<STUDENT> &studenci);
void wypisz_wyszukanych(std::vector<STUDENT> &studenci, std::string szukany);

double srednia_wszystkich(std::vector<STUDENT> &studenci);
double najwyzsza_wartosc(std::vector<STUDENT> &studenci);
int powyzej_sredniej(std::vector<STUDENT> &studenci);

STUDENT tworz_studenta();
std::vector<STUDENT> wczytaj_dane(std::string sciezka);
void zapisz_dane(std::vector<STUDENT> &studenci, std::string sciezka);
void modyfikuj(std::vector<STUDENT> &studenci);

int main()
{
#ifdef _WIN32
    system("chcp 65001"); // Zmiana kodowaniu wiersza poleceń na windowsie dla obsługi polskich znaków
#endif
    std::cout << std::setprecision(3);
    czysc();
    std::vector<STUDENT> studenci;
    bool wyjdz = false;
    std::string tekst = "";
    while(!wyjdz)
    {
        menu(studenci);
        std::cout <<  "Wybór: ";
        char wybor = 0;
        while (!(std::cin >> wybor) || wybor < '0' || wybor > '9')
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout <<  "Wybór: ";
        }

        switch (wybor)
        {
        case '0':
            wyjdz = true;
            break;
        case '1':
            wypisz_wszystkich(studenci);
            break;
        case '2':
            czysc();
            studenci = wczytaj_dane("dane.txt");
            break;
        case '3':
            czysc();
            zapisz_dane(studenci, "dane.txt");
            break;
        case '4':
            czysc();
            std::cout << "Średnia: " << srednia_wszystkich(studenci);
            break;
        case '5':
            czysc();
            std::cout << "Średnia: " << srednia_wszystkich(studenci) << "\nIlośc studentów powyżej średniej: " << powyzej_sredniej(studenci);
            break;
        case '6':
            czysc();
            wypisz_najlepszych(studenci);
            break;
        case '7':
            czysc();
            tekst = "";
            std::cout << "Podaj szukany fragment: ";
            std::cin >> tekst;
            wypisz_wyszukanych(studenci, tekst);
            break;
        case '8':
            czysc();
            studenci.push_back(tworz_studenta());
            break;
        case '9':
            czysc();
            modyfikuj(studenci);
            break;
        }
    }

    return 0;
}

void czysc()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void menu(std::vector<STUDENT> &studenci)
{
    std::cout << "\n\nAktualna ilość studentów: " << studenci.size() << "\n"
              << "1. Wypisz studentów\n"
              << "2. Wczytaj studentów z pliku dane.txt\n"
              << "3. Zapisz studentów do pliku dane.txt\n"
              << "4. Wypisz średnią wszystkich studentów\n"
              << "5. Wypisz ilość studentów powyżej średniej\n"
              << "6. Wypisz studentów z najwyższą średnią\n"
              << "7. Wyszukaj i wypisz dane studentów których imię/nazwisko zawiera szukany tekst\n"
              << "8. Dodaj studenta\n"
              << "9. Modyfikuj lub usuń studenta\n"
              << "0. Wyjdź\n";
}

double licz_srednia(STUDENT &student)
{
    double srednia = 0;

    for (int i = 0; i < 6; ++i)
    {
        srednia += student.oceny[i];
    }
    srednia = srednia / 6.0;
    return srednia;
}

std::string ocena(STUDENT &student)
{
    if (student.srednia >= 91)
        return "bardzo dobry";
    if (student.srednia >= 81)
        return "dobry plus";
    if (student.srednia >= 71)
        return "dobry";
    if (student.srednia >= 61)
        return "dostateczny plus";
    if (student.srednia >= 51)
        return "dostateczny";
    return "niedostateczny";
}

STUDENT tworz_studenta()
{
    STUDENT s;
    std::string tmp_txt;
    std::cout << "Podaj imię: ";
    std::cin >> tmp_txt;
    s.imie_nazwisko = tmp_txt;
    tmp_txt = "";
    std::cout << "Podaj nazwisko: ";
    std::cin >> tmp_txt;
    s.imie_nazwisko += " ";
    s.imie_nazwisko += tmp_txt;
    int tmp = -1;
    for(int i = 0;i<6;++i)
    {
        std::cout <<  "Podaj ocenę " << i+1 <<": ";
        while (!(std::cin >> tmp) || (tmp <50 && tmp !=0 ) || tmp > 100)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Błąd, ocena musi być 50 <= ocena <= 100 lub równa 0\n";
            std::cout <<  "Podaj ocenę " << i+1 <<": ";
        }
        s.oceny[i] = tmp;
    }
    s.srednia = licz_srednia(s);
    s.ocena_koncowa = ocena(s);
    return s;
}

void modyfikuj(std::vector<STUDENT> &studenci)
{
    czysc();
    wypisz_wszystkich(studenci);
    std::cout << "\nCo chcesz zrobić?\n1.Modyfikuj\n2.Usuń\n3.Anuluj\nWybór: ";
    char wybor = 0;
    while (!(std::cin >> wybor) || wybor < '1' || wybor > '3')
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Wybór: ";
    }
    int id = -1;
    switch (wybor)
    {
    case '1':
        std::cout << "\nPodaj id: ";
        while (!(std::cin >> id))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nPodaj id: ";
        }
        if (id < 0 || id >= studenci.size())
        {
            std::cout << "Błędne id!\n";
            return;
        }
        else
            studenci[id] = tworz_studenta();
        break;
    case '2':
        std::cout << "\nPodaj id: ";
        while (!(std::cin >> id))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nPodaj id: ";
        }
        if(id<0 || id>=studenci.size())
        {
            std::cout << "Błędne id!\n";
            return;
        }
        else
            studenci.erase(studenci.begin()+id);
        break;
    case '3':
        return;
    }
}

void zapisz_dane(std::vector<STUDENT> &studenci, std::string sciezka)
{
    std::ofstream plik(sciezka);
    if (!plik.is_open())
    {
        std::cout << "Nie można otworzyć pliku: " << sciezka << std::endl;
        return;
    }
    for (auto &s : studenci)
    {
        plik << s.imie_nazwisko << std::endl;
        for (int i = 0; i < 6; ++i)
        {
            plik << s.oceny[i] << " ";
        }
        plik << "\n";
    }
    plik.close();
}

std::vector<STUDENT> wczytaj_dane(std::string sciezka)
{
    std::vector<STUDENT> studenci;
    std::ifstream plik(sciezka);
    if (!plik.is_open())
    {
        std::cout << "Nie można otworzyć pliku: " << sciezka << std::endl;
        return studenci;
    }
    std::string line;
    while (std::getline(plik, line))
    {
        if (!line.empty())
        {
            STUDENT s;
            s.imie_nazwisko = line;
            for (int i = 0; i < 6; ++i)
            {
                plik >> s.oceny[i];
            }
            plik.ignore();
            s.srednia = licz_srednia(s);
            s.ocena_koncowa = ocena(s);
            studenci.push_back(s);
        }
    }
    plik.close();
    return studenci;
}

double srednia_wszystkich(std::vector<STUDENT> &studenci)
{
    if (studenci.empty())
        return 0;
    double suma = 0;
    for (auto &student : studenci)
    {
        suma += student.srednia;
    }
    return suma / studenci.size();
}

int powyzej_sredniej(std::vector<STUDENT> &studenci)
{
    int ret = 0;
    double srednia = srednia_wszystkich(studenci);
    for(auto &s :studenci)
    {
        if(s.srednia > srednia) ++ret;
    }
    return ret;
}

double najwyzsza_wartosc(std::vector<STUDENT> &studenci)
{
    double max = 0;
    for (auto s : studenci)
    {
        if(s.srednia>max) max = s.srednia;
    }
    return max;
}

void wypisz_wszystkich(std::vector<STUDENT> &studenci)
{
    czysc();
    if(studenci.size() == 0)
    {
        std::cout << "Brak studentów!\n";
        return;
    }

    std::cout << "Lista studentów:\n";
    printf("%2s | %31s | %30s | %10s | %19s\n","ID","Imię i nazwisko","Oceny","Średnia","Ocena Końcowa");
    printf("---+--------------------------------+--------------------------------+-----------+-------------------\n");
    for (int j = 0; j < studenci.size(); ++j)
    {
        std::string oceny = "";
        STUDENT &s = studenci[j];

        for (int i = 0; i < 6; ++i)
        {
            oceny += std::to_string(s.oceny[i]);
            oceny += ((i == 5) ? " " : ", ");
        }

        printf("%2i | %30s | %30s | %9.2f | %18s\n",j,s.imie_nazwisko.c_str(),oceny.c_str(),s.srednia,s.ocena_koncowa.c_str());
    }
}

void wypisz_wyszukanych(std::vector<STUDENT> &studenci, std::string szukany)
{
    czysc();
    std::vector<STUDENT> znalezieni;
    if (studenci.size() == 0)
    {
        std::cout << "Brak studentów!\n";
        return;
    }
    std::cout << "Lista studentów zawierających \"" << szukany << "\":\n";
    bool znaleziono = false;
    printf("%-31s | %30s | %10s | %19s\n","Imię i nazwisko","Oceny","Średnia","Ocena Końcowa");
    printf("-------------------------------+--------------------------------+-----------+-------------------\n");
    for (auto &s : studenci)
    {
        if (s.imie_nazwisko.find(szukany) != std::string::npos)
        {
            znalezieni.push_back(s);
            znaleziono = true;
            std::string oceny = "";

            for (int i = 0; i < 6; ++i)
            {
                oceny += std::to_string(s.oceny[i]);
                oceny += ((i == 5) ? " " : ", ");
            }

            printf("%-30s | %30s | %9.2f | %18s\n", s.imie_nazwisko.c_str(), oceny.c_str(), s.srednia,
                   s.ocena_koncowa.c_str());
        }
    }
    if(!znaleziono) std::cout << "Nie znaleziono\n";
    else
    {
        std::cout << "\nZapisać do pliku \"wyszukani.txt\"?\n1.Tak\n2.Nie\n";
        std::cout << "Wybór: ";
        char wybor = 0;
        while (!(std::cin >> wybor) || wybor < '1' || wybor > '2')
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Wybór: ";
        }
        if(wybor=='1') zapisz_dane(znalezieni, "wyszukani.txt");
    }
}

void wypisz_najlepszych(std::vector<STUDENT> &studenci)
{
    czysc();
    if (studenci.size() == 0)
    {
        std::cout << "Brak studentów!\n";
        return;
    }
    std::vector<STUDENT> najlepsi;
    double max = najwyzsza_wartosc(studenci);
    std::cout << "Studenci o najwyższej średniej " << max << ":\n";
    printf("%-31s | %30s | %10s | %19s\n", "Imię i nazwisko", "Oceny", "Średnia", "Ocena Końcowa");
    printf("-------------------------------+--------------------------------+-----------+-------------------\n");
    for (auto &s : studenci)
    {
        if (s.srednia == max)
        {
            std::string oceny = "";

            for (int i = 0; i < 6; ++i)
            {
                oceny += std::to_string(s.oceny[i]);
                oceny += ((i == 5) ? " " : ", ");
            }

            printf("%-30s | %30s | %9.2f | %18s\n", s.imie_nazwisko.c_str(), oceny.c_str(), s.srednia,
                   s.ocena_koncowa.c_str());
            najlepsi.push_back(s);
        };
    }
    std::cout << "\nZapisać do pliku \"najlepsi.txt\"?\n1.Tak\n2.Nie\n";
    std::cout << "Wybór: ";
    char wybor = 0;
    while (!(std::cin >> wybor) || wybor < '1' || wybor > '2')
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Wybór: ";
    }
    if (wybor == '1')
        zapisz_dane(najlepsi, "najlepsi.txt");
}
