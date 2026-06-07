/* UVa10908
* 測資組數
* m*n ,問題數量
* 每個問題的輸入
* 找出與中心點字母相同的最大正方形邊
*/
#include<iostream>
#include<vector>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int m, n, tt;
		cin >> m >> n >> tt;
		vector<vector<char>> M(m, vector<char>(n));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> M[i][j];
			}
		}
		cout << m << " " << n << " " << tt << "\n";
		while (tt--) {
			int row, col;
			cin >> row >> col;
			int target = M[row][col];
			int ans = 1;
			int r = 1;
			bool same = true;
			while (same) {
				if (row - r < 0 || row + r >= m || col - r < 0 || col + r >= n) {
					break;
				}
				for (int i = row - r; i <= row + r; i++) {
					for (int j = col - r; j <= col + r; j++) {
						if (M[i][j] != target) {
							same = false;
							break; //只能跳一個迴圈
						}
					}
					if (!same) break; //再跳一個迴圈
				}
				if (same) {
					ans += 2;
					r++;
				}
			}	
			cout << ans << "\n";
		}
	}
	return 0;
}