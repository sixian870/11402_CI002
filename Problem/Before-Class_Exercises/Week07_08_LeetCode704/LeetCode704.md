# LeetCode 704 - Binary Search


## 題目簡述

給定一個含有 $n$ 個元素的整數陣列 `nums`，該陣列已按 **升序（從小到大）** 排列，另給定一個目標值 `target`。<br>
請寫一個函式搜尋 `nums` 中的 `target`，如果目標值存在，則回傳它的**索引位置（Index）**；否則回傳 `-1`。<br>
你必須設計一個時間複雜度為 **$O(\log n)$** 的演算法。

**Sample Input & Output**：

* **Example 1 :**
  * **Input :** `nums = [-1,0,3,5,9,12]`, `target = 9`
  * **Output :** `4` ($\rightarrow 9$ 存在於陣列中，其索引為 4)

* **Example 2 :**
  * **Input :** `nums = [-1,0,3,5,9,12]`, `target = 2`
  * **Output :** `-1` ($\rightarrow 2$ 不存在於陣列中，回傳 -1)


## 程式碼

1. **核心思考方向**：既然陣列已經排序好，要達到 $O(\log n)$ 的速度，最經典的武器就是**二分搜尋法（Binary Search）**。每次藉由檢查區間的中點（`mid`），就能直接淘汰掉一半不可能的範圍。

2. **避免算術溢位（Overflow Trap）**：在計算中點索引時，傳統直覺寫法是 `mid = (left + right) / 2`。然而，如果 `left` 和 `right` 的數值非常大，兩者相加 `left + right` 可能會**超過 `int` 的最大範圍**進而導致溢位錯誤（變成負數）。

3. **極致防禦公式**：為了防禦此類 Bug，應將中點公式改寫為：<br>
    $$\text{mid} = \text{left} + \frac{\text{right} - \text{left}}{2}$$ <br>
    這樣寫是先計算兩者間的距離，折半後再加上起點，數值永遠不會超過 `right`，完全杜絕了整數溢位的風險。

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            // 避免 (left + right) 造成整數溢位 (Overflow)
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid; // 找到目標值，直接回傳索引
            } 
            else if (nums[mid] < target) {
                left = mid + 1; // 目標值在右半邊，限縮左邊界
            } 
            else {
                right = mid - 1; // 目標值在左半邊，限縮右邊界
            }
        }
        return -1; // 搜尋區間耗盡仍未找到，回傳 -1
    }
};
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 704 - Binary Search](https://leetcode.com/problems/binary-search/)
