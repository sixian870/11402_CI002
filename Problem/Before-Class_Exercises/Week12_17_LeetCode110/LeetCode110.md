# LeetCode 110 - Balanced Binary Tree


## 題目簡述

給定一個二元樹，請判斷它是否是 **高度平衡（Height-Balanced）** 的二元樹。

在這裡，一棵高度平衡二元樹的定義為：
* 這棵樹的**左子樹**和**右子樹**的高度差的絕對值不超過 `1`。
* 並且其**左子樹和右子樹也必須各自是一棵高度平衡的二元樹**。

**Sample Input & Output**：

* **Example 1 :**
  
  <img width="260" height="169" alt="螢幕擷取畫面 2026-06-28 024007" src="https://github.com/user-attachments/assets/6e2a73c3-cf3b-4541-991e-51be868298bd" />
  <br><br>
  
  * **Input :** `root = [3,9,20,null,null,15,7]`
  * **Output :** `true`

* **Example 2 :**
  
  <img width="275" height="179" alt="螢幕擷取畫面 2026-06-28 024039" src="https://github.com/user-attachments/assets/2cd9a45c-64e0-47ca-86a3-b0df4fd7191f" />
  <br><br>
  
  * **Input :** `root = [1,2,2,3,3,null,null,4,4]`
  * **Output :** `false` ($\rightarrow$ 節點 2 的左子樹高度為 3，右子樹為 1，高度差為 2，已失衡。)

* **Example 3 :**
  * **Input :** `root = []`
  * **Output :** `true` ($\rightarrow$ 空樹在定義上視為高度平衡。)


## 程式碼

1. **直覺暴力的缺點 (Top-down)**：如果對每個節點都單獨呼叫一次計算高度的函式，會導致同一個節點被重複計算高度很多次，時間複雜度會劣退到 $O(N^2)$。

2. **自底向上剪枝法 (Bottom-up)**：
   - 我們可以利用後序走訪（先左右、再根節點），從最底層的葉節點開始往上回傳高度。
   - 遞迴函式 `checkHeight` 的設計邏輯：如果某棵子樹是平衡的，就回傳它的真實高度；**一旦發現任何一棵子樹不平衡，就立刻向上回傳 `-1` 進行剪枝（提前結束）**。
   - 當前節點收到左子樹高度 `left` 與右子樹高度 `right` 後：
       - 若 `left == -1` 或 `right == -1`：代表下方早已失衡，直接繼續傳回 `-1`。
       - 若 `abs(left - right) > 1`：代表當前節點左右失衡，立即封鎖並傳回 `-1`。
       - 若兩邊都合法且平衡：則當前節點的高度為 `max(left, right) + 1`，繼續傳給上層。

3. **複雜度**：這種自底向上的思維讓每個節點都只被走訪到一次，時間複雜度是完美的 $O(N)$，空間複雜度取決於樹高引起的遞迴堆疊深度 $O(H)$。

```cpp
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
private:
    int checkHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        
        // 左子樹高度
        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) return -1; // 左子樹已失衡，回傳 -1
        
        // 右子樹高度
        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) return -1; // 右子樹已失衡，回傳 -1
        
        // 檢查當前節點是否平衡，若左右子樹高度差大於 1，代表當前節點失衡，回傳 -1
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }
        
        // 若平衡，則回傳當前節點的真實高度（左右較高者 + 1）
        return max(leftHeight, rightHeight) + 1;
    }

public:
    bool isBalanced(TreeNode* root) {
        // 若最終回傳值不是 -1，代表整棵樹皆符合平衡定義
        return checkHeight(root) != -1;
    }
};
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 110 - Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/)
