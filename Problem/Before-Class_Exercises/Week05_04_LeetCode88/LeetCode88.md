# LeetCode 88 - Merge Sorted Array


## 題目簡述

給定兩個按 **非遞減順序**（從小到大）排列的整數陣列 `nums1` 和 `nums2`，另有兩個整數 `m` 和 `n`，分別表示 `nums1` 和 `nums2` 中的有效元素數量。<br>
請將 `nums2` 合併到 `nums1` 中，使合併後的陣列同樣按 **非遞減順序** 排列。

**Sample Input & Output**：

* **Example 1 :**
  * **Input :** `nums1 = [1,2,3,0,0,0]`, `m = 3`, `nums2 = [2,5,6]`, `n = 3`
  * **Output :** `[1,2,2,3,5,6]`

* **Example 2 :**
  * **Input :** `nums1 = [1]`, `m = 1`, `nums2 = []`, `n = 0`
  * **Output :** `[1]`
 
* **Example 3 :**
  * **Input :** `nums1 = [0]`, `m = 0`, `nums2 = [1]`, `n = 1`
  * **Output :** `[1]`


## 程式碼

1. 如果從頭（索引 0）開始比較並填入，為了不覆蓋掉 `nums1` 本身還沒被比較的有效元素，我們通常必須開一個大小為 `m + n` 的新陣列來輔助，這會消耗 $O(m + n)$ 的額外空間。

2. 因為 `nums1` 的尾端（從索引 `m + n - 1` 開始往前）原本就塞滿了無用的填補值 0，這代表**尾部的空間是完全安全的空位**。

3. 我們從兩個陣列的「有效元素末尾」開始向前比較，誰比較大，就把誰塞進 `nums1` 最尾端的安全空位，並將各自的指針往前推。這樣一路往回填，完全不需要動用額外空間，即可在 $O(m + n)$ 時間與 $O(1)$ 額外空間的極致規格下完成合併。

> 合併後的陣列不應由函式回傳，而是直接 **修改原陣列 `nums1`**。為了容納合併後的元素，`nums1` 的空間大小已被預先擴充至 `m + n`，其中前 `m` 個個數為有效元素，後 `n` 個個數初始化為 0，應予以忽略或覆蓋。

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;          // 指向 nums1 有效元素的末尾
        int j = n - 1;          // 指向 nums2 元素的末尾
        int k = m + n - 1;      // 指向 nums1 預留總空間的末尾
        
        // 將較大者由後往前填入空位
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        
        // 若 nums1 的元素先填完(i < 0)，但 nums2 還有剩餘，則直接把 nums2 剩下的較小元素依序搬移進去；若 nums2 先填完則不理
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 88 - Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/)
