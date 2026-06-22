# UVa 100 - The 3n+1 problem

## 題目簡述

對於任意正整數 $n$：
* 如果 $n$ 是偶數，則將其除以 2（ $n \rightarrow n/2$ ）。
* 如果 $n$ 是奇數，則將其乘 3 加 1（ $n \rightarrow 3n+1$ ）。
  
重複上述過程，考查 Collatz 猜想（考量到所有正整數最終都會回到 1）。從原來的數字變到 1 所經過的數字總個數，稱之為「循環長度」（Cycle length）。<br>
給定一對整數 $i$ 和 $j$，請計算出介於 $i$ 和 $j$ 之間（包含 $i, j$）所有整數中，最大的循環長度。

**Sample Input**：

  **1 10** $\rightarrow$ 每一行包含一對整數 $i$ 和 $j$。<br>
  **100 200**<br>
  **201 210**<br>
  **900 1000**

**Sample Output**：

  **1 10 20** $\rightarrow$ 依序印出：原始輸入的 $i$、原始輸入的 $j$、最大循環長度。<br>
  **100 200 125**<br>
  **201 210 89**<br>
  **900 1000 174**


## 解題思路與考點分析

### 核心觀念：Collatz 猜想（冰雹猜想）
本題基於著名的數學未解之謎——**Collatz Conjecture**。模擬過程中，數字會忽大忽小，就像雲層中的冰雹一樣，但最終都會墜落回 1。

### 演算法步驟
1. 不斷讀入 $i$ 與 $j$，直到檔案結束（EOF）。
2. **注意輸出要求**：不論 $i$ 和 $j$ 的大小順序為何，輸出時必須保持「先 $i$ 後 $j$」的原始輸入順序。
3. 利用 `min(i, j)` 與 `max(i, j)` 確立走訪的閉區間 $[ \text{min}, \text{max} ]$。
4. 逐一模擬區間內每個數字的變換過程，統計每次降回 1 的計數值，並動態更新全域最大值 `max_count`。


## 複雜度分析

* **時間複雜度**： $\mathcal{O}(|i - j| \times K)$
  其中 $|i - j|$ 為查詢的區間長度，$K$ 為該區間內數字的平均循環長度。由於 Collatz 猜想尚未被數學證明其確切的上界，實務上在 UVa 給定的資料範圍內（$n < 10,000$），純暴力模擬即可在時限內通過。
* **空間複雜度**： $\mathcal{O}(1)$
  僅使用固定數量的純量變數（`temp`, `count`, `max_count`）進行迭代模擬，未佔用額外記憶體。


## 邊界條件與潛在陷阱 (Edge & Corner Cases)

這題雖然是 UVa 的第一題，卻有兩個極具代表性的經典陷阱：

1. **輸入順序陷阱 ($i > j$)**：
   題目並未保證輸入的第一個數 $i$ 一定小於第二個數 $j$（例如輸入 `10 1`）。在寫 `for` 迴圈遍歷時，必須先用 `min` 和 `max` 抓出正確範圍。但最後**輸出時，必須按照原始讀入的順序印出 $i$ 與 $j$**。
2. **整數溢位陷阱 (Integer Overflow)**：
   雖然輸入的 $n$ 限制在 $10,000$ 以內，但在執行 $3n+1$ 的模擬過程中，中間產生的暫存值可能會劇烈暴增。若使用標準 32 位元有號整數（`int`），在某些極端數字的運算過程中可能會發生溢位，導致程式陷入死迴圈。**因此，強烈建議模擬變數使用 `long long` 或 `unsigned int`。**


## 程式碼實作

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // 加速標準 I/O 串流
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n1, n2;
    while (cin >> n1 >> n2) {
        int max_count = 0;
        
        // 找出實際的遍歷範圍，但保留原始的 n1, n2 用於輸出
        int start = min(n1, n2);
        int end = max(n1, n2);
        
        for (int i = start; i <= end; i++) {
            long long temp = i; // 使用 long long 預防 3n+1 過程中的整數溢位
            int count = 1;      // 包含起始數字本身
            
            while (temp != 1) {
                if (temp % 2 == 0) {
                    temp /= 2;
                } else {	
                    temp = 3 * temp + 1;
                }
                count++;
            } 
            
            if (count > max_count) {
                max_count = count;
            }
        }
        // 必須依照原始輸入順序輸出 n1 與 n2
        cout << n1 << " " << n2 << " " << max_count << "\n";
    }
    return 0;
}
```

## 進階優化思考 (Optimization)

在暴力法中，許多數字的後半段路徑是重複計算的。例如，數字 3 的路徑是 3 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1。當我們之後計算到數字 6 時（6 -> 3 -> ...），一旦走到 3，我們其實可以直接借用先前查到的結果，不需重複模擬。

**重疊子問題優化：記憶化搜尋（Memoization / DP）**
我們可以使用一個全域陣列（或 `unordered_map` ）來當作快取（Cache），記錄已經計算過的數字及其循環長度。

**優化思路實作片段：**

```cpp
// 建立一個足夠大的陣列記錄已知的長度
int memo[1000000] = {0};

int get_cycle_length(long long n) {
    if (n == 1) return 1;
    if (n < 1000000 && memo[n] != 0) return memo[n];
    
    int length;
    if (n % 2 == 0) length = 1 + get_cycle_length(n / 2);
    else length = 1 + get_cycle_length(3 * n + 1);
    
    if (n < 1000000) memo[n] = length;
    return length;
}
```
透過這種空間換時間的動態規劃手法，可以將多次重複查詢的平攤時間複雜度逼近 $\mathcal{O}(1)$。


## 參考資料

**題目連結**：[UVa100](./UVa100.pdf)

**測試網站**：[The 3n+1 problem](https://vjudge.net/problem/UVA-100)
