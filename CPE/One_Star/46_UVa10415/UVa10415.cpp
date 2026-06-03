/*UVa10415 - Eb Alto Saxophone
沒按->按,count+1
*/
#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

map<char, vector<int>> finger = {
	{'c',{2,3,4,7,8,9,10}},
	{'d',{2,3,4,7,8,9}},
	{'e',{2,3,4,7,8}},
	{'f',{2,3,4,7}},
	{'g',{2,3,4}},
	{'a',{2,3}},
	{'b',{2}},
	{'C',{3}},
	{'D',{1,2,3,4,7,8,9}},
	{'E',{1,2,3,4,7,8}},
	{'F',{1,2,3,4,7}},
	{'G',{1,2,3,4}},
	{'A',{1,2,3}},
	{'B',{1,2}}
};

int main() {
	int t;
	cin >> t;
	cin.ignore();
	while (t--) {
		string s;
		//cin >> s;可能有空字串
		getline(cin, s);
		vector<int> count(10, 0); //index 0~9
		vector<bool> pressed(11, false); //index 1~10
		for (char c : s) {
			vector<int> now = finger[c];
			vector<bool> next(11, false);
			for (int i : now) {
				next[i] = true;
			}
			for (int i = 1; i <= 10; i++) {
				if (next[i] == true && pressed[i] == false) {
					count[i - 1]++;
				}
			}
			pressed = next;
		}
		for (int i = 0; i < 10; i++) {
			cout << count[i] << (i == 9 ? "" : " ");
		}
		cout << endl;
	}
	return 0;
}