#include <iostream>
#include <string>
#include <list>
using namespace std;
int main() {
    string s;
    while (cin >> s) {
        list<char> dst;
        auto it = dst.end();
        for (char c : s) {
            if (c == '[') {
                it = dst.begin();
            }
            else if (c == ']') {
                it = dst.end();
            }
            else {
                dst.insert(it, c);
            }
        }
        for (char c : dst) {
            cout << c;
        }
        cout << "\n";
    }
    return 0;
}