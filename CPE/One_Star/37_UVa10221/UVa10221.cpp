/*UVa10221
地球 r= 6440km
衛星離地球高度 h
兩衛星夾角 a (deg,min) *1 deg = 60 min
弧長=(6440+h)*deg*(pi/180)
弦長=2*(6440+h)*sin((deg/2)*(pi/180))
*因為要找最短距離，所以若角度超過180度，則要用360-角度來算
*/
#include<iostream>
#include<cmath>
#include<iomanip>
#include<string>
using namespace std;
int main() {
	int h, d;
	string unit;
	const double pi = acos(-1.0);
	while (cin >> h >> d >> unit) {
		double deg;
		double ans1, ans2;
		if (unit == "deg") {
			deg = d;
		}
		else if (unit == "min") {
			deg = d / 60.0;
		}
		if (deg > 180) {
			deg = 360 - deg;
		}
		ans1 = (6440 + h) * deg * (pi / 180);
		ans2 = 2 * (6440 + h) * sin((deg / 2) * (pi / 180));
		cout << fixed << setprecision(6) << ans1 << " " << ans2 << endl;
	}
	return 0;
}