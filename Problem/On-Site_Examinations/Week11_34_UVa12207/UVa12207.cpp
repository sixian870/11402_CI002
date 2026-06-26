#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    long long P;
    int C;
    int count= 1;
    while (cin >> P >> C && (P != 0 || C != 0)) {
        cout << "Case " << count++ << ":\n";
        deque<long long> dq;
        long long limit = min(P, (long long)C);
        for (long long i = 1; i <= limit; i++) {
            dq.push_back(i);
        }
        while (C--) {
            char cmd;
            cin >> cmd;
            if (cmd == 'N') {
                long long current = dq.front();
                cout << current << "\n";
                dq.pop_front();
                dq.push_back(current);
            }
            else if (cmd == 'E') {
                long long x;
                cin >> x;
                auto it = find(dq.begin(), dq.end(), x);
                if (it != dq.end()) {
                    dq.erase(it);
                }
                dq.push_front(x);
            }
        }
    }
    return 0;
}