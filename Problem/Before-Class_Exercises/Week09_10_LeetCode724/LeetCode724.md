# LeetCode 724 - Find Pivot Index


## 題目簡述

給定一個整數陣列 `nums`，請計算該陣列的 **中心索引（Pivot Index）**。<br>
中心索引的定義為：該索引**左側所有元素相加的總和**，剛好等於**右側所有元素相加的總和**。

* 如果中心索引位於陣列的開頭（索引 `0`），則其左側總和視為 `0`。
* 同理，如果中心索引位於陣列的末尾，則其右側總和視為 `0`。

如果陣列中存在多個中心索引，請回傳 **最左邊（最小）的那個索引**；如果完全不存在中心索引，則回傳 `-1`。

**Sample Input & Output**：

* **Example 1 :**
  * **Input :** `nums = [1,7,3,6,5,6]`
  * **Output :** `3` ($\rightarrow$ 中心索引為 3。左側和 $= 1+7+3 = 11$；右側和 $= 5+6 = 11$，兩者相等。)

* **Example 2 :**
  * **Input :** `nums = [1,2,3]`
  * **Output :** `-1` ($\rightarrow$ 找不到任何一個位置滿足左右總和相等。)

* **Example 3 :**
  * **Input :** `nums = [2,1,-1]`
  * **Output :** `0` ($\rightarrow$ 中心索引為 0。左側和視為 0；右側和 $= 1 + (-1) = 0$，兩者相等。)


## 程式碼

1. **直覺暴力的缺點**：如果對每個位置都重新用迴圈往左、往右累加，時間複雜度會劣化到 $O(N^2)$。

2. **全域總和前綴法**：我們可以用更聰明的數學關係在單次巡邏中解決它。

   - 先花費 $O(N)$ 的時間把整張陣列所有元素的總和算出來，令其為 `total_sum`。
   - 接著，我們維護一個變數 `left_sum` 代表目前指針左邊的所有元素和（初始化為 `0`）。
   - 當指針走到索引 `i` 時，`nums[i]` 就是中心點。此時，右側的總和不需要重新用迴圈算，它在數學上必然等於：<br>
   
     $$\text{rightSum} = \text{totalSum} - \text{leftSum} - \text{nums}[i]$$
   - 因此，我們只要檢查是否滿足 `left_sum == total_sum - left_sum - nums[i]` 即可。如果不相等，就把目前的 `nums[i]` 累加到 `left_sum` 中，繼續往右推進。

4. **完美的一刀切複雜度**：這種前綴和的概念讓我們只需進行兩次獨立的單層巡邏，時間複雜度為完美的 $O(N)$，且空間複雜度維持在極致的 $O(1)$！

```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }
        int left_sum = 0;
        // 從左到右巡邏，尋找平衡點
        for (int i = 0; i < nums.size(); i++) {
            // 右側和 = 總和 - 左側和 - 目前的的中心值，若 左側和 == 右側和，代表找到中心索引
            if (left_sum == total_sum - left_sum - nums[i]) {
                return i;
            }
            // 若不相等，將當前數值納入左側和，為下一個位置做準備
            left_sum += nums[i];
        }
        return -1; // 巡邏結束皆未符合，代表中心點不存在
    }
};
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 724 - Find Pivot Index](https://leetcode.com/problems/find-pivot-index/)
