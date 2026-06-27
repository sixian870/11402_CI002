# LeetCode 658 - Find K Closest Elements


## 題目簡述

給定一個 **已排序**（升序）的整數陣列 `arr`，以及兩個整數 `k` 和 `x`。請從陣列中找出 `k` 個最接近 `x` 的元素，並將這 `k` 個元素按 **升序（從小到大）** 排列後回傳。

整數 `a` 比整數 `b` 更接近 `x` 的定義為：
* $|a - x| < |b - x|$ 
* 如果絕對值差相等，則數值較小者優先（$|a - x| == |b - x|$ 且 $a < b$）

**Sample Input & Output**：

* **Example 1 :**
  * **Input :** `arr = [1,2,3,4,5]`, `k = 4`, `x = 3`
  * **Output :** `[1,2,3,4]` ($\rightarrow$ 1, 2, 3, 4 距離 3 最近)

* **Example 2 :**
  * **Input :** `arr = [1,1,2,3,4,5]`, `k = 4`, `x = -1`
  * **Output :** `[1,1,2,3]` ($\rightarrow$ 越小的數距離 -1 最近)


## 程式碼

1. **核心思考方向**：既然陣列已經是排序好的，那麼最接近 `x` 的 `k` 個元素，在原陣列中一定是一段**連續的區間**。

2. **雙指針向內收縮法 ($O(N - K)$)**：
   - 我們可以先將指針 `left` 設在陣列開頭（0），指針 `right` 設在陣列末尾（`arr.size() - 1`）。
   - 此時整個區間包含的元素量是 $N$ 個。只要這個區間的長度大於 `k`，我們就必須淘汰掉最左端或最右端的其中一個元素。
   - 比較 `x - arr[left]` 與 `arr[right] - x` 的距離。如果左端點距離比較遠，或者兩端點距離一樣遠（因為左端點數值較小必須保留），我們就放棄右端點（`right--`）；否則就放棄左端點（`left++`）。
   - 當區間長度剛好縮小到 `k` 個時，`left` 到 `right` 的連續區間就是我們要的答案。

3. **極致的空間複雜度**：利用這個方法，我們不需要動用複雜的二分搜尋法與前後展開，也不用自訂排序，能直接在原陣列上透過雙指針鎖定答案，空間複雜度僅為 $O(1)$（不計回傳答案空間）。

```cpp
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - 1;
        
        // 當前區間長度大於 k 時，持續從兩端淘汰較遠的元素
        while (right - left + 1 > k) {
            // 比較左端點與右端點到 x 的距離，若距離相等，因為左端點數值較小應保留，故淘汰右端點
            if (x - arr[left] > arr[right] - x) {
                left++; // 左端點距離較遠，淘汰左端點
            } else {
                right--; // 右端點距離較遠（或距離相等），淘汰右端點
            }
        }
        // 鎖定長度為 k 的區間後，直接利用建構子切出該連續區間回傳
        return vector<int>(arr.begin() + left, arr.begin() + right + 1);
    }
};
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 658 - Find K Closest Elements](https://leetcode.com/problems/find-k-closest-elements/)
