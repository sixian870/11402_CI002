/*UVa10189
找地雷,n*m地圖,*:地雷.:安全
if(*)->cout<<*
if(.)->找八方,cout<<count
 (-1,1)  (0,1)  (1,1)
 (-1,0) .(0,0)  (1,0) 
(-1,-1) (0,-1) (1,-1)
遇到地雷count++;
*/
#include<iostream>
#include<vector>
using namespace std;
int main() {
	int m, n;
	int case_count = 1;
	bool isFirst = true;
	while (cin >> m >> n && (m != 0 && n != 0)) {
		vector<vector<char>> g(m,vector<char> (n));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> g[i][j];
			}
		}
		if (!isFirst) {
			cout << "\n";
		}
		cout << "Field #" << case_count++ << ":\n";
		isFirst = false;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (g[i][j] == '*') {
					cout << "*";
				}
				else {
					int count = 0;
					for (int di = -1; di <= 1; di++) {
						for (int dj = -1; dj <= 1; dj++) {
							int ni = i + di;
							int nj = j + dj;
							if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
								if (g[ni][nj] == '*') {
									count++;
								}
							}
						}
					}
					cout << count;
				}
			}
			cout << "\n";
		}
	}
	return 0;
}

