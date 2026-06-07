/*UVa118
* 02 12 22 32 42
* 01 11 21 31 41
* 00 10 20 30 40
*	N
* W   E
*	S
* R:E->S->W->N
* E+F:x++
* S+F:y--
* W+F:x--
* N+F:y++
*/
#include<iostream>
#include<vector>
using namespace std;
int main() {
	int col, row;
	cin >> col >> row;
	vector<vector<bool>> M(row + 1, vector<bool>(col + 1, false));
	int x, y;
	char d;
	while (cin >> x >> y >> d) {
		char dir[4] = { 'E','S','W','N' };
		int dx[4] = { 1,0,-1,0 };
		int dy[4] = { 0,-1,0,1 };
		string cmd;
		cin >> cmd;
		int idx;
		for (int i = 0; i < 4; i++) {
			if (dir[i] == d) {
				idx = i;
				break;
			}
		}
		bool lost = false;
		for (char c : cmd) {
			if (c == 'R') {
				idx = (idx + 1) % 4;//Á×§K¶W¯Á¤Þ½d³ò index:0~3
			}
			else if (c == 'L') {
				idx = (idx + 3) % 4;//Á×§K¶W¯Á¤Þ½d³ò index:0~3
			}
			else if (c == 'F') {
				if (x + dx[idx] > col || x + dx[idx] <0 || y + dy[idx]>row || y + dy[idx] < 0) {
					if (M[x][y] == true) {
						continue;
					}
					else {
						M[x][y] = true;
						lost = true;
						break;
					}
				}
				else {
					x += dx[idx];
					y += dy[idx];
				}
			}
		}
		if (lost) {
			cout << x << " " << y << " " << dir[idx] << " LOST\n";
		}
		else {
			cout << x << " " << y << " " << dir[idx] << "\n";
		}
	}
	return 0;
}