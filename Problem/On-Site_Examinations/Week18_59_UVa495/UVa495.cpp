#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	vector<string> a(5001);
	a[0] = "0";
	a[1] = "1";
	for (int i = 2; i <= 5000; i++) {
		string b = a[i - 1];
		string c = a[i - 2];
		int carry = 0;
		int j = b.length() - 1;
		int k = c.length() - 1;
		while (j >= 0 || k >= 0 || carry > 0) {
			int sum = carry;
			if (j >= 0) {
				sum += b[j] - '0';
				j--;
			}
			if (k >= 0) {
				sum += c[k] - '0';
				k--;
			}
			a[i] += (sum % 10) + '0';
			carry = sum / 10;
		}
		reverse(a[i].begin(), a[i].end());
	}
	int x;
	while (cin >> x) {
		cout << "The Fibonacci number for " << x << " is " << a[x] << endl;
	}
	return 0;
}