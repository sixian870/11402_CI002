#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, d, r;
    while (cin >> n >> d >> r && (n != 0 || d != 0 || r != 0)) {
        vector<int> morning(n);
        vector<int> afternoon(n);

        for (int i = 0; i < n; i++) cin >> morning[i];
        for (int i = 0; i < n; i++) cin >> afternoon[i];

        sort(morning.begin(), morning.end());
        sort(afternoon.begin(), afternoon.end(), greater<int>());

        int total_overtime_pay = 0;
        for (int i = 0; i < n; i++) {
            int total_distance = morning[i] + afternoon[i];
            if (total_distance > d) {
                total_overtime_pay += (total_distance - d) * r;
            }
        }
        cout << total_overtime_pay << "\n";
    }
    return 0;
}