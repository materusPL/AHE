program silnia_czas;
uses sysUtils;
function Czytaj_liczbe: Int64;
var
   liczba : Int64;
begin
   Write('Podaj liczbe calkowita: ');
   ReadLn(liczba);
   Czytaj_liczbe := liczba;
end;

function Silnia_rekurencyjna(n: Int64): Int64;
begin
   if n = 0 then
      Silnia_rekurencyjna := 1
   else
      Silnia_rekurencyjna := n * Silnia_rekurencyjna(n - 1);
end;

function Silnia_iteracyjna(n: Int64): Int64;
var
   wynik, i : Int64;
begin
   wynik := 1;
   for i := 1 to n do
      wynik := wynik * i;
   Silnia_iteracyjna := wynik;
end;

procedure Wypisz_wyniki(liczba,ile,wynikRek, wynikIter : Int64; CzasI, CzasR : TdateTime);
begin
   writeln('Podana liczba: ', liczba);
   writeln('Podana liczba iteracji', ile);
   writeln('Czas silni rekurencyjnej: ', CzasR:0:2, ' sekund');
   WriteLn('Silnia rekurencyjna: ', wynikRek:10);
   writeln('Czas silni iteracyjnej: ', CzasI:0:2, ' sekund');
   WriteLn('Silnia iteracyjna:   ', wynikIter:10);
end;


procedure Glowna_procedura;
var
   CzasI, CzasR   : TdateTime;
   i              : Int64;
   ile, liczba    : Int64;
   wynikI, wynikR : Int64;
begin
   liczba := Czytaj_liczbe();
   Write('Podaj liczbe iteracji: ');
   ReadLn(ile);
   CzasI := Time();
   for i  := 0 to ile do
      wynikI := Silnia_iteracyjna(liczba);
   CzasI := Time()-CzasI;
   CzasI := CzasI*24*60*60;


   CzasR := Time();
   for i := 0 to ile do
      wynikR := Silnia_rekurencyjna(liczba);
   CzasR := Time()-CzasR;
   CzasR := CzasR*24*60*60;
   

   Wypisz_wyniki(liczba,ile,wynikR,wynikI,CzasI,CzasR);

end;

begin
   Glowna_procedura()
end.
