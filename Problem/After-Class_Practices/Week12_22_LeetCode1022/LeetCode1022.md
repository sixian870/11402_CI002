# LeetCode 1022 - Sum of Root To Leaf Binary Numbers


## 題目簡述

給定一棵二元樹的根節點 `root`，其中每個節點的值不是 `0` 就是 `1`。<br>
這棵二元樹從根節點到任何葉子節點的每條路徑，都可以表示成一個二進位數字。例如，如果路徑是 `1 -> 0 -> 1`，則代表二進位數 `101`，其十進位價值為 `5`。<br>
請計算並回傳從 **根節點到所有葉子節點** 所能表示的二進位數字的 **總和**。

> **邊界規範**：最終答案保證能塞進一個 32 位元有號整數（`int`）的範圍內。

**Sample Input & Output**：

* **Example 1 :**

  <img width="218" height="137" alt="螢幕擷取畫面 2026-06-28 193238" src="https://github.com/user-attachments/assets/182e0420-611b-49a5-90c4-288c314c68e3" />
  <br><br>
  
  * **Input :** `root = [1,0,1,0,1,0,1]`
  * **Output :** `22`
  * **解釋 :** <br>
    這棵樹共有四條從根到葉子的路徑，對應的二進位與十進位如下：
    - `1 -> 0 -> 0` = 二進位 `100` = 十進位 4
    - `1 -> 0 -> 1` = 二進位 `101` = 十進位 5
    - `1 -> 1 -> 0` = 二進位 `110` = 十進位 6
    - `1 -> 1 -> 1` = 二進位 `111` = 十進位 7
    - 總和為：$4 + 5 + 6 + 7 = 22$。

* **Example 2 :**
  * **Input :** `root = [0]`
  * **Output :** `0`


## 程式碼

1. **核心思考方向**：<br>
   要收集所有「根到葉子」的路徑，最直覺且標準的武器就是 **深度優先搜尋（DFS）**。我們需要從根節點出發一路向下摸到葉子節點（Leaf Node），當判定當前格子是葉子時，就把整條路徑累積出來的數值加到全域總和中。

2. **二進位價值的動態累積公式**：<br>
   我們不需要開一個陣列或字串去把歷史路徑的 `0` 和 `1` 存起來最後才做進位變換。當我們從父節點走向子節點時，原本累積的數值在二進位中等同於「全部往左前移一位（乘上 2）」，然後再加上當前新節點的數值。
   - 假設上一層傳下來的數值是 `current_sum`。
   - 來到當前節點後，最新的數值轉移公式為： $$\text{currentSum} = (\text{currentSum} \ll 1) \mid \text{root}\rightarrow\text{val}$$ <br>
     *(註：`(current_sum << 1)` 代表左移一位即乘以 2；`| root->val` 則是利用位元或運算把 0 或 1 填入最後一個位元，這比用 `+` 運算更具備底層效能優勢)*

3. **遞迴終止與回傳邏輯**：
   - **空節點安全防禦**：如果走到 `nullptr`，說明此路不通，直接回傳 `0`。
   - **葉子節點觸發點**：如果發現 `!root->left && !root->right`，說明我們成功解鎖了一條完整的根到葉子路徑，直接把當前算好的 `current_sum` 回傳。
   - **分治向下探索**：若還沒到葉子，就將當前加權好的數值各自傳給左子樹與右子樹，並將兩邊回傳的總和加總起來。

4. **複雜度分析**：
   - **時間複雜度**： $O(N)$。每個節點剛好被 DFS 造訪一次。
   - **空間複雜度**： $O(H)$，其中 $H$ 為樹的高度（最壞情況下退化為鏈狀時為 $O(N)$，平衡樹時為 $O(\log N)$），主要用於系統隱式遞迴棧的空間消耗。

```cpp
#include <iostream>

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
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode* root, int current_sum) {
        if (!root) {
            return 0;
        }
        current_sum = (current_sum << 1) | root->val; // 將上層累積值左移一位（等同乘以 2），並嵌入當前節點的值
        if (!root->left && !root->right) {
            return current_sum; // 若當前節點為葉子節點（左右皆空），代表一條二進位數路徑收尾，回傳結果
        }
        return dfs(root->left, current_sum) + dfs(root->right, current_sum); // 向下遞迴收集左子樹與右子樹的所有路徑總和
    }
};
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 1022 - Sum of Root To Leaf Binary Numbers](https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/)
