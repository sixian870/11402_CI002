/*UVa10222
將輸入的亂碼往左兩格鍵盤對應以解碼
1.建立字串對照表
2.轉小寫
3.-2 找位置輸出 
//字串 
#include<bits/stdc++.h>
using namespace std;
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	string s="1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
	char text;
	while(cin.get(text)){
		text=tolower(text);//轉小寫
		int position=s.find(text);//回傳text在字串 s中的位置
		if(position!=string::npos){
			cout<<s[position-2];
		}
		else{
			cout<<text;
		}
	}
	return 0;
}
//字元 
#include<bits/stdc++.h>
using namespace std;
int main(){
	string s="1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
	char c;
	while(cin.get(c)){
		c=tolower(c);
		int p=s.find(c);
		if(p!=string::npos){
			cout<<s[p-2];
		}
		else{
			cout<<c;
		}
	}
	return 0;
}
*/ 

#include<bits/stdc++.h>
using namespace std;
int main(){
	char c;
	string s="1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";//'\'要多加一個，避免誤會 
	while(cin.get(c)){
		c=tolower(c);
		int pos=s.find(c);
		if(pos!=string::npos){
			cout<<s[pos-2];
		}
		else{
			cout<<c;
		}
	}
	return 0;
} 
