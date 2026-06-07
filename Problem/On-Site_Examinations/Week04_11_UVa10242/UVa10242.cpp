/*UVa10242
找平行四邊形的第四個點
AB,BC,D=A+C-B
p1p2,p3p4
p1=p3 -> p2+p4-p3
p1=p4 -> p2+p3-p4
p2=p3 -> p1+p4-p3
p2=p4 -> p1+p3-p4
*/
#include<bits/stdc++.h>
using namespace std;
struct Point{
	double x;
	double y;
};
int main(){
	Point p1,p2,p3,p4,d;
	while(cin>>p1.x>>p1.y>>p2.x>>p2.y>>p3.x>>p3.y>>p4.x>>p4.y){
		if(p1.x==p3.x&&p1.y==p3.y){ //p1=p3
			d.x=p2.x+p4.x-p3.x;
			d.y=p2.y+p4.y-p3.y;
		}
		if(p1.x==p4.x&&p1.y==p4.y){ //p1=p4
			d.x=p2.x+p3.x-p4.x;
			d.y=p2.y+p3.y-p4.y;
		}
		if(p2.x==p3.x&&p2.y==p3.y){ //p2=p3
			d.x=p1.x+p4.x-p3.x;
			d.y=p1.y+p4.y-p3.y;
		}
		if(p2.x==p4.x&&p2.y==p4.y){ //p2=p4
			d.x=p1.x+p3.x-p4.x;
			d.y=p1.y+p3.y-p4.y;
		}
		cout<<fixed<<setprecision(3)<<d.x<<" "<<d.y<<endl;
	}
}

