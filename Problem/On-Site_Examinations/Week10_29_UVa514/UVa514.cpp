/*UVa541
用 stack實作達成目標火車出站順序
input
1: 車廂數量 (0:end)
2: 目標順序 (0:end) 
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(cin>>n&&n!=0){
		while(true){
			
			//讀取目標陣列 
			vector<int> target(n);
			cin>>target[0];
			if(target[0]==0) break;
			for(int i=1;i<n;i++){
				cin>>target[i];
			}
			
			stack<int> station;
			int next=1;
			bool possible=true;
			
			for(int j=0;j<n;j++){
				
				//目標未進站就一直 push 
				while(next<=n&&(station.empty()||station.top()!=target[j])){
					station.push(next);
					next++;
				}
				
				//是目標就往前 
				if(!station.empty()&&station.top()==target[j]){
					station.pop();
				}
				else{
					possible=false;
					break;
				}
			}
			if(possible==true){
				cout<<"Yes\n";
			}
			else{
				cout<<"No\n";
			}
		}
		cout<<"\n";
	}
	return 0;
}
