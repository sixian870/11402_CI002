/*UVa10954
* 找出數列相加最小成本
* 1 2 3 
* 1+2=3 3+3=6 總成本3+6=9
* 3+2=5 5+1=6 總成本5+6=11
* 先相加的會重複被加到後面，所以要先相加小的數字，才能讓相加的成本降低
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main() {
	int n;
	while (cin >> n && n != 0) {
		priority_queue<long long, vector<long long>, greater<long long>> min_heap;
		for (int i = 0; i < n; i++) {
			long long val;
			cin >> val;
			min_heap.push(val);
		}
		int cost = 0;
		while (min_heap.size() > 1) {
			int sum = 0;
			int a = min_heap.top();
			min_heap.pop();
			int b = min_heap.top();
			min_heap.pop();
			sum = a + b;
			cost += sum;
			min_heap.push(sum);
		}
		cout << cost << endl;
	}
	return 0;
}