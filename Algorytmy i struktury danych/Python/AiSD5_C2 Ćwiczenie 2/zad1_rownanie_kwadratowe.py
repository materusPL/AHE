import math;

a = float(input("Podaj a: "))
b = float(input("Podaj b: "))
c = float(input("Podaj c: "))

if(a==0):
    x=c/b
    print("To jest rownanie liniowe\n", x)
else:
    Delta=b*b-4*a*c
    if (Delta < 0):
        print("Brak rozwiazan")
    elif (Delta > 0):
        x1=(-b - math.sqrt(Delta))/(2*a)
        x2=(-b + math.sqrt(Delta))/(2*a)
        print('Dwa pierwiastki\n', x1,'\n', x2)
    else:
        x=b/(2*a)
        print('Jeden pierwiastek\n',x); 
