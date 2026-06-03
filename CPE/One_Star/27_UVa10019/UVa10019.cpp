/*UVa10019
input M
output b1,b2
b1:M(秈)->秈,参璸1
M=1234,b1=10011010010,1计=5
b2:M(16秈)->10秈->秈,参璸1
M=1234
1=0001
2=0010
3=0011
4=0100
b2=0001 0010 0011 0100,1计=5
*****__builtin_popcount(n);钡盢秈锣Θ秈璸衡计
*/
#include<iostream>
#include<algorithm>
using namespace std;
int count(int n) {
	return __builtin_popcount(n);
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int m;
		cin >> m;
		int b1 = count(m);
		int b2 = 0;
		while (m > 0) {
			int digit = m % 10;
			b2 += count(digit);
			m /= 10;
		}
		cout << b1 << " " << b2 << "\n";
	}
	return 0;
}