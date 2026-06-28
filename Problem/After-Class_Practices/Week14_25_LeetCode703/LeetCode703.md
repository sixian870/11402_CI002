# LeetCode 703 - Kth Largest Element in a Stream


## 題目簡述

設計一個類別 `KthLargest`，用來尋找資料流（Stream）中第 `k` 大的元素。注意，我們要找的是排序後的第 `k` 大元素，而不是第 `k` 個不同的元素。

實作 `KthLargest` 類別：
* `KthLargest(int k, int[] nums)`：用整數 `k` 和整數資料流 `nums` 初始化物件。
* `int add(int val)`：將一個新整數 `val` 插入到資料流中，並回傳當前資料流中**第 `k` 大**的元素。

**Sample Input & Output**：

* **Input :**
  ```text
  ["KthLargest", "add", "add", "add", "add", "add"]
  [[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
  ```
* **Output :**
  ```text
  [null, 4, 5, 5, 8, 8]
  ```
* **解釋 :**
  ```text
  KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
  kthLargest.add(3);   // 資料流變為 [2, 3, 4, 5, 8]，回傳第 3 大的元素 4
  kthLargest.add(5);   // 資料流變為 [2, 3, 4, 5, 5, 8]，回傳第 3 大的元素 5
  kthLargest.add(10);  // 資料流變為 [2, 3, 4, 5, 5, 8, 10]，回傳第 3 大的元素 5
  kthLargest.add(9);   // 資料流變為 [2, 3, 4, 5, 5, 8, 9, 10]，回傳第 3 大的元素 8
  kthLargest.add(4);   // 資料流變為 [2, 3, 4, 4, 5, 5, 8, 9, 10]，回傳第 3 大的元素 8
  ```


## 程式碼

1. **直覺暴力的時間地獄**：<br>
   如果每次呼叫 `add` 時都把數字塞進 `vector` 裡重新排序（`sort`），單次操作的時間複雜度會達到 $O(N \log N)$。在持續輸入的資料流（Stream）場景中，這會引發嚴重的效能崩潰。

2. **核心逆向思維：用「最小堆疊」找「第 K 大」**：
   * 既然我們只關心「第 `k` 大」是誰，這代表**比第 `k` 大還要小的那些數字，通通都不重要**。
   * 我們可以建立一個 **最小堆疊（Min-Heap）**，並強行規定這個堆疊的容量**最多只能裝 `k` 個元素**。
   * 最小堆疊的特性是：**最小的數字永遠在最頂端（`top()`）**。
   * 當堆疊裝滿 `k` 個最優隊員時，**頂端那個最小的數字，剛好就會是這 `k` 個最大數字裡「墊底」的那一個**——也就是我們苦苦尋找的「第 `k` 大元素」！

3. **動態維護策略**：
   * **初始化**：巡邏 `nums`，把元素通通丟進最小堆疊。只要堆疊大小超過 `k`，就把頂端的最小值彈出（`pop`），最後堆疊裡只會留存全場最大的 `k` 個數字。
   * **`add(val)`**：把新數字 `val` 推入堆疊。如果此時堆疊大小超過 `k`，同樣踢掉最頂端的最小值。最後直接回傳 `top()`，收工！

4. **複雜度分析**：
   * **初始化時間複雜度**： $O(N \log K)$，其中 $N$ 是初始陣列的長度。
   * **單次插入時間複雜度**： $O(\log K)$。堆疊內部調整指標的時間與堆疊大小相關，由於大小被固定在 $K$，因此速度極快。
   * **空間複雜度**： $O(K)$。我們只需要一個大小不超過 $K$ 的最小堆疊空間。

```cpp
#include <vector>
#include <queue>

class KthLargest {
private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    int k_size;

public:
    KthLargest(int k, std::vector<int>& nums) {
        k_size = k;
        for (int num : nums) {
            add(num); // 複用 add 邏輯，自動進行容量裁剪
        }
    }
    int add(int val) {
        min_heap.push(val);
        if (min_heap.size() > k_size) {
            min_heap.pop(); // 若堆疊內元素超過 k 個，將當前最小的（頂端）淘汰掉
        }
        return min_heap.top(); // 最小堆疊的頂端就是目前全場前 k 大裡面最小的，即為第 k 大元素
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 703 - Kth Largest Element in a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream/)
