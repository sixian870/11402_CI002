/*UVa10107
不斷讀取數字加入陣列並即時輸出中位數
1->1
1,3->(1+3)/2=2
1,3,4->3
1,3,4,60->(3+4)/2=3
1,3,4,60,70->4
1,3,4,60,70,50->1,3,4,50,60,70->(4+50)/2=27 //要先 sort
1,3,4,60,70,50,2->1,2,3,4,60,70,50->4
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	vector<long long> arr; //動態陣列，大小不固定 
	while(cin>>n){
		arr.push_back(n); //把 n放進 arr
		sort(arr.begin(),arr.end()); // 先排列
		 int size=arr.size();
		 if(size%2!=0){
		 	cout<<arr[size/2]<<endl; //1/2=0,a[0];3/2=1,a[1]
		 } 
		 if(size%2==0){ //a[0],a[1],a[2],a[3]
		 	int m1=arr[size/2]; //4/2=2,a[2]
		 	int m2=arr[size/2-1]; //4/2-1=1,a[1]
		 	cout<<(m1+m2)/2<<endl;
		 }
	}
	return 0;
}
