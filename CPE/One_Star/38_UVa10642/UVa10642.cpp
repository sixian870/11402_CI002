/*UVa10642
x 軸
▲
│ (3,0)[9]
│ (2,0)[5]  (2,1)[8]
│ (1,0)[2]  (1,1)[4]  (1,2)[7]
│ (0,0)[0]  (0,1)[1]  (0,2)[3]  (0,3)[6]
└──────────────────────► y 軸
input:起始點與終點
output:路徑距離
x+y=
0:1
1:2
2:3
3:4
x+y=s:s-1
if start=(1,0) end=(2,1)
(0,0)~(1,0)=1+(1)=2
(0,0)~(2,1)=1+2+3+(2)=8
(1,0)~(2,1)=1+2+3+(2)-1-(1)+1=2+3+(2)-(1)=8-2=6
if start=(a,b) end=(c,d)
(0,0)~(a,b)=1+...+(a+b)+(a)
(0,0)~(c,d)=1+...+(c+d)+(c)
(a,b)~(c,d)=(a+b+1)+...+(c+d)+(c)-(a)
*/
#include<iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	int count = 1;
	while (t--) {
		long long a, b, c, d;
		long long ans = 0;
		cin >> a >> b >> c >> d;
		for (int i = a + b + 1; i <= c + d; i++) {
			ans += i;
		}
		ans = ans + c - a;
		cout << "Case " << count++ << ": " << ans << endl;
	}
	return 0;
}