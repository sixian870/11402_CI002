# LeetCode 322 - Coin Change


## 題目簡述

給定一個整數陣列 `coins`，表示不同面額的硬幣；以及一個整數 `amount`，表示總金額。<br>
請計算可以湊成該總金額所需的 **最少硬幣個數**。如果沒有任何一種硬幣組合能湊出該總金額，回傳 `-1`。<br>
你可以假設每種面額的硬幣都有**無限個**。

**Sample Input & Output**：

* **Example 1 :**
  * **Input :** `coins = [1,2,5]`, `amount = 11`
  * **Output :** `3`
  * **解釋 :** $11 = 5 + 5 + 1$，共需要 3 枚硬幣。

* **Example 2 :**
  * **Input :** `coins = [2]`, `amount = 3`
  * **Output :** `-1`
  * **解釋 :** 只有 2 元硬幣，無論如何都無法湊出 3 元。

* **Example 3 :**
  * **Input :** `coins = [1]`, `amount = 0`
  * **Output :** `0`


## 程式碼

1. **核心思考方向**：要湊齊金額 `i`，我們可以嘗試拿任何一枚硬幣 `coin`。如果拿了這枚硬幣，剩下的金額就是 `i - coin`。因此，湊齊金額 `i` 的最少硬幣數，就會是湊齊金額 `i - coin` 的最少硬幣數再加 `1`（那一枚硬幣本身）。

2. **狀態轉移方程式**：<br>
   我們建立一個一維陣列 `dp`，其中 `dp[i]` 代表湊齊金額 `i` 所需的最少硬幣數量。對於每一個金額 `i`，遍歷所有硬幣面額 `coin`：
   $$\text{dp}[i] = \min(\text{dp}[i], \text{dp}[i - \text{coin}] + 1)$$

3. **初始化與防禦機制**：
   - 基地條件：`dp[0] = 0`，因為金額為 0 不需要任何硬幣。
   - 其他金額初始化為一個不可能達到的極大值 `amount + 1`（因為全部拿最小面額 1 元硬幣也最多只需要 `amount` 個）。這能方便我們用 `min` 進行取小值運算，同時在收尾時判定是否無解。

4. **時間與空間複雜度**：外層迴圈遍歷金額 $O(\text{amount})$，內層迴圈遍歷硬幣種類 $O(N)$。整體時間複雜度為 $O(\text{amount} \times N)$，空間複雜度為建立 DP 陣列的 $O(\text{amount})$。

```cpp
#include <vector>
#include <algorithm>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        std::vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                // 只有當前金額大於或等於硬幣面額時，這枚硬幣才有資格被挑選
                if (i - coin >= 0) {
                    // 取「不拿這枚硬幣」與「拿了這枚硬幣（剩餘金額步數 + 1）」的較小值
                    dp[i] = std::min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount]; // 若 dp[amount] 依然是初始的極大值，代表完全無法湊出該金額，回傳 -1
    }
};
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 322 - Coin Change](https://leetcode.com/problems/coin-change/)
