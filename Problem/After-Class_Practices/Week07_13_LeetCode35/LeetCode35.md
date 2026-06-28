# LeetCode 35 - Search Insert Position


## 題目簡述

給定一個已排序的整數陣列 `nums` 和一個目標值 `target`。

* 如果在陣列中找到 `target`，請回傳其**索引位置**。
* 如果找不到，請回傳它若按順序**被插入陣列後合適的索引位置**。

> **限制**：時間複雜度為 **$O(\log N)$** 。

**Sample Input & Output**：

* **Example 1 :**
  * **Input :** `nums = [1,3,5,6]`, `target = 5`
  * **Output :** `2`

* **Example 2 :**
  * **Input :** `nums = [1,3,5,6]`, `target = 2`
  * **Output :** `1`
  * **解釋 :** 數字 2 找不到，但它應該被插入在 1 和 3 之間，也就是索引 1 的位置。

* **Example 3 :**
  * **Input :** `nums = [1,3,5,6]`, `target = 7`
  * **Output :** `4`
  * **解釋 :** 數字 7 找不到，但它比陣列裡所有數字都大，應該被插入在陣列最後面，也就是索引 4 的位置。


## 程式碼

1. **核心思考方向**：
   題目強烈暗示時間複雜度必須是 $O(\log N)$，這代表絕對不能用 `for` 迴圈從頭到尾線性掃描（那會是 $O(N)$）。唯一符合規格的武器就是 **二分搜尋法（Binary Search）**。

2. **區間收縮的邏輯設計（左閉右閉 `[left, right]`）**：
   - 宣告雙指針 `left = 0` 和 `right = nums.size() - 1`。
   - 每次取中點 `mid = left + (right - left) / 2` 進行比對（利用這個寫法可以防範 `left + right` 引起的整數溢位）。
   - 如果 `nums[mid] == target`，運氣很好，直接回傳 `mid`。
   - 如果 `nums[mid] < target`，代表目標值在右半邊，我們收縮左邊界：`left = mid + 1`。
   - 如果 `nums[mid] > target`，代表目標值在左半邊，我們收縮右邊界：`right = mid - 1`。

3. **神奇的「找不到」收尾機制**：
   - 如果 `while (left <= right)` 迴圈因為 `left > right` 而停下來了，說明陣列中真的沒有 `target`。
   - 此時有一個非常神奇的數學規律：**當二分搜尋找不到目標而結束時，`left` 指針所停留的位置，剛好就會是這個數字應該被插入的正確索引位置！**
   - 為什麼？因為當區間縮小到最後一個元素時，如果該元素小於 `target`，`left` 會移動到 `mid + 1`（剛好是該元素的下一格）；如果該元素大於 `target`，`left` 會留在 `mid`（剛好把該元素往後擠）。因此，最後直接回傳 `left` 即可。

4. **複雜度分析**：
   - **時間複雜度**： $O(\log N)$，每次將搜尋範圍砍半。
   - **空間複雜度**： $O(1)$，只用了 `left` , `right` , `mid` 三個變數，達到極致的常數空間。

```cpp
#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2; // 防禦整數溢位（Overflow）
            if (nums[mid] == target) {
                return mid; // 找到了，直接回傳索引
            } 
            else if (nums[mid] < target) {
                left = mid + 1; // 目標在右半邊，左邊界右移
            } 
            else {
                right = mid - 1; // 目標在左半邊，右邊界左移
            }
        }
        return left; // 當找不到目標值時，迴圈結束後的 left 指針位置就是合適的插入點
    }
};
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 35 - Search Insert Position](https://leetcode.com/problems/search-insert-position/)
