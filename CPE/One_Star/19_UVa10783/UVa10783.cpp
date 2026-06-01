/**UVa10783
第一行輸入測資組數，接著給予一組兩個整數 a,b，將 [a,b]區間內的奇數加總 *包括 a,b
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,a,b;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>a>>b;
		int sum=0;
		for(int j=a;j<=b;j++){
			if(j%2==1){
				sum+=j;
			}
		}
		cout<<"Case "<<i<<": "<<sum<<endl; //注意加空格 
	}
	return 0;
}
