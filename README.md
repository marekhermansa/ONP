# RPN

Opis działania:
Program dokonuje translacji wyrażeń z postaci nawiasowej na ONP (ang. RPN); wyrażenia postaci nawiasowej wczytuje z pliku *.txt; wynik w postaci ONP wyświetla w oknie konsoli.

Przykładowe wywołanie programu:
Translator.exe input.txt

Przykładowy plik wejsciowy input.txt:
x+y
x+y^z
x^y^z
a+b*c
((a)+b*c)*(d*(e+f)+g)*h
((a-b)/c*d*e)^f^g
