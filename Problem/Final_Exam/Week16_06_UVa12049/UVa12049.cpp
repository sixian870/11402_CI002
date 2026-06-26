#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    if (cin >> T) {
        while (T--) {
            int N, M;
            cin >> N >> M;
            map<int, int> freq;
            for (int i = 0; i < N; ++i) {
                int val;
                cin >> val;
                freq[val]++;
            }
            for (int i = 0; i < M; ++i) {
                int val;
                cin >> val;
                freq[val]--;
            }
            int removed = 0;
            for (const auto& pair : freq) {
                removed += abs(pair.second);
            }
            cout << removed << "\n";
        }
    }
    return 0;
}
