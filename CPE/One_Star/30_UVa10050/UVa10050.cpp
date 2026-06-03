/*UVa10050
1    // 共有 1 個測資案例
14   // 案例 1：共 14 天
3    // 有 3 個政黨
3    // 政黨 1：間隔 3 天
4    // 政黨 2：間隔 4 天
8    // 政黨 3：間隔 8 天
算浪費幾天工作日，從星期日開始，五六不算!!!
Su Mo Tu We Th Fi Sa Su Mo Tu We Th Fi Sa
      a        x        a        a
         b           b           b
                     c
Total: 5
*/
#include<iostream>
#include<vector>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int count = 0;
        int d, n;
        cin >> d >> n;
		vector<bool> totalday(d + 1, false); //index = 1~d // false: 工作日, true: 休息日
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        for (int i = 1; i <= d; i++) { // 1-n day
            for (int j = 0; j < n; j++) { // p[j]
                if (i % p[j] == 0) {
					totalday[i] = true;
                    if (i % 7 == 6 || i % 7 == 0) {
                        totalday[i] = false; // 五六
                    }
                }
            }
        }
        for (int i = 1; i <= d; i++) {
            if (totalday[i] == true) {
				count++;
            }
        }
        cout << count << "\n";
    }
    return 0;
}