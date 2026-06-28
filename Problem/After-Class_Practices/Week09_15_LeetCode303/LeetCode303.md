# LeetCode 303 - Range Sum Query - Immutable


## 題目簡述

給定一個整數陣列 `nums`，請實作一個 `NumArray` 類別，處理多個針對特定區間的 **區域和檢索** 請求：

* `NumArray(int[] nums)`：用整數陣列 `nums` 初始化物件。
* `int sumRange(int left, int right)`：回傳陣列 `nums` 中從索引 `left` 到 `right`（**包含 `left` 和 `right`**，即 `[left, right]` 閉區間）的元素總和。

**Sample Input & Output**：

* **Input :**
  ```text
  ["NumArray", "sumRange", "sumRange", "sumRange"]
  [[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
  ```
* **Output :**
  ```text
  [null, 1, -1, -3]
  ```
  
* **解釋**
  ```text
  NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
  numArray.sumRange(0, 2); // 回傳 (-2) + 0 + 3 = 1
  numArray.sumRange(2, 5); // 回傳 3 + (-5) + 2 + (-1) = -1
  numArray.sumRange(0, 5); // 回傳 (-2) + 0 + 3 + (-5) + 2 + (-1) = -3
  ```


## 程式碼

1. **直覺暴力的時間地獄**：<br>
  如果每次呼叫 `sumRange` 時，都用一個 `for` 迴圈從 `left` 累加到 `right`，那麼每次查詢的時間複雜度會是 $O(N)$。若總共需要查詢 $M$ 次，整體時間複雜度將高達 $O(M \times N)$，在面試或巨量資料測試中會直接吃下 TLE。

2. **前綴和（Prefix Sum）的降維打擊**：
   - 為了在 $O(1)$ 時間內秒殺查詢，我們可以建立一個空間換時間的輔助陣列 `prefix_sum`。<br>
   - 我們定義 `prefix_sum[i]` 代表原陣列中**前 `i` 個元素的總和**（意即從 `nums[0]` 一路累加到 `nums[i-1]` 的和）。
   - 為了排版優雅並防範邊界溢位，我們通常將 `prefix_sum` 的長度設為 `nums.size() + 1`，並將 `prefix_sum[0]` 初始化為 `0`。

3. **區間和轉移公式**：<br>
   當我們想知道 `nums` 陣列中 `[left, right]` 的區間和時，只需要將「前 `right + 1` 個元素的和」減去「前 `left` 個元素的和」即可：<br>
    $$\text{sumRange}(left, right) = \text{prefixSum}[right + 1] - \text{prefixSum}[left]$$ <br>
   這就像剪報紙一樣，拿一整條大長度，剪掉前面不需要的碎屑，留下的就是目標區間！

4. **複雜度分析**：
   * **建構子建置時間**： $O(N)$。只需要在初始化時線性巡邏一遍 `nums` 建立前綴和陣列。
   * **單次查詢時間**： $O(1)$。`sumRange` 內部只做一次減法運算，達到極致的常數時間。
   * **額外空間複雜度**： $O(N)$。需要開闢一個大小為 $N + 1$ 的前綴和快取陣列。

```cpp
#include <vector>

class NumArray {
private:
    std::vector<int> prefix_sum; // 儲存前綴和快取的陣列

public:
    NumArray(std::vector<int>& nums) {
        int n = nums.size();
        prefix_sum.assign(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];
        }
    }
    int sumRange(int left, int right) {
        return prefix_sum[right + 1] - prefix_sum[left]; // [left, right] 的總和 = 前 right+1 個元素和 - 前 left 個元素和
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 303 - Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/)
