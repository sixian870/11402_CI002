/*UVa10474
第一行輸入 M:石頭數量, N:詢問次數
輸入 M 行石頭數字 -> 存到動態陣列 
輸入 N 行要找的數字
輸入 0 0 停止 
輸出要找的數字在排列後的第一個出現位置
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int m,n;
	int count=1;
	while(cin>>m>>n&&(m!=0||n!=0)){
		vector<int> s(m);
		for(int i=0;i<m;i++){
			cin>>s[i];
		}
		sort(s.begin(),s.end());
		cout<<"CASE# "<<count++<<":"<<endl;
		while(n--){
			int q;
			cin>>q;
			auto it=lower_bound(s.begin(),s.end(),q); //回傳大於等於 q的位置 index,若無則指向 s.end() 
			int pos=(it-s.begin())+1;
			if(it!=s.end() && *it==q){ //*為陣列索引值 
				cout<<q<<" found at "<<pos<<endl;
			}
			else{
				cout<<q<<" not found"<<endl;
			}
		}
	}
} 
 
