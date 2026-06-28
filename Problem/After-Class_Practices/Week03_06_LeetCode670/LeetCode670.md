# LeetCode 670 - Maximum Swap


## 題目簡述

給定一個非負整數 `num`。你最多可以選擇交換該數字中的兩個數位（位數）一次。<br>
請找出並回傳通過交換所能獲得的 **最大數值**。

**Sample Input & Output**：

* **Example 1 :**
  * **Input :** `num = 2736`
  * **Output :** `7236`
  * **解釋 :** 交換數字 2 和 7，可以得到最大數 7236。

* **Example 2 :**
  * **Input :** `num = 9973`
  * **Output :** `9973`
  * **解釋 :** 不需要進行任何交換，因為它已經是所能達到的最大數字。


## 程式碼

1. **核心思考方向**：<br>
   要讓一個數字變得最大，我們應該儘量**把後面較大的數位，和前面較小的數位進行交換**。而且，越高的位數（越左邊）如果能被換成更大的數字，對整體數值的提升幅度就越大。

2. **最後出現位置紀錄法（Bucket Array / Hash Map）**：
   - 首先，我們可以將整數轉為字串（或字元陣列），方便我們依據索引訪問每一位數。
   - 建立一個大小為 10 的陣列 `last_pos`，用來記錄 **0 到 9 這十個數字在該數中「最後一次出現」的索引位置**。
   - 為什麼要記錄「最後一次」？因為如果有重複的最大數字（例如 `199`），我們應該拿**最右邊的 9** 和前面的 1 交換（變成 `991`），這樣才會使數值最大（若拿第一個 9 換會變成 `919`）。

3. **雙層貪心比對**：
   - 由左至右遍歷字串中的每一位數（設當前索引為 `i`，數位為 `num[i]`）。
   - 對於當前位置 `i`，我們從最大的數位 `9` 開始往下尋找（直到大於當前數位 `num[i] - '0'` 為止）。
   - 如果發現有一個數字 `d` 大於當前數位，且它最後出現的位置 `last_pos[d]` 比 `i` 還要在右邊（`last_pos[d] > i`），這就是我們要找的最佳交換對象！
   - 只要一找到，立刻進行交換並將結果轉回整數回傳。因為我們是從左到右、且從大數字 9 開始找，這次交換必定能帶來最大增幅（貪心策略）。

4. **時間與空間複雜度**：
   - 數字最多只有 9 位數（32 位元整數範圍內），紀錄位置與雙層比對的範圍都在常數級別。時間複雜度為完美的 $O(N)$（$N$ 為數字的位數，實際上不超過 10 步），空間複雜度因只需大小為 10 的固定陣列，達到極致的 $O(1)$！

```cpp
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumSwap(int num) {
        std::string numStr = std::to_string(num);
        int n = numStr.length();
        std::vector<int> last_pos(10, -1);
        for (int i = 0; i < n; i++) {
            last_pos[numStr[i] - '0'] = i;
        }
        // 由左至右找出第一個「可以被後面更大數位替換」的位置
        for (int i = 0; i < n; i++) {
            int current_digit = numStr[i] - '0';
            // 從最大數字 9 開始往下找，看有沒有比當前數位大、且出現在更右側的數字
            for (int d = 9; d > current_digit; d--) {
                if (last_pos[d] > i) {
                    // 找到最佳交換點，直接原地交換
                    std::swap(numStr[i], numStr[last_pos[d]]);
                    return std::stoi(numStr); // 交換一次後即可直接回傳結果
                }
            }
        }
        // 若完全沒有觸發交換，代表原本的數字就已經是最大值
        return num;
    }
};
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 670 - Maximum Swap](https://leetcode.com/problems/maximum-swap/)
