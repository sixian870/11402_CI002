# LeetCode 414 - Third Maximum Number


## 題目簡述

給定一個整數陣列 `nums`，請回傳其中 **第三大的相異數**。<br>
如果該「第三大的數」不存在（例如陣列中相異的數字少於三個），則請直接回傳該陣列中**最大的數**。

**Sample Input & Output**：

* **Example 1 :**
  * **Input :** `nums = [3,2,1]`
  * **Output :** `1` ($\rightarrow$ 相異數有 3、2、1，第三大的是 1。)

* **Example 2 :**
  * **Input :** `nums = [1,2]`
  * **Output :** `2` ($\rightarrow$ 相異數不足三個，回傳最大的數 2。)

* **Example 3 :**
  * **Input :** `nums = [2,2,3,1]`
  * **Output :** `1` ($\rightarrow$ 去重後的相異數為 3、2、1，第三大的是 1。)


## 程式碼

1. 如果先將整數陣列排序（`sort`）並去重，時間複雜度會達到 $O(N \log N)$。題目只要求「第三大」，我們可以只宣告三個變數 `first`、`second`、`third` 來記錄目前遇到的前三名最大值。初始化時，因為數值可能為 `INT_MIN`，我們使用 `long long` 的最小值（`LLONG_MIN`）作為空位標記。

2. **單次巡邏更新機制**：
    
    - 遍歷陣列時，如果遇到與目前前三名重複的數字，直接 `continue` 忽略。
    - 如果新數字大於 `first`：所有人退後一位，`third = second; second = first; first = num;`。
    - 如果新數字介於 `first` 與 `second` 之間：二三名退後，`third = second; second = num;`。
    - 如果新數字介於 `second` 與 `third` 之間：第三名換人，`third = num;`。

3. **時間與空間極致優化**：這樣僅需單次遍歷陣列，時間複雜度為完美的 $O(N)$，且只花費了三個變數的 $O(1)$ 額外空間。

> **相異數定義：** 這裡所指的「第三大」必須是**不同的數字**。例如，若陣列為 `[2, 2, 3, 1]`，相異由大到小排序後為 `3, 2, 1`，因此第三大的數是 `1`，重複的 `2` 不能重複計算名次。

```cpp
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first = LLONG_MIN;
        long long second = LLONG_MIN;
        long long third = LLONG_MIN;
        
        for (int num : nums) {
            // 如果數字已經在名次內，則不重複計算
            if (num == first || num == second || num == third) {
                continue;
            }
            
            // 更新前三名次
            if (num > first) {
                third = second;
                second = first;
                first = num;
            } else if (num > second) {
                third = second;
                second = num;
            } else if (num > third) {
                third = num;
            }
        }
        
        // 如果第三名依然是初始的極小值，代表相異數少於三個，依題意回傳最大值 (first)
        if (third == LLONG_MIN) {
            return first;
        }
        return third;
    }
};
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 414 - Third Maximum Number](https://leetcode.com/problems/third-maximum-number/)
