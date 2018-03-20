#include <iostream>
#include <fstream> // zapis/odczyt do/z pliku
#include <string> // zmienne typu string
#include <stack>

using namespace std;

int main(int argc, char *argv[])
{
	// wczytaj nazwe pliku z danymi do zmiennej input
	string input = argv[1];

	// zdefiniuj i otworz strumien wejscia dla pliku z notacja nawiasowa
	ifstream ifs;
	ifs.open(input);

	if (!ifs.is_open()) {
		cerr << "Problem z odczytem pliku: " << input << '\n';
		getchar();
		exit(0);
	}

	stack <char> s;

	char t; // zmienna pomocnicza

	while(1){
		//getline()
		while (1) { // Poki zostały symbole do przeczytania wykonuj:
		// Przeczytaj symbol.
			ifs >> t;
			if (ifs.eof()) break;

			if (t > 96 && t < 123) cout << t; // Jeśli symbol jest a-z dodaj go do kolejki wyjście

			// Jeśli symbol jest operatorem, o1 wtedy:
			else if (t == '+' || t == '-') { //
				while ((!(s.empty())) && (s.top() == '+' || s.top() == '-' || s.top() == '*' || s.top() == '/' || s.top() == '^')) {
					cout << s.top();
					s.pop(); // zdejmij ze stosu
				}
				s.push(t);
			}

			else if (t == '*' || t == '/') { //
				while ((!(s.empty())) && (s.top() == '*' || s.top() == '/' || s.top() == '^')) {
					cout << s.top();
					s.pop(); // zdejmij ze stosu
				}
				s.push(t);
			}

			else if (t == '^') { //  inaczej - prawostronnie łaczny operator
				s.push(t);
			}

			else if (t == '(') { // Jeżeli symbol jest lewym nawiasem to włóż go na stos.
				s.push(t);
			}

			else if (t == ')') {// Jeżeli symbol jest prawym nawiasem
			// nie sprawdzam czy stos jest pusty, zakladam ze nie jest
				while (s.top() != '(') { // zdejmuj operatory ze stosu i dokładaj je do kolejki wyjście, dopóki symbol na górze stosu nie jest lewym nawiasem
					cout << s.top();
					s.pop();
				}
				// symbol na górze stosu jest lewym nawiasem
				s.pop(); // zdejmij lewy nawias ze stosu bez dokładania go do kolejki wyjście
			}

			if (ifs.peek() == '\n' || ifs.eof()) break; //na koncu kazdego wersu trzeba wyczyscic stos
		}

		//zdejmij reszte operatorów ze stosu jeśli ten jest niepusty
		while (!(s.empty())) {
			cout << s.top();
			s.pop();
		}
		cout << '\n';

		if (ifs.eof()) break;
		/*
		if (ifs.fail()) {
			cerr << "Blad po probie odczytu kolejnego symbolu";
			getchar();
			exit(0);
		}
		*/
	}

	// zamknij strumien wejscia
	ifs.close();

	system("pause");

	return 0;
}

