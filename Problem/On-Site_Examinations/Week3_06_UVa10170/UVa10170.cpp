/*第一組有 S人,住 S天;下一組有 S+1人, S+1天
求第 D天,住的是幾人的組合
s=1,d=5
s=1,t=1
s=2,t=3
s=3,t=6
s++,t+=s
*/ 

#include<bits/stdc++.h>
using namespace std;
int main(){
	long long s,d; //要記得注意測資範圍 
	while(cin>>s>>d){//1 6
		long long total=0;
		while(true){
			total+=s;//1 3 6
			if(total>=d){//6
				break;
			}
			s++;//2 3 4
		}
		cout<<s<<endl;
	}
	return 0;
}
