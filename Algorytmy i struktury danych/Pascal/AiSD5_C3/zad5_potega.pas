program potega;
function potega_iter(a : Integer ;n : Integer ) : Integer;
var
   wynik, i : Integer;
begin
   wynik := 1;
   for i := 1 to n do
      wynik:= wynik*a;
   potega_iter:= wynik;
end;

function potega_rek(a : Integer ;n : Integer ) :Integer;
begin
   if n = 0 then
      potega_rek:= 1
   else
      potega_rek:= a * potega_rek(a,n-1);
end;


function potega_iter_kwr(a : Integer ;n : Integer ) : Integer;
var
   wynik : Integer;
begin
   wynik := 1;
   if n = 1 then
      wynik:=a;
   while n>1 do
   begin
      if n mod 2 = 1 then
        begin
           wynik:=a*wynik;
           n:=n-1;
        end
     else
        begin
           wynik:=a*a*wynik;
           n:=n div 2;
        end;
     end;
   potega_iter_kwr:=wynik;
end;

function potega_rek_kwr(a : Integer ;n : Integer ) :Integer;
var
   wynik :  Integer;
begin
   wynik:=0;
   if n = 0 then
      potega_rek_kwr:= 1
   else if n mod 2 = 1 then
      potega_rek_kwr:= a * potega_rek_kwr(a,n-1)
   else
      begin
         wynik := potega_rek_kwr(a, n div 2);
         potega_rek_kwr:=wynik*wynik;
      end;
end;

begin
   WriteLn('Potega Iteracyjna: ', potega_iter(2,3));
   WriteLn('Potega Rekurencyjna: ', potega_rek(2,3));
   WriteLn('Potega Iteracyjna Kwadratowa: ', potega_iter_kwr(2,3));
   WriteLn('Potega Rekurencyjna Kwadratowa: ', potega_rek_kwr(2,3));
end.
