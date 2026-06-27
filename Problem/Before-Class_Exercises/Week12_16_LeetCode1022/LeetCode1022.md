# LeetCode 1022 - Sum of Root To Leaf Binary Numbers


## 題目簡述

給定一棵二元樹，每個節點的值不是 `0` 就是 `1`。每一條從根節點（Root）到葉節點（Leaf）的延伸路徑都代表一個從最高位元開始的**二進位數字**。

* 例如，路徑如果依序經過 `0 -> 1 -> 1 -> 0 -> 1`，它代表的二進位數字就是 `01101`，換算成十進位就是 `13`。

請計算並回傳這棵二元樹中，**所有從根到葉路徑所代表的二進位數之十進位總和**。

**Sample Input & Output**：

* **Example 1 :**
  * **Input :** `root = [1,0,1,0,1,0,1]`
  * **Output :** `22`
  * **解釋 :**
    * 路徑 1 (`1->0->0`): 二進位 `100` $\rightarrow$ 十進位 4
    * 路徑 2 (`1->0->1`): 二進位 `101` $\rightarrow$ 十進位 5
    * 路徑 3 (`1->1->0`): 二進位 `110` $\rightarrow$ 十進位 6
    * 路徑 4 (`1->1->1`): 二進位 `111` $\rightarrow$ 十進位 7
    * 總和 $= 4 + 5 + 6 + 7 = 22$。

* **Example 2 :**
  * **Input :** `root = [0]`
  * **Output :** `0`


## 程式碼

1. **核心思考方向**：要走完所有從根到葉的路徑，最適合的武器就是 **深度優先搜尋（DFS, Depth First Search）**。我們可以用遞迴的方式從根節點一路向下探索。

2. **二進位轉十進位的即時運算**：
   - 當我們從上層往下層走時，每往下走一步，原本累積的數字在二進位中就要**向左移一位**（在十進位中相當於乘以 2），接著再加上當前節點的值。
   - 舉例來說：原本路徑是 `1` (十進位 1)。走到下一層的 `0` 時，數字變成 `1 * 2 + 0 = 2` (二進位 `10`)。再走到下一層的 `1` 時，數字變成 `2 * 2 + 1 = 5` (二進位 `110` -> `101`)。
   - 在 C++ 中，我們可以用 `(current_sum << 1) | node->val` 或者是傳統的 `current_sum * 2 + node->val` 來優雅地完成這個動態轉算。

3. **觸及葉節點的結算機制**：
   - 當遞迴發現當前節點的左右子節點皆為空（`!root->left && !root->right`），代表這條路徑已經完整走完。此時直接回傳當前累積的 `current_sum`。
   - 如果不是葉節點，則將當前算好的 `current_sum` 繼續丟給左子樹與右子樹遞迴計算，並將兩邊回傳的所有總和相加即可。

> **葉節點（Leaf Node）** 是指沒有任何子節點（既沒有左子節點，也沒有右子節點）的節點。

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode* node, int current_sum); 
};

int Solution::dfs(TreeNode* node, int current_sum) {
    if (node == nullptr) return 0;
    current_sum = (current_sum << 1) | node->val;
    if (node->left == nullptr && node->right == nullptr) return current_sum;
    return dfs(node->left, current_sum) + dfs(node->right, current_sum);
}
```


## 參考資料

**題目連結 & 測試網站**：[LeetCode 1022 - Sum of Root To Leaf Binary Numbers](https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/)
