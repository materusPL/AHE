// Mateusz Słodkowicz D3

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <string>

#define X 3
#define Y 30

const char *mies[] = {"Czerwiec", "Lipiec","Sierpien"};

using namespace std;


void losujTablice(char[][Y],size_t);
void wypiszTablice(char[][Y], size_t);
void wypiszStatystyki(char[][Y],size_t);

int main()
{
    srand(time(NULL));
    char temperatury[X][Y] = {0};
    losujTablice(temperatury,X);
    std::cout << "Wyniki Pogodowe dla Czerwca, Lipca i Sierpnia\n\n";

    wypiszTablice(temperatury,X);
    std::cout << "\n";
    wypiszStatystyki(temperatury,X);
    return 0;
}


void wypiszStatystyki(char tab[][Y],size_t x_max)
{
    unsigned int D[X] = {0},P[X] = {0},S[X] = {0};
    unsigned int D_lacz=0,P_lacz=0,S_lacz=0;
    for(size_t x = 0; x<x_max;++x)
    {
        for(size_t y = 0; y<Y; ++y)
        {
            switch(tab[x][y])
            {
            case 'D':
                D[x] += 1;
                ++D_lacz;
                break;
            case 'P':
                P[x] += 1;
                ++P_lacz;
                break;
            case 'S':
                S[x] += 1;
                ++S_lacz;
                break;
            default:
                break;
            }
        }
        std::cout << "Statystyki dla miesiaca " << mies[x] << ":\n";
        std::cout << "\tDni Deszczowe: " << D[x] << "\n";
        std::cout << "\tDni Pochmurne: " << P[x] << "\n";
        std::cout << "\tDni Sloneczne: " << S[x] << "\n";
    }
    std::cout << "Statystyki laczne:\n";
    std::cout << "\tDni Deszczowe: " << D_lacz << "\n";
    std::cout << "\tDni Pochmurne: " << P_lacz << "\n";
    std::cout << "\tDni Sloneczne: " << S_lacz << "\n";

    size_t id_max = 0;
    for(size_t x = 1; x<x_max;++x)
    {
        if(D[id_max]<D[x]) id_max = x;
    }
    std::cout << "\nNajwiecej dni deszczowych w: " << mies[id_max];



}
void wypiszTablice(char tab[][Y], size_t x_max)
{
    printf("%10s", "Dni: ");
    for(int y =0; y<Y;++y)
    {
        printf("%3i", y+1);
    }
    std::cout << "\n";
    for(size_t x = 0; x<x_max; ++x)
    {
        printf("%10s: ",mies[x]);
        for(size_t y = 0; y<Y;++y)
        {
            std::cout<<tab[x][y] << "  ";
        }
        std::cout << "\n";
    }
}

void losujTablice(char tab[][Y], size_t x_max)
{
    short losulosu = 0;
    for(size_t x = 0; x < x_max;++x)
    {
        for(size_t y = 0; y < Y;++y)
        {
            losulosu = rand() % 3;
            switch(losulosu)
            {
                case 0:
                    tab[x][y] = 'D';
                    break;
                case 1:
                    tab[x][y] = 'P';
                    break;
                case 2:
                    tab[x][y] = 'S';
                    break;
                default:
                    break;
            }
        }
    }

}
