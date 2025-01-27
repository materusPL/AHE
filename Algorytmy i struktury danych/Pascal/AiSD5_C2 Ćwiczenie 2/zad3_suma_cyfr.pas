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
var suma : Integer;
begin
   suma:=0;
   liczba:=abs(liczba);
   while liczba>0 do
   begin
      suma:=suma+(liczba mod 10);
      liczba:=trunc(liczba/10);
   end;
   Suma_cyfr:=suma;
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
