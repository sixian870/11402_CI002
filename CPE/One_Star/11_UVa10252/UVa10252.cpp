/*UVa10252
兩個字串一組 找出相同字母輸出
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	string v1,v2;
	while(getline(cin,v1)&&getline(cin,v2)){ //因為字串成對 
		int count1[26]={0}; //全部設為 0 
		int count2[26]={0};
		for(char c:v1){ //把字串 s1裡的字元依序取出輪流丟給 c變數處理
			if(c>='a'&&c<='z'){ //'a'=97 
				count1[c-'a']++; //count['a'-'a']=count[0],count['b'-'a']=count[1]
			}  
		}
		for(char c:v2){
			if(c>='a'&&c<='z'){
				count2[c-'a']++;
			}  
		}
		for(int i=0;i<26;i++){ //count[0]='a',count[25]='z'
			int t=min(count1[i],count2[i]);
			for(int j=0;j<t;j++){ //輸出最小次數
				cout<<char('a'+i);//'a'+0=a,'a'+1=b
			}
		}
		cout<<endl;
	}
	return 0;
} 
