program rok_przestepny;

function Czytaj_rok: Integer;
var
   rok: Integer; 
begin
   write('Podaj rok: ');
   readln(rok);
   Czytaj_rok:=rok;
end;

function Czy_przestepny(rok :Integer ): Boolean;
begin
   Czy_przestepny:= ((rok mod 4 = 0) AND (NOT (rok mod 100 = 0)) ) OR (rok mod 400 = 0); 
end;

procedure Wypisz_czy_przestepny(rok : Integer; przestepny: Boolean );
begin
  if przestepny then
     writeln('Rok ', rok, ' jest przestepny')
  else
     writeln('Rok ', rok, ' nie jest przestepny');
end;

procedure Glowna_procedura;
var
   rok        : Integer;
   przestepny : Boolean;
begin
   rok:= Czytaj_rok();
   przestepny:= Czy_przestepny(rok);
   Wypisz_czy_przestepny(rok,przestepny);
end;

begin
   Glowna_procedura()
end.
