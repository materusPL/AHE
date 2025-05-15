from math import trunc
def Czytaj_liczbe():
    return int(input("Podaj liczbe: "))
def Suma_cyfr(liczba):
    suma=0
    liczba=abs(liczba)
    while(liczba>0):
        suma=suma+(liczba%10)
        liczba=int(trunc(liczba/10))
    return suma
def Wypisz_wynik(liczba,suma):
    print("Suma cyfr liczby",liczba,"to",suma)
def Glowna_procedura():
    liczba=Czytaj_liczbe()
    Wypisz_wynik(liczba,Suma_cyfr(liczba))
Glowna_procedura()
