/**UVa10008
統計 n行字串字母出現頻率，輸出大寫依照次數多寡，相同時才依照字母順序 
*/
#include<bits/stdc++.h>
using namespace std;
struct Data{
	char name;
	int count;
};
bool compare(Data a,Data b){
	if(a.count!=b.count){ //次數不一樣 
		return a.count>b.count; //回傳次數多的在前面 
	}
	else{ //次數一樣
		return a.name<b.name; //回傳 ASCII碼小的在前面 
	}
}
int main(){
	int n; //行數
	cin>>n;
	cin.ignore();
	
	vector<Data> alpha(26); //不能設為 0要錄入字母 
	for(int i=0;i<26;i++){
		alpha[i].name='A'+i;
		alpha[i].count=0;
	}
	
	string line;
	while(n--){ //有幾行就執行幾次 
		getline(cin,line);
		for(char c:line){
			if(isalpha(c)){
				c=toupper(c);
				alpha[c-'A'].count++;
			}
		}
	}
	sort(alpha.begin(),alpha.end(),compare);
	
	for(int j=0;j<26;j++){
		if(alpha[j].count>0){
			cout<<alpha[j].name<<" "<<alpha[j].count<<endl;
		}
	}
	return 0;
}
