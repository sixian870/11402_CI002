# LeetCode 179 - Largest Number


## 題目簡述

給定一個非負整數陣列 `nums`，請將這些數字重新排列，組合成一個**最大的整數**。

由於最後組合出來的整數數值可能會非常大（超出 `int` 或 `long long` 的容納範圍），因此請以**字串（string）**的形式回傳這個最大數。

**Sample Input & Output**：

* **Example 1 :**
  * **Input :** `nums = [10,2]`
  * **Output :** `"210"`

* **Example 2 :**
  * **Input :** `nums = [3,30,34,5,9]`
  * **Output :** `"9534330"`


## 程式碼

1. **直覺貪心法的盲點**：如果只按照數字大小或傳統的字典序排序，往往會出錯。例如 `3` 和 `30`，若按一般降序排成 `303`，但其實組成 `330` 會更大。

2. **神奇的字串拼接比對法**：對於任意兩個數字（轉成字串後為 `a` 和 `b`），要決定誰排在前面，最精準的策略就是直接串起來比比看：
    - 如果 `a + b > b + a`，代表 `a` 放在前面可以組出更大的數（例如 `"3" + "30" = "330"` 大於 `"30" + "3" = "303"`），所以 `a` 應該排在 `b` 前面。

3. **全零邊界特判**：當陣列裡面全部都是 `0` 時（例如 `[0, 0]`），如果不做處理，程式最後會拼接出 `"00"`。但數學上最大數只能是 `"0"`，因此排序完後如果發現最大的那個數（即第 0 個元素）是 `'0'`，直接提早結束並回傳 `"0"` 即可。
```cpp
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (int num : nums) {
            strs.push_back(to_string(num));
        }
        
        // 若 a + b > b + a，則 a 應該排在 b 前面
        sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });
        
        // 若排序後最大的數字是 "0"，代表整個陣列都是 0，直接回傳 "0"
        if (strs[0] == "0") {
            return "0";
        }
        
        // 將排序後的字串依序拼接起來
        string ans = "";
        for (const string& s : strs) {
            ans += s;
        }
        return ans;
    }
};
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 179 - Largest Number](https://leetcode.com/problems/largest-number/)
