/*UVa12347*/
#include<iostream>
#include<vector>
using namespace std;

vector<int> pre;

void solve(int l, int r) {
	if (l > r) return;
	int root = pre[l];
	int split = l + 1;
	while (split <= r && pre[split] < root) split++;
	solve(l + 1, split - 1);
	solve(split, r);
	cout << root << endl;
}

int main() {
	int n;
	while (cin >> n) pre.push_back(n);
	if (!pre.empty()) solve(0, pre.size() - 1);
	return 0;
}