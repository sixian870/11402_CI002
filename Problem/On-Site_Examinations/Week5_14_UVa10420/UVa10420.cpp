/**UVa10420
計算國家出現次數
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	map<string,int> countrys;
	string country,text;
	for(int i=0;i<n;i++){
		cin>>country;
		getline(cin,text);
		countrys[country]++;
	}
	for(auto const& it:countrys){ //自動把 countrys當成不能更改的常數讀取，把 value1放入name，value2放入count 
		cout<<it.first<<" "<<it.second<<endl;
	}
	return 0;
}
