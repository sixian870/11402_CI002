# LeetCode 148 - Sort List


## 題目簡述

給定一個單向鏈結串列的頭節點 `head`，請將該鏈結串列按 **升序**（從小到大）進行排序，並回傳排序後的鏈結串列。

> **限制**：在 **$O(N \log N)$ 時間複雜度** 與 **$O(1)$ 額外空間複雜度**（常數級別的輔助空間）下完成

**Sample Input & Output**：

* **Example 1 :**

  <img width="269" height="116" alt="螢幕擷取畫面 2026-06-28 172546" src="https://github.com/user-attachments/assets/40d2bcdc-65c3-4c14-b034-1d001167aa0e" />
  <br><br>
  
  * **Input :** `head = [4,2,1,3]`
  * **Output :** `[1,2,3,4]`

* **Example 2 :**
  
  <img width="266" height="91" alt="螢幕擷取畫面 2026-06-28 172600" src="https://github.com/user-attachments/assets/a938849f-a6d9-434c-ade8-bf1694e0a14a" />
  <br><br>
  
  * **Input :** `head = [-1,5,3,4,0]`
  * **Output :** `[-1,0,3,4,5]`

* **Example 3 :**
  * **Input :** `head = []`
  * **Output :** `[]`


## 程式碼

1. **核心思考方向**：<br>
   要在 $O(N \log N)$ 時間內對資料進行排序，最常見的演算法是快排（Quick Sort）、堆排（Heap Sort）或合併排序（Merge Sort）。對於單向鏈結串列而言， **合併排序（Merge Sort）** 是最適合的選擇，因為鏈結串列具有原地修改指標的特性，非常適合用來進行「分割」與「合併」。

2. **經典的自底向上（Bottom-up）與自頂向下（Top-down）遞迴**：
   - 這裡我們採用經典的**自頂向下（Top-down）遞迴分治法**。
   - **第一步：切半（Find Middle）**。我們使用 **快慢雙指針（Slow & Fast Pointers）** 技巧。快指針每次走兩步，慢指針每次走一步，當快指針走到末尾時，慢指針剛好停在串列的中點。
   - **第二步：斷開（Disconnect）**。從中點將鏈結串列切成左、右兩半，並記得將左半邊的尾端指向 `nullptr` 以切斷連結。
   - **第三步：遞迴（Recursive Sort）**。對左半邊和右半邊分別遞迴呼叫 `sortList`。
   - **第四步：合併（Merge Sorted Lists）**。實作一個類似 LeetCode 21 的 `mergeTwoLists` 函式，用雙指針比較左右兩半的節點大小，將其重新串接成一條有序的完整鏈結串列。

3. **複雜度分析**：
   - **時間複雜度**： $O(N \log N)$。每次將串列平分成兩半需要 $\log N$ 層分割，每層合併兩個有序串列需要 $O(N)$ 的時間。
   - **空間複雜度**：遞迴解法會消耗 $O(\log N)$ 的系統隱式核心棧（Stack）空間。若要達到題目要求的絕對 $O(1)$ 空間，通常需要改寫為反向疊代的「自底向上（Bottom-up）」非遞迴版本，但在面試中，寫出優雅的遞迴分治解法通常已足夠。

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head; // 若鏈結串列為空或只有一個節點，無需排序，直接回傳
        }
        // 使用快慢雙指針找出鏈結串列的中點
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr; // 用來記錄 slow 的前一個節點，方便切斷串列
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr; // 從中點將串列切成獨立的左、右兩半
        // 遞迴向下分治排序
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);
        return merge(left, right); // 將兩個排序好的有序串列進行合併
    }

private:
    // 合併兩個已排序的鏈結串列
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0); // 虛擬頭節點，方便串接
        ListNode* curr = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if (l1) curr->next = l1;
        if (l2) curr->next = l2;
        return dummy.next;
    }
};
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 148 - Sort List](https://leetcode.com/problems/sort-list/)
