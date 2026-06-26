#include <bits/stdc++.h>
using namespace std;

int get_depth(int x) {
    int depth = 0;
    while (x > 0) {
        depth++;
        x >>= 1;
    }
    return depth;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (cin >> T) {
        while (T--) {
            int N, A, B;
            cin >> N >> A >> B;

            int max_depth = max(get_depth(A), get_depth(B));
           
            int H = N - max_depth + 1;
           
            int ans = (1 << N) - (1 << H) + 1;
           
            cout << ans << "\n";
        }
    }

    return 0;
}
