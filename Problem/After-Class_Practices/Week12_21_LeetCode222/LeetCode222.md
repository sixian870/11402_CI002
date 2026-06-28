# LeetCode 222 - Count Complete Tree Nodes


## 題目簡述

給定一個 **完全二元樹（Complete Binary Tree）** 的根節點 `root`，請找出並回傳該樹的節點總個數。

> **完全二元樹的定義**：在完全二元樹中，除了最後一層外，其餘每層的節點都是滿的，且最後一層的所有節點都儘可能地靠左排列。如果最後一層是第 $h$ 層，則該層包含的節點數量在 $1$ 到 $2^h$ 之間。

> **限制**：時間複雜度低於 **$O(N)$** 。

**Sample Input & Output**：

* **Example 1 :**

  <img width="271" height="218" alt="螢幕擷取畫面 2026-06-28 192214" src="https://github.com/user-attachments/assets/3d15e172-4df5-4838-9f49-d1256f39e9c7" />
  <br><br>
  
  * **Input :** `root = [1,2,3,4,5,6]`
  * **Output :** `6`

* **Example 2 :**
  * **Input :** `root = []`
  * **Output :** `0`

* **Example 3 :**
  * **Input :** `root = [1]`
  * **Output :** `1`


## 程式碼

1. **直覺遍歷的缺點**：<br>
   如果使用一般的 DFS（如 `1 + countNodes(root->left) + countNodes(root->right)`）或 BFS，會強行造訪樹中的每一個節點，時間複雜度是 $O(N)$，這完全浪費了題目給定的「完全二元樹」這項強大幾何特性。

2. **滿二元樹（Perfect Binary Tree）的數學捷徑**：
   - 如果一棵二元樹是「滿的」，其高度為 $h$（從根節點到葉子節點的左邊緣深度，根節點高度計為 0），那麼它的總節點數可以直接透過數學公式計算出來： $$2^{h+1} - 1$$
   - 我們可以利用這一點，分別去量測當前樹的**極左深度（Left Height）**與**極右深度（Right Height）**。

3. **分治二分法（Divide and Conquer）破局邏輯**：
   - **情況一：極左深度 == 極右深度**：
     說明從左到右整棵子樹是完美的對稱滿二元樹，直接套用公式 $2^{\text{leftHeight} + 1} - 1$ 秒殺該子樹的總節點數，**完全不需要遞迴進去數**！
   - **情況二：極左深度 != 極右深度**：<br>
     說明最後一層還沒有填滿，且殘缺的部分出現在右半邊。此時，我們只能摸摸鼻子對左子樹與右子樹分別遞迴呼叫 `countNodes`，再把兩邊結果加上根節點（`1`）加總起來。
   - 驚人的是，因為完全二元樹的結構特性，每次切半時，**左子樹與右子樹中必定至少會有一邊是完美的滿二元樹**！這意味著在每一層遞迴中，只有一邊會繼續往下遞迴，另一邊會觸發公式直接 $O(1)$ 回傳。

4. **複雜度分析**：
   - **時間複雜度**： $O(\log^2 N)$。樹的總深度為 $\log N$，每一層遞迴中我們需要花 $O(\log N)$ 的時間去測量左右樹的深度，因此整體時間遠低於 $O(N)$，效能極佳。
   - **空間複雜度**： $O(\log N)$。遞迴時佔用的系統隱式棧（Stack）空間，其深度與樹高成正比。

```cpp
#include <iostream>
#include <cmath>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        TreeNode* leftNode = root;
        TreeNode* rightNode = root;
        int leftHeight = 0;
        int rightHeight = 0;
        
        // 量測極左邊緣深度
        while (leftNode->left) {
            leftHeight++;
            leftNode = leftNode->left;
        }
        
        // 量測極右邊緣深度
        while (rightNode->right) {
            rightHeight++;
            rightNode = rightNode->right;
        }
        
        // 若極左深度等於極右深度，說明此子樹為完美的「滿二元樹」，直接套用公式計算
        if (leftHeight == rightHeight) {
            return (1 << (leftHeight + 1)) - 1; // 2^(height + 1) - 1
        }
        
        // 若不相等，則傳統分治：1 (當前根節點) + 左子樹節點數 + 右子樹節點數
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 222 - Count Complete Tree Nodes](https://leetcode.com/problems/count-complete-tree-nodes/)
