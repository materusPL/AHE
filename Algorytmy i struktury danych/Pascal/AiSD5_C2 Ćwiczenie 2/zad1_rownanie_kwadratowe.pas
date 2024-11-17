program rownanie_kwadratowe;
var
   a,b,c   : Double;
   x,x1,x2 : Double;
   Delta   : Double;
begin
   write('Podaj a: ');
   ReadLn(a);
   write('Podaj b: ');
   ReadLn(b);
   write('Podaj c: ');
   ReadLn(c);


   
   if a=0 then
   begin
      x:=c/b;
      writeln('To jest rownanie liniowe');
      writeln(x:0:5); // Wypisze pięć miejsc po przecinku zamiast naukowej notacji
   end else
   begin
      Delta:=b*b-4*a*c;
      if Delta < 0 then
         writeln('Brak rozwiazan')
      else
      begin
         if Delta > 0 then
         begin
            x1:=(-b - Sqrt(Delta))/(2*a);
            x2:=(-b + Sqrt(Delta))/(2*a);
            writeln('Dwa pierwiastki');
            writeln(x1:0:5);
            writeln(x2:0:5);
         end else 
         begin
            x:=b/(2*a);
            writeln('Jeden pierwiastek');
            writeln(x:0:5);
         end;
      end;
      
   end;
end.
