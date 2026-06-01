/**UVa490
旋轉文字從橫變直
00|10|20    02|01|00
01|11|21 -> 12|11|10
02|12|22    22|21|20
1.先取得最長的那一 row
2.最長的 row決定輸出有幾 col 
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s[105];
	int row=0;
	int maxLen=0;
	
	while(getline(cin,s[row])){
		if(s[row].length()>maxLen){
			maxLen=s[row].length();
		}
		row++;
	}
	for(int j=0;j<maxLen;j++){
		for(int i=row-1;i>=0;i--){
			if(j<s[i].length()){
				cout<<s[i][j];
			}
			else{
				cout<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}

























#include<bits/stdc++.h>
using namespace std;
int main(){
	string s[105];
	int maxLen=0;
	int rowcount=0;
	
	while(getline(cin,s[rowcount])){
		if(s[rowcount].length()>maxLen){
			maxLen=s[rowcount].length();
		}
		rowcount++;
	}
	for(int j=0;j<maxLen;j++){
		for(int i=rowcount-1;i>=0;i--){
			if(j<s[i].length()){
				cout<<s[i][j];
			}
			else{
				cout<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
} 
