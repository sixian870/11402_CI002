/*UVa11005
* 測資組數
* 第一組價錢
* 第一組側資數量
* 中間空行
*/
#include<iostream>
#include<vector>
using namespace std;
int main() {
	int t;
	int count = 1;
	bool isFirst = true;
	cin >> t;
	while (t--) {
		vector<int> price(36); //index:0~35
		for (int i = 0; i < 36; i++) {
			cin >> price[i];
		}
		if(!isFirst) {
			cout << "\n";
		}
		cout << "Case " << count++ << ":\n";
		int tt;
		cin >> tt;
		while (tt--) {
			vector<int> cost(37); //index:0~36
			long long min_cost = 1e18;
			int n;
			cin >> n;
			for (int i = 2; i < 37; i++) { //2~36
				int temp = n; //換進位要重製 n
				if (temp == 0) {
					cost[i] = price[0]; //n=0
				}
				else {
					while (temp != 0) {
						cost[i] += price[temp % i];
						temp /= i;
					}
				}
				if (cost[i] < min_cost) {
					min_cost = cost[i];
				}
			}
			cout << "Cheapest base(s) for number " << n << ":";
			for (int i = 2; i < 37; i++) {
				if (cost[i] == min_cost) {
					cout << " " << i;
				}
			}
			cout << "\n";
		}
		isFirst = false;
	}
	return 0;
}