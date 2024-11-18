from datetime import datetime
def Czytaj_liczbe():
    return int(input("Podaj liczbe calkowita: "))
def Silnia_rekurencyjna(n):
    if(n==0):
        return 1
    else:
        return n * Silnia_rekurencyjna(n-1);
def Silnia_iteracyjna(n):
    wynik = 1
    for i in range(1,n+1):
        wynik = wynik*i
    return wynik
def Wypisz_wynikli(liczba,ile,wynikRek,wynikIter,CzasI,CzasR):
    print("Podana liczba:", liczba);
    print("Podana liczba iteracji", ile);
    print("Czas silni rekurencyjnej:", CzasR, 'sekund');
    print("Silnia rekurencyjna:", wynikRek);
    print("Czas silni iteracyjnej:", CzasI, 'sekund');
    print("Silnia iteracyjna:", wynikIter);
def Glowna_procedura():
    wynikR = 0
    wynikI = 0
    liczba = Czytaj_liczbe()
    ile = int(input("Podaj liczbe iteracji: "))
    CzasI = datetime.today()
    for i in range(0,ile+1):
        wynikI = Silnia_iteracyjna(liczba)
    CzasI = datetime.today() - CzasI
    CzasI = CzasI.seconds+CzasI.microseconds*0.000001

    CzasR = datetime.today()
    for i in range(0,ile+1):
        wynikR = Silnia_rekurencyjna(liczba)
    CzasR = datetime.today() - CzasR
    CzasR = CzasR.seconds+CzasR.microseconds*0.000001

    Wypisz_wynikli(liczba,ile,wynikR,wynikI,CzasI,CzasR)

Glowna_procedura()
