# LeetCode 8 - String to Integer (atoi)


## 題目簡述

請實作一個 `myAtoi(string s)` 函式，將一個字串轉換成一個 32 位元的有號整數（類似 C/C++ 中的 `atoi` 函式）。

該演算法的轉換規則如下：
1. **空白字元**：忽略開頭的任何前導空白字元（`' '`）。
2. **正負號**：檢查下一個字元是否為正號 (`'+'`) 或負號 (`'-'`)，若有，讀取它以決定最終答案的正負（若無，預設為正數）。
3. **數字轉換**：讀取接下來的字元，直到遇到**非數字**字元或字串結尾為止。將這些讀取到的數字字元轉換成整數（例如 `"123"` $\rightarrow 123$）。後續的非數字字元一律忽略。
4. **邊界溢位（Overflow Handling）**：如果轉換後的數值超出了 32 位元有號整數的範圍 $[ -2^{31}, 2^{31} - 1 ]$，則必須將其截斷（Clamp）到邊界：
   - 小於 $-2^{31}$ 的數值一律截斷為 $-2^{31}$（即 `INT_MIN`）。
   - 大於 $2^{31} - 1$ 的數值一律截斷為 $2^{31} - 1$（即 `INT_MAX`）。

**Sample Input & Output**：

* **Example 1 :**
  * **Input :** `s = "42"`
  * **Output :** `42`

* **Example 2 :**
  * **Input :** `s = " -042"`
  * **Output :** `-42` ($\rightarrow$ 忽略前導空白與字元前的 0)

* **Example 3 :**
  * **Input :** `s = "1337c0d3"`
  * **Output :** `1337` ($\rightarrow$ 讀到非數字字元 'c' 時，後續一律中斷並忽略)

* **Example 4 :**
  * **Input :** `s = "0-1"`
  * **Output :** `0` ($\rightarrow$ 讀取了「0」；因下一個字元是非數字而停止讀取)

* **Example 5 :**
  * **Input :** `s = "words and 987"`
  * **Output :** `0` ($\rightarrow$ 開頭忽略空白後第一個就是英文字母，無法轉換成數字)

## 程式碼

1. **核心思考方向**：本題最大的陷阱在於「不能直接用一個 `long long` 或大數去存答案最後再來判斷是否溢位」，因為題目可能在環境上限制你**只能使用 32 位元整數空間**。我們必須在**「數值快要爆掉的前一步」**就提早進行防禦攔截。

2. **數學防溢位公式**：
   在我們把新的一位數字 `pop_digit` 塞入當前結果 `res` 之前（即執行 `res = res * 10 + pop_digit` 之前），我們需要拿 `res` 與 `INT_MAX / 10` 進行預先審查：
   - 如果 `res > INT_MAX / 10`：代表只要再乘以 10 就絕對會超出範圍，不用再乘了，直接依據正負號判定並回傳 `INT_MAX` 或 `INT_MIN`。
   - 如果 `res == INT_MAX / 10`：這時要看準備塞進來的個位數 `pop_digit` 是否大於 `7`（因為 `INT_MAX` 的個位數是 `7`，即 `2147483647`）。如果大於 7，同樣宣告溢位，提早進行截斷回傳。

3. **時間與空間複雜度**：單次單向線性掃描字串，時間複雜度為完美的 $O(N)$（$N$ 為字串長度），空間複雜度為極致的 $O(1)$！

```cpp
#include <string>
#include <climits>

class Solution {
public:
    int myAtoi(std::string s) {
        int i = 0;
        int n = s.length();
        int sign = 1; // 1 代表正數，-1 代表負數
        int res = 0;
        while (i < n && s[i] == ' ') { // 消除前導空白
            i++;
        }
        if (i < n && (s[i] == '+' || s[i] == '-')) { // 辨識正負號
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        while (i < n && isdigit(s[i])) { // 逐字讀取數字並進行轉換
            int pop = s[i] - '0';
            
            // 在數字結合前，提前預判是否會發生 32 位元整數溢位 (Overflow)
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && pop > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN; // 根據正負號決定回傳極大值或極小值
            }
            res = res * 10 + pop;
            i++;
        }
        return res * sign;
    }
};
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 8 - String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/)
