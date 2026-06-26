#include <bits/stdc++.h>
using namespace std;
int main() {
    unordered_map<string, string> dictionary;
    string line;
    while (getline(cin, line) && !line.empty()) {
        stringstream ss(line);
        string english, foreign;

        ss >> english >> foreign;
       
        dictionary[foreign] = english;
    }
    string query_word;
    while (cin >> query_word) {
        if (dictionary.count(query_word)) {
            cout << dictionary[query_word] << "\n";
        } else {
            cout << "eh\n";
        }
    }
    return 0;
}
