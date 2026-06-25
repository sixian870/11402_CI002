/*UVa10935
cin>>5;
{1,2,3,4,5}
1:pop->{1} 2:pop,back
{3,4,5,2}
3:pop->{1,3} 4:pop,back
{5,2,4}
5:pop->{1,3,5} 2:pop,back
{4,2}
4:pop->{1,3,5,4) Remain:2
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(cin>>n&&n!=0){
		queue<int> r;
		vector<int> d;
		for(int i=1;i<=n;i++){
			r.push(i);
		}
		while(r.size()>1){
			d.push_back(r.front());
			r.pop();
			
			r.push(r.front());
			r.pop();
		}
		cout<<"Discarded cards:";
		for(int j=0;j<d.size();j++){
			if(j==0){
				cout<<" "<<d[0];
			}
			else{
				cout<<", "<<d[j];
			}
		}
		cout<<"\n";
		cout<<"Remaining card: "<<r.front()<<"\n";
	}
	return 0;
}
