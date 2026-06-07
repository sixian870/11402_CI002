/*UVa10041
幫老大找門牌號住 要找中位數 輸出中位數到其他門牌號的總距離 
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> arr(n);
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		sort(arr.begin(),arr.end());
		int mid=arr[n/2]; //無條件捨去
		int total=0;
		for(int j=0;j<n;j++){
			total+=abs(arr[j]-mid);
		}
		cout<<total<<endl;
	}
}
