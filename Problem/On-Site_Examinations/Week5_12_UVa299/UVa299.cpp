/**UVa299
計算輸入車廂需最少經過幾次交換編號才能變從小到大排好
1,3,2->1,2,3
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int count=0;
		int n;
		cin>>n;
		vector<int> train(n);
		for(int i=0;i<n;i++){
			cin>>train[i];
		}
		for(int j=0;j<n-1;j++){
			for(int k=0;k<n-1;k++){
				if(train[k]>train[k+1]){
					swap(train[k],train[k+1]);
					count++;
				}
			}
		}
		cout<<"Optimal train swapping takes "<<count<<" swaps."<<endl;
	}
	return 0;
}
