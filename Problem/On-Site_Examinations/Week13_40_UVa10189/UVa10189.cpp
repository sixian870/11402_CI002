/*UVa10189
找地雷,n*m地圖,*:地雷.:安全
if(*)->cout<<*
if(.)->找八方,cout<<count
 (-1,1)  (0,1)  (1,1)
 (-1,0) .(0,0)  (1,0) 
(-1,-1) (0,-1) (1,-1)
遇到地雷count++;
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	int cases=1;
	while(cin>>n>>m&&(n!=0||m!=0)){
		if(cases>1){
			cout<<endl;
		}
		vector<string> arr(n); //row
		for(int i=0;i<n;i++){
			cin>>arr[i]; //row 
		}
		cout<<"Field #"<<cases<<":"<<endl;
		
		int dx[]={-1,-1,-1,0,0,1,1,1};
		int dy[]={-1,0,1,-1,1,-1,0,1};
		for(int j=0;j<n;j++){
			for(int k=0;k<m;k++){
				if(arr[j][k]=='*'){
					cout<<"*";
				}
				else{
					int count=0;
					for(int l=0;l<8;l++){
						int x=j+dx[l]; //row
						int y=k+dy[l]; //col
						if(x>=0&&x<n&&y>=0&&y<m){
							if(arr[x][y]=='*'){
							count++;
							}
						}	
					}
					cout<<count;
				}
			}
			cout<<endl;
		}
		cases++;
	}
	return 0;
}

