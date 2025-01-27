program silnia;
function Czytaj_liczbe: Int64;
var
  liczba: Int64;
begin
  Write('Podaj liczbę calkowita: ');
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
  wynik, i: Int64;
begin
  wynik := 1;
  for i := 1 to n do
    wynik := wynik * i;
  Silnia_iteracyjna := wynik;
end;

procedure Wypisz_wyniki(wynikRek, wynikIter: Int64);
begin
   WriteLn('Silnia rekurencyjna: ', wynikRek:10);
   WriteLn('Silnia iteracyjna:   ', wynikIter:10);
end;

procedure Glowna_procedura;
var
  liczba, wynikRek, wynikIter: Int64;
begin
  liczba := Czytaj_liczbe;
  if liczba < 0 then
  begin
    WriteLn('Silnia jest zdefiniowana tylko dla liczb nieujemnych.');
    Exit;
  end;

  wynikRek := Silnia_rekurencyjna(liczba);
  wynikIter := Silnia_iteracyjna(liczba);
  Wypisz_wyniki(wynikRek, wynikIter);
end;

begin
   Glowna_procedura()
end.
