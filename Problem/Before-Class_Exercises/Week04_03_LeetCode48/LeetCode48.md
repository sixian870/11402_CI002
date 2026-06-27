# LeetCode 48 - Rotate Image


## 題目簡述

給定一個 $n \times n$ 的二維矩陣 `matrix`，代表一張影像。請將這張影像**順時針旋轉 90 度**。

題目要求必須 **原地（In-place）** 修改矩陣，這意味著你必須直接在原矩陣上進行翻轉與互換，**不能**開一個全新的二維矩陣來排答案。

**Sample Input & Output**：

* **Example 1 :**

  <img width="278" height="110" alt="螢幕擷取畫面 2026-06-27 202752" src="https://github.com/user-attachments/assets/5cc7c3ba-b138-4e4f-b605-0a31f81833dd" />
  <br><br>
  
  * **Input :** `matrix = [[1,2,3],[4,5,6],[7,8,9]]`
  * **Output :** `[[7,4,1],[8,5,2],[9,6,3]]`

* **Example 2 :**

  <img width="278" height="116" alt="螢幕擷取畫面 2026-06-27 202810" src="https://github.com/user-attachments/assets/c660ad66-ec75-4b2c-bab1-17a2172bff46" />
  <br><br>
  
  * **Input :** `matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]`
  * **Output :** `[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]`


## 程式碼

1. **直接旋轉的難度**：如果想直接把各個元素挪到旋轉 90 度後的位置，程式的四角交換索引會寫得極其複雜且容易出錯。

2. **經典幾何兩步變換法**：在線性代數與數位影像處理中，順時針旋轉 90 度有一個非常經典的兩步拆解技巧：
    
    - **第一步：沿著主對角線（左上到右下）進行轉置（Transpose）**。也就是把 `matrix[i][j]` 與 `matrix[j][i]` 對調。
    - **第二步：水平翻轉每一行（Reverse columns）**。也就是把每一列（Row）的左半邊跟右半邊對調。

3. **空間與時間優化**：轉置只需要雙層迴圈掃描右上三角（`j > i`），水平翻轉則可直接調用內建的 `reverse()` 函式。這樣兩步做完，不僅程式碼極其精簡易讀，還能完美滿足 $O(1)$ 額外空間的 In-place 規範。

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // 沿主對角線進行矩陣轉置 (Transpose)
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // 水平翻轉每一列 (Reverse each row)
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 48 - Rotate Image](https://leetcode.com/problems/rotate-image/)
