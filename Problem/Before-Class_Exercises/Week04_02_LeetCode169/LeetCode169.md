# LeetCode 169 - Majority Element


## 題目簡述

給定一個大小為 $n$ 的陣列 `nums`，請找出其中的 **多數元素 (Majority Element)**。

* 多數元素的定義為：**在陣列中出現次數「大於 $\lfloor n / 2 \rfloor$」的元素**。

題目假設該陣列為非空，且陣列中**一定會存在**這樣一個多數元素。

**Sample Input & Output**：

* **Example 1 :**
  * **Input :** `nums = [3,2,3]`
  * **Output :** `3` ($\rightarrow 3$ 出現了 2 次，大於 $3/2 = 1.5$)

* **Example 2 :**
  * **Input :** `nums = [2,2,1,1,1,2,2]`
  * **Output :** `2` ($\rightarrow 2$ 出現了 4 次，大於 $7/2 = 3.5$)


## 程式碼

1. **時間與空間的抉擇**：最直覺的方法是拿 `std::map` 或哈希表來計數，但這需要 $O(n)$ 的額外空間。

2. **波耶-摩爾投票演算法 (Boyer-Moore Voting Algorithm)**：這是一個非常神奇且優雅的 $O(n)$ 時間、 $O(1)$ 空間解法。
    - 我們想像這是一場大亂鬥，每個人都有自己的陣營（數字）。
    - 我們設定一個候選人 `candidate` 與一個計數器 `count`。
    - 遍歷陣列時，如果 `count == 0`，代表前面的陣營剛好同歸於盡了，我們就讓目前遇到的數字當新候選人。
    - 接下來，如果遇到同陣營的（數字相同），`count++`（戰力增加）；如果遇到敵對陣營的（數字不同），`count--`（同歸於盡）。
    - 因為多數元素的數量絕對大於全場的一半，所以不論戰況多慘烈，它最後一定能挺過所有的同歸於盡，成為留在台上的最後贏家。

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        
        for (int num : nums) {
            // 當前的陣營全數陣亡，更換新的候選人
            if (count == 0) {
                candidate = num;
            }
            
            // 遇到同陣營則戰力 +1，異陣營則同歸於盡 -1
            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }
        
        return candidate;
    }
};
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 169 - Majority Element](https://leetcode.com/problems/majority-element/)
