/*leetcode231
判斷輸入整數是否為 2^n
不斷除 2，直至 =1=2^0 
*/

/*
class Solution{
public:
	bool isPowerOfTwo(int n){
		if(n<1){
			return false;
		}
		while(n%2==0){
		n=n/2;
		}
		return n==1; //省略寫法，執行 n==1的檢查，成立就 return true，不成立就 return false 
	}
};
*/ 
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		if(n<1){
			cout<<"False"<<endl;
		}
		else{
			while(n%2==0){
				n=n/2;
			}
			if(n==1){
				cout<<"True"<<endl;
			}
			else{
				cout<<"False"<<endl;
			}
		}
	}
	return 0;
} 
