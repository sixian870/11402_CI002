# LeetCode 33 - Search in Rotated Sorted Array


## 題目簡述

整數陣列 `nums` 原本按 **升序**（從小到大）排列，且陣列中的數值皆不相同。<br>
在傳遞給函式之前，該陣列在某個未知的波峰索引處進行了 **旋轉**（Rotated）。例如，原陣列 `[0,1,2,4,5,6,7]` 可能在索引 3 處旋轉，變成 `[4,5,6,7,0,1,2]`。<br>
給定旋轉後的陣列 `nums` 和一個目標值 `target`，如果 `target` 存在於陣列中，請回傳它的 **索引位置**；否則，回傳 `-1`。

> **限制**：時間複雜度為 **$O(\log N)$** 。

**Sample Input & Output**：

* **Example 1 :**
  * **Input :** `nums = [4,5,6,7,0,1,2]` , `target = 0`
  * **Output :** `4`

* **Example 2 :**
  * **Input :** `nums = [4,5,6,7,0,1,2]` , `target = 3`
  * **Output :** `-1`

* **Example 3 :**
  * **Input :** `nums = [1]` , `target = 0`
  * **Output :** `-1`


## 程式碼

1. **核心思考方向**：<br>
   雖然陣列被旋轉了，但如果我們從中點 `mid` 切一刀，會發現一個奇妙的物理規律：**左半邊和右半邊，必定至少有一邊是完全有序的（Sorted）！**
   - 比如 `[4,5,6,7,0,1,2]` 的中點是 `7`。左半邊 `[4,5,6,7]` 是完美的升序；右半邊 `[7,0,1,2]` 則是混亂的。
   - 我們可以利用這一點，先判斷哪一邊是有序的，再判定 `target` 有沒有落在那個有序的範圍內。

2. **雙指針收縮邏輯（左閉右閉 `[left, right]`）**：
   - **步驟一：判定左半邊是否有序？**
     如果 `nums[left] <= nums[mid]`，說明**左半邊是完美的升序區間**。
     - 此時，只要檢查 `target` 是否剛好落在這個左區間內（即 `nums[left] <= target && target < nums[mid]`）。
     - 如果是，代表目標在左邊，將右邊界左移：`right = mid - 1`。
     - 如果不是，說明目標一定在另一邊，將左邊界右移：`left = mid + 1`。
   - **步驟二：反之，右半邊是否有序？**
     如果步驟一不成立，說明**右半邊是完美的升序區間**。
     - 同理，檢查 `target` 是否剛好落在這個右區間內（即 `nums[mid] < target && target <= nums[right]`）。
     - 如果是，將左邊界右移：`left = mid + 1`。
     - 如果不是，將右邊界左移：`right = mid - 1`。

3. **複雜度分析**：
   - **時間複雜度**： $O(\log N)$。每次切半比對都能藉由有序性排除掉整整一半的搜尋範圍，完全符合題目嚴格要求的對數時間。
   - **空間複雜度**： $O(1)$。原地指針收縮，不需要開闢額外的容器空間。

```cpp
#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid; // 中點剛好就是目標值
            }
            
            // 左半邊 [left ... mid] 是完全有序的
            if (nums[left] <= nums[mid]) {
                // 檢查 target 是否正好夾在左半邊的有序範圍之內
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1; // 縮限至左半邊
                } else {
                    left = mid + 1;  // 目標在右半邊
                }
            } 
            // 右半邊 [mid ... right] 是完全有序的
            else {
                // 檢查 target 是否正好夾在右半邊的有序範圍之內
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;  // 縮限至右半邊
                } else {
                    right = mid - 1; // 目標在左半邊
                }
            }
        }
        return -1;
    }
};
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 33 - Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)
