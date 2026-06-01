/*UVa12019
輸入2011年的月日，輸出星期幾
2011年 2月只有 28天，2011/1/10是星期一 [10(1),9(7),8(6),7(5),6(4),5(3),4(2),3(1),2(7),1(6)]
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,m,d;
	string week[]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
	int month[]={0,31,28,31,30,31,30,31,31,30,31,30,31}; //注意 index從 0開始 
	cin>>t;
	while(t--){
		cin>>m>>d;
		int total=0;
		for(int i=1;i<m;i++){ //if m=2,i=1,total=31 
			total+=month[i];
		}
		total+=d;
		cout<<week[(total-1)%7]<<endl;
	}
	return 0;
} 
