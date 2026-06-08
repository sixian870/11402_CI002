/*UVa1121
一個由 N 個正整數組成的陣列，找到一段「連續的子陣列」滿足：
1.連續數字的總和必須大於或於 S
2.連續數字的長度要越短越好
如果把整個陣列全部加起來都達不到 S，就輸出 0。
目標 S = 15，陣列 [5,1,3,5,10,7]
right++:[5,1,3,5] = 14 (還不夠 15)
right++:[5,1,3,5,10] = 24 (大於15) 最短長度 = 5
left++：[1,3,5,10] = 19 (大於15) 最短長度 = 4
left++：[3,5,10] = 18 (大於15) 最短長度 = 3
left++：[5,10] = 15 (等於15) 最短長度 = 2
left++：[10] = 10 (小於15) 最短長度 = 2
right++:[10,7] = 17(大於15) 最短長度 = 2
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n, s;
	while (cin >> n >> s) {
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int d = 100000;
		int left = 0;
		int sum = 0;
		for (int right = 0; right < n; right++) {
			sum += a[right];
			while (sum >= s) { //達標
				d = min(d, (right - left + 1));//進來先算距離
				sum -= a[left];
				left++;
			}
		}
		if (d == 100000) { //沒被改過
			cout << "0\n";
		}
		else {
			cout << d << "\n";
		}
	}
	return 0;
}