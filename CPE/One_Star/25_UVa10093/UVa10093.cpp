/*UVa10093
秈穦瞷 0 ㎝ 1┮ 1程秈琌 1+1=2,т计 N 秈计砆 (N-1) 俱埃
0101=2 max=1 ぶ琌 2(max+1) 秈2:2%(2-1)==0
0~9->0~9
A~Z->10~35
a~z->36~61
*/
#include<iostream>
#include<string>
using namespace std;
int main() {
	string s;
	while (getline(cin, s)) {
		int sum = 0;
		int t = -1;
		int max = 1; //min=2
		for (int i = 0; i < s.length(); i++) {
			if (s[i] >= '0' && s[i] <= '9') {
				t = s[i] - '0';
			}
			else if (s[i] >= 'A' && s[i] <= 'Z') {
				t = s[i] - 'A' + 10;
			}
			else if (s[i] >= 'a' && s[i] <= 'z') {
				t = s[i] - 'a' + 36;
			}
			if (t != -1) { //筁耾じ
				sum += t;
				if (t > max) {
					max = t;
				}
			}
		}
		//max+1琌程秈眖max+1秨﹍ттsum%(i-1)==0
		bool flag = false;
		for (int i = max + 1; i < 63; i++) {
			if (sum % (i - 1) == 0) {
				cout << i << "\n";
				flag = true;
				break;
			}
		}
		if (!flag) {
			cout << "such number is impossible!\n";
		}
	}
	return 0;
}