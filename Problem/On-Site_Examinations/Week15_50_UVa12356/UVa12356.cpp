/*
s=攻擊線上的士兵數量
b=row
[l,r] 會被殺
s=1 b=1
l=1 r=1

*/
#include<iostream>
#include<vector>
using namespace std;
int main() {
	int s, b;
	while (cin >> s >> b && (s != 0 && b != 0)) {
		vector<int> left(s + 2);
		vector<int> right(s + 2);
        for (int i = 1; i <= s; i++) {
            left[i] = i - 1;
            right[i] = i + 1;
        }
        left[1] = 0;
        right[s] = 0;

        while (b--) {
            int l, r;
            cin >> l >> r;
            right[left[l]] = right[r];
            left[right[r]] = left[l];
            if (left[l] == 0) {
                cout << "* ";
            }
            else {
                cout << left[l] << " ";
            }
            if (right[r] == 0) {
                cout << "*\n";
            }
            else {
                cout << right[r] << "\n";
            }
        }
        cout << "-\n";
	}
	return 0;
}
//1 (2 3 4 5) 6 7 8 9 10 ->1 6
//1 2 3 4 5 (6 7 8 9) 10 ->1 10
//(1) 2 3 4 5 6 7 8 9 10 ->* 10