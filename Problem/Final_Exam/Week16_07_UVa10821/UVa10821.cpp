#include <bits/stdc++.h>
using namespace std;

void build(long long L, long long R, int H) {
    if (L > R) return;
    long long K;
    if (H - 1 >= 30) {
        K = L;
    } else {
        long long max_right = (1LL << (H - 1)) - 1;
        long long required_k = R - max_right;
        K = max(L, required_k);
    }
    cout << " " << K;
    build(L, K - 1, H - 1);
    build(K + 1, R, H - 1);
}

int main() {
    long long N;
    int H;
    int case_num = 1;
    while (cin >> N >> H && (N != 0 || H != 0)) {
        cout << "Case " << case_num++ << ":";
       
        if (H < 30 && N > (1LL << H) - 1) {
            cout << " Impossible.\n";
        } else {
            build(1, N, H);
            cout << "\n";
        }
    }
    return 0;
}
