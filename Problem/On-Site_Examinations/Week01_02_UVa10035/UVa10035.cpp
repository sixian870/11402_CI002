/*
UVa10035
兩數相加計算進位次數 輸入到 0 0時結束輸入
分別 %10相加，確認是否大於等於十，是的話需要紀錄進位加一且用一變數與下一位相加
*要注意輸出單複數 
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	long long int a,b;
	int dight_a,dight_b;

	while(cin>>a>>b){
		int c=0,carry=0;
		
		if(a==0&&b==0){
			break;
		}
		while(a>0||b>0){
			
			dight_a=a%10;
			a=a/10;
			dight_b=b%10;
			b=b/10;
			
			if(dight_a+dight_b+c>=10){
				c=1;
				carry++;
			}
			else{
				c=0;
			}
		}
		if(carry==0){
			cout<<"No carry operation."<<endl;
		}
		if(carry==1){
			cout<<carry<<" carry operation."<<endl;
		}
		if(carry>1){
			cout<<carry<<" carry operations."<<endl;
		}
	}
}
