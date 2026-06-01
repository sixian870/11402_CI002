/*UVa11461
找出 a,b之間有幾個完全平方數
0<a<=b<=100000 輸出 0 0表結束
1___a_______b 所求區間為[a,b]=(1到 b的數量)-(1到 a之前的數量) 
設 a=36,b=98.01
(a-1)^1/2=5.91,b^1/2=9.9
9-5=4
A:6,7,8,9
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	long long a,b;
	int countA=0,countB=0;
	while(cin>>a>>b&&(a!=0||b!=0)){
		countA=floor(sqrt(a-1));
		countB=floor(sqrt(b));
		cout<<countB-countA<<endl; 
	}
	return 0;
}
