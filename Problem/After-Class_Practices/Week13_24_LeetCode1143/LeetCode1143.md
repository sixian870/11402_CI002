# LeetCode 1143 - Longest Common Subsequence


## 題目簡述

給定兩個字串 `text1` 和 `text2`，回傳這兩個字串的 **最長公共子序列（Longest Common Subsequence, LCS）** 的長度。<br>
一個字串的 **子序列** 是指這樣一個新字串：它是由原字串在不改變相對順序的情況下刪除某些字元（也可以不刪除任何字元）後組成的新字串。（例如，`"ace"` 是 `"abcde"` 的子序列，但 `"aec"` 不是）。<br>
兩個字串的 **公共子序列** 是這兩個字串所共同擁有的子序列。如果不存在公共子序列，回傳 `0`。

**Sample Input & Output**：

* **Example 1 :**
  * **Input :** `text1 = "abcde"` , `text2 = "ace"`
  * **Output :** `3`
  * **解釋 :** 最長公共子序列是 `"ace"`，它的長度為 3。

* **Example 2 :**
  * **Input :** `text1 = "abc"` , `text2 = "abc"`
  * **Output :** `3`
  * **解釋 :** 最長公共子序列是 `"abc"`，它的長度為 3。

* **Example 3 :**
  * **Input :** `text1 = "abc"` , `text2 = "def"`
  * **Output :** `0`
  * **解釋 :** 兩個字串沒有任何共同字元，因此回傳 0。


## 程式碼

1. **核心思考方向**：<br>
   比對兩個字串的子序列關係，如果採取暴力窮舉，時間複雜度會直接劣化成恐怖的指數級 $O(2^{M+N})$。為了優化它，我們通常會開闢一個二維矩陣 `dp`，其中 `dp[i][j]` 代表 **`text1` 的前 `i` 個字元與 `text2` 的前 `j` 個字元的最長公共子序列長度**。<br>
   為了排版優雅並完美兼顧空字串的邊界防禦，我們將 `dp` 矩陣的大小宣告為 `(M + 1) * (N + 1)`，並將第一列與第一欄通通初始化為 `0`。

2. **經典雙狀態轉移方程式**：<br>
   我們由左至右、由上至下遍歷 `dp` 矩陣（其中 `i` 對應 `text1` 的字元，`j` 對應 `text2` 的字元）：
   - **情況一：字元正好相符（`text1[i - 1] == text2[j - 1]`）**：
     說明我們抓到了一個共同的子序列成員！這個字元能讓 LCS 的長度直接往上加 1。此時它會承接除去這個字元後、左上角的最佳狀態：
     $$\text{dp}[i][j] = \text{dp}[i - 1][j - 1] + 1$$
   - **情況二：字元不相符（`text1[i - 1] != text2[j - 1]`）**：
     說明當前這兩個字元無法同時貢獻給同一個子序列。我們只能退而求其次，從「退掉 `text1` 當前字元（上方格子 `dp[i - 1][j]`）」與「退掉 `text2` 當前字元（左方格子 `dp[i][j - 1]`）」這兩個狀態中，挑選一個最大值繼承過來：
     $$\text{dp}[i][j] = \max(\text{dp}[i - 1][j], \text{dp}[i][j - 1])$$

3. **複雜度分析**：
   - **時間複雜度**： $O(M \times N)$，其中 $M$ 和 $N$ 分別為兩個字串的長度。我們需要用雙層 `for` 迴圈將整個二維 `dp` 表格填滿。
   - **空間複雜度**： $O(M \times N)$，需要一個二維維度的 `vector` 矩陣來保存子問題快取。（註：此題亦可進一步利用滾動陣列將空間複雜度優化至 $O(\min(M, N))$）。

```cpp
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        int m = text1.length();
        int n = text2.length();
        
        // 建立 (m + 1) x (n + 1) 的二維 DP 表格，並初始化為 0
        // 第 0 列與第 0 欄代表空字串與另一字串比對，LCS 長度自然為 0
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // 因為 dp 索引比字串索引多 1，所以當前比對的字元是 text1[i-1] 與 text2[j-1]
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1; // 字元相同，繼承左上角狀態並加 1
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]); // 字元不同，從上方與左方狀態中取最大值
                }
            }
        }
        return dp[m][n]; // 右下角的終點格子即為兩個完整字串的 LCS 最大長度
    }
};
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 1143 - Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/)
