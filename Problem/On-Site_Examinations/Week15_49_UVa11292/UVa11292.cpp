#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n, m;
	while (cin >> n >> m && (n != 0 && m != 0)) {
		vector<int> d(n);
		for (int i = 0; i < n; i++) {
			cin >> d[i];
		}
		vector<int> k(m);
		for (int i = 0; i < m; i++) {
			cin >> k[i];
		}
		if (n > m) {
			cout << "Loowater is doomed!\n";
			continue;
		}
		sort(d.begin(), d.end());
		sort(k.begin(), k.end());

		int head = 0;
		int cost = 0;
		for (int i = 0; i < m; i++) {
			if (head == n) break;
			if (k[i] >= d[head]) {
				cost += k[i];
				head++;
			}
		}

		if (head == n) {
			cout << cost << "\n";
		}
		else {
			cout << "Loowater is doomed!\n";
		}
	}
	return 0;
}