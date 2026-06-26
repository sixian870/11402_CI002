#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int C, S;
    int TC = 0;
   
    while (cin >> C >> S) {
        int n = 2 * C;
        vector<int> a(n, 0);
        double sum = 0.0;
       
        for (int i = 0; i < S; i++) {
            cin >> a[i];
            sum += a[i];
        }
       
        double avg = sum / C;
        sort(a.begin(), a.end());
       
        double imbalance = 0.0;
        cout << "Set #" << ++TC << "\n";
       
        for (int i = 0; i < C; i++) {
            cout << setw(2) << i << ":";
           
            if (a[i] != 0) {
                cout << " " << a[i];
            }
            if (a[n - 1 - i] != 0) {
                cout << " " << a[n - 1 - i];
            }
           
            imbalance += abs(a[i] + a[n - 1 - i] - avg);
            cout << "\n";
        }
       
        cout << "IMBALANCE = " << fixed << setprecision(5) << imbalance << "\n\n";
    }
   
    return 0;
}
