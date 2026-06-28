# LeetCode 641 - Design Circular Deque


## 題目簡述

請實作一個 **循環雙端佇列（Circular Deque / 環狀雙端緩衝區）**。<br>
雙端佇列（Deque, Double-ended queue）是一種可在佇列兩端（隊頭或隊尾）同時進行插入和刪除操作的線性資料結構。而「循環」則代表陣列的頭尾相連，能最大化重複利用已被釋放的空間。

實作 `MyCircularDeque` 類別：
* `MyCircularDeque(k)`：構造器，設定雙端佇列的最大容量為 `k`。
* `boolean insertFront(value)`：將一個元素添加到雙端佇列頭部。若成功則回傳 `true`。
* `boolean insertLast(value)`：將一個元素添加到雙端佇列尾部。若成功則回傳 `true`。
* `boolean deleteFront()`：從雙端佇列頭部刪除一個元素。若成功則回傳 `true`。
* `boolean deleteLast()`：從雙端佇列尾部刪除一個元素。若成功則回傳 `true`。
* `int getFront()`：從雙端佇列頭部獲取元素。如果佇列為空，回傳 `-1`。
* `int getRear()`：從雙端佇列尾部獲取元素。如果佇列為空，回傳 `-1`。
* `boolean isEmpty()`：檢查雙端佇列是否為空。
* `boolean isFull()`：檢查雙端佇列是否已滿。

**Sample Input & Output**：

* **Input :**
  ```text
  ["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
  [[3], [1], [2], [3], [4], [], [], [], [4], []]
  ```
* **Output :**
  ```text
  [null, true, true, true, false, 2, true, true, true, 4]
  ```
* **解釋 :**
  ```text
  MyCircularDeque myCircularDeque = new MyCircularDeque(3);
  myCircularDeque.insertLast(1);  // 回傳 true，佇列變為 [1]
  myCircularDeque.insertLast(2);  // 回傳 true，佇列變為 [1, 2]
  myCircularDeque.insertFront(3); // 回傳 true，3 塞到頭部，佇列變為 [3, 1, 2]
  myCircularDeque.insertFront(4); // 回傳 false，因為容量已滿
  myCircularDeque.getRear();      // 回傳 2
  myCircularDeque.isFull();       // 回傳 true
  myCircularDeque.deleteLast();   // 回傳 true，移除尾端的 2，佇列剩下 [3, 1]
  myCircularDeque.insertFront(4); // 回傳 true，4 成功塞入頭部，佇列變為 [4, 3, 1]
  myCircularDeque.getFront();     // 回傳 4
  ```


## 程式碼

1. **核心思考方向**：
   * 由於需要在頭尾兩端都進行新增與刪除，我們依然使用固定大小的 `vector`，並維護 `head`（指向隊頭元素）和 `tail`（指向隊尾元素）兩個指標。
   * 與單向循環佇列不同的是，雙端佇列的指標移動可能是**逆時針（指標減 1）**或**順時針（指標加 1）**。為了防止出現負數索引，逆時針推移時必須先加上 `capacity` 再進行模運算。
   * 為了安全防禦「空」與「滿」的重疊邊界，我們同樣引進一個全域的 `size` 變數來精準追蹤元素總數。

2. **雙端指標操作公式設計**：
   定義 `head` 剛好停在目前頭部元素的位置；`tail` 剛好停在目前尾部元素的位置。
   * **`insertFront`（頭部插入）**：
     * 指標需要逆時針前移： $$\text{head} = (\text{head} - 1 + \text{capacity}) \% \text{capacity}$$
     * 移動後，再把新值填入 `queue[head]`。
   * **`insertLast`（尾部插入）**：
     * 指標需要順時針後移： $$\text{tail} = (\text{tail} + 1) \% \text{capacity}$$
     * 移動後，再把新值填入 `queue[tail]`。
   * **`deleteFront`（頭部刪除）**：
     * 不需要清除數值，直接將頭指標順時針後移即可： $$\text{head} = (\text{head} + 1) \% \text{capacity}$$
   * **`deleteLast`（尾部刪除）**：
     * 直接將尾指標逆時針前移即可： $$\text{tail} = (\text{tail} - 1 + \text{capacity}) \% \text{capacity}$$

3. **初始化小技巧**：<br>
   為了讓第一個插入的元素在 `insertFront` 或 `insertLast` 時都能完美對齊，我們可以在初始化時將 `head` 設為 `0`，而 `tail` 設為 `capacity - 1`（或 `head` 為 `0`，`tail` 為 `0`，但插入公式需對應微調）。以下程式碼採用 `head = 0`, `tail = 0` 且先動指針後填值（或先填值後動指針）的互補邏輯，非常直覺好懂。

4. **複雜度分析**：
   * **所有操作時間複雜度**： $O(1)$。無論是哪一端的新增、刪除或查詢，均可在常數時間內秒殺。
   * **空間複雜度**： $O(K)$。固定陣列大小，無任何動態記憶體配置的額外開銷。

```cpp
#include <vector>

class MyCircularDeque {
private:
    std::vector<int> queue;
    int head;     // 指向目前隊頭元素的位置
    int tail;     // 指向目前隊尾元素的位置
    int size;     // 目前雙端佇列中的有效元素總數
    int capacity; // 佇列最大限制容量

public:
    MyCircularDeque(int k) {
        queue.resize(k);
        head = 0;
        tail = 0;
        size = 0;
        capacity = k;
    }
    bool insertFront(int value) {
        if (isFull()) return false;
        if (size > 0) {
            head = (head - 1 + capacity) % capacity; // 逆時針向前推移頭指標，防範負數需 + capacity
        }
        queue[head] = value;
        size++;
        return true;
    }
    bool insertLast(int value) {
        if (isFull()) return false;
        if (size > 0) {
            tail = (tail + 1) % capacity; // 順時針向後推移尾指標
        }
        queue[tail] = value;
        size++;
        return true;
    }
    bool deleteFront() {
        if (isEmpty()) return false;
        if (size > 1) {
            head = (head + 1) % capacity; // 順時針向後推移頭指標
        }
        size--;
        return true;
    }
    bool deleteLast() {
        if (isEmpty()) return false;
        if (size > 1) {
            tail = (tail - 1 + capacity) % capacity; // 逆時針向前推移尾指標
        }
        size--;
        return true;
    }
    int getFront() {
        if (isEmpty()) return -1;
        return queue[head];
    }
    int getRear() {
        if (isEmpty()) return -1;
        return queue[tail];
    }
    bool isEmpty() {
        return size == 0;
    }
    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
```

## 參考資料

**題目連結 & 測試網站**：[LeetCode 641 - Design Circular Deque](https://leetcode.com/problems/design-circular-deque/)
