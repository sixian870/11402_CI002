# LeetCode 9 - Palindrome Number


## 題目簡述

給定一個整數 `x`，如果 `x` 是一個 **迴文整數**，回傳 `true`；否則，回傳 `false`。

> 當一個整數**正著讀**和**倒著讀**完全相同時，它才是一個迴文整數。例如，`121` 是迴文，而 `123` 不是。

**Sample Input & Output**：

* **Example 1 :**
  * **Input :** `x = 121`
  * **Output :** `true`

* **Example 2 :**
  * **Input :** `x = -121`
  * **Output :** `false` ($\rightarrow$ 從左向右為 -121，從右向左為 121-，不相等。)

* **Example 3 :**
  * **Input :** `x = 10`
  * **Output :** `false` ($\rightarrow$ 從右向左讀為 01，不不相等。)


## 程式碼

1. **直覺轉字串的缺點**：雖然將數字轉成字串（`to_string`）再用雙指針兩頭比對非常直覺，但這會帶來額外的字串記憶體配置開銷。面試官通常會限制：**「不准將整數轉為字串，請直接用純數學解法挑戰」**。

2. **純數學反轉法**：
   - **負數必非迴文**：所有的負數（例如 `-121`）倒過來讀會變成 `121-`，結尾多了一個負號，因此負數一律直接剔除（回傳 `false`）。
   - **非零且結尾為 0 的數必非迴文**：除了 `0` 本身以外，任何以 `0` 結尾的數字（例如 `10`、`120`）倒過來開頭都會變成 `0`，這在正整數的正常書寫中是不可能的，同樣直接剔除。

3. **反轉整數公式**：<br>
   我們可以用一個 `while` 迴圈，透過「取餘數 `x % 10`」剝離出最後一位數，並透過「除以 10 (`x /= 10`)」向左移位。將剝離出的數字動態累加進反轉變數中：
   $$\text{reversedNum} = \text{reversedNum} \times 10 + (\text{x} \% 10)$$

4. **只反轉一半（防禦溢位 Overflow）**：<br>
   如果把整個極大的數字全部反轉，可能會超過 `int` 的上限而導致 runtime error。最聰明的策略是**只反轉數字的後半段**！
   當 `originalX > reversedNum` 不再成立時，代表我們已經處理了剛好一半（或過半）的位數。
   - 若數字長度為偶數（如 `1221`）：當迴圈停止時，兩邊完全相等 `originalX == reversedNum` (`12 == 12`)。
   - 若數字長度為奇數（如 `12321`）：當迴圈停止時，中間的數字會留在反轉變數的個位數（`originalX = 12`, `reversedNum = 123`）。此時只要把反轉變數除以 10 剔除中位數再進行比對即可（`originalX == reversedNum / 10`）。

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        // 負數絕對不可能是迴文，除了 0 以外，任何個位數為 0 的數字絕對不可能是迴文
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        
        int revertedNumber = 0;
        // 只反轉後半段的數字。當前段小於或等於後段時，代表已經切分過半
        while (x > revertedNumber) {
            // 將原本累積的數字乘以 10 往前推，並補上當前剥離出來的個位數
            revertedNumber = revertedNumber * 10 + x % 10;
            // 前段數字除以 10，向右移位
            x /= 10;
        }
        
        // 最終比對：
        // 情況一（偶數長度）：若為迴文，前段 x 必然等於後段 revertedNumber (例如 12 == 12)
        // 情況二（奇數長度）：若為迴文，中央數字會落到 revertedNumber 的個位，除以 10 拔掉它即可 (例如 12 == 123 / 10)
        return x == revertedNumber || x == revertedNumber / 10;
    }
};
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 9 - Palindrome Number](https://leetcode.com/problems/palindrome-number/)
