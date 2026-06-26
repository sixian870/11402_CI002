/*UVa501
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int m, n;
		cin >> m >> n;
		vector<int> A(m);
		vector<int> u(n);
		for (int i = 0; i < m; i++) {
			cin >> A[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> u[i];
		}
		priority_queue<int> left; //top=Max
		priority_queue<int, vector<int>, greater<int>> right; //top=Min
		int a_idx = 0;
		int idx = 0;
		for (int i = 0; i < n; i++) {
			while (a_idx < u[i]) {
				int v = A[a_idx];
				if (!left.empty() && v < left.top()) {
					left.push(v);
				}
				else {
					right.push(v);
				}
				if (left.size() > idx) {
					right.push(left.top());
					left.pop();
				}
				a_idx++;
			}
			idx++;
			if (!right.empty()) {
				left.push(right.top());
				right.pop();
			}
			cout << left.top() << "\n";
		}
		if (t > 0) {
			cout << "\n";
		}
	}
	return 0;
}