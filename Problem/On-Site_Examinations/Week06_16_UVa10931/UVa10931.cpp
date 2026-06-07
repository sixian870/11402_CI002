/*UVa10931
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	while(cin>>n&&n!=0){
		long long count=0;
		string s=" ";
		while(n>0){
			if(n%2==1){
				count++;
				s+="1";
			}
			else if(n%2==0){
				s+="0";
			}
			n=n/2;
		}
		reverse(s.begin(),s.end());
		cout<<"The parity of "<<s<<"is "<<count<<" (mod 2)."<<endl;
	}
	return 0;
}
