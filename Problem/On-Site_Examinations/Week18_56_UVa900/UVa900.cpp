#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long fib[55];
    fib[1] = 1;
    fib[2] = 2;
    for (int i = 3; i <= 50; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    int n;
    while (cin >> n && n != 0) {
        cout << fib[n] << "\n";
    }
    return 0;
}