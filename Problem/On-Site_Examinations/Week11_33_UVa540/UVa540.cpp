//{(101,102,103),(201,202,201)}
#include<iostream>
#include<map>
#include<queue>
using namespace std;
int main() {
	int t;
	int count = 1;
	while (cin >> t && t != 0) {
		map<int, int> team_map;
		for (int i = 0; i < t; i++) { //2 times
			int n;
			cin >> n;
			for (int j = 0; j < n; j++) { //3 times
				int m;
				cin >> m;
				team_map[m] = i;
			}
		}
		cout << "Scenario #" << count++ << "\n";
		queue<int> main;
		queue<int> team[1005];
		string cmd;
		while (cin >> cmd && cmd != "STOP") {
			if (cmd == "ENQUEUE") {
				int x;
				cin >> x;
				int teamID = team_map[x];//team_map[101]=1 team_map[201]=2
				if (team[teamID].empty()) {//team[1] team[2] 
					main.push(teamID);//{1,2}
					team[teamID].push(x);//team[1]={101} team[2]={201}
				}
				else {
					team[teamID].push(x);//team[1]={101,102,103} team[2]={201,202,203}
				}
			}
			else if (cmd == "DEQUEUE") {
				int front_team = main.front();//1 1 1
				cout << team[front_team].front() << "\n";//101 102 103 
				team[front_team].pop();
				if (team[front_team].empty()) {
					main.pop();
				}
			}
		}
		cout << "\n";
	}
	return 0;
}