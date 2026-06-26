#include<iostream>
using namespace std;
int main() {
	string s;
	int count = 1;
	while (cin >> s && s != "#") {
		cout << "Case " << count++;
		if (s == "HELLO") {
			cout << ": ENGLISH\n";
		}
		else if (s == "HOLA") {
			cout << ": SPANISH\n";
		}
		else if (s == "HALLO") {
			cout << ": GERMAN\n";
		}
		else if (s == "BONJOUR") {
			cout << ": FRENCH\n";
		}
		else if (s == "CIAO") {
			cout << ": ITALIAN\n";
		}
		else if (s == "ZDRAVSTVUJTE") {
			cout << ": RUSSIAN\n";
		}
		else {
			cout << ": UNKNOWN\n";
		}
	}
	return 0;
}