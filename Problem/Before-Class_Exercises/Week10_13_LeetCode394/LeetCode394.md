# LeetCode 394 - Decode String


## 題目簡述

給定一個經過編碼的字串 `s`，請回傳它解碼後的字串。<br>
編碼規則為：`k[encoded_string]`，表示其中方括號內部的 `encoded_string` 正好需要重複 `k` 次。注意 `k` 保證是一個正整數。<br>
你可以假設輸入字串總是有效的（例如：沒有錯誤的方括號、方括號內的結構完全對稱）。此外，原始字串中不會包含任何數字，數字只會用來表示重複次數 `k`。

**Sample Input & Output**：

* **Example 1 :**
  * **Input :** `s = "3[a]2[bc]"`
  * **Output :** `"aaabcbc"`

* **Example 2 :**
  * **Input :** `s = "3[a2[c]]"`
  * **Output :** `"accaccacc"`

* **Example 3 :**:
  * **Input :** `s = "2[abc]3[cd]ef"`
  * **Output :** `"abcabccdcdcdef"`


## 程式碼

1. **核心思考方向**：字串的展開順序具有「層層嵌套」的幾何特性（例如 `3[a2[c]]` 必須先展開內層的 `cc` 變成 `3[acc]`，再展開成 `acccacccaccc`）。這種越內層越早被處理、越外層需要越晚被還原的特性，跟 **堆疊（Stack）** 的後進先出特性完美契合。

2. **雙堆疊分工合作法**：<br>
   為了在單次巡邏中處理好複雜的結構，我們準備兩個堆疊：一個用來存次數 `stack<int> countStack`，另一個用來存目前還沒閉合的半成品字串 `stack<string> resStack`。同時維護當前的數字 `currNum` 與當前字串 `currStr`。

3. **四種字元的分流處理**：
    - **遇到數字**：可能有多位數（如 `100`），利用 `currNum = currNum * 10 + (c - '0')` 持續累加。
    - **遇到左括號 `[`**：代表一場新的嵌套開始了。我們把手上現有的 `currNum` 和半成品 `currStr` 分別推入（`push`）各自的堆疊保存，隨後將牠們清空，騰出雙手來處理這個括號內部的世界。
    - **遇到右括號 `]`**：代表當前的括號宣告結束，到了展開與結合的時刻。我們把 `countStack` 頂端的次數拿出來，將當前的 `currStr` 重複拼接那麼多次。接著取出 `resStack` 頂端先前存檔的外層字串，將剛剛展開完的結果完美接在牠後面，合成新的 `currStr`。
    - **遇到普通字母**：直接加到 `currStr` 尾端。

```cpp
class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;      // 專門儲存重複次數 k 的堆疊
        stack<string> resStack;    // 專門儲存外層半成品字串的堆疊
        
        string currStr = "";        // 當前正在累積的解碼字串
        int currNum = 0;            // 當前正在累積的重複次數
        
        for (char c : s) {
            // 遇到數字，持續換算多位數數值
            if (isdigit(c)) {
                currNum = currNum * 10 + (c - '0');
            } 
            // 遇到左括號，將目前的狀態封存進堆疊
            else if (c == '[') {
                countStack.push(currNum);
                resStack.push(currStr);
                
                // 清空狀態，用來搜集括號內的新世界
                currNum = 0;
                currStr = "";
            } 
            // 遇到右括號，開始解封並展開字串
            else if (c == ']') {
                int repeatTimes = countStack.top();
                countStack.pop();
                
                string lastStr = resStack.top();
                resStack.pop();
                
                // 依據次數重複拼接當前的子字串
                string temp = "";
                for (int i = 0; i < repeatTimes; i++) {
                    temp += currStr;
                }
                currStr = lastStr + temp; // 與外層之前的字串重新串接，組裝成更新後的目前字串
            } 
            // 遇到一般英文字母，直接累積
            else {
                currStr += c;
            }
        }
        return currStr;
    }
};
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 394 - Decode String](https://leetcode.com/problems/decode-string/)
