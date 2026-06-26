#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

bool check(int C, const vector<int>& milk, int m) {
    int count = 1;
    int current_weight = 0;
    for (int i = 0; i < milk.size(); i++) {
        if (milk[i] > C) return false;
        if (current_weight + milk[i] <= C) {
            current_weight += milk[i];
        }
        else {
            count++;
            current_weight = milk[i];
        }
    }
    return count <= m;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<int> milk(n);
        int sum = 0;
        int max_milk = 0;
        for (int i = 0; i < n; i++) {
            cin >> milk[i];
            sum += milk[i];
            max_milk = max(max_milk, milk[i]);
        }
        int low = max_milk;
        int high = sum;
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid, milk, m)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}