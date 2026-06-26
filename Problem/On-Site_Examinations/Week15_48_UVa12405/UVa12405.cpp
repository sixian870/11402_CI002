#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int case_num = 1; case_num <= t; case_num++) {
        int n;
        cin >> n;

        string field;
        cin >> field;

        int scarecrows = 0;
        for (int i = 0; i < n; ) {
            if (field[i] == '.') {
                scarecrows++;
                i += 3;
            }
            else {
                i++;
            }
        }
        cout << "Case " << case_num << ": " << scarecrows << endl;
    }
    return 0;
}