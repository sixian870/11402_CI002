/*UVa11364
* 一條街給定 n 家商店的 x 座標
* ____23_______40________78______98___
* 小名需要選一家商店停車 下車去把每家商店走完再回去停車的地方
* Result:不管停在哪都要來回走兩遍
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		int b = a[0];
		int c = a[n - 1];
		cout << (c - b) * 2 << endl;
	}
	return 0;
}