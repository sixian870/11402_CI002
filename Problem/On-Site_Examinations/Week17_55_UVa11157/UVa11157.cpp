#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    if (!(cin >> T)) return 0;

    for (int t = 1; t <= T; ++t) {
        int N;
        long long D;
        cin >> N >> D;

        vector<long long> pos;
       
        pos.push_back(0);
        pos.push_back(0);

        for (int i = 0; i < N; ++i) {
            string stone;
            cin >> stone;
           
            long long m = stoll(stone.substr(2));
           
            if (stone[0] == 'B') {
                pos.push_back(m);
                pos.push_back(m);
            } else {
                pos.push_back(m);
            }
        }

        pos.push_back(D);
        pos.push_back(D);

        long long max_leap = 0;
       
        for (size_t i = 0; i < pos.size() - 2; ++i) {
            max_leap = max(max_leap, pos[i+2] - pos[i]);
        }
        cout << "Case " << t << ": " << max_leap << "\n";
    }
    return 0;
}
