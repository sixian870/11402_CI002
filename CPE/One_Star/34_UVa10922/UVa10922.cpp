/*UVa10922
判斷是否為9的倍數(加總可被9整除)
若不是就直接輸出
若是就計算degree
99999999999999999999 ***超過long long 要用string
第一次總和：9*20 = 180(Degree = 1)
第二次總和：1+8+0 = 9 (Degree = 2)
最終結果為 9，所以 Degree 是 2
*/
#include<iostream>
using namespace std;

int getsum(string s) {
	int sum = 0;
	for (char c : s) {
		sum += (c - '0');//string轉int
	}
	return sum;
}
int main() {
	string s;
	while (cin >> s && s != "0") {
		int sum = getsum(s);
		if (sum % 9 != 0) {
			cout << s << " is not a multiple of 9.\n";
		}
		else {
			int degree = 1;
			while (sum != 9) {//sum=180
				int digit = 0;
				int temp_sum = sum;
				while (temp_sum > 0) { //temp_sum=180
					digit += (temp_sum % 10);
					temp_sum /= 10;
				}
				sum = digit;
				degree++;
			}
			cout << s << " is a multiple of 9 and has 9-degree " << degree << ".\n";
		}
	}
	return 0;
}