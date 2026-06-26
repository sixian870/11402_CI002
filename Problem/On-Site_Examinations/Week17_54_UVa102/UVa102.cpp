#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;
int main() {
    int b[9];
    while (cin >> b[0] >> b[1] >> b[2] >> b[3] >> b[4] >> b[5] >> b[6] >> b[7] >> b[8]) {
        int total = 0;
        for (int i = 0; i < 9; i++) {
            total += b[i];
        }
        int min = INT_MAX;
        string best = "";
        string configs[] = { "BCG", "BGC", "CBG", "CGB", "GBC", "GCB" };

        for (string config : configs) {
            int stay = 0;
            // 矪瞶材 1 表
            if (config[0] == 'B') stay += b[0];
            else if (config[0] == 'G') stay += b[1];
            else if (config[0] == 'C') stay += b[2];

            // 矪瞶材 2 表
            if (config[1] == 'B') stay += b[3];
            else if (config[1] == 'G') stay += b[4];
            else if (config[1] == 'C') stay += b[5];

            // 矪瞶材 3 表
            if (config[2] == 'B') stay += b[6];
            else if (config[2] == 'G') stay += b[7];
            else if (config[2] == 'C') stay += b[8];

            int moves = total - stay;// 惠璶穐笆Ω计 = 羆计 - ぃ笆计秖
            if (moves < min) {
                min = moves;
                best = config;
            }
        }
        cout << best << " " << min << "\n";
    }
    return 0;
}