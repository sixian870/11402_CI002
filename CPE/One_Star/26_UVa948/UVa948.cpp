/*UVa948
1 = 1 (fib)
2 = 10 (fib)
3 = 100 (fib)
4 = 101 (fib)
5 = 1000 (fib)
6 = 1001 (fib)
7 = 1010 (fib)
8 = 10000 (fib)
9 = 10001 (fib)
10 = 10010 (fib)
fib = 0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584
因為輸入 n < 100,000,000
fib[40]=102334155
所以 index 上限為 39

#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<long long> fib;
	fib.push_back(0);
	fib.push_back(1);
	for (int i = 2; i < 50; i++) {
		fib.push_back(fib[i - 1] + fib[i - 2]);
	}
	for (int i = 2; i < 50; i++) {
		cout << i << "=" << fib[i] << "\n";
	}
}
*/
#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<long long> fib(40);//index=0~39,填 0,不能用 push_back()
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i < 40; i++) {
		fib[i] = (fib[i - 1] + fib[i - 2]);
	}
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int idx;
		for (int i = 39; i > 1; i--) {
			if (fib[i] <= n) {
				idx = i;
				break;
			}
		}
		cout << n << " = ";
		for (int i = idx; i > 1; i--) {
			if (n >= fib[i]) {
				cout << "1";
				n -= fib[i];
			}
			else {
				cout << "0";
			}
		}
		cout << " (fib)\n";
	}
	return 0;
}