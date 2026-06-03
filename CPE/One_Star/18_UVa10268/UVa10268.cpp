/*
3 -> x=3 *long long -> size()=3
1 2 3 -> a[0]=1,a[1]=2,a[2]=3
f(x)=1*x^2+2*x^1+1*x^0=x^2+2x+1 -> a[0]*x^(a.size()-1)
f'(x)=1*2*x^1+2*1*x^0+0=2x+2 -> a[0]*(size()-1)*x^(a.size()-2)+a[1]*(size()-2)*x^(a.size()-3)
F'(3)=2(3)+2=8
因為不知道會輸入幾位數字 所以要用字串讀 再切字串 
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	long long x;
	while(cin>>x){
		cin.ignore();
		string num;
		getline(cin,num);
		stringstream ss(num);
		long long c;
		vector<long long> a;
		while(ss>>c){
			a.push_back(c);
		}
		long long n=a.size()-1;
		long long total=0;
		//a[0]*(n)*x^(n-1)+a[1]*(n-1)*x^(n-2)
		for(int i=0;i<n;i++){
			total=total*x+a[i]*(n-i);
		}
		cout<<total<<"\n";
	}
	return 0;
}
