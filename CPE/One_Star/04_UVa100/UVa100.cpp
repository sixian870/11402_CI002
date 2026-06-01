/**
UVa100
輸入起始數跟結尾數
每個數字經歷循環 if(%2==0)->/2; if(%2==1)->*3+1; if(==1)break;
分別計算循環次數且輸出最大值 
*/ 

#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n1,n2;
	
	while(cin>>n1>>n2){ //當(條件)符合就不斷執行 
	
		int max_count=0;
		
		for(int i=min(n1,n2);i<=max(n1,n2);i++){
			
			int temp=i;
			int count=1;
			
			while(temp!=1){
				
				if(temp%2==0){
					temp=temp/2;
				}
				else{	
					temp=3*temp+1;
				}
				count++;
			} 
			/*if(i==1){
				break;
			}*/
			//用 while才能重複執行
			if(count>max_count){
				max_count=count;
			}
		}
		cout<<n1<<" "<<n2<<" "<<max_count<<endl;
	}
	return 0;
} 
