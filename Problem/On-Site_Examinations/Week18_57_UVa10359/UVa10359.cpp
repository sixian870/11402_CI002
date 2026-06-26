#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string stringAdd(string a, string b) {
    string result = "";
    int i = a.length() - 1;
    int j = b.length() - 1;
    int carry = 0;
    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0) {
            sum += a[i] - '0';
            i--;
        }
        if (j >= 0) {
            sum += b[j] - '0';
            j--;
        }
        result += (sum % 10) + '0';
        carry = sum / 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    vector<string> f(251);
    f[0] = "1";
    f[1] = "1";
    for (int i = 2; i <= 250; i++) {
        string two_times_f_prev2 = stringAdd(f[i - 2], f[i - 2]);
        f[i] = stringAdd(f[i - 1], two_times_f_prev2);
    }
    int n;
    while (cin >> n) {
        cout << f[n] << "\n";
    }
    return 0;
}