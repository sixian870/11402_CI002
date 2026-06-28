# LeetCode 349 - Intersection of Two Arrays


## 題目簡述

給定兩個整數陣列 `nums1` 和 `nums2`，請回傳它們的 **交集**。<br>
輸出結果中的每個元素都必須是 **唯一** 的，也就是說，結果陣列中不能有重複的數字。你可以不考慮輸出結果的**順序**。

**Sample Input & Output**：

* **Example 1 :**
  * **Input :** `nums1 = [1,2,2,1]`, `nums2 = [2,2]`
  * **Output :** `[2]`

* **Example 2 :**
  * **Input :** `nums1 = [4,9,5]`, `nums2 = [9,4,9,8,4]`
  * **Output :** `[9,4]` 或 `[4,9]` （順序不影響答案）


## 程式碼

1. **核心思考方向**：<br>
   要找出兩個陣列共同擁有的元素，且結果必須「去重」（唯一性）。如果用雙層迴圈兩兩比對，時間複雜度會劣退到 $O(M \times N)$。最有效率的武器就是利用資料結構中的 `std::unordered_set`。

2. **雙 Set 線性篩選法**：
   - **第一步：建立過濾網**。我們將第一個陣列 `nums1` 的所有元素通通塞進一個雜湊集合 `set1` 中。在這個過程中，`nums1` 原本重複的數字（例如 `[1,2,2,1]`）會自動被縮減為唯一的獨立成員（變為 `{1, 2}`）。
   - **第二步：線性查找比對**。接著，我們遍歷第二個陣列 `nums2`。每拿到一個數字，就去 `set1` 裡面打聽它是否存在（利用 `set1.count()` 或 `set1.find()`）。
   - **第三步：二次去重防禦**。因為 `nums2` 本身也可能包含重複的數字（例如交集是 2，而 `nums2` 有兩個 2），為了避免答案陣列噴出重複的 2，我們將查找到的交集元素先丟進第二個集合 `intersection_set` 中做二次去重。
   - **第四步：打包輸出**。最後，直接把 `intersection_set` 裡面的所有唯一元素倒進一個 `vector<int>` 中回傳即可。

3. **時間與空間複雜度**：
   - 雜湊集合的插入與尋找在平均情況下都是常數時間 $O(1)$。
   - 整體時間複雜度為完美的 **$O(M + N)$**（$M$ 和 $N$ 分別為兩陣列的長度）。
   - 額外空間複雜度為 **$O(M)$**，主要用於存放 `nums1` 去重後的集合空間。

```cpp
#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_set<int> set1(nums1.begin(), nums1.end());
        std::unordered_set<int> intersection_set;
        // 巡邏 nums2，若該元素在 set1 中存在，代表是共同交集
        for (int num : nums2) {
            if (set1.count(num)) {
                intersection_set.insert(num); // 塞入交集集合中
            }
        }
        return std::vector<int>(intersection_set.begin(), intersection_set.end()); // 將交集集合轉換回 vector 輸出
    }
};
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 349 - Intersection of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays/)
