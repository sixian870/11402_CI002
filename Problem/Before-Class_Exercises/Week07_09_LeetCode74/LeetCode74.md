# LeetCode 74 - Search a 2D Matrix


## 題目簡述

給定一個大小為 $m \times n$ 的整數矩陣 `matrix` 和一個目標值 `target`。該矩陣具有以下兩項特殊性質：
1. 每行（Row）中的整數皆已按 **從左到右、從小到大**（升序）排列。
2. 每行的第一個整數皆大於前一行的最後一個整數。

請判斷 `target` 是否存在於矩陣中。如果存在，回傳 `true`；否則回傳 `false`。<br>
你必須設計一個時間複雜度為 **$O(\log(m \times n))$** 的演算法。

**Sample Input & Output**：

* **Example 1 :**
  
  <img width="244" height="186" alt="螢幕擷取畫面 2026-06-27 215433" src="https://github.com/user-attachments/assets/5986737f-1de5-4cc7-b769-e94f7e619694" />
  <br><br>

  * **Input :** `matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]]`, `target = 3`
  * **Output :** `true` ($\rightarrow 3$ 存在於矩陣中)

* **Example 2 :**

  <img width="244" height="185" alt="螢幕擷取畫面 2026-06-27 215444" src="https://github.com/user-attachments/assets/14007a9e-ec8f-4f70-8b11-38039b049ff2" />
  <br><br>
 
  * **Input :** `matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]]`, `target = 13`
  * **Output :** `false` ($\rightarrow 13$ 不存在於矩陣中)


## 程式碼

1. **核心思考方向**：由於性質二指出「下一行的起點大於上一行的終點」，這意味著如果我們把這個二維矩陣 **「頭尾相接、攤平拉直」**，它本質上就是一個**完全排序好的巨大一維陣列**。

2. **座標映射技巧 (Coordinate Mapping)**：
   - 假設矩陣寬度（行數）為 `n`。
   - 當我們在虛擬的一維空間中，對某個虛擬索引 `mid` 進行二分搜尋時，我們不需要真的開一個陣列來攤平它，這樣會耗費 $O(m \times n)$ 的空間。
   - 我們可以直接利用除法與取餘數公式，將一維索引 `mid` 逆向映射回原矩陣的二維座標：
     $$\text{row} = \text{mid} / n, \quad \text{col} = \text{mid} \% n$$
   - 透過 `matrix[mid / n][mid % n]` 就能直接取得對應值。

3. **極致的時間與空間複雜度**：將總元素個數 $m \times n$ 視為一維搜尋範圍，直接套用標準的二分搜尋法。這樣一來，時間複雜度是完美的 $O(\log(m \times n))$，且沒有耗費任何額外的矩陣記憶體空間，空間複雜度為 $O(1)$！

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int m = matrix.size();       // 矩陣的列數 (Rows)
        int n = matrix[0].size();    // 矩陣的行數 (Columns)
        int left = 0;
        int right = m * n - 1;       // 虛擬一維陣列的末尾索引
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // 將一維索引 mid 映射回二維座標 [mid / n][mid % n]
            int mid_val = matrix[mid / n][mid % n];
            
            if (mid_val == target) {
                return true; // 成功找到目標值
            } 
            else if (mid_val < target) {
                left = mid + 1; // 目標值在右半側
            } 
            else {
                right = mid - 1; // 目標值在左半側
            }
        }
        return false; // 搜尋範疇耗盡，目標值不存在
    }
};
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 74 - Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-Matrix/)
