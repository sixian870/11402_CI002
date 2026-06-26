#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Segment {
    int l;
    int r;
};

bool cmp(const Segment& a, const Segment& b) {
    return a.l < b.l;
}

int main() {
    int t;
    cin >> t;

    bool first_case = true;

    while (t--) {
        int m;
        cin >> m;
        vector<Segment> segments;
        int l, r;
        while (cin >> l >> r && (l != 0 || r != 0)) {
            if (r <= 0) continue;
            segments.push_back({ l, r });
        }
        sort(segments.begin(), segments.end(), cmp);

        int current_L = 0;
        int i = 0;
        vector<Segment> result;
        bool success = false;
        while (current_L < m) {
            int max_R = current_L;
            int best_idx = -1;
            while (i < segments.size() && segments[i].l <= current_L) {
                if (segments[i].r > max_R) {
                    max_R = segments[i].r;
                    best_idx = i;
                }
                i++;
            }
            if (best_idx == -1) {
                break;
            }
            result.push_back(segments[best_idx]);
            current_L = max_R;
            if (current_L >= m) {
                success = true;
                break;
            }
        }
        if (!first_case) {
            cout << "\n";
        }
        first_case = false;
        if (success) {
            cout << result.size() << "\n";
            for (const auto& seg : result) {
                cout << seg.l << " " << seg.r << "\n";
            }
        }
        else {
            cout << "0\n";
        }
    }
    return 0;
}