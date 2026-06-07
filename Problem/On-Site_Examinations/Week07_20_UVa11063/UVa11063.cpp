/*UVa11063
* 判斷數列是否嚴格遞增且皆大於等於 0，且任兩數之和皆不重複
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n;
	int count = 1;
	while (cin >> n) {
		bool isB2 = true;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (i == 0) {
				if (a[0] <= 0) {
					isB2 = false;
				}
			}
			else if (i > 0) {
				if (a[i] <= a[i - 1]) {
					isB2 = false;
				}
			}
		}
		cout << "Case #" << count++ << ": ";
		if (isB2) {
			vector<int> sum;
			for (int i = 0; i < n; i++) { //0 00 01 02 1 11 12 2 22
				for (int j = i ; j < n; j++) {
					sum.push_back(a[i] + a[j]);
				}
			}
			sort(sum.begin(), sum.end());
			for (int i = 1; i < sum.size(); i++) {
				if (sum[i] == sum[i - 1]) {
					isB2 = false;
					break;
				}
			}
		}
		if (isB2) {
			cout << "It is a B2-Sequence.\n";
		}
		else {
			cout << "It is not a B2-Sequence.\n";
		}
		cout << "\n";
	}
	return 0;
}