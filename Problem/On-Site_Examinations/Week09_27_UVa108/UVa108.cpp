/*UVa108
找出最大子陣列和
 1 -2
-3  4

 0  0
 1 -2
-2  2

*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		vector<vector<int>> col_prefix(n+1,vector<int>(n+1,0));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int val;
				cin>>val;
				col_prefix[i][j]=col_prefix[i-1][j]+val;
			}
		}
		int max_sum=-127*100*100;
		for(int top=1;top<=n;top++){
			for(int bottom=top;bottom<=n;bottom++){
				int sum=0;
				for(int col=1;col<=n;col++){
					int col_sum=col_prefix[bottom][col]-col_prefix[top-1][col];
					sum+=col_sum;
					if(sum>max_sum){
						max_sum=sum;
					}
					if(sum<0){
						sum=0;
					}
				}
			}
		}
		cout<<max_sum<<"\n"; 
	}
	return 0;
} 
