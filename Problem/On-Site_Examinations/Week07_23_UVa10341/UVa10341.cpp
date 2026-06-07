/*UVa10341
有一個遞減公式=0只在 [0,1]中有解，算出其解值
用二分法設 low=0.0,hight=1.0,mid=(low+hight)/2
if(f(mid)>0):f(mid)太大(在解左邊)要減少(往右縮) -> low = f(mid) 
if(f(mid)<0):f(mid)太小(在解右邊)要增加(往左縮) -> high = f(mid)
*/
#include<bits/stdc++.h>
using namespace std;

double p,q,r,s,t,u;
double f(double x){
	return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
} 

int main(){
	while(cin>>p>>q>>r>>s>>t>>u){
		
		if(f(0)<0||f(1)>0){
		cout<<"No solution"<<endl;
		continue; //跳過後面計算 
		}
		
		double low=0.0,high=1.0,mid;
		for(int i=0;i<100;i++){
			mid=(low+high)/2.0;
			if(f(mid)>0){
				low=mid; //f(mid),mid要分清楚要求的是 x=mid 
			}
			else{
				high=mid;
			}
		}
		cout<<fixed<<setprecision(4)<<mid<<endl;
	}
	return 0;
}
