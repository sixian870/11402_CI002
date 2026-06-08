/*UVa1062
* ACB
* [A]
* [A,C]
* [A,B]
*/
#include<iostream>
#include<vector>
using namespace std;
int main() {
	string s;
	int count = 1;
	while (cin >> s && s != "end") {
		vector<char> stack;
		for (int i = 0; i < s.size(); i++) {
			if (i == 0) stack.push_back(s[i]);
			int which = -1;
			int suitable = 'Z' + 1;
			for (int j = 0; j < stack.size(); j++) {
				if (s[i] <= stack[j]) {
					if (stack[j] < suitable) {
						suitable = stack[j];
						which = j;
					}
				}
			}
			if (which != -1) {
				stack[which] = s[i];
			}
			else {
				stack.push_back(s[i]);
			}
		}
		cout << "Case " << count++ << ": " << stack.size() << endl;
	}
}