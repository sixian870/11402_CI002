/*UVa10190
n/m until n=1
若無法整除 output:Boring!
若m<2||n<1 output:Boring!
*/
#include <iostream>
#include <vector>

using namespace std;

void solve(long long n, long long m) {
    // 邊界條件：m < 2 是無效的，且 n 必須大於 0
    if (m < 2 || n < 2) {
        cout << "Boring!" << endl;
        return;
    }
    vector<long long> result;
    long long temp = n;

    while (temp > 1) {
        if (temp % m != 0) {
            cout << "Boring!" << endl;
            return;
        }
        temp /= m;
        result.push_back(temp);
    }

    cout << n;
    for (long long val : result) {
        cout << " " << val;
    }
    cout << endl;
}

int main() {
    long long n, m;
    while (cin >> n >> m) {
        solve(n, m);
    }
    return 0;
}