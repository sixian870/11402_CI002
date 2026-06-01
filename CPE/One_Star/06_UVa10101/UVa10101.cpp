/*UVa10101
將整數轉成孟加拉語
kuti=10000000
lakh=100000
hajar=1000
shata=100
1234567890/10000000=123kuti
1234567890%10000000=4567890
4567890/100000=45lakh
4567890%100000=67890
67890/1000=67hajar
67890%1000=890
890/100=8shata
890%100=90
*要考慮 kuti過大 
*/
#include<bits/stdc++.h>
using namespace std;
long long unit[]={10000000,100000,1000,100};
string name[]={"kuti","lakh","hajar","shata"};
void solve(long long n){
	for(int i=0;i<4;i++){
		if(n>=unit[i]){ //1234567890
			solve(n/unit[i]); //123
			cout<<" "<<name[i];
			n%=unit[i];
		}
	}
	if(n>0){
		cout<<" "<<n;
	}
}

int main(){
	long long n;
	int t=1;
	while(cin>>n){
		cout<<setw(4)<<t++<<".";
		if(n==0){
			cout<<" 0";
		}
		else{
			solve(n);
		}
		cout<<endl;
	}
	return 0;
}
