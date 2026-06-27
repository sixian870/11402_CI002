# LeetCode 56 - Merge Intervals


## 題目簡述

給定一個區間的陣列 `intervals`，其中 `intervals[i] = [start_i, end_i]`。<br>
請合併所有重疊的區間，並回傳一個**不重疊的區間陣列**，該陣列需恰好覆蓋輸入中的所有區間。

**Sample Input & Output**：

* **Example 1 :**
  * **Input :** `intervals = [[1,3],[2,6],[8,10],[15,18]]`
  * **Output :** `[[1,6],[8,10],[15,18]]`
  * **解釋 :** 區間 `[1,3]` 和 `[2,6]` 重疊，合併為 `[1,6]`。其餘區間皆各自獨立。

* **Example 2 :**
  * **Input :** `intervals = [[1,4],[4,5]]`
  * **Output :** `[[1,5]]`
  * **解釋 :** 區間 `[1,4]` 和 `[4,5]` 被視為在邊界 `4` 上重疊，合併為 `[1,5]`。
 
* **Example 3 :**
  * **Input :** `intervals = [[4,7],[1,4]]`
  * **Output :** `[[1,7]]`
  * **解釋 :** 區間 `[4,7]` 和 `[1,4]` 重疊，合併為 `[1,7]`。


## 程式碼

1. **直覺暴力的困境**：如果區間完全無序，任意兩個區間都可能發生重疊，我們必須進行兩兩比對，時間複雜度會劣退至 $O(N^2)$。

2. **排序破局法（將幾何關係線型化）**：
   - 依據每個區間的**起點（Start）由小到大**進行排序。
   - 排序的好處：一旦起點有序，**有可能發生重疊的區間在陣列中一定會變得相鄰**。我們只需要單次巡邏、依序檢查相鄰區間即可。

3. **單次巡邏的合併邏輯**：
   - 我們建立一個答案陣列 `ans`，並先將第一個區間丟進去當作當前的基準。
   - 從第二個區間開始往後遍歷，將新遇到的區間 `curr` 與 `ans` 中最後一個加入的區間 `last` 進行比對：
     - **情況一（發生重疊）**：如果 `curr` 的起點 $\le$ `last` 的終點（例如 `[1,4]` 和 `[2,6]`），代表兩者黏在一起了。此時我們不需要新增區間，只需要將 `last` 的終點更新為兩者終點的較大值（`last[1] = max(last[1], curr[1])`）。
     - **情況二（完全獨立）**：如果 `curr` 的起點 $>$ `last` 的終點（例如 `[1,3]` 和 `[4,6]`），代表這是一個嶄新的獨立區間。我們直接將 `curr` 全員推入 `ans` 尾端，並讓它成為下一輪的比對基準。

4. **時間與空間複雜度**：排序消耗 $O(N \log N)$，後續的線性掃描消耗 $O(N)$。整體時間複雜度為完美的 $O(N \log N)$，額外空間複雜度在排除回傳答案外僅需 $O(1)$ 或排序輔助的 $O(\log N)$。

```cpp
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        if (intervals.empty()) {
            return {}; // 若區間集為空，直接回傳空陣列
        }
        
        // 依據區間的「起點」由小到大（升序）排序
        std::sort(intervals.begin(), intervals.end());
        
        std::vector<std::vector<int>> ans;
        ans.push_back(intervals[0]); // 先將第一個區間作為基準塞入答案陣列中
        
        // 從第二個區間開始向右巡邏比對
        for (int i = 1; i < intervals.size(); i++) {
            std::vector<int>& last = ans.back(); // 取出目前答案陣列裡，最後一個被合併完成的基準區間
            std::vector<int>& curr = intervals[i]; // 取得當前準備拿來比對的新區間
            
            // 若新區間的起點 <= 基準區間的終點，代表重疊了
            if (curr[0] <= last[1]) {
                // 將基準區間的終點向外擴張（取兩者終點的最大值）
                last[1] = std::max(last[1], curr[1]);
            } else {
                // 若沒有重疊，代表這是一個完全獨立的新區間，直接推入答案陣列
                ans.push_back(curr);
            }
        }
        return ans;
    }
};
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 56 - Merge Intervals](https://leetcode.com/problems/merge-intervals/)
