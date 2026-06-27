# LeetCode 231 - Power of Two


## 題目簡述

給定一個整數 $n$，請判斷它是否為 **2 的冪次方（Power of Two）**。如果是，回傳 `true`；否則回傳 `false`。<br>
若一個整數滿足 $n = 2^x$（其中 $x$ 為整數），則稱該整數為 2 的冪次方。

**Sample Input & Output**：

* **Example 1 :**
  * **Input :** `n = 1`
  * **Output :** `true` ($\rightarrow 2^0 = 1$)

* **Example 2 :**
  * **Input :** `n = 16`
  * **Output :** `true` ($\rightarrow 2^4 = 16$)
* **Example 3 :**
  * **Input :** `n = 3`
  * **Output :** `false`


## 程式碼

1. **小於等於 0 的特判**：2 的任何整數次方（包含負數次方，如 $2^{-1} = 0.5$）在整數型態（`int`）的範圍內都必須是正整數。因此，只要 $n \le 0$，絕對不可能是 2 的冪次方，必須提早防禦回傳 `false`。

2. **連續除以 2 法**：本程式採用非常直覺的模擬法。只要 $n$ 能夠被 2 整除（`n % 2 == 0`），就持續將 $n$ 除以 2（`n = n / 2`）。當迴圈結束時，如果 $n$ 降到 `1`，代表它是完美的 2 的冪次方；若剩餘其他奇數，則不是。

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 1){
            return false;
        }
        while(n % 2 == 0){
            n = n / 2;
        }
        return n == 1;
    }
};
```

## 參考資料

**題目連結 & 測試網站**：[LeetCode 231 - Power of Two](https://leetcode.com/problems/power-of-two/)
