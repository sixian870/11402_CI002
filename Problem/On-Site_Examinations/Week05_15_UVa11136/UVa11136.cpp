#include<iostream>
#include<set>
#include<iterator>
using namespace std;
int main() {
	int t;
	while (cin >> t && t != 0) {
		multiset<int> box;
		long long total = 0;
		for (int j = 0; j < t; j++) {
			int x;
			cin >> x;
			for (int i = 0; i < x; i++) {
				int a;
				cin >> a;
				box.insert(a);
			}
			auto ma = prev(box.end());
			auto mi = box.begin();
			total += (*ma - *mi);
			box.erase(mi);
			box.erase(ma);
		}
		cout << total << "\n";
	}
	return 0;
}