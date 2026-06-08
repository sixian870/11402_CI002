/*UVa10405
* 找最常共同子序列長度
* 
*   . A B C D
* . 0 0 0 0 0
* C 0 0 0 1 0
* A 0 1 0 1 1
* B 0 1 2 2 2
**相同就取左上角值+1
**不同取max(上面值,左邊值)
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	string s1, s2;
	while (getline(cin, s1) && getline(cin, s2)) {
		vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
		for (int i = 1; i <= s1.size(); i++) {
			for (int j = 1; j <= s2.size(); j++) {
				if (s1[i-1] == s2[j-1]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else if (s1[i - 1] != s2[j - 1]) {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		cout << dp[s1.size()][s2.size()] << endl;
	}
	return 0;
}
