/*UVa11034
20 4 -> ´ç½üªø 20m=2000cm
380 left 
720 left
1340 right
1040 left
lefr:{380,720,1040}
right:{1340}
bool left=true;
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int m,n;
		cin>>m>>n;
		m*=100;
		queue<int> left,right;
		while(n--){
			int cm;
			string d;
			cin>>cm>>d;
			if(d=="left"){
				left.push(cm);
			}
			if(d=="right"){
				right.push(cm);
			}
		}
		bool isLeft=true;
		int count=0;
		while(!left.empty()||!right.empty()){
			int load=0;//
			if(isLeft==true){
				while(!left.empty()&&load+left.front()<=m){
					load+=left.front();
					left.pop();
				}
				count++;
				isLeft=false;
			}
			else if(isLeft!=true){
				while(!right.empty()&&load+right.front()<=m){
					load+=right.front();
					right.pop();
				}
				count++;
				isLeft=true;
			}
		}
		cout<<count<<"\n";
	}
	return 0;
}
