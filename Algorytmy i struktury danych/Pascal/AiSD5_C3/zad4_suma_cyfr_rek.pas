program suma_cyfr;
function Czytaj_liczbe : Integer;
var
   liczba : Integer;
begin
   write('Podaj liczbe: ');
   readln(liczba);
   Czytaj_liczbe:=liczba;
end;

function Suma_cyfr(liczba : Integer) : Integer;
begin
   if liczba = 0 then
      Suma_cyfr:=0
   else
      Suma_cyfr:= (abs(liczba) mod 10) + Suma_cyfr(liczba div 10);
end;

procedure Wypisz_wynik(liczba : Integer; suma : Integer );
begin
   writeln('Suma cyfr liczby ', liczba, ' to ', suma);
end;

procedure Glowna_procedura;
var liczba : Integer;
begin
   liczba:=Czytaj_liczbe();
   Wypisz_wynik(liczba,Suma_cyfr(liczba));
end;

begin
   Glowna_procedura();
end.
