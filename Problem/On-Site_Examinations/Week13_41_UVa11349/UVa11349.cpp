/*UVa11349
* 5 1 3		00 01 02
* 2 0 2 ->  10 11 12
* 3 1 5		20 21 22
* 00=22
* 01=21
* 02=20
* 10=12
*/
#include<iostream>
#include<vector>
using namespace std;
int main() {
	int t;
	int count = 1;
	cin >> t;
	while (t--) {
		char a, b;
		int n;
		bool isS = true;
		cin >> a >> b >> n;
		cout << "Test #" << count++;
		vector<vector<long long>> M(n, vector<long long>(n));//n*n//ij很大 要用 long long
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> M[i][j];
				if (M[i][j] < 0) {
					//cout << ": Non-symmetric.\n";
					//continue;
					isS = false;
				}
			}
		}
		for (int i = 0; i < n; i++) { //0 1 2
			for (int j = 0; j < n; j++) {
				if (M[i][j] != M[n - 1 - i][n - 1 - j]) { //00=22 01=21 02=20
					isS = false;
					break;
				}
			}
		}
		if (isS) {
			cout << ": Symmetric.\n";
		}
		else if (!isS) {
			cout << ": Non-symmetric.\n";
		}
	}
	return 0;
}