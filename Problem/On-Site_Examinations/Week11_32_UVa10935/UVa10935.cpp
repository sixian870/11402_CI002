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

/*
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	while(cin>>n&&n!=0){ //7
		queue<int> remaining; //不能設(n),只能用 front 
		vector<int> discarded;
		for(int i=1;i<=n;i++){ //[0]=1,[1]=2,[2]=3,[3]=4,[4]=5,[5]=6,[6]=7
			remaining.push(i);
		}
		while(remaining.size()>1){
			discarded.push_back(remaining.front());
			remaining.pop();
			
			int top=remaining.front();
			remaining.pop();
			remaining.push(top);
		}
		cout<<"Discarded cards:"; //notice n==1
		for(int j=0;j<discarded.size();j++){
			if(j==0){
				cout<<" "<<discarded[j];
			}
			else{
				cout<<", "<<discarded[j];
			}
		}
		cout<<"\n";
		cout<<"Remaining card: "<<remaining.front()<<"\n";
		//n==1 error
		/*cout<<"Discarded cards: ";
		for(int j=0;j<discarded.size()-1;j++){ //不能設 n-1 
			cout<<discarded[j]<<", ";
		}
		cout<<discarded[discarded.size()-1]<<"\n";
		cout<<"Remaining card: "<<remaining.front()<<"\n";
	}
	return 0;
}*/
