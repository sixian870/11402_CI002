# LeetCode 121 - Best Time to Buy and Sell Stock


## 題目簡述

給定一個陣列 `prices`，其中 `prices[i]` 表示某支股票在第 `i` 天的價格。<br>
你只能選擇在 **某一天買入** 這支股票，並在 **未來的某一個不同的日子賣出**。請設計一個演算法來計算你所能獲取的 **最大利潤**。<br>
如果你無法獲取任何利潤，請回傳 `0`。

**Sample Input & Output**：

* **Example 1 :**
  * **Input :** `prices = [7,1,5,3,6,4]`
  * **Output :** `5`
  * **解釋 :** 在第 2 天（價格 = 1）買入，在第 5 天（價格 = 6）賣出，最大利潤 = $6 - 1 = 5$。注意，你不能在第 2 天買入前就在第 1 天（價格 = 7）賣出，因為你必須先買進才能賣出。

* **Example 2 :**
  * **Input :** `prices = [7,6,4,3,1]`
  * **Output :** `0`
  * **解釋 :** 在這種情況下，股票價格天天都在下跌，沒有任何交易能獲利，因此最大利潤為 0。


## 程式碼

1. **直覺暴力的缺點**：<br>
   如果我們用兩層 `for` 迴圈窮舉所有可能的買入天與賣出天組合，時間複雜度會劣退至 $O(N^2)$，在長度極大的測試資料下會直接導致 TLE。

2. **線性時間掃描破局法**：<br>
   - 當我們一邊往右遍歷股票價格時，我們可以動態維護一個全域變數 `min_price`，用來記錄**「到目前為止，歷史上出現過的最低股票價格」**。
   - 同時，如果我們假設今天就是賣出日，那麼今天的現價減去這個歷史最低價，就是「如果今天賣出，所能拿到的最大利潤」。
   - 我們用另一個變數 `max_profit` 即時紀錄並更新這個利潤的最大值。

3. **狀態更新核心公式**：<br>

   對於每一天的價格 `price`：
   - 刷新歷史低點：
     $$\text{minPrice} = \min(\text{minPrice}, \text{price})$$
   - 刷新最高利潤：
     $$\text{maxProfit} = \max(\text{maxProfit}, \text{price} - \text{minPrice})$$

4. **時間與空間複雜度**：<br>
   只需要單次的單層 `for` 迴圈掃描，時間複雜度為極佳的 $O(N)$（$N$ 為天數），空間複雜度由於僅需儲存最低價與最高利潤兩個數值，達到最極致的 $O(1)$！

```cpp
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit = 0;
        for (int price : prices) {
            if (price < min_price) {
                min_price = price; // 如果今天的價格比歷史最低還要低，更新歷史最低點
            } 
            else if (price - min_price > max_profit) {
                max_profit = price - min_price; // 如果今天賣出的獲利比歷史最高獲利還要高，更新最高利潤
            }
        }
        return max_profit;
    }
};
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 121 - Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
