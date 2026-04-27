/*UVa12503
輸出機器人執行完所有指令後的位置
*/ 
#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> ins(n);
	int pos=0;
	for(int i=0;i<n;i++){
		string cm;
		cin>>cm;
		if(cm=="LEFT"){
			ins[i]=-1;
		}
		if(cm=="RIGHT"){
			ins[i]=1;
		}
		if(cm=="SAME"){
			string AS;
			int a;
			cin>>AS>>a;
			ins[i]=ins[a-1];
		}
		pos+=ins[i];
	}
	cout<<pos<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
