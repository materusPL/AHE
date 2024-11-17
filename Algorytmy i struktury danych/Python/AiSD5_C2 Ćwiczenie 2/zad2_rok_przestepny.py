def Czytaj_rok():
    rok = int(input("Podaj rok: "))
    return rok;
def Czy_przestepny(rok):
    return ((rok%4==0) and not (rok%100==0)) or (rok % 400 == 0)
def Wypisz_czy_przestepny(rok,przestepny):
    if(przestepny):
        print("Rok", rok, "jest przestepny")
    else:
        print("Rok", rok, "nie jest przestepny")
def Glowna_procedura():
    rok = Czytaj_rok()
    Wypisz_czy_przestepny(rok,Czy_przestepny(rok))

Glowna_procedura()
