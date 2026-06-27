# LeetCode 1109 - Corporate Flight Bookings


## 題目簡述

這裡有 `n` 個航班，標號從 `1` 到 `n`。<br>
給定一個航班預訂表紀錄 `bookings`，其中 `bookings[i] = [first_i, last_i, seats_i]` 代表第 `i` 筆預訂記錄為：從航班 `first_i` 到航班 `last_i`（**包含這兩個航班**）的每個航班，都預訂了 `seats_i` 個座位。<br>
請回傳一個長度為 `n` 的陣列 `answer`，其中 `answer[i]` 代表第 `i + 1` 個航班被預訂的總座位數。

**Sample Input & Output**：

* **Example 1 :**
  * **Input :** `bookings = [[1,2,10],[2,3,20],[2,5,25]]`, `n = 5`
  * **Output :** `[10,55,45,25,25]`

  * **解釋 :**
    * 航班 1: 10 = 10
    * 航班 2: 10 + 20 + 25 = 55
    * 航班 3: 20 + 25 = 45
    * 航班 4: 25 = 25
    * 航班 5: 25 = 25

* **Example 2 :**
  * **Input :** `bookings = [[1,2,10],[2,2,15]]`, `n = 2`

  * **Output :** `[10,25]`


## 程式碼

1. **直覺暴力法的缺點**：如果對每一筆 booking，都用一個迴圈從 `first` 跑到 `last` 一個個加上 `seats`，若預訂紀錄很多且區間很長，時間複雜度會劣化到 $O(\text{bookings.size()} \times n)$，在 LeetCode 上會直接拿到 **TLE (Time Limit Exceeded)**。

2. **什麼是差分陣列？**：差分陣列的精髓在於 **「只記錄變動量」**。如果我們要對區間 `[left, right]` 全部的元素都加上 `val`，我們不需要真的去改動區間內的每一個數，只需要做兩件事：

   - 在起點補上變動量：`diff[left] += val;`（代表從這裡開始，後面的累積和都會增加 `val`）
   - 在終點的「下一格」扣掉變動量：`diff[right + 1] -= val;`（代表過了這一格後，增加的 `val` 影響力就結束了）

3. **前綴和還原答案**：當我們把所有的預訂單都用上面的 $O(1)$ 操作標記在差分陣列中後，最後只需要從頭到尾做一次**前綴和（Prefix Sum）**的累加還原，就能一口氣得到所有航班的最終座位數。

4. **時間與空間複雜度**：時間複雜度大幅優化至完美的 $O(n + \text{bookings.size()})$，空間複雜度除回傳陣列外僅需 $O(1)$ 的輔助。


```cpp
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n, 0);
        for (const auto& booking : bookings) {
            int first = booking[0];
            int last = booking[1];
            int seats = booking[2];
            
            // 轉為 0-based 索引：區間起點為 first - 1
            ans[first - 1] += seats;
            
            // 區間終點的下一格為 (last - 1) + 1 = last，若下一格超出陣列邊界 n 則不需要記錄
            if (last < n) {
                ans[last] -= seats;
            }
        }
        
        // 利用前綴和（累加）還原出每個位置的真實數值
        for (int i = 1; i < n; i++) {
            ans[i] += ans[i - 1];
        }
        return ans;
    }
};
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 1109 - Corporate Flight Bookings](https://leetcode.com/problems/corporate-flight-bookings/)
