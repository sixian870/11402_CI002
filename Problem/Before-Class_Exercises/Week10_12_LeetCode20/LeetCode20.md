# LeetCode 20 - Valid Parentheses


## 題目簡述

給定一個只包含字元 `'('`，`')'`，`'{'`，`'}'`，`'['` 和 `']'` 的字串 `s`，請判斷該輸入字串是否有效。

一個輸入字串在滿足以下所有條件時才有效：
1. 左括號必須用**相同類型**的右括號閉合。
2. 左括號必須以**正確的順序**閉合。
3. 每個右括號都有一個對應的相同類型的左括號。

**Sample Input & Output**：

* **Example 1 :**
  * **Input :** `s = "()"`
  * **Output :** `true`

* **Example 2 :**
  * **Input :** `s = "()[]{}"`
  * **Output :** `true`

* **Example 3 :**
  * **Input :** `s = "(]"`
  * **Output :** `false` ($\rightarrow$ 圓括號無法與方括號配對)

* **Example 4 :**
  * **Input :** `s = "([])"`
  * **Output :** `true` ($\rightarrow$ 層層嵌套的正確順序)


## 程式碼

1. **核心思考方向**：括號的匹配具有「越晚出現的左括號，必須越早被閉合」的特性。這種**後進先出（LIFO）**的幾何結構，跟資料結構中的 **堆疊（Stack）** 完美契合。

2. **標準演算法流程**：

   - 我們準備一個空堆疊，從左到右掃描字串中的每個字元。
   - **遇到左括號**：代表它是等待被閉合的半邊，我們直接把它推入（`push`）堆疊中。
   - **遇到右括號**：代表我們要找最近期的左括號來配對。此時，我們先檢查堆疊是否為空（若為空代表右括號多出來了，直接淘汰），若不為空，則查看堆疊頂端（`top`）的左括號類型是否能與目前的右括號湊成一對。若匹配成功，就將堆疊頂端彈出（`pop`）；若類型不符，則字串無效。

3. **收尾防禦陷阱**：當整個字串全部掃描完畢後，不能直接一口氣回傳 `true`。我們必須檢查堆疊是否已經「完全被清空」（`st.empty()`）。如果堆疊裡面還殘留有左括號（例如輸入 `s = "([]"`），代表有孤兒左括號沒被閉合，同樣是無效字串。

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            // 遇到左括號推入堆疊中等待配對
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } 
            // 遇到右括號進行對稱性檢查
            else {
                // 若此時堆疊已空，代表右括號多出來了，直接失敗
                if (st.empty()) {
                    return false;
                }
                
                char top_element = st.top();
                // 檢查堆疊頂端的左括號，是否與目前的右括號類型相符
                if ((c == ')' && top_element == '(') ||
                    (c == ']' && top_element == '[') ||
                    (c == '}' && top_element == '{')) {
                    st.pop(); // 匹配成功，將已閉合的左括號彈出
                } else {
                    return false; // 類型不符合（例如方括號配圓括號），直接失敗
                }
            }
        }
        
        // 掃描完字串後，堆疊必須是空的才算完全有效，若裡面還留有左括號（例如 s = "(()"），則不合法
        return st.empty();
    }
};
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 20 - Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)

**相似題目**：[UVa 673 - Parentheses Balance](./Problem/On-Site_Examinations/Week10_28_UVa673/UVa673.md)
