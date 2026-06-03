/**UVa272
讀取整行文字，遇到第一個(單數) "用 ``代替，第二個(雙數)用 ''
*/ 
#include<bits/stdc++.h>
using namespace std;
int main(){
	string text;
	int count=0;
	
	while(getline(cin,text)){
		for(int i=0;i<text.length();i++){
			if(text[i]=='"'){
				count=(count+1)%2;
				if(count==1){
					cout<<"``";
				}
				if(count==0){
					cout<<"''";
				}
			}
			else{
				cout<<text[i];
			}
		}
		cout<<endl;//getline要換行 
	}
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	char text;
	int count=0;
	
	while(cin.get(text)){//完整讀取 text包括空白與換行,cin>>text會跳過空白與換行 
		if(text=='"'){
			count=(count+1)%2;
			if(count==1){
				cout<<"``";
			}
			if(count==0){
				cout<<"''";
			}
		}
		else{
			cout<<text;
		}
	}
	return 0;
} 

