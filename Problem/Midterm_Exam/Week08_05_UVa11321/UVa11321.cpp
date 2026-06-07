/*UVa11321
N计籔埃计 M
逼硂 N计
1.緇计纔緇计パ逼
2.緇计 
	- 案:玡案
	- ㄢ:
	- ㄢ案:
*/

#include<bits/stdc++.h>
using namespace std;
int N,M;
bool isOdd(int n){
	return abs(n%2)==1;
}
bool cmp(int a,int b){
	int A=a%M;
	int B=b%M;
	//緇计 
	if(A!=B){
		return A<B;
	}
	//緇计ぃ 
	bool aOdd=isOdd(a);
	bool bOdd=isOdd(b);
	if(aOdd&&!bOdd){ //a b案
		return true; //a玡 b 
	}
	if(!aOdd&&bOdd){ //a案 b 
		return false; //a b玡 
	}
	if(aOdd&&bOdd){ //2 
		return a>b; //玡 
	}
	if(!aOdd&&!bOdd){ //2案 
		return a<b; //玡 
	}
}
int main(){
	while(cin>>N>>M&&(N!=0||M!=0)){
		vector<int> nums(N);
		for(int i=0;i<N;i++){
			cin>>nums[i];
		}
		sort(nums.begin(),nums.end(),cmp);
		cout<<N<<" "<<M<<endl;
		for(int j=0;j<N;j++){
			cout<<nums[j]<<endl;
		}
	}
	cout<<"0 0"<<endl;
	return 0;
}
