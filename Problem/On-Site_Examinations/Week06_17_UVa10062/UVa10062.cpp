/**UVa10062
讀取輸入的字串 紀錄 ASCII出現次數 次數不同輸出由小到大 相同則輸出 ASCII大到小
*注意輸出之間要加空行 
*/
#include<bits/stdc++.h>
using namespace std;
struct Data{
	int ascii;
	int count;
};
bool cmp(Data a,Data b){
	if(a.count!=b.count) return a.count<b.count;
	return a.ascii>b.ascii;
}
int main(){
	string s;
	bool firstline=true;
	while(getline(cin,s)){
		if(!firstline) cout<<endl;
		firstline=false;
		int arr1[256]={0};
		for(char c:s){
			arr1[(unsigned char)c]++;
		}
		vector<Data> arr2;
		for(int i=0;i<256;i++){
			if(arr1[i]!=0){
				arr2.push_back({i,arr1[i]}); //ascii=i,count=arr1[i]
			}
		}
		sort(arr2.begin(),arr2.end(),cmp);
		for(auto n:arr2){
			cout<<n.ascii<<" "<<n.count<<endl;
		}
	}
	return 0;
}
