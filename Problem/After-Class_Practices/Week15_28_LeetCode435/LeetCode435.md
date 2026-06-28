# LeetCode 435 - Non-overlapping Intervals


## 題目簡述

給定一個區間陣列 `intervals`，其中 `intervals[i] = [start_i, end_i]`。請計算並回傳：為了讓剩下的區間 **互不重疊**，你需要移除的 **最小區間數量**。

> **注意**：在邊界處「恰好接觸」的兩個區間**不被視為重疊**。例如 `[1, 2]` 和 `[2, 3]` 是不重疊的。

**Sample Input & Output**：

* **Example 1 :**
  * **Input :** `intervals = [[1,2],[2,3],[3,4],[1,3]]`
  * **Output :** `1`
  * **解釋 :** 移除 `[1,3]` 後，剩下的區間為 `[[1,2],[2,3],[3,4]]`，彼此皆不重疊。

* **Example 2 :**
  * **Input :** `intervals = [[1,2],[1,2],[1,2]]`
  * **Output :** `2`
  * **解釋 :** 你需要移除兩個 `[1,2]` 來使剩下的區間沒有重疊。

* **Example 3 :**
  * **Input :** `intervals = [[1,2],[2,3]]`
  * **Output :** `0`
  * **解釋 :** 區間彼此本來就沒有重疊，因此不需要移除任何區間。


## 程式碼

1. **核心逆向轉化思考**：<br>
   題目要求「移除的最少區間數」，這等同於要我們求出**「全場最多可以留下多少個不重疊的區間」**。<br>
   $$\text{移除的最小數量} = \text{總區間數} - \text{最多可留下的不重疊區間數}$$

2. **貪婪演算法的排序抉擇：為什麼要依「結束時間」排序？** <br>
   要讓後面能塞進更多區間，我們留下的區間必須滿足一個核心貪婪特質：**「誰越早結束（`end` 越小），留給後面發揮的剩餘空間就越大」**。
   - 如果依「開始時間（`start`）」排序，假設有個區間長度極長如 `[1, 100]`，選了它就會把後面所有空間鎖死，顯然不合理。
   - 因此，最經典的貪婪解法，就是將所有區間**按照「結束位置（`end`）」由小到大升序排列**。

3. **指針掃描與排除邏輯**：
   - 排序完成後，先預設挑選第一個區間，並記錄其結束位置為 `end_boundary`。
   - 從第二個區間開始由左至右掃描：

     - 如果當前區間的 `start >= end_boundary`，說明這個區間完美銜接上了，沒發生重疊！我們成功多留下了一個區間，並將 `end_boundary` 更新為這個新區間的結束位置。
     - 如果當前區間的 `start < end_boundary`，說明這個區間與先前的區間發生了嚴重的重疊。因為我們是按結束位置排序，當前這個重疊區間的 `end` 必然大於或等於 `end_boundary`。為了保留更好的發展空間（較小的 `end`），我們果斷捨棄當前區間，將移除計數器 $+1$。

4. **複雜度分析**：
   - **時間複雜度**： $O(N \log N)$，其中 $N$ 是區間的數量。主要的時間開銷來自於對區間陣列進行 `std::sort` 排序；後續的貪婪線性掃描只需要 $O(N)$。
   - **空間複雜度**： $O(1)$ 或 $O(\log N)$。如果不計算排序所需要的系統內部棧空間，我們僅維護了常數個指針與計數變數。

```cpp
#include <vector>
#include <algorithm>

class Solution {
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        // 依據「結束位置 (end)」由小到大進行升序排序
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1];
        });
        int remove_count = 0;              // 記錄被移除的重疊區間數
        int end_boundary = intervals[0][1]; // 記錄當前合法區間的結束邊界位置
        for (size_t i = 1; i < intervals.size(); i++) {
            // 如果當前區間的開頭小於當前的結束邊界，代表發生重疊，必須移除
            if (intervals[i][0] < end_boundary) {
                remove_count++;
            } 
            // 沒有重疊，完美銜接，將結束邊界往後推移更新
            else {
                end_boundary = intervals[i][1];
            }
        }
        return remove_count;
    }
};
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 435 - Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/)
