/*UVa11286
有 N 個學生選課，每個學生都必須選 5 門課。
選出最熱門的選課組合，且總共有幾個人選
**若有兩組人數一樣 輸出兩組相加的人數
*/
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n;
	while (cin >> n && n != 0) {
		int most = 0;
		map<vector<int>, int> list;
		while (n--) {
			vector<int> student(5);
			for (int i = 0; i < 5; i++) {
				cin >> student[i];
			}
			sort(student.begin(), student.end());
			list[student]++;
			most = max(most, list[student]);
		}
		int total = 0;
		for (auto const& it : list) {
			if (it.second == most) {
				total += it.second;
			}
		}
		cout << total << endl;
	}
	return 0;
}