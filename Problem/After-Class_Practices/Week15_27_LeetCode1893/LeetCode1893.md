# LeetCode 1893 - Check if All the Integers in a Range Are Covered


## 題目簡述

給定一個二維整數陣列 `ranges` 和兩個整數 `left` 和 `right`。每個 `ranges[i] = [start_i, end_i]` 表示一個從 `start_i` 到 `end_i` 的 **閉區間**（包含兩端點）。<br>
如果閉區間 `[left, right]` 中的 **每一個整數** 都被 `ranges` 中的至少一個區間所覆蓋，請回傳 `true`；否則，回傳 `false`。<br>
一個整數 `x` 被區間 `ranges[i] = [start_i, end_i]` 覆蓋，當且僅當 `start_i <= x <= end_i`。

**Sample Input & Output**：

* **Example 1 :**
  * **Input :** `ranges = [[1,2],[3,4],[5,6]]`, `left = 2`, `right = 5`
  * **Output :** `true`
  * **解釋 :** `[2, 5]` 區間內的整數為 2, 3, 4, 5。
    - 2 被 `[1, 2]` 覆蓋。
    - 3 和 4 被 `[3, 4]` 覆蓋。
    - 5 被 `[5, 6]` 覆蓋。
    所有整數皆被覆蓋，因此回傳 `true`。

* **Example 2 :**
  * **Input :** `ranges = [[1,10],[10,20]]`, `left = 21`, `right = 21`
  * **Output :** `false`
  * **解釋 :** 21 沒有被任何區間覆蓋，因此回傳 `false`。


## 程式碼

1. **直覺暴力的時間開銷**：<br>
   最直覺的作法是開一個布林陣列（或雜湊表），然後把 `ranges` 裡的每個區間用 `for` 迴圈跑一遍，將踩到的格子全部標記為 `true`。雖然這題的數值範圍很小（題目規定數值最大不超過 50），暴力解能輕鬆過關，但若今天區間長度或範圍暴增（例如達到 $10^5$），這種暴力染色的法子就會面臨 TLE 危機。

2. **差分陣列（Difference Array）的動態前綴和思維**：
   - 為了達成 $O(N)$ 的高效處理，我們可以利用**差分陣列**的技巧：**「區間修改看兩端，單點查詢看前綴和」**。
   - 想像一條軸線，每當遇到一個區間 `[start, end]`，代表在這個範圍內的覆蓋次數都應該 $+1$。
   - 我們不需要把中間每一格都手動加 1，只需要在起點 `start` 標記變更：`diff[start]++`（代表從這裡開始覆蓋次數加 1）；並在終點的下一格 `end + 1` 標記扣回：`diff[end + 1]--`（代表過了這個區間後，覆蓋次數減 1）。

3. **前綴和還原與範圍判定**：
   - 將所有區間的兩端標記完成後，我們從左到右（索引 `1` 到 `50`）計算 `diff` 陣列的**前綴和（Prefix Sum）**。
   - 累加出來的當前前綴和 `overlap_count`，就代表**該整數點被多少個區間給覆蓋**。
   - 當我們巡邏到 `left <= i <= right` 的區間時，只要發現當前的覆蓋次數 `overlap_count <= 0`，就代表抓到了漏網之魚（沒有任何區間覆蓋它），便可果斷回傳 `false`！

4. **複雜度分析**：
   - **時間複雜度**： $O(N + L)$，其中 $N$ 是 `ranges` 的區間個數，$L$ 是數值範圍的長度（本題最大為 50）。我們只掃描了一次區間來標記端點，並做了一次常數級的線性累加。
   - **空間複雜度**： $O(L)$。需要開闢一個固定大小（52格，防範 `end + 1` 越界）的差分陣列。

```cpp
#include <vector>

class Solution {
public:
    bool isCovered(std::vector<std::vector<int>>& ranges, int left, int right) {
        std::vector<int> diff(52, 0);
        for (const auto& range : ranges) {
            int start = range[0];
            int end = range[1];
            diff[start]++;     // 進入區間：覆蓋數 +1
            diff[end + 1]--;   // 離開區間：覆蓋數 -1
        }
        // 由左至右計算前綴和，還原出每一點的實際覆蓋次數 (O(L) 時間)
        int overlap_count = 0;
        for (int i = 1; i <= 50; i++) {
            overlap_count += diff[i];
            // 如果當前點落在 [left, right] 的檢驗範圍，且累積的覆蓋次數為 0，說明此整數被漏掉了，沒有被完整覆蓋
            if (i >= left && i <= right && overlap_count <= 0) {
                return false;
            }
        }
        return true;
    }
};
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 1893 - Check if All the Integers in a Range Are Covered](https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered/)
