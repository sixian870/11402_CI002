# LeetCode 347 - Top K Frequent Elements


## 題目簡述

給定一個整數陣列 `nums` 和一個整數 `k`，請回傳其中出現頻率前 `k` 高的元素。<br>
可以按 **任何順序** 回傳答案。<br>

> **限制**：演算法時間複雜度必須優於 **$O(N \log N)$**，其中 $N$ 是陣列的大小。

**Sample Input & Output**：

* **Example 1 :**
  * **Input :** `nums = [1,1,1,2,2,3]`, `target = 2`
  * **Output :** `[1,2]`

* **Example 2 :**
  * **Input :** `nums = [1]`, `target = 1`
  * **Output :** `[1]`
 
* **Example 3 :**
  * **Input :** `nums = [1,2,1,2,1,2,3,1,3,2]`, `target = 2`
  * **Output :** `[1,2]`


## 程式碼

1. **第一步：建立頻率地圖（Frequency Map）**：<br>
   無論採用何種優化演算法，我們都必須先巡邏一遍 `nums` 陣列，統計出每個數字各自出現了幾次。這可以用一個雜湊表 `std::unordered_map<int, int>`（元素 $\rightarrow$ 出現次數）在 $O(N)$ 時間內搞定。

2. **核心計數逆向思維**：
   - 如果把雜湊表的所有統計資料丟進 `vector` 裡對「頻率」做大到小排序，時間複雜度會是 $O(N \log N)$，這無法滿足題目更嚴格的期望。
   - 既然我們只關心「前 `k` 個最高頻」的數字，這代表比這 `k` 個數字還要低頻的數據，我們通通不想理。
   - 我們可以建立一個 **最小堆疊（Min-Heap）**，強行規定它的容量**最多只能裝 `k` 個元素**。
   - 在 C++ 的 `priority_queue` 中，我們將比較對象設為「頻率（次數）」，讓低頻的元素自動浮到最頂端（`top()`）。

3. **動態過濾與裁剪機制**：
   - 遍歷整個雜湊表，把（頻率, 數值）依序推入（`push`）最小堆疊中。
   - 一旦堆疊的 size 超過了 `k`，就把頂端「目前最低頻」的那個淘汰隊員彈出（`pop`）。
   - 這樣一路掃描完雜湊表後，堆疊裡留存下來的，保證就是全場最頂尖、**出現頻率最高的前 `k` 名精銳隊員**！

4. **複雜度分析**：
   - **時間複雜度**： $O(N \log K)$。建立雜湊表花費 $O(N)$；接著將最多 $N$ 個不重複的元素依序塞入大小固定為 $K$ 的堆疊中，每次調整成本為 $O(\log K)$。因為 $K \le N$，整體時間明顯優於 $O(N \log N)$。
   - **空間複雜度**： $O(N)$。主要為雜湊表儲存不重複元素的開銷。

```cpp
#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        // 統計每個數字出現的頻率 (O(N) 時間)
        std::unordered_map<int, int> frequency_map;
        for (int num : nums) {
            frequency_map[num]++;
        }
        
        // 利用最小堆疊動態篩選出前 K 高頻的元素
        // 堆疊元素型態為 pair<int, int> -> <出現頻率, 數字數值>
        // std::greater 確保這是一個最小堆疊，會把目前頻率最低的元素頂在最上方
        std::priority_queue<std::pair<int, int>, 
                            std::vector<std::pair<int, int>>, 
                            std::greater<std::pair<int, int>>> min_heap;
        
        for (auto& it : frequency_map) {
            min_heap.push({it.second, it.first}); // it.second 是頻率，it.first 是該數字本身
            if (min_heap.size() > k) {
                min_heap.pop(); // 若堆疊超過 k 個元素，就把當前頻率最低的（頂端）淘汰掉
            }
        }
        
        // 將堆疊中留下來的前 K 頂尖精銳輸出成答案陣列
        std::vector<int> result;
        while (!min_heap.empty()) {
            result.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return result;
    }
};
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 347 - Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/)
