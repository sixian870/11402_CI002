# UVa 673 - Parentheses Balance

## 題目簡述

給定一個只包含圓括號 `()` 與方括號 `[]` 的字串，請判斷該字串中的括號是否完全合法配對。<br>
一個合法的括號字串必須滿足以下條件：
1. 空字串是合法的。
2. 如果字串 $X$ 與 $Y$ 皆為合法，則字串 $XY$ 也是合法的。
3. 如果字串 $X$ 是合法的，則 $(X)$ 與 $[X]$ 也是合法的。

**Sample Input**：

  **3** $\rightarrow$ 測資組數 $T$。<br>
  **([])** $\rightarrow$ 第一組字串（合法）。<br>
  **(([)])** $\rightarrow$ 第二組字串（不合法，交叉錯位）。<br>
  **)** $\rightarrow$ 第三組字串（不合法）。

**Sample Output**：

  **Yes**<br>
  **No**<br>
  **No**


## 解題思路與後進先出模型

### 核心觀念：堆疊（Stack）的後進先出（LIFO）特性
這道題目是標準的**資料結構應用題（括號配對檢查）**。
括號配對具有「最晚出現的左括號，必須最早與右括號配對」的幾何天性。這與堆疊（Stack）「後進先出（Last In, First Out）」的運作模型完美契合。

1. **左括號入堆疊**：由左至右遍歷字串，每當遇到左括號（`(` 或 `[`）時，直接將其推入（`push`）堆疊中，記錄當前的配對期許。
2. **右括號即時配對**：當遇到右括號（`)` 或 `]`）時，代表必須立刻與最近的一個左括號進行閉合。此時必須進行安全防禦檢查：
   * 檢查堆疊是否為空。若此時堆疊已空（`s1.empty()`），代表有右括號溢出，沒有左括號能與其配對，字串不合法。
   * 檢查堆疊頂端元素（`s1.top()`）。如果當前是 `)`，而堆疊頂端不是 `(`（例如是 `[`），代表括號發生了交叉錯位（如 `([)]`），字串不合法。
   * 若檢查完全合格，則將堆疊頂端的左括號彈出（`pop`），代表配對成功。
3. **最終清空檢查**：當字串全數遍歷完畢後，如果堆疊內仍留有殘餘的左括號（`!s1.empty()`），代表有左括號未被閉合（如 `(()`），字串同樣不合法。


## 複雜度分析

* **Time Complexity（時間複雜度）**： $\mathcal{O}(N)$
  其中 $N$ 為字串的總長度。我們只需從左到右掃描字串一次。在掃描過程中，對堆疊執行的 `push`、`pop` 與 `top` 操作都可以在 $\mathcal{O}(1)$ 常數時間內完成。因此總時間複雜度與字串長度呈線性正比。
* **Space Complexity（空間複雜度）**： $\mathcal{O}(N)$
  在最差情況下（例如字串全由左括號組成 `((((((`），堆疊需要消耗與字串等長的空間來存放字元，因此空間複雜度為線性時間 $\mathcal{O}(N)$。


## 邊界條件與潛在陷阱

1. **`cin` 與 `getline` 緩衝區地雷**：
   原程式碼在讀入測試組數 `t` 後，非常精準地補上了一行 `cin.ignore();`。這行代碼至關重要，因為 `cin >> t` 只會吃掉數字，把換行符 `\n` 留在緩衝區。如果不清除，後續的第一個 `getline` 會誤讀這個 `\n` 而抓到一個不該存在的空字串。
2. **完全空字串或空行的合法性**：
   根據題目規範，空字串是合法的（應輸出 `Yes`）。在 UVa 的實際測資中，可能會包含完全沒有任何字元的空行。使用 `getline(cin, s)` 能安全地將空行讀入為長度為 0 的字串，此時迴圈不執行，最後因為 `s1.empty() && isValid == true` 成立，正確輸出 `Yes`。
