# LeetCode 232 - Implement Queue using Stacks


## 題目簡述

請僅使用兩個堆疊（Stack）實作一個先進先出（FIFO）的佇列（Queue）。所實作的佇列應支援一般佇列支援的所有函式（`push`、`pop`、`peek`、`empty`）：

實作 `MyQueue` 類別：
* `void push(int x)`：將元素 `x` 推入佇列的末尾。
* `int pop()`：移除並回傳佇列開頭的元素。
* `int peek()`：回傳佇列開頭的元素。
* `boolean empty()`：如果佇列為空，回傳 `true`；否則回傳 `false`。

**Sample Input & Output**：

* **Input :**
  ```text
  ["MyQueue", "push", "push", "peek", "pop", "empty"]
  [[], [1], [2], [], [], []]
  ```
* **Output :**
  ```text
  [null, null, null, 1, 1, false]
  ```
* **解釋 :**
  ```text
  MyQueue myQueue = new MyQueue();
  myQueue.push(1); // 佇列變為 [1]
  myQueue.push(2); // 佇列變為 [1, 2]
  myQueue.peek();  // 回傳 1
  myQueue.pop();   // 回傳 1，佇列變為 [2]
  myQueue.empty(); // 回傳 false
  ```


## 程式碼

1. **核心思考方向**：
   * Stack 是**後進先出（LIFO）**，而 Queue 是**先進先出（FIFO）**。如果我們把一組數字丟進 Stack，倒出來的時候順序會完全反過來。
   * 如果我們把這些反過來的數字**再丟進第二個 Stack 倒出來一次**，負負得正，順序就會變回原本的先進先出（FIFO）了！這就是為什麼我們需要兩個 Stack 的原因。

2. **輸入桶（stIn）與輸出桶（stOut）分工策略**：<br>
   我們準備兩個標準的 `std::stack`：`stIn`（負責應付新進的 `push`）和 `stOut`（負責處理 `pop` 和 `peek`）。
   * **`push(x)`**：無腦把新元素直接丟進 `stIn`，這一步的時間複雜度是極致的 $O(1)$。
   * **`pop()` / `peek()`**：
     * 當我們想拿最前面的元素時，如果 `stOut` 裡面有存貨，它的頂端（`top()`）剛好就是全場最先進入的元素，直接拿取即可。
     * 如果 `stOut` 是空的，我們就把目前 `stIn` 裡面的所有元素**一股腦全部「倒扣」進 `stOut` 中**。這樣一倒，`stIn` 的底部元素（最早進來的）就會跑到 `stOut` 的頂部。接下來再從 `stOut` 進行 `pop` 或 `peek` 即可。

3. **均攤時間複雜度（Amortized Time Complexity）**：<br>
   雖然在 `stOut` 為空、需要從 `stIn` 搬移數據的那一次操作中會消耗 $O(N)$ 的時間，但每個元素在生命週期中最多只會被「搬家一次」（從 `stIn` 到 `stOut`）。因此，平均下來每次操作的**均攤時間複雜度是極致的 $O(1)$**！

```cpp
#include <stack>

class MyQueue {
private:
    std::stack<int> stIn;  // 輸入堆疊：負責接收 push 進來的元素
    std::stack<int> stOut; // 輸出堆疊：負責處理 pop 和 peek
    // 當 stOut 為空時，將 stIn 的元素全數轉移至 stOut
    void moveInToOut() {
        if (stOut.empty()) {
            while (!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
    }

public:
    MyQueue() {}
    void push(int x) {
        stIn.push(x);
    }
    int pop() {
        moveInToOut(); // 確保 stOut 有目前的先頭存貨
        int res = stOut.top();
        stOut.pop();
        return res;
    }
    int peek() {
        moveInToOut(); // 確保 stOut 有目前的先頭存貨
        return stOut.top();
    }
    bool empty() {
        return stIn.empty() && stOut.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 232 - Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/)
