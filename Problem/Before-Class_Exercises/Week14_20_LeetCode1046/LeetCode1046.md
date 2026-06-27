# LeetCode 1046 - Last Stone Weight


## 題目簡述

有一堆石頭，每塊石頭都有一個正整數重量。每一回合，我們從中選出**兩塊最重的石頭**，然後將牠們一起粉碎。
假設兩塊石頭的重量分別為 `x` 和 `y`，且滿足 `x <= y`。粉碎的可能結果如下：
* 如果 `x == y`，兩塊石頭都會完全粉碎。
* 如果 `x != y`，重量為 `x` 的石頭會完全粉碎，而重量為 `y` 的石頭新重量會變成 `y - x`。

重複這個過程，直到**最多只剩下一塊**石頭。請回傳這塊石頭的最小可能重量。如果最後沒有石頭剩下，則回傳 `0`。

**Sample Input & Output**：

* **Example 1 :**
  * **Input :** `stones = [2,7,4,1,8,1]`
  * **Output :** `1`
  * **解釋 :**
    * 先選出 7 和 8 撞擊 $\rightarrow$ 剩下 1，石頭變成 `[2,4,1,1,1]`
    * 再選出 2 和 4 撞擊 $\rightarrow$ 剩下 2，石頭變成 `[2,1,1,1]`
    * 再選出 2 和 1 撞擊 $\rightarrow$ 剩下 1，石頭變成 `[1,1,1]`
    * 再選出 1 和 1 撞擊 $\rightarrow$ 兩者皆粉碎，石頭變成 `[1]`
    * 最後只剩下一塊石頭，重量為 1。

* **Example 2 :**
  * **Input :** `stones = [1]`
  * **Output :** `1`


## 程式碼

1. **核心思考方向**：每一回合，我們都必須精準且動態地抓出全場「第一重」和「第二重」的石頭。如果每次都重新對陣列進行重新排序（`sort`），會耗費大量不必要的時間。

2. **優先佇列庫元件的妙用**：在 C++ 中，`std::priority_queue<int>` 預設就是一個 **最大堆疊 (Max-Heap)**。
   - 牠能保證堆疊頂端（`top()`）永遠是目前整座容器裡數值最大的那個元素。
   - 插入（`push`）與彈出（`pop`）新石頭的時間複雜度都只有極佳的 $O(\log N)$。

3. **模擬撞擊流程**：
   - 我們把所有石頭通通丟進 `priority_queue` 中。
   - 只要 queue 裡面的石頭數量大於 1，就連續彈出兩次，分別取得最重的 `y`（第一次彈出）與次重的 `x`（第二次彈出）。
   - 若 `y > x`，則將差值 `y - x` 重新推回（`push`）queue 中繼續等待下一輪大亂鬥。
   - 最終，如果 queue 空了就回傳 `0`；若還剩下一顆孤獨的贏家石頭，回傳它的重量即可。

4. **時間與空間複雜度**：建堆疊耗費 $O(N)$，後續最多進行 $N-1$ 次碰撞，每次碰撞調整耗費 $O(\log N)$。整體時間複雜度為完美的 $O(N \log N)$，額外空間複雜度為儲存樹狀節點的 $O(N)$。

```cpp
#include <queue>
#include <vector>

class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
        // 宣告最大堆疊，並在建構時直接將數組轉換為 Heap (波特曼建堆優化 $O(N)$)
        std::priority_queue<int> pq(stones.begin(), stones.end());
        
        // 只要場上還有至少兩塊石頭，就繼續進行
        while (pq.size() > 1) {
            int y = pq.top(); // 抓出第一重石頭
            pq.pop();
            
            int x = pq.top(); // 抓出第二重石頭
            pq.pop();
            
            // 若兩者重量不相等，將剩餘重量推回堆疊
            if (y > x) {
                pq.push(y - x);
            }
        }
        return pq.empty() ? 0 : pq.top(); // 若堆疊已空回傳 0，否則回傳最後殘留的贏家石頭重量
    }
};
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 1046 - Last Stone Weight](https://leetcode.com/problems/last-stone-weight/)
