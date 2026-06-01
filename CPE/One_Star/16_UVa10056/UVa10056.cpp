/*UVa10056
input:玩家總數(n),單次成功的機率(p),指定的玩家(i)
output:第 i個玩家獲勝的總機率(小數點後第 4位)
*P=(p*q^(i-1))/(1-(q^n))
*p=0時，要輸出 0.0000
次方:pow,開根號:sqrt
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,i;
		double p,q,a,b,c;
		cin>>n>>p>>i;
		if(p==0){
			cout<<0.0000<<endl;
		}
		else{
			q=1-p;
			a=p*pow(q,i-1);
			b=1-pow(q,n);
			c=a/b;
			cout<<fixed<<setprecision(4)<<c<<endl;
		}
	}
	return 0;
}
