# LeetCode 622 - Design Circular Queue


## 題目簡述

請實作一個 **循環佇列（Circular Queue / 環狀緩衝區）**。<br>
循環佇列是一種線性資料結構，其操作依然基於先進先出（FIFO）原則，並且**陣列的最後一個位置會重新連接回第一個位置**，形成一個環。這樣做的好處是可以重複利用已被釋放的空間。

實作 `MyCircularQueue` 類別：
* `MyCircularQueue(k)`：構造器，設定佇列長度為 `k`。
* `int Front()`：從佇列前端獲取元素。如果佇列為空，回傳 `-1`。
* `int Rear()`：獲取佇列隊尾的元素。如果佇列為空，回傳 `-1`。
* `boolean enQueue(int value)`：向循環佇列插入一個元素。若成功插入則回傳 `true`。
* `boolean deQueue()`：從循環佇列刪除一個元素。若成功刪除則回傳 `true`。
* `boolean isEmpty()`：檢查循環佇列是否為空。
* `boolean isFull()`：檢查循環佇列是否已滿。

**Sample Input & Output**：

* **Input :**
  ```text
  ["MyCircularQueue", "enQueue", "enQueue", "enQueue", "enQueue", "Rear", "isFull", "deQueue", "enQueue", "Rear"]
  [[3], [1], [2], [3], [4], [], [], [], [4], []]
  ```
* **Output :**
  ```text
  [null, true, true, true, false, 3, true, true, true, 4]
  ```
* **解釋 :**
  ```text
  MyCircularQueue myCircularQueue = new MyCircularQueue(3);
  myCircularQueue.enQueue(1); // 回傳 true
  myCircularQueue.enQueue(2); // 回傳 true
  myCircularQueue.enQueue(3); // 回傳 true
  myCircularQueue.enQueue(4); // 回傳 false，因為陣列容量只有 3，目前已滿
  myCircularQueue.Rear();     // 回傳 3
  myCircularQueue.isFull();   // 回傳 true
  myCircularQueue.deQueue();  // 回傳 true，釋放前端空間，佇列剩下 [2, 3]
  myCircularQueue.enQueue(4); // 回傳 true，4 被成功填入剛釋放的環狀空間，佇列變為 [2, 3, 4]
  myCircularQueue.Rear();     // 回傳 4
  ```


## 程式碼

1. **核心思考方向**：
   * 如果使用一般的 `vector` 進行 `deQueue`（刪除前端元素），會迫使後面所有元素向左平移，導致時間複雜度劣退到 $O(N)$。
   * 循環佇列的核心，就是利用一個固定大小的陣列，並透過雙指針 `head` 和 `tail` 分別標記隊頭與隊尾。當指針走到陣列末尾時，利用 **模運算（`%`）** 讓它自動繞回索引 `0`。

2. **區分「空」與「滿」的策略**：<br>
    傳統上如果 `head == tail`，可能代表空也可能代表滿。為了避開這個模糊地帶，最直覺、安全且乾淨的作法是：**多宣告一個變數 `size` 來即時紀錄當前佇列中的元素總數**。
    * 當 `size == 0` 時，必定為空（`isEmpty`）。
    * 當 `size == capacity` 時，必定為滿（`isFull`）。

3. **環狀指標推移公式**：
   * **`enQueue`（推入新元素）**：先確認沒滿。新元素應該被放在 `tail` 指向的位置，接著將 `tail` 順時針往前推一格：<br>
     $$\text{tail} = (\text{tail} + 1) \% \text{capacity}$$
   * **`deQueue`（彈出舊元素）**：先確認沒空。不需要真的移除數據，直接將 `head` 順時針往前推一格即可：<br>
     $$\text{head} = (\text{head} + 1) \% \text{capacity}$$

4. **複雜度分析**：
   * **所有操作時間複雜度**： $O(1)$。無論是推入、彈出或查詢，全部都只透過索引與模運算定位，達到最完美的常數時間。
   * **空間複雜度**： $O(K)$。只開闢了大小固定為 `k` 的儲存空間，符合題目環狀緩衝區的原生限制。

```cpp
#include <vector>

class MyCircularQueue {
private:
    std::vector<int> queue;
    int head;     // 指向佇列前端元素的索引
    int tail;     // 指向未來新元素準備插入的尾端位置
    int size;     // 目前佇列中的元素個數
    int capacity; // 佇列的最大限制容量

public:
    MyCircularQueue(int k) {
        queue.resize(k);
        head = 0;
        tail = 0;
        size = 0;
        capacity = k;
    }
    bool enQueue(int value) {
        if (isFull()) return false;
        queue[tail] = value;
        tail = (tail + 1) % capacity; // 利用模運算防止指標越界，使其能繞回開頭
        size++;
        return true;
    }
    bool deQueue() {
        if (isEmpty()) return false;
        head = (head + 1) % capacity; // 將頭指標直接後移一格
        size--;
        return true;
    }
    int Front() {
        if (isEmpty()) return -1;
        return queue[head];
    }
    int Rear() {
        if (isEmpty()) return -1;
        // 由於 tail 指向的是「下一個準備插入的空位」，因此當前的最後一個元素位於 tail - 1 的位置，為防範 tail - 1 出現負數索引，需加上 capacity 再進行模運算
        return queue[(tail - 1 + capacity) % capacity];
    }
    bool isEmpty() {
        return size == 0;
    }
    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 622 - Design Circular Queue](https://leetcode.com/problems/design-circular-queue/)
