/*UVa679
    1    D=1, root=1
   / \     
  2   3  D=2, left=1*2,right=1*2+1
 /\  /\
4 5 6 7  D=3, left=2*2,right=2*2+1

node p -> child: left node 2p,right node 2p+1
each node have a Flag=OFF: OFF->left->ON,ON->right->OFF
odd->left		第 I 顆球是奇數 -> 第 (I+1)/2 顆往左滾的球
even->right     第 I 顆球是偶數 -> 第 I/2 顆往右滾的球

求當丟下第 I 顆球時，請算出這顆球最後會落在深度 D 的哪一個節點編號？
//2,2
//
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	while(cin>>t&&t!=-1){
		while(t--){
			int i,d;
			cin>>i>>d;
			int root=1;
			for(int j=1;j<d;j++){
				if(i%2==1){//odd
					root*=2;
					i=(i+1)/2;
				}
				else if(i%2==0){
					root=(2*root)+1;
					i/=2;
				}
			}
			cout<<root<<"\n";
		}
	}
	return 0;
}
