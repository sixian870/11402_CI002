/*UVa11332
將數字 123456789每位相加，直至變成個位數
123456789 -> 1+2+3+4+5+6+7+8+9=45 -> 4+5=9
*讀取輸入直至 0出現表示結束 
*/
#include<bits/stdc++.h>
using namespace std;
long long f(long long n){
	int sum=0;
	while(n>0){
		sum=sum+n%10;
		n=n/10;
	}
	return sum;
}
int main(){
	long long n;
	while(cin>>n&&n!=0){
		while(n>=10){
			n=f(n);
		}
		cout<<n<<endl;
	}
	return 0;
}
