# LeetCode 64 - Minimum Path Sum


## 題目簡述

給定一個包含非負整數的 $m \times n$ 網格 `grid`，請找出條從左上角（起點）到右下角（終點）的路徑，使得**路徑上的數字總和為最小**。<br>
機器人每次只能**向下**或者**向右**移動一步。

**Sample Input & Output**：

* **Example 1 :**

  <img width="187" height="186" alt="螢幕擷取畫面 2026-06-28 030151" src="https://github.com/user-attachments/assets/6939bc3d-0843-4db7-aef9-6bde2b10ba60" />
  <br><br>
  
  * **Input :** `grid = [[1,3,1],[1,5,1],[4,2,1]]`
  * **Output :** `7`
  * **解釋 :** 因為路徑 $1 \to 3 \to 1 \to 1 \to 1$ 的總和最小，為 7。

* **Example 2 :**:
  * **Input :** `grid = [[1,2,3],[4,5,6]]`
  * **Output :** `12`


## 程式碼

1. **核心思考方向**：因為限制只能「向下」或「向右」，這意味著要到達格子 $(i, j)$，前一步只能是從上方 $(i-1, j)$ 或從左方 $(i, j-1)$ 跨過來。

2. **狀態轉移方程式**：<br>
   為了讓總和最小，我們應該從「上方格子的最小代價」與「左方格子的最小代價」中選擇較小的那一個，再加上當前格子的數字：
   $$\text{dp}[i][j] = \min(\text{dp}[i-1][j], \text{dp}[i][j-1]) + \text{grid}[i][j]$$

3. **邊界初始化（首列與首欄特判）**：<br>
   - 對於最左邊那一欄（`j = 0`），只能一路從上面掉下來，所以它的路徑和是上方格子的值持續累加。
   - 對於最上面那一列（`i = 0`），只能一路向右走，所以它的路徑和是左方格子的值持續累加。

4. **原地優化技巧（In-place DP）**：<br>
   因為題目給定的 `grid` 矩陣在計算完後就不再需要了，我們可以直接把 `grid[i][j]` 當作 `dp[i][j]` 空間來儲存計算結果。如此一來，連一維滾動陣列都不用開，能將額外的空間複雜度直接壓縮到究極的 $O(1)$！
   
```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 1; i < m; i++) {
            grid[i][0] += grid[i - 1][0];
        }
        for (int j = 1; j < n; j++) {
            grid[0][j] += grid[0][j - 1];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // 當前格子的值 += min(上方累積值, 左方累積值)
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[m - 1][n - 1]; // 右下角的終點格子即為全域最小路徑和
    }
};
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 64 - Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/)
