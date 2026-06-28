# LeetCode 763 - Partition Labels


## 題目簡述

給定一個由小寫英文字母組成的字串 `s`。我們希望將這個字串劃分為儘可能多的片段，並滿足：**同一字母最多只能出現在其中一個片段中**。<br>
請回傳一個整數陣列，表示**每個劃分片段的長度**。

**Sample Input & Output**：

* **Example 1 :**
  * **Input :** `s = "ababcbacadefegdehijhklij"`
  * **Output :** `[9,7,8]`
  * **解釋 :**
    
    劃分結果為 `"ababcbaca"`、`"defegde"`、`"hijhklij"`。
    - 第一個片段 `"ababcbaca"` 長度為 9，包含了所有出現在該片段的字母（a, b, c）。
    - 第二個片段 `"defegde"` 長度為 7，包含了該片段的所有字母（d, e, f, g）。
    - 第三個片段 `"hijhklij"` 長度為 8，包含了該片段的所有字母（h, i, j, k, l）。
    每個字母都只乖乖待在自己的片段中，這是不違反規則下所能切出的最多區段。

* **Example 2 :**
  * **Input :** `s = "eccbbbbdec"`
  * **Output :** `[10]`
  * **解釋 :**
    
    因為字母 'e' 同時出現在索引 0 與 8，字母 'c' 出現在索引 1 與 9。<br>
    為了讓同一個字母不跨區，我們無法切出任何更小的獨立子區間，只能被迫整條輸出，因此長度為 10。


## 程式碼

1. **核心限制的數學化身**：<br>
   既然「同一字母最多只能出現在一個片段中」，這代表當我們決定在某個片段收容了字母 `a` 時，**這個片段的右邊界，就必須至少延伸到字串中最後一個 `a` 出現的位置**。

2. **雙指針雙階段（Two-Pass）貪婪策略**：
   - **第一階段（預處理）**：我們用一個大小固定為 26 的陣列（或雜湊表）`last_position`，先掃描一遍字串，記下**每個小寫字母在字串中最後一次現身的「終點索引」**。
   - **第二階段（線性切割）**：重新從頭由左至右遍歷字串，並維護兩個游標：`start`（當前片段的起點）和 `end`（當前片段被迫要延伸到的最遠右邊界）。

3. **邊界動態拓展與完美切割點**：
   - 每踩到一個新字元，我們就去查它的最後現身位置，並用它來更新目前區間的極限防線：<br>
     $$\text{end} = \max(\text{end}, \text{lastPosition}[s[i] - \text{'a'}])$$
   - 當我們一路往前走，發現指針居然**剛好走到了當前的極限防線（即 `i == end`）**，這代表什麼？這代表「目前被這個區間收容的所有字母，在後面都絕對不會再出現了」！
   - 此時就是完美的切割時機！我們立刻結算這個片段的長度：`i - start + 1`，將其塞入結果陣列，接著將下一個片段的起點更新為 `start = i + 1`，繼續往後摸索。

4. **複雜度分析**：
   - **時間複雜度**： $O(N)$，其中 $N$ 是字串 `s` 的長度。第一遍建立最後位置花費 $O(N)$，第二遍貪婪切割同樣花費 $O(N)$，兩次線性巡邏即可秒殺。
   - **空間複雜度**： $O(1)$。`last_position` 的空間固定為 26（小寫字母總數），屬於常數級別的極致記憶體控制。

```cpp
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::vector<int> partitionLabels(std::string s) {
        int last_position[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            last_position[s[i] - 'a'] = i;
        }
        
        std::vector<int> result;
        int start = 0; // 當前區間片段的起點索引
        int end = 0;   // 當前區間片段必須涵蓋的最遠邊界索引
        
        for (int i = 0; i < s.length(); i++) {
            // 每遇到一個字母，就必須把邊界強制向右延伸到該字母最後一次現身的位置
            end = std::max(end, last_position[s[i] - 'a']);
            // 當前指針走到了被迫延伸的最遠極限，說明此區間內所有字母在後方已絕跡
            if (i == end) {
                result.push_back(i - start + 1); // 結算當前區間長度
                start = i + 1;                   // 開闢下一個新區間的起點
            }
        }
        return result;
    }
};
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 763 - Partition Labels](https://leetcode.com/problems/partition-labels/)
