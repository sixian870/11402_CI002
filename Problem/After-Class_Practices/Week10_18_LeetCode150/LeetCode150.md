# LeetCode 150 - Evaluate Reverse Polish Notation


## 題目簡述

根據 **逆波蘭表示法（Reverse Polish Notation, RPN / 後序表示法）**，求該算術表達式的有效值。<br>
有效的運算符號包括 `"+"`、`"-"`、`"*"` 和 `"/"`。每個運算元（Operand）可以是一個整數，也可以是另一個逆波蘭表達式。

> **核心規範與注意事項**：
> 1. 兩個整數之間的除法只保留整數部分（即向零截斷 / Truncate toward zero）。
> 2. 給定的逆波蘭表達式總是有效的。這意味著表達式總能求得一個有效值，且不會出現除以零（Division by zero）的異常狀況。
> 3. 所有中間運算與最終結果皆能保證在 32 位元有號整數（`int`）的範圍之內。

**Sample Input & Output**：

* **Example 1 :**
  * **Input :** `tokens = ["2","1","+","3","*"]`
  * **Output :** `9`
  * **解釋 :** 該表達式轉化為常見的中序表示法為：`((2 + 1) * 3) = 9`。

* **Example 2 :**
  * **Input :** `tokens = ["4","13","5","/","+"]`
  * **Output :** `6`
  * **解釋 :** 該表達式轉化為常見的中序表示法為：`(4 + (13 / 5)) = 6`。

* **Example 3 :**
  * **Input :** `tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]`
  * **Output :** `22`
  * **解釋 :**<br>
    該表達式的計算軌跡為：
    
    ```text
      ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
    = ((10 * (6 / (12 * -11))) + 17) + 5
    = ((10 * (6 / -132)) + 17) + 5
    = ((10 * 0) + 17) + 5
    = (0 + 17) + 5
    = 17 + 5
    = 22
    ```


## 程式碼

1. **逆波蘭表示法（後序表示法）的物理特性**：<br>
   在一般的數學式子（中序表示法，如 `2 + 3`）中，運算子是夾在兩個數字中間的，這需要考慮括號和「先乘除後加減」的優先級分配。<br>
   而後序表示法則將運算子移到了數字的後面（如 `2 3 +`），它的特性是：**「運算子永遠會緊跟在它要處理的兩個運算元後面」**。

2. **利用 Stack 進行模擬**：
   - 建立一個儲存整數的 `std::stack<int>`。
   - 由左至右依序巡邏字串陣列 `tokens` 中的每一個元素：
     - 如果讀到的是 **數字**：直接將它轉換為整數（利用 `stoi`）並推入 `stack` 中。
     - 如果讀到的是 **運算子**（`+`, `-`, `*`, `/`）：代表此時 `stack` 頂端的最上層兩位數就是它要處理的目標。
   
3. **順序顛倒的大陷阱（減法與除法）**：<br>
   當我們從 `stack` 連續彈出（`pop`）兩個數字時，因為 Stack 後進先出的特性，**第一個彈出的數字（`num1`）其實是數學式子中的「右操作數（被減數/被除數）」**，而**第二個彈出的數字（`num2`）才是「左操作數」**。
   - 例如處理減法：正確算式應為 `num2 - num1`。
   - 例如處理除法：正確算式應為 `num2 / num1`。
   - 計算完畢後，再將得出的新結果重新推入（`push`）`stack` 中，作為下一輪運算的基底。

4. **複雜度分析**：
   - **時間複雜度**： $O(N)$。每個字串標記（Token）僅會被掃描一次，且 Stack 的 `push` 與 `pop` 操作均為 $O(1)$。
   - **空間複雜度**： $O(N)$。最壞情況下（所有數字都在前半段）需要一個容量最大為 $N/2$ 的堆疊空間。

```cpp
#include <vector>
#include <string>
#include <stack>
#include <stdexcept>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> st;
        for (const std::string& token : tokens) {
            // 若遇到運算子，從堆疊彈出兩個元素進行運算
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                // 第一個彈出的是右操作數，第二個彈出的是左操作數
                int num1 = st.top(); st.pop();
                int num2 = st.top(); st.pop();
                if (token == "+") st.push(num2 + num1);
                else if (token == "-") st.push(num2 - num1);
                else if (token == "*") st.push(num2 * num1);
                else if (token == "/") st.push(num2 / num1);
            } 
            else {
                st.push(std::stoi(token)); // 若遇到純數字，直接轉成整數並推入堆疊中
            }
        }
        return st.top(); // 最終堆疊中殘留的唯一一個數字，即為該逆波蘭表達式的最終答案
    }
};
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 150 - Evaluate Reverse Polish Notation](https://leetcode.com/problems/evaluate-reverse-polish-notation/)