3. **右括號領頭或溢出**：
   如果字串開頭第一個字元就是右括號（例如 `)`），此時堆疊內沒有任何元素。在調用 `s1.top()` 之前，**必須強迫先進行 `s1.empty()` 的安全檢查**。如果直接對空堆疊執行 `.top()` 操作，會引發嚴重的記憶體區段錯誤（Segmentation Fault / Runtime Error）。


## 程式碼實作

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // 提升標準 I/O 串流之效能
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    if (cin >> t) {
        cin.ignore(); // 核心防禦：清除讀取整數後殘留在緩衝區的換行符，避免 getline 漏讀
        
        while (t--) {
            string s;
            stack<char> s1; // 宣告標準庫 LIFO 堆疊
            bool isValid = true;
            
            getline(cin, s); // 逐行讀取，可完美相容空行與含空格文本
            
            for (char c : s) {
                // 狀況一：遇到左括號，直接推入堆疊紀錄
                if (c == '(' || c == '[') {
                    s1.push(c);
                }
                // 狀況二：遇到右圓括號
                else if (c == ')') {
                    // 安全防禦：若堆疊已空（右括號溢出）或頂端無法配對（交叉錯位），則宣告失效
                    if (s1.empty() || s1.top() != '(') {
                        isValid = false;
                        break; // 提早中斷，節省時間
                    }
                    s1.pop(); // 配對成功，彈出頂端左括號
                }
                // 狀況三：遇到右方括號
                else if (c == ']') {
                    // 安全防禦：同上，進行方括號的合法性比對
                    if (s1.empty() || s1.top() != '[') {
                        isValid = false;
                        break;
                    }
                    s1.pop();
                }
            }
            
            // 最終判定：必須字串合法，且堆疊內不留任何未閉合的左括號
            if (s1.empty() && isValid == true) {
                cout << "Yes\n";
            }
            else {
                cout << "No\n";
            }
        }
    }
    return 0;
}
```


## 進階優化思考

雖然使用 C++ 內建的 std::stack 在邏輯上最清晰，但因為 std::stack 底層預設是基於 std::deque 實作，在頻繁動態配置記憶體時會有微幅的常數開銷。

**輕量化陣列模擬堆疊（Array-based Stack 優化）**

既然我們已知單行字串的最大長度，我們完全不需要使用高階容器。可以直接利用原程式碼註解中提到的 vector<char>，甚至是直接開闢一個靜態字元陣列搭配一個整數指標 top_ptr 來手動模擬堆疊。

**優化程式碼片段：**
```cpp
string s;
getline(cin, s);

int n = s.length();
vector<char> my_stack(n);
int top_ptr = -1; // 頂端指標，-1 代表堆疊為空
bool isValid = true;

for (char c : s) {
    if (c == '(' || c == '[') {
        my_stack[++top_ptr] = c; // 入堆疊
    } else if (c == ')') {
        if (top_ptr == -1 || my_stack[top_ptr] != '(') {
            isValid = false; break;
        }
        top_ptr--; // 出堆疊
    } else if (c == ']') {
        if (top_ptr == -1 || my_stack[top_ptr] != '[') {
            isValid = false; break;
        }
        top_ptr--;
    }
}
if (top_ptr == -1 && isValid) cout << "Yes\n";
else cout << "No\n";
```
* **優化改善**：這個重構版本完全免去了高階物件封裝與動態記憶體分配（Dynamic Allocation）的額外開銷。整條數組空間在迴圈開始前就一次對齊配置好，指標的 ++ 與 -- 在底層直接對應 CPU 的暫存器操作，這在面對極為巨大的測資或極端嚴格的時限要求時，是最極致的常數級效能調優。


## 參考資料

**題目連結**：[UVa673](./UVa673.pdf)

**測試網站**：[Parentheses Balance](https://vjudge.net/problem/UVA-673)
