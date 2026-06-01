/**UVa10035
兩數相加計算進位次數 輸入到 0 0時結束輸入
分別 %10相加，確認是否大於等於十，是的話需要紀錄進位加一且用一變數與下一位相加
*要注意輸出單複數 
}*/

#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b;//123 456
	while(cin>>a>>b&&(a!=0||b!=0)){
		int count=0;
		int c=0;
		while(a!=0||b!=0){
			int digit_a,digit_b;
			digit_a=a%10;//3 2
			a=a/10;//12 1
			digit_b=b%10;//6 5
			b=b/10;//45 4
			if((digit_a+digit_b+c)>=10){//9 7
				count++;//0 0
				c=1;
			}
			else{
				c=0;
			}
		}
		if(count==0){
			cout<<"No carry operation."<<endl;
		}
		else{
			if(count==1){
				cout<<count<<" carry operation."<<endl;
			}
			else{
				cout<<count<<" carry operations."<<endl;
			}
		}
	}
	return 0;
}
