/*UVa10071
琘采Τ硉㎝单硉
块ㄢ俱计 t,v安砞 t采硉 v叫拜硂采 2t┮竒筁簿琌ぶ
v=a*t,a=v/t
S=v_0*t+(a*t^2)/2=0+{(v/t)*(2t)^2}/2=2*v*t
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,v;
	while(cin>>t>>v){
		cout<<2*v*t<<endl;
	}
	return 0;
}
