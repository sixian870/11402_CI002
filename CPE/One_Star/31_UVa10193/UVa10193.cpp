/*UVa10193
輸入兩個二進位字串 轉成十進位後 若兩者最大公因數不為 1 輸出 All you need is love!
*/
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main() {
	int t;
	cin >> t;
	int count = 1;
	while (t--) {
		string s1, s2;
		int n1 = 0, n2 = 0;
		cin >> s1 >> s2;
		int p1 = 0;
		for (int i = s1.size() - 1; i >= 0; i--) { // size()=3 i=2,1,0 -> s1[2],s1[1],s1[0]
			n1 += (s1[i] - '0') * pow(2, p1);
			p1++;
		}
		int p2 = 0;
		for (int i = s2.size() - 1; i >= 0; i--) {
			n2 += (s2[i] - '0') * pow(2, p2);
			p2++;
		}
		cout << "Pair #" << count++ << ": ";
		if (gcd(n1, n2) == 1) {
			cout << "Love is not all you need!\n";
		}
		else {
			cout << "All you need is love!\n";
		}
	}
	return 0;
}