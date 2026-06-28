# LeetCode 125 - Valid Palindrome


## 題目簡述

給定一個字串 `s`，在**移除非字母與數字字元**，並將所有大寫字母**轉換為小寫字母**之後，如果該字串正著讀和倒著讀都一樣，則回傳 `true`；否則回傳 `false`。

> 空字串或移除所有非字母數字後的空字串，亦被視為有效的迴文串。

**Sample Input & Output**：

* **Example 1 :**
  * **Input :** `s = "A man, a plan, a canal: Panama"`
  * **Output :** `true`
  * **解釋 :** 移除非字母數字字元並轉小寫後為 `"amanaplanacanalpanama"`，這是一個迴文串。

* **Example 2 :**
  * **Input :** `s = "race a car"`
  * **Output :** `false`
  * **解釋 :** 清洗後的字串為 `"raceacar"`，倒過來讀是 `"racaecar"`，兩者不相等。

* **Example 3 :**
  * **Input :** `s = " "`
  * **Output :** `true`
  * **解釋 :** 清洗後為空字串 `""`，依據題目定義，空字串是有效的迴文串。


## 程式碼

1. **直覺作法（開輔助字串）的缺點**：<br>
   如果先巡邏一遍字串，把所有合法的字母和數字挑出來拼成一個新字串，最後再檢查它是否迴文，雖然符合邏輯，但這會消耗 $O(N)$ 的記憶體空間來存放新字串。

2. **雙指針原地包夾破局法**：
   - 我們可以完全不需要動用額外空間，改用兩個指針：`left` 指向字串開頭（`0`），`right` 指向字串末尾（`s.length() - 1`）。
   - 讓兩個指針同時向中間靠攏（包夾）：
     - **過濾雜質**：在每一步比對前，如果 `left` 指向的不是字母或數字（可以用 `isalnum()` 判斷），我們就大膽地將 `left` 往右推一步（`left++`）；同理，如果 `right` 指向的不是字母或數字，就把 `right` 往左推一步（`right--`）。
     - **忽略大小寫比對**：當兩側指針都鎖定了合法的字母或數字字元時，將它們通通轉為小寫（可以用 `tolower()`）並進行比對。
     - 如果不相等，代表一定不是迴文，直接回傳 `false`；如果相等，則兩側指標各自向內推一步，繼續下一輪比對。

3. **時間與空間複雜度**：雙指針各自單向移動，所有字元最多只被掃描一次，時間複雜度為完美的 $O(N)$。因為是直接在原字串上比對，完全沒有開闢新字串，額外空間複雜度達到極致的 $O(1)$！

```cpp
#include <string>
#include <cctype>

class Solution {
public:
    bool isPalindrome(std::string s) {
        int left = 0;
        int right = s.length() - 1;
        while (left < right) {
            // 若左指針遇到非字母或數字的雜質字元，直接跳過
            while (left < right && !std::isalnum(s[left])) {
                left++;
            }
            // 若右指針遇到非字母或數字的雜質字元，直接跳過
            while (left < right && !std::isalnum(s[right])) {
                right--; 
            }
            if (std::tolower(s[left]) != std::tolower(s[right])) {
                return false; // 將雙方字元皆轉為小寫，若不相等則立即宣告失敗
            }
            // 比對成功，雙指針同步向內推進
            left++;
            right--;
        }
        return true;
    }
};
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 125 - Valid Palindrome](https://leetcode.com/problems/valid-palindrome/)
