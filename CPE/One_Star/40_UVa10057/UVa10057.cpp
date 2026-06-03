/*UVa10057
找中位數，輸出三個數
1.最小的可能 A：即排序後左側的中位數 X(n-1/2)
2.輸入資料中符合條件的個數：在原始輸入中，有多少個數等於 X(n-1/2) or X(n/2)
3.可能的整數 A共有幾種：即區間 [X(n-1/2),X(n/2)]內的整數個數，計算公式為 X(n-1/2)-X(n/2)+1
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		vector<int> arr(n); 
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		sort(arr.begin(),arr.end());
		int mid1=arr[(n-1)/2];
		int mid2=arr[n/2];
		int count=0;
		for(int j=0;j<n;j++){
			if(arr[j]==mid1||arr[j]==mid2){
				count++;
			}
		}
		cout<<mid1<<" "<<count<<" "<<mid2-mid1+1<<endl;
	}
	return 0;
}
