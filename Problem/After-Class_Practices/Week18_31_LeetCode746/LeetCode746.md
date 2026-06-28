# LeetCode 746 - Min Cost Climbing Stairs


## 題目簡述

給定一個整數陣列 `cost`，其中 `cost[i]` 是從樓梯第 `i` 個台階向上爬的成本。一旦你支付了這個成本，你可以選擇向上爬一個或兩個台階。<br>
你可以選擇從索引為 `0` 或索引為 `1` 的台階作為**起始點**。<br>
請計算出達到樓梯頂部的 **最小成本**。

> **注意**：「樓梯頂部」是指超過最後一個台階的位置（意即如果陣列長度為 `N`，頂部是指索引為 `N` 的位置，而不是 `N-1`）。

**Sample Input & Output**：

* **Example 1 :**
  * **Input :** `cost = [10,15,20]`
  * **Output :** `15`
  * **解釋 :** 
    - 最佳策略：從索引 1 的台階（成本 15）出發。
    - 向上跨兩步，直接到達樓梯頂部（索引 3）。
    - 總成本為 15。

* **Example 2 :**
  * **Input :** `cost = [1,100,1,1,1,100,1,1,100,1]`
  * **Output :** `6`
  * **解釋 :**
    - 最佳路徑：從索引 0 的台階開始（成本 1）。
    - 踩到索引 2 -> 索引 4 -> 索引 6 -> 索引 7 -> 索引 9。
    - 支付 `cost[0] + cost[2] + cost[4] + cost[6] + cost[7] + cost[9] = 1 + 1 + 1 + 1 + 1 + 1 = 6`。
    - 最後跨一步踩到頂部，總代價為 6。


## 程式碼

1. **核心動態規劃思考**：<br>
   要到達第 `i` 個台階，機器人只有兩種可能的方法：
   - 從「前一個台階（`i - 1`）」跨一步上來，花費成本為：到達 `i - 1` 的最小成本 + 站在 `i - 1` 往上踩的代價 `cost[i - 1]`。
   - 從「前兩個台階（`i - 2`）」跨兩步上來，花費成本為：到達 `i - 2` 的最小成本 + 站在 `i - 2` 往上踩的代價 `cost[i - 2]`。
   我們理所當然要從這兩種手段中，挑選一個最便宜的方案。

2. **狀態轉移方程式**：<br>
   定義 `dp[i]` 代表到達第 `i` 個台階頂部的最小花費：
   $$\text{dp}[i] = \min(\text{dp}[i - 1] + \text{cost}[i - 1], \text{dp}[i - 2] + \text{cost}[i - 2])$$

3. **核心空間壓縮：滾動變數優化**：
   - 傳統作法會開闢一個大小為 `N + 1` 的 `dp` 陣列，這會帶來 $O(N)$ 的空間消耗。
   - 觀察公式可以發現，要算出了最新的 `dp[i]`，我們其實**只需要前兩項的歷史數據**。
   - 因此，我們可以捨棄整條陣列，只用兩個整數變數 `first` 和 `second` 來記錄前兩步的最低花費：
     - `first` 代表到達 `i - 2` 的最小成本（初始化為 `0`，因為可以免費從索引 0 或 1 開始）。
     - `second` 代表到達 `i - 1` 的最小成本。
   - 每次往上走一階，就算出最新值 `current`，並把變數向後平移滾動：`first = second; second = current;`。

4. **複雜度分析**：
   - **時間複雜度**： $O(N)$。我們僅用一個 `for` 迴圈從台階 2 線性掃描到樓梯頂部。
   - **空間複雜度**： $O(1)$。將記憶體快取極致精簡至三個標記狀態的整數，達到最完美的常數級空間規格。

```cpp
#include <vector>
#include <algorithm>

class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        int n = cost.size();
        int first = 0;  // 代表 dp[i - 2]
        int second = 0; // 代表 dp[i - 1]
        for (int i = 2; i <= n; i++) {
            int current = std::min(second + cost[i - 1], first + cost[i - 2]); // 從前一階跨一步，或從前兩階跨兩步，取兩者成本較小者
            first = second;
            second = current;
        }
        return second; // 當迴圈結束時，second 剛好儲存了抵達頂部第 n 階的最小累積花費
    }
};
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 746 - Min Cost Climbing Stairs](https://leetcode.com/problems/min-cost-climbing-stairs/)
