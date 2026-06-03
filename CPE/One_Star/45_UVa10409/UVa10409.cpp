/*UVa10409
* top = 1, bottom = 6, north = 2, south = 5, east = 4, west = 3
* North: nouth=top,top=south,south=bottom,bottom=north(n,t,s,b,n)
* South: south=top,top=north,north=bottom,bottom=south(s,t,n,b,s)
* East: east=top,top=west,west=bottom,bottom=east(e,t,w,b,e)
* West: west=top,top=east,east=bottom,bottom=west(w,t,e,b,w)
*/
#include<iostream>
using namespace std;
int main() {
	int t;
	while (cin >> t && t != 0) {
		int top = 1, bottom = 6, north = 2, south = 5, east = 4, west = 3;
		while (t--) {
			string s;
			cin >> s;
			if (s == "north") {
				int temp = north;
				north = top; top = south; south = bottom; bottom = temp;
			}
			else if(s == "south") {
				int temp = south;
				south = top; top = north; north = bottom; bottom = temp;
			}
			else if (s == "east") {
				int temp = east;
				east = top; top = west; west = bottom; bottom = temp;
			}
			else if (s == "west") {
				int temp = west;
				west = top; top = east; east = bottom; bottom = temp;
			}
		}
		cout << top << "\n";
	}
	return 0;
}