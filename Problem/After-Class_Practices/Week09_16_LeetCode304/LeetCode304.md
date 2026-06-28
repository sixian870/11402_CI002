# LeetCode 304 - Range Sum Query 2D - Immutable


## 題目簡述

給定一個二維矩陣 `matrix`，請實作一個 `NumMatrix` 類別，用來高效處理多個針對特定子矩陣的 **區域和檢索** 請求：

* `NumMatrix(int[][] matrix)`：用二維整數矩陣 `matrix` 初始化物件。
* `int sumRegion(int row1, int col1, int row2, int col2)`：回傳子矩陣內元素的 **總和**。該子矩陣的左上角頂點為 `(row1, col1)`，右下角頂點為 `(row2, col2)`（包含邊界）。

**Sample Input & Output**：

* **Input :**
  ```text
  ["NumMatrix", "sumRegion", "sumRegion", "sumRegion"]
  [[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]], [2, 1, 4, 3], [1, 1, 2, 2], [1, 2, 2, 4]]
  ```
* **Output :**
  ```text
  [null, 8, 11, 12]
  ```
* **解釋 :**
  
  初始化後的矩陣如下：
  ```text
  3  0  1  4  2
  5  6  3  2  1
  1 [2  0  1] 5
  4 [1  0  1] 7
  1 [0  3  0] 5
  ```
  `numMatrix.sumRegion(2, 1, 4, 3);` 回傳 8。（即紅框/括號內子矩陣的總和： $2+0+1+1+0+1+0+3+0 = 8$ ）


## 程式碼

1. **直覺暴力的時間地獄**：<br>
  如果每次呼叫 `sumRegion` 時，都用雙層 `for` 迴圈遍歷該區域的每一格進行累加，單次查詢的時間複雜度會高達 $O(M \times N)$。在頻繁查詢的場景下，會直接吃下 TLE。

2. **二分圖形容斥原理（2D Prefix Sum）**：
   - 為了在 $O(1)$ 時間內秒殺查詢，我們建立一個二維輔助陣列 `dp`。
   - 我們定義 `dp[i][j]` 代表**以 `(0, 0)` 為左上角、`(i-1, j-1)` 為右下角的所有矩陣元素總和**。
   - 為了排版優雅並防範邊界溢位，我們將 `dp` 的大小宣告為 `(M + 1) * (N + 1)`，並將第一列與第一欄初始化為 `0`。

3. **建構子 DP 狀態轉移方程式**：<br>
   在初始化時，我們可以透過幾何重疊的邏輯，以 $O(M \times N)$ 的時間遞迴算出全矩陣的前綴和：<br>
   $$\text{dp}[i][j] = \text{matrix}[i-1][j-1] + \text{dp}[i-1][j] + \text{dp}[i][j-1] - \text{dp}[i-1][j-1]$$ <br>
   *(當前格前綴和 = 當前數值 + 上方大方塊 + 左邊大方塊 - 重複加到的左上方方塊)*

4. **查詢區域和轉移公式（容斥原理）**：<br>
   當我們想查詢左上角 `(row1, col1)` 到右下角 `(row2, col2)` 的子矩陣和時，利用對應的 `dp` 區塊進行「大方塊減去上方、左邊多餘區塊，並加回重複扣掉的左上角」：<br>
   $$\text{sumRegion} = \text{dp}[row2+1][col2+1] - \text{dp}[row1][col2+1] - \text{dp}[row2+1][col1] + \text{dp}[row1][col1]$$

5. **複雜度分析**：
   * **建構子建置時間**： $O(M \times N)$，在初始化時線性掃描一遍矩陣即可。
   * **單次查詢時間**： $O(1)$，`sumRegion` 內部僅需做四項常數級的加減法，極致高效。
   * **額外空間複雜度**： $O(M \times N)$，需要開闢一個大小為 $(M + 1) \times (N + 1)$ 的二維前綴和快取陣列。

```cpp
#include <vector>

class NumMatrix {
private:
    std::vector<std::vector<int>> dp; // 儲存二維前綴和快取的矩陣

public:
    NumMatrix(std::vector<std::vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        int m = matrix.size();
        int n = matrix[0].size();
        // 預留 m+1, n+1 大小，讓第 0 列與第 0 欄預設為 0，防範邊界溢位
        dp.assign(m + 1, std::vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = matrix[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]; // 當前值 + 上方前綴和 + 左方前綴和 - 重複算到的左上方前綴和
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1]; // 總大矩陣 - 上方多餘區塊 - 左方多餘區塊 + 重複扣掉的左上方區塊
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 304 - Range Sum Query 2D - Immutable](https://leetcode.com/problems/range-sum-query-2d-immutable/)
