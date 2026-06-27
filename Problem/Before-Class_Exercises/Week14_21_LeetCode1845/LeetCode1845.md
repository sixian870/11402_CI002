# LeetCode 1845 - Seat Reservation Manager


## 題目簡述

請設計一個管理 `n` 個座位預約系統。座位編號從 `1` 到 `n`。

請實作 `SeatManager` 類別：
* `SeatManager(int n)`：初始化物件，座位編號為從 `1` 到 `n` 都是可以被預約的。
* `int reserve()`：找到目前**編號最小的可用座位**，將其預約並回傳該座位編號。
* `void unreserve(int seatNumber)`：釋放指定編號的座位（將其變回可用狀態）。題目保證每次呼叫 `unreserve` 時，該座位原本一定是處於已被預約的狀態。

**Sample Input & Output**：

* **Example 1 :**
  * **Input :** <br>
    `["SeatManager", "reserve", "reserve", "unreserve", "reserve", "reserve", "reserve", "reserve", "unreserve"]` <br>
    `[[5], [], [], [2], [], [], [], [], [5]]`
  * **Output :** <br>
    `[null, 1, 2, null, 2, 3, 4, 5, null]`


## 程式碼

1. **核心思考方向**：系統的核心要求是實時且動態地取得「最小編號」的可用座位。如果我們用普通的 bool 陣列或 vector，每次預約時都從頭用迴圈去掃描尋找第一個可用的位子，單次操作的時間複雜度會退化到 $O(N)$，在大規模的連續呼叫下會直接導致 **TLE (Time Limit Exceeded)**。

2. **優先佇列庫元件的妙用**：在 C++ 中，`std::priority_queue` 預設是最大堆疊（Max-Heap）。但如果我們加上額外參數將其改寫為 `priority_queue<int, vector<int>, greater<int>>`，它就會變成一個 **最小堆疊 (Min-Heap)**。
   - 最小堆疊能保證頂端（`top()`）永遠是當前所有可用編號中「最小」的那個。
   - 提取最小編號（`reserve`）與塞回釋放編號（`unreserve`）的時間複雜度都只有極佳的 $O(\log N)$。

3. **極致的懶惰初始化（Lazy Initialization）**：
   - **傳統做法**：在建構子裡用 `for` 迴圈把 `1` 到 `n` 全部 `push` 進去堆疊，建構耗費 $O(N)$。
   - **優化做法**：我們可以直接宣告一個計數指針 `available_marker` 從 `1` 開始。當呼叫 `reserve` 時，如果堆疊內是空的（代表之前被釋放的舊座位都被坐滿了），我們就直接拿 `available_marker` 當作答案並將其累加 `+1`。
   - 只有當有人退位呼叫 `unreserve` 時，我們才把被釋放的座位號碼丟進最小堆疊。當下次預約時，若發現堆疊不為空，就優先從堆疊頂端取出被釋放的最小座位。這樣一來，建構子的時間複雜度能優化到奇蹟般的 $O(1)$！

```cpp
#include <queue>
#include <vector>

class SeatManager {
private:
    // 宣告 Min-Heap，用來儲存那些「被釋放出來」的空座位編號
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    // 指向目前「從未被預約過」的最小座位編號
    int available_marker;

public:
    SeatManager(int n) {
        available_marker = 1;
    }
    
    int reserve() {
        // 如果堆疊內有先前退位釋放的座位，優先從裡面拿最小的
        if (!min_heap.empty()) {
            int seat = min_heap.top();
            min_heap.pop();
            return seat;
        }
        // 若堆疊為空，代表前面沒有任何退位空檔，直接分配全新的下一個座位
        int seat = available_marker;
        available_marker++;
        return seat;
    }
    
    void unreserve(int seatNumber) {
        // 客人退位釋放座位，直接將號碼推入最小堆疊中，重新排隊等待被遞補
        min_heap.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 1845 - Seat Reservation Manager](https://leetcode.com/problems/seat-reservation-manager/)
