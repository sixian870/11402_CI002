/*UVa10226
讀取樹木種類照字母排序輸出佔比
*/
#include<iostream>
#include<string>
#include<map>
#include<iomanip>
using namespace std;
int main() {
	int t;
	cin >> t;
	cin.ignore();
	string s;
	getline(cin, s);
	bool isFirst = true;
	while (t--) {
		map<string, int> tree;
		int total = 0;
		while (getline(cin, s) && !s.empty()) {
			tree[s]++;
			total++;
		}
		if (!isFirst) cout << "\n";
		for (auto const& i : tree) {
			cout << i.first << " " << fixed << setprecision(4) << (double)i.second / total * 100 << endl;
		}
		isFirst = false;
	}
	return 0;
}