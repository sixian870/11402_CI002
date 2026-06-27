# LeetCode 228 - Summary Ranges


## 題目簡述

給定一個 **已排序且無重複元素** 的整數陣列 `nums`。

請將陣列中的數字依據**連續性**切分成數個區間，並依據以下格式將每個區間轉化為字串，最後放入陣列中回傳：
* 如果區間內只有單個數字 `a`，格式為 `"a"`。
* 如果區間包含連續多個數字，從 `a` 到 `b`（包含兩端點），格式為 `"a->b"`。

**Sample Input & Output**：

* **Example 1 :**
  * **Input :** `nums = [0,1,2,4,5,7]`
  * **Output :** `["0->2","4->5","7"]`
  * **解釋 :** 
    * 區間 [0,2] 連續 $\rightarrow$ `"0->2"`
    * 區間 [4,5] 連續 $\rightarrow$ `"4->5"`
    * 數字 7 孤立 $\rightarrow$ `"7"`

* **Example 2 :**
  * **Input :** `nums = [0,2,3,4,6,8,9]`
  * **Output :** `["0","2->4","6","8->9"]`


## 程式碼

1. **核心思考方向**：既然陣列已經是排序好的，要找出連續的數字，只需要檢查相鄰兩個數的差是否為 `1`（即 `nums[i] + 1 == nums[i + 1]`）。

2. **雙指針雙層迭代法**：
   - 我們可以使用一個外層 `while` 迴圈來控制當前區間的起點 `left`。
   - 隨後設定一個內層指針 `right` 從 `left` 出發向右探索。只要滿足 `right + 1 < n` 且 `nums[right] + 1 == nums[right + 1]`，就代表數字依然連續，我們可以大膽地將 `right` 往前推。
   - 當內層迴圈因為數字斷掉而停下來時，`[left, right]` 就是一個完整的最大連續區間。

3. **格式化輸出與下一輪準備**：
   - 比對 `left` 與 `right`。若 `left == right`，代表這個區間只有一個孤兒數字，直接轉字串丟進答案；若 `left != right`，代表有連續，組裝成 `"left->right"` 的格式。
   - 最後，將外層的起點直接更新為 `left = right + 1`，跳過剛才處理完的區間，繼續尋找下一個新世界。

4. **時間與空間複雜度**：雖然程式碼看起來是雙層迴圈，但因為 `left` 和 `right` 指針都是**一路向右、不曾回頭**，每個元素最多都只被掃描過兩次，因此時間複雜度為完美的 $O(N)$，額外空間複雜度為極致的 $O(1)$！

```cpp
#include <string>

class Solution {
public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums) {
        std::vector<std::string> ans;
        int n = nums.size();
        int left = 0;
        while (left < n) {
            int right = left;
            // 向右探索，只要相鄰兩數連續（相差 1），就持續擴張右邊界
            // nums[right] + 1 有可能超越 int 最大範圍，故轉換成 long long 比較最安全
            while (right + 1 < n && (long long)nums[right] + 1 == nums[right + 1]) {
                right++;
            }
            
            // 區間探索結束，依據長度進行格式化組裝
            if (left == right) { // 區間內只有單個數字
                ans.push_back(std::to_string(nums[left]));
            } else { // 區間內包含連續多個數字
                ans.push_back(std::to_string(nums[left]) + "->" + std::to_string(nums[right]));
            }
            // 下一個區間的起點，直接跳到當前區間終點的下一格
            left = right + 1;
        }
        return ans;
    }
};
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 228 - Summary Ranges](https://leetcode.com/problems/summary-ranges/)
