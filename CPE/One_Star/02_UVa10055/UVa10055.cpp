/*UVa10055
取得兩數差
*注意:沒講輸入順序，所以要加絕對值 
}*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	long long a,b;
	while(cin>>a>>b){
		cout<<abs(a-b)<<endl;
	}
	return 0;
}
