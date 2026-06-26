#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int main() {
    unsigned long long dp[65][65];
    memset(dp, 0, sizeof(dp));
    for (int b = 0; b <= 60; b++) {
        dp[0][b] = 1;
        dp[1][b] = 1;
    }
    for (int n = 2; n <= 61; n++) {
        for (int b = 0; b <= 60; b++) {
            dp[n][b] = 1;
            for (int i = 1; i <= b; i++) {
                if (n - i <= 0) {
                    dp[n][b] += dp[0][b];
                }
                else {
                    dp[n][b] += dp[n - i][b];
                }
            }
        }
    }

    int n, back;
    int case_num = 1;
    while (cin >> n >> back && n <= 60) {
        if (n < 0) {
            cout << "Case " << case_num++ << ": " << 1 << "\n";
        }
        else {
            cout << "Case " << case_num++ << ": " << dp[n][back] << "\n";
        }
    }
    return 0;
}