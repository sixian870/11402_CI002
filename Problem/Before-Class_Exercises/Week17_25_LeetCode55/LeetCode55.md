# LeetCode 55 - Jump Game


## 題目簡述

給定一個非負整數陣列 `nums`，你最初位於陣列的 **第一個索引（Index 0）**。<br>
陣列中的每個元素代表你在該位置可以**跳躍的最大長度**。<br>
請判斷是否能夠到達陣列的**最後一個索引**。如果可以，回傳 `true`；否則回傳 `false`。

**Sample Input & Output**：

* **Example 1 :**
  * **Input :** `nums = [2,3,1,1,4]`
  * **Output :** `true`
  * **解釋 :** 先從索引 0 跳 1 步到索引 1，然後從位置 1 可以直接跳最大 3 步一腳踩到最後一個索引。

* **Example 2 :**
  * **Input :** `nums = [3,2,1,0,4]`
  * **Output :** `false`
  * **解釋 :** 無論如何，你都會步向索引 3（數值為 0）。一旦到了位置 3，其最大跳躍長度是 0，你永遠無法跨越這個斷崖到達索引 4。


## 程式碼

1. **核心思考方向**：我們不需要去窮舉或遞迴嘗試每一種「跳 1 步、跳 2 步...」的組合，這樣會掉進 $O(2^N)$ 或 $O(N^2)$ 的時間地獄。我們只需要關注一件最重要的事：**「以目前走得到的地方為基礎，我最遠最遠可以衝到哪裡？」**

2. **動態極限維護法**：
   - 建立一個變數 `max_reach` 代表目前所能到達的最遠位置，初始化為 `0`。
   - 從頭（索引 0）開始往後巡邏。每走到一個位置 `i`，我們都要先進行一項嚴格的合法性檢查：**「我現在走到的這格 `i`，有沒有超過我們先前算出的最遠極限 `max_reach`？」**
   - 如果 `i > max_reach`，代表這個位置對我們而言是個**永遠到不了的斷崖空檔**，遊戲直接宣告失敗（回傳 `false`）。
   - 如果可以走到這一格，我們就借助這一格的跳躍能力，嘗試去刷新我們的全域最遠極限：
     $$\text{maxReach} = \max(\text{maxReach}, i + \text{nums}[i])$$

3. **提早通關機制**：在刷新極限後，如果發現 `max_reach` 已經大於或等於最後一個格子的索引（`nums.size() - 1`），代表勝利的道路已經鋪好，可以直接提早回傳 `true` 結束巡邏。

4. **時間與空間複雜度**：只需要單次的單層 `for` 迴圈掃描，時間複雜度為極佳的 $O(N)$，且除了維護一個極限變數外不需要開額外陣列，空間複雜度達到極致的 $O(1)$！

```cpp
#include <vector>
#include <algorithm>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int max_reach = 0;
        int target = nums.size() - 1;
        
        // 逐一巡邏每個陣列位置
        for (int i = 0; i <= target; i++) {
            if (i > max_reach) {
                return false; // 如果目前的索引已經超過了最遠可達極限，代表此路不通
            }
            max_reach = std::max(max_reach, i + nums[i]); // 利用當前格子的能力 (i + nums[i])，嘗試更新最遠極限
            if (max_reach >= target) {
                return true; // 若最遠極限已經可以覆蓋到終點，直接回傳成功
            }
        }
        return false;
    }
};
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 55 - Jump Game](https://leetcode.com/problems/jump-game/)
