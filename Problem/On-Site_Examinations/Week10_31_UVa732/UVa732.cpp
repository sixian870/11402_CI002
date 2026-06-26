#include<iostream>
#include<queue>
#include<stack>
using namespace std;

string s1, s2;

void dfs(int s1_idx, int s2_idx, stack<char> a1, string result) {
	if (s2_idx == s2.length()) {
		if (!result.empty()) result.pop_back();
		cout << result << "\n";
		return;
	}
	if (s1_idx < s1.length()) {
		stack<char> next_st = a1;
		next_st.push(s1[s1_idx]);
		dfs(s1_idx + 1, s2_idx, next_st, result + "i ");
	}
	if (!a1.empty() && a1.top() == s2[s2_idx]) {
		stack<char> next_st = a1;
		next_st.pop();
		dfs(s1_idx, s2_idx + 1, next_st, result + "o ");
	}
}
int main() {
	while (cin >> s1 >> s2) {
		cout << "[\n";
		if (s1.length() == s2.length()) {
			stack<char> a1;
			dfs(0, 0, a1, "");
		}
		cout << "]\n";
	}
	return 0;
}