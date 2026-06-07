/*UVa673
判斷字串是否合法
*可能有空字串
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		string s;
		//vector<char> stack;
		stack<char> s1;
		bool isValid=true;
		getline(cin,s);
		for(char c:s){
			if(c=='('||c=='['){
				s1.push(c);
			}
			else if(c==')'){
				if(s1.empty()||s1.top()!='('){
					isValid=false;
					break;
				}
				s1.pop();
			}
			else if(c==']'){
				if(s1.empty()||s1.top()!='['){
					isValid=false;
					break;
				}
				s1.pop();
			}
		}
		if(s1.empty()&&isValid==true){
			cout<<"Yes\n";
		}
		else{
			cout<<"No\n";
		}
	}
	return 0;
} 
