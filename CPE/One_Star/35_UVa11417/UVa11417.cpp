/*UVa11417
т眖 1-Nぇ丁┮Τぃ狡计舱 (i,j)礛衡ウ程そ计 (GCD)程р┮Τ GCD场癬ㄓ
*/
#include<iostream>
using namespace std;
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
int main(){
	int n;
	while(cin>>n&&n!=0){
		long long g=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				g+=gcd(i,j);
			}
		}
		cout<<g<<endl;
	}
	return 0;
}
