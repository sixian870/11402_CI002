/*UVa10038
4 1,4,2,3
4=n
|1-4|=3
|4-2|=2
|2-3|=1
{1,2,3}=1~n-1 -> Jolly
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	
	while(cin>>n){ //4
		//cin>>n後再宣告 
		vector<int>arr(n);
		vector<int>b(n-1);
		//cin>>1,4,2,3
		for(int i=0;i<n;i++){
			cin>>arr[i]; //a[0]=1,a[1]=4,a[2]=2,a[3]=3
		}
		for(int j=0;j<n-1;j++){
			b[j]=abs(arr[j]-arr[j+1]);
		}
		sort(b.begin(),b.end()); //放迴圈外 
		
		bool isJolly=true;
		for(int k=0;k<n-1;k++){
			if(b[k]!=(k+1)){
				isJolly=false;
				break;
			}
		}
		if(isJolly){
			cout<<"Jolly"<<endl;
		}
		else{
			cout<<"Not jolly"<<endl;
		}
	}
	return 0;
}
