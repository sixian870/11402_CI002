/*UVa10235
* 判斷輸入的 n
* 不為質數 (emirp)
* 為質數但不是回文質數 (not prime)
* 為質數且是回文質數 (emirp)
*/
#include<iostream>
using namespace std;
bool isPrime(int n) {
	if (n <= 1) return false;
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
int reverse_n(int n) {
	int r = 0;
	while (n != 0) {
		r = ((r * 10) + (n % 10)); //r += ((r * 10) + (n % 10));
		n /= 10;
	}
	return r;
}
int main() {
	int n;
	while (cin >> n) {
		if (!isPrime(n)) {
			cout << n << " is not prime.\n";
		}
		else {
			int r = reverse_n(n);
			if (n != r && isPrime(r)) {
				cout << n << " is emirp.\n";
			}
			else {
				cout << n << " is prime.\n";
			}
		}
	}
	return 0;
}