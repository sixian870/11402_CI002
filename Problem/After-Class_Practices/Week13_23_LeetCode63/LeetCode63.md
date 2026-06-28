# LeetCode 63 - Unique Paths II


## 題目簡述

一個機器人位於一個 $m \times n$ 網格的左上角（起始點在 `obstacleGrid[0][0]`）。<br>
機器人每次只能**向下**或**向右**移動一步。機器人試圖達到網格的右下角（終點在 `obstacleGrid[m-1][n-1]`）。<br>
現在考慮網格中可能包含**障礙物**。不幸的是，機器人無法通過有障礙物的格子。網格中的障礙物和空位分別用 `1` 和 `0` 來表示。<br>
請計算機器人從左上角到右下角一共有多少條 **不同的路徑**？

> **邊界與型態規範**：測試案例保證最終的答案小於或等於 $2 \times 10^9$（意即答案能塞進標準的 32 位元有號整數 `int` 中）。

**Sample Input & Output**：

* **Example 1 :**

  <img width="185" height="185" alt="螢幕擷取畫面 2026-06-28 201314" src="https://github.com/user-attachments/assets/ecc1314c-b6df-4f1f-9f1e-aa7a280fa682" />
  <br><br>
  
  * **Input :** `obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]`
  * **Output :** `2`
  * **解釋 :** 
    一個 $3 \times 3$ 的網格中，正中央有一個障礙物（`1`）。<br>
    從左上角到右下角一共有 2 條不同的路徑：
    1. 向右 -> 向右 -> 向下 -> 向下
    2. 向下 -> 向下 -> 向右 -> 向右

* **Example 2 :**

  <img width="125" height="124" alt="螢幕擷取畫面 2026-06-28 201327" src="https://github.com/user-attachments/assets/0ad51124-1b11-4975-bb65-7af542f6fb74" />
  <br><br>
  
  * **Input :** `obstacleGrid = [[0,1],[0,0]]`
  * **Output :** `1`


## 程式碼

1. **核心動態規劃思維**：<br>
   機器人只能從「上方格子」或「左方格子」走過來。<br>
   因此，到達某一格 `(i, j)` 的方法總數，就是這兩個方向的路徑數加總。<br>
   但如果當前格子是障礙物（`obstacleGrid[i][j] == 1`），機器人根本踩不上去，所以到達該格的路徑數必須直接歸零 `0`。

2. **基礎二維 DP 狀態轉移方程式**：<br>
   若當前格子非障礙物： $$\text{dp}[i][j] = \text{dp}[i-1][j] + \text{dp}[i][j-1]$$ <br>
   若當前格子為障礙物： $$\text{dp}[i][j] = 0$$

3. **維度打擊：滾動陣列（Rolling Array）優化**：
   - 傳統的二維 DP 會建立一個 $m \times n$ 的表格，空間複雜度是 $O(m \times n)$。
   - 觀察公式可以發現，要算當前格子，我們只需要「上一列的同一欄（`dp[i-1][j]`）」和「當前列的前一欄（`dp[i][j-1]`）」。
   - 因此，我們只需要宣告一個大小為 $n$（欄數）的**一維 `dp` 陣列**。
   - 當我們從左到右更新 `dp[j]` 時：
     - `dp[j]` 本身在更新前，存放的其實就是**上一列同一欄的數據**（等同 `dp[i-1][j]`）。
     - 更新後的 `dp[j-1]`，存放的就是**當前列前一欄新算好的數據**（等同 `dp[i][j-1]`）。
     - 所以一維陣列更新公式可以直接精簡為：`dp[j] = dp[j] + dp[j-1]`。

4. **複雜度分析**：
   - **時間複雜度**： $O(m \times n)$。需要遍歷整個網格的所有格子各一次。
   - **空間複雜度**： $O(n)$。將空間壓縮至僅需維護一列寬度的滾動快取，達到極致的常數級記憶體控制（優化時建議挑選 $m$ 和 $n$ 較小者作為陣列大小）。

```cpp
#include <vector>

class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
            return 0; // 若起點或終點本身就是障礙物，機器人動彈不得，直接回傳 0
        }
        std::vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0; // 如果當前格子是障礙物，路徑數直接斷絕，歸零
                } 
                else if (j > 0) { // 若非障礙物，且非每列的第一個格子（j > 0），進行累加更新
                    dp[j] = dp[j] + dp[j - 1]; // 最新的 dp[j] = 上方格子舊值 (dp[j]) + 左方格子新值 (dp[j-1])
                }
            }
        }
        return dp[n - 1]; // 滾動陣列的最後一格即為右下角終點的總路徑數
    }
};
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 63 - Unique Paths II](https://leetcode.com/problems/unique-paths-ii/)
