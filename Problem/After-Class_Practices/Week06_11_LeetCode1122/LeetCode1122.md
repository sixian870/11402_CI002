# LeetCode 1122 - Relative Sort Array


## 題目簡述

給定兩個整數陣列 `arr1` 和 `arr2`，其中 `arr2` 中的元素是各不相同的，且 `arr2` 中的所有元素都存在於 `arr1` 中。<br>
請對 `arr1` 中的元素進行排列，使得 `arr1` 中元素的相對順序與 `arr2` 中的相對順序相同。那些未在 `arr2` 中出現的元素，則需要按照 **升序（從小到大）** 排列在 `arr1` 的末尾。

**Sample Input & Output**：

* **Example 1 :**
  * **Input :** `arr1 = [2,3,1,3,2,4,6,7,9,2,19]`, `arr2 = [2,1,4,3,9,6]`
  * **Output :** `[2,2,2,1,4,3,3,9,6,7,19]`
  * **解釋 :** 
    - 先按照 `arr2` 的順序排列 `arr1` 中有的元素：2 出現 3 次，1 出現 1 次，4 出現 1 次，3 出現 2 次，9 出現 1 次，6 出現 1 次。
    - 剩下沒在 `arr2` 出現的有 7 和 19，把它們依升序排在最後。

* **Example 2 :**
  * **Input :** `arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]`
  * **Output :** `[22,28,8,6,17,44]`


## 程式碼

1. **值域特性的關鍵突破口**：<br>
   觀察題目限制，陣列中元素的數值範圍通常很小（本題限制為 $0 \le \text{arr1}[i] \le 1000$）。當數值範圍高度集中且有限時， **計數排序（Counting Sort）** 就是能在線性時間內破局的終極武器。

2. **雙階段計數填入法**：
   - **第一步：建立頻率統計表**。我們開一個大小為 1001 的計數陣列 `frequence`，巡邏一遍 `arr1`，把每個數字出現的次數統計下來。
   - **第二步：依照 `arr2` 順序導出答案**。接著巡邏 `arr2`，每拿到一個數字，就去 `frequence` 查它在 `arr1` 裡出現了幾次，出現幾次我們就在答案陣列中連續填入幾次，填完後把該數字的頻率清空為 0。
   - **第三步：升序掃描殘留元素**。最後，我們直接從索引 `0` 到 `1000` 依序掃描整個 `frequence` 陣列。只要發現某個數字的頻率不為 0（代表它是沒在 `arr2` 中出現過的孤兒數字），就依據剩餘頻率把它們填入答案末尾。因為我們是從索引小到大（0 到 1000）線性掃描，這會**自動保證殘留元素是完美的升序排列**，連 `sort` 都不用呼叫！

3. **時間與空間複雜度**：
   - **時間複雜度**： $O(N + M + K)$，其中 $N$ 是 `arr1` 的長度， $M$ 是 `arr2` 的長度， $K$ 是值域大小（固定為 1001）。整體在線性時間內完成，效能極高。
   - **空間複雜度**： $O(K)$，只需要一個大小固定為 1001 的常數級計數陣列。

```cpp
#include <vector>

class Solution {
public:
    std::vector<int> relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2) {
        std::vector<int> frequence(1001, 0);
        for (int num : arr1) {
            frequence[num]++; // 統計 arr1 中每個元素出現的頻率次數
        }
        std::vector<int> ans;
        ans.reserve(arr1.size()); // 預先配置記憶體，優化推入效能
        // 按照 arr2 的順序，將元素依據頻率次數填入答案中
        for (int num : arr2) {
            while (frequence[num] > 0) {
                ans.push_back(num);
                frequence[num]--;
            }
        }
        // 從小到大掃描計數陣列，將未在 arr2 出現過的元素自然升序填入末尾
        for (int num = 0; num <= 1000; num++) {
            while (frequence[num] > 0) {
                ans.push_back(num);
                frequence[num]--;
            }
        }
        return ans;
    }
};
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 1122 - Relative Sort Array](https://leetcode.com/problems/relative-sort-array/)
