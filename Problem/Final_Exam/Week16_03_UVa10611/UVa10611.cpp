/*UVa10611
第一行輸入 N:猩猩數量
第二行輸入 N個猩猩身高
第三行輸入 M:待測目標
第四行輸入 M個目標身高
輸出目標身高前一個、後一個猩猩身高，若沒有則輸出 X
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> H(n);
	for(int i=0;i<n;i++){
		cin>>H[i];
	}
	int m;
	cin>>m;
	while(m--){
		int t;
		cin>>t;
		auto low=lower_bound(H.begin(),H.end(),t);//大於等於 t
		auto high=upper_bound(H.begin(),H.end(),t);//大於 t 
		if(low!=H.begin()){
			cout<<*(--low)<<" "; //大於等於 t的前一個 
		}
		else{
			cout<<"X ";
		}
		if(high!=H.end()){
			cout<<*high<<endl;
		}
		else{
			cout<<"X"<<endl;
		}
	}
	return 0;
} 

 
