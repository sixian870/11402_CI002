/*UVa11450
9 4 -> money=9,kind=4
      [0][1][2][3][4][5][6][7][8]
       1  2  3  4  5  6  7  8  9
[0] 1  o  o  x  o  x  x  x  x  x
[1] 2  x  o  o  x  o  o  o  x  o
[2] 3  x  x  o  o  o  o  o  o  o
[3] 4                          o

3 1 2 4 
2 5 1
4 1 3 3 7
4 5 1 2 8
*/
#include<iostream>
#include<vector>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int money, kind;
		cin >> money >> kind;
		vector<vector<bool>> price(kind, vector<bool> (money + 1 , false)); //Åý index=money
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int p;
			cin >> p;
			if (p <= money) {
				price[0][p] = true;
			}
		}
		for (int i = 1; i < kind; i++) {
			cin >> n;
			for (int j = 0; j < n; j++) {
				int p;
				cin >> p;
				for (int k = 0; k <= money; k++) { 
					if (price[i - 1][k] == true && k + p <= money) {
						price[i][k + p] = true;
					}
				}
			}
		}
		int ans = -1;
		for (int m = money; m >= 0; m--) {
			if (price[kind - 1][m] == true) {
				ans = m;
				break;
			}
		}
		if (ans == -1) {
			cout << "no solution\n";
		}
		else {
			cout << ans << "\n";
		}
	}
	return 0;
}