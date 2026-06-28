# LeetCode 378 - Kth Smallest Element in a Sorted Matrix


## 題目簡述

給定一個 $n \times n$ 的矩陣 `matrix`，其中**每一列（Row）**和**每一欄（Column）**都已按**非遞減順序**（從小到大）排列。<br>
請找出並回傳矩陣中**第 `k` 小**的元素。<br>
請注意，我們要找的是這組數字**排序後**的第 `k` 小元素，而不是第 `k` 個不同的元素。

**Sample Input & Output**：

* **Example 1 :**
  * **Input :** `matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8`
  * **Output :** `13`
  * **解釋 :** 矩陣中的元素為 `[1, 5, 9, 10, 11, 13, 12, 13, 15]`，排序後為 `[1, 5, 9, 10, 11, 12, 13, 13, 15]`。其中第 8 小的元素是 13。

* **Example 2 :**
  * **Input :** `matrix = [[-5]], k = 1`
  * **Output :** `-5`


## 程式碼

1. **突破傳統的思維**：<br>
   一般我們用二分搜尋法，都是在對「陣列的索引（Index）」進行二分。但面對這個每一列、每一欄都有序的矩陣，我們可以轉向對 **「數值範圍（Value Range）」** 進行二分搜尋！
   - 起始左邊界 `low` 為矩陣左上角（全域最小值 `matrix[0][0]`）。
   - 起始右邊界 `high` 為矩陣右下角（全域最大值 `matrix[n-1][n-1]`）。

2. **自適應階梯計數法（與主導值比對）**：
   - 每次取一個中間值 `mid = low + (high - low) / 2`，我們要計算矩陣中有多少個數字**小於或等於 `mid`**（假設有 `count` 個）。
   - 利用矩陣的雙向遞增特性，我們不需要盲目去掃描所有格子，而是從**左下角**（或右上角）出發：
     - 如果當前格子 `matrix[row][col] <= mid`，代表這格以及它上方所有的元素都必定小於或等於 `mid`。我們可以直接把這一整欄的合法個數加入累加（`count += row + 1`），並把指針**向右移動一欄**（`col++`）。
     - 如果當前格子 `matrix[row][col] > mid`，代表這個值太大了，我們必須把指針**向上移動一列**（`row--`）。
   - 這個階梯式的計數技巧，能讓我們只花 $O(N)$ 的時間就數出全場有多少數字小於等於 `mid`。

3. **調整二分邊界**：
   - 如果算出來的 `count < k`，代表估計的 `mid` 太小了，第 `k` 小的數字必定在右半邊，所以將左邊界推移：`low = mid + 1`。
   - 反之，若 `count >= k`，代表 `mid` 夠大，第 `k` 小的數字可能就是 `mid` 本身或在其左半邊，我們收縮右邊界：`high = mid`。
   - 當 `low == high` 時，這兩個指標相遇的位置就是我們苦苦尋找的第 `k` 小整數。

4. **時間與空間複雜度**：
   - **時間複雜度**： $O(N \log(\text{max} - \text{min}))$，其中 $N$ 為矩陣的邊長， $\text{max} - \text{min}$ 為最大與最小值的差值。在大多數情況下，這遠比使用優先佇列（Heap）的 $O(K \log N)$ 或 $O(N^2 \log N)$ 還要快速。
   - **空間複雜度**： $O(1)$，完全不需要任何額外容器，達成極致的常數級記憶體控制。

```cpp
#include <vector>

class Solution {
public:
    int kthSmallest(std::vector<std::vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];          // 全域最小值
        int high = matrix[n - 1][n - 1]; // 全域最大值
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            // 利用階梯計數法，計算矩陣中 <= mid 的元素個數
            if (countLessOrEqual(matrix, mid, n) < k) {
                low = mid + 1; // 如果數量不夠 k 個，代表 mid 太小，目標值在右半區
            } else {
                high = mid; // 否則，目標值在左半區（包含 mid 本身）
            }
        }
        return low;
    }

private:
    // 以 O(N) 的線性時間在有序矩陣中數出有多少元素 <= mid
    int countLessOrEqual(const std::vector<std::vector<int>>& matrix, int mid, int n) {
        int count = 0;
        int row = n - 1; // 從左下角開始出發
        int col = 0;
        while (row >= 0 && col < n) {
            if (matrix[row][col] <= mid) {
                // 若當前位置 <= mid，代表這格與其上方整欄都符合條件
                count += (row + 1);
                col++; // 向右推進一欄
            } else {
                row--; // 太大了，向上退回一列
            }
        }
        return count;
    }
};
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 378 - Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/)
