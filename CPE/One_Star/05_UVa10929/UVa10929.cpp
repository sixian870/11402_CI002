/*UVa10929
耞琌琌 11计
*1000 计ぃノ long long璶ノ string
11计:|计计㎝ -案计计ぇ㎝| % 11 = 0
12321
s[0]=1,s[2]=3,s[4]=1  i%2==0 =>odd
s[1]=2,s[3]=2 =>even  i%2==1 =>even
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	string num;
	while(cin>>num&&num!="0"){
		int odd=0;
		int even=0;
		for(int i=0;i<num.length();i++){
			int a=num[i]-'0'; //char->int
			if(i%2==0){
				odd+=a;
			}
			if(i%2==1){
				even+=a;
			}
		}
		if(abs(odd-even)%11==0){
			cout<<num<<" is a multiple of 11."<<endl;
		}
		else{
			cout<<num<<" is not a multiple of 11."<<endl;
		}
	}
	return 0;
}

