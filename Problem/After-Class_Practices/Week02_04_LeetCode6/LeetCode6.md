# LeetCode 6 - Zigzag Conversion


## 題目簡述

將一個給定的字串 `s` 根據給定的列數 `numRows`，以從上往下、從左到右的 **Z 字形（Zigzag）** 模式進行排列。

比如輸入字串為 `"PAYPALISHIRING"`，列數 `numRows = 3` 時，排列成 Z 字形的幾何圖形如下：
```text
P   A   H   N
A P L S I I G
Y   I   R
```
之後，我們需要按行（Row by Row）由左至右重新讀取這些字元，將其串接成一個新的字串。以剛才的圖形為例，由上而下逐行讀取的結果為：`"PAHN"` + `"APLSIIG"` + `"YIR"` $\rightarrow$ 最終輸出為 `"PAHNAPLSIIGYIR"`。<br>
請寫一個函式完成這個轉換模擬。

**Sample Input & Output**

* **Example 1 :**
  * **Input :** `s = "PAYPALISHIRING"` , `numRows = 3`
  * **Output :** `"PAHNAPLSIIGYIR"`

* **Example 2:**
  * **Input :** `s = "PAYPALISHIRING"` , `numRows = 4`
  * **Output :** `"PINALSIGYAHRPI"`
  * **解釋 :**
    
    排列成 4 列的 Z 字形如下：
    
    ```text
    P     I    N
    A   L S  I G
    Y A   H R
    P     I
    ```
    逐行讀取為： `"PIN"` + `"ALSIG"` + `"YAHR"` + `"PI"` $\rightarrow$ `"PINALSIGYAHRPI"`。

* **Example 3 :**
  * **Input :** `s = "A"` , `numRows = 1`
  * **Output :** `"A"`


## 程式碼

1. **核心思考方向**：我們不需要真的去建立一個開銷極大的二維矩陣（因為我們根本不在乎中間有多少空白字元）。最聰明的作法是建立 numRows 個獨立的字串（或字元陣列），分別代表 Z 字形的每一列。

2. **雙向彈跳控制法**：
   * 想像有一個指針 `currRow` 從 `第 0 列` 出發，隨著我們遍歷 `字串 s`，它會把字元塞進對應的 `rows[currRow]` 裡。
   * 關鍵在於：`currRow` 要怎麼在「往下走」與「往右上折返」之間完美切換？
   * 我們可以利用一個布林旗標 `goingDown`（控制方向）。
   * 折返點特判：當指針觸及天花板（`currRow == 0`）時，下一步必須改為「往下」（`goingDown = true`）；當指針觸及地板（`currRow == numRows - 1`）時，下一步必須改為「往上」（`goingDown = false`）。
   * 每移動一個字元，就依據 `goingDown` 的狀態，決定 `currRow += 1` 或是 `currRow -= 1`。

3. **時間與空間複雜度**：單次巡邏字串即可完成歸類，時間複雜度為完美的 $O(N)$（$N$ 為字串長度）。空間複雜度除了用來存儲答案的空間外，僅需儲存每一列的字串片段，同樣為 $O(N)$。

```cpp
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s; // 如果只有 1 列，或者列數大於等於字串長度，Z 字形根本無法折返，原字串即為答案
        }
        std::vector<std::string> rows(std::min(numRows, (int)s.length()));
        int currRow = 0;
        bool goingDown = false; // true 表向下移動，false 表向右上折返
        for (char c : s) {
            rows[currRow] += c;
            if (currRow == 0 || currRow == numRows - 1) {
                goingDown = !goingDown; // 走到天花板(0)或地板(numRows-1)時，方向強行反轉
            }
            currRow += goingDown ? 1 : -1; // 依據方向更新下一列的座標
        }
        std::string ans = "";
        for (const std::string& row : rows) {
            ans += row; // 將每一列的成品字串依序拼接到第一列，組裝成最終答案
        }
        return ans;
    }
};
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 6 - Zigzag Conversion](https://leetcode.com/problems/zigzag-conversion/)
