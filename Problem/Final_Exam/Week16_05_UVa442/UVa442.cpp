#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    if (!(cin >> n)) return 0;
    unordered_map<char, pair<long long, long long>> matrices;
    for (int i = 0; i < n; ++i) {
        char name;
        long long r, c;
        cin >> name >> r >> c;
        matrices[name] = {r, c};
    }
    string expr;
    while (cin >> expr) {
        stack<pair<long long, long long>> st;
        bool error = false;
        long long ans = 0;
        for (char ch : expr) {
            if (isalpha(ch)) {
                st.push(matrices[ch]);
            } else if (ch == ')') {
                if (st.size() < 2) {
                    error = true;
                    break;
                }
               
                auto m2 = st.top();
                st.pop();
                auto m1 = st.top();
                st.pop();

                if (m1.second != m2.first) {
                    error = true;
                    break;
                }

                ans += m1.first * m1.second * m2.second;
                st.push({m1.first, m2.second});
            }
        }
        if (error) {
            cout << "error\n";
        } else {
            cout << ans << "\n";
        }
    }
    return 0;
}
