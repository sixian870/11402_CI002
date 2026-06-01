/*UVa10812
块ㄢ俱计 s:ㄢ钉だ计㎝,d:ㄢ钉だ计畉
―块ㄢ钉だ计だ计玡璝獶单箂ぇ俱计糶 impossible
砞ㄢ钉だ计だ x,y
- x+y=s -(1)
- x-y=d -(2)
- (1)+(2) => 2x=s+d => x=(s+d)/2
- (1)-(2) => 2y=s-d => y=(s-d)/2
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,s,d;
	int x,y;
	cin>>t;
	while(t--){
		cin>>s>>d;
		if(s<d||(s+d)%2!=0){ //(s+-d)%2!=0絋玂 x,y俱计絋玂 s>d碞穦 x>y璝 s<d玥ぃΘミ 
			cout<<"impossible"<<endl;
		}
		else{
			x=(s+d)/2;
		    y=(s-d)/2;
			cout<<x<<" "<<y<<endl;
		}
	}
	return 0;
} 
