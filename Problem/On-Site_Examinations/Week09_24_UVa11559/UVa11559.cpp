#include<iostream>
using namespace std;
int main() {
	int N, B, H, W;
	while (cin >> N >> B >> H >> W) {
		int min = B + 1;
		for (int i = 1; i <= H; i++) {//hotel
			int p;//price
			cin >> p;
			for (int j = 1; j <= W; j++) {//week
				int a;
				cin >> a;
				if (a >= N && p * N < min) {
					min = p * N;
				}
			}
		}
		if (min <= B) {
			cout << min << endl;
		}
		else {
			cout << "stay home" << endl;
		}
	}
	return 0;
}