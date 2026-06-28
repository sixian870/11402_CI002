# 基礎程式設計 - C++實習 (二) 課程學習紀錄

本儲存庫主要用於完整記錄學習軌跡並針對練習內容利用ai輔助做重點分析，方便複習快速瀏覽。<br>
內容編排上將每週主題式練習、CPE 49 題一星題進行解構分類，並且將練習中常用的優化手段、高頻語法核心與數學函式，整理到本儲存庫的 CodeBook 中。


## Repository Structure

```text
├── 📂 CPE/                        # CPE 檢定專區
│   ├── 📂 One_Star/               # CPE 一星 49 題解題資料夾
│   └── 📄 CPE.md                  # CPE 一星題庫總覽介面 (快速導覽)
│
├── 📂 Problem/                    # 課程練習與考試紀錄專區
│   ├── 📂 Before-Class_Exercises/ # 課前預習題目 (LeetCode)
│   ├── 📂 On-Site_Examinations/   # 課堂上機實戰題目 (UVa)
│   ├── 📂 After-Class_Practices/  # 課後複習題目 (LeetCode)
│   ├── 📂 Midterm_Exam/           # 期中上機考試題解
│   ├── 📂 Final_Exam/             # 期末上機考試題解
│   └── 📄 Problem.md              # 課程練習總覽介面 (快速導覽)
│
├── 📄 CodeBook.md                 # 個人競賽實戰演算法模板總覽
└── 📄 README.md                   # 本儲存庫主導覽說明文件 (本檔案)
```


## 快速核心導覽主分頁

點擊下方分頁連結可直接前往各單元的獨立詳細導覽介面：

* **[課程練習總覽 (Problem.md)](./Problem/Problem.md)**  ——  查看 16 個週次的主題進度演變、課前後練習與期中期末考題。

* **[CPE 一星題選集 (CPE.md)](./CPE/CPE.md)**  ——  橫跨八大核心領域的 49 題一星必刷題庫。

* **[CodeBook (CodeBook.md)」](./CodeBook.md)**  ——  專為檢定與競賽整理的快速重點篩查。


## 1. Problem 資料夾：課程練習與考試紀錄

本區塊完整收錄每週由淺入深的主題進度。<br>
每週核心題目架構橫跨課前、課堂與課後，並包含兩大重要期考，透過五個資料夾進行分流管理：

### Before-Class_Exercises ＆ After-Class_Practices
  
* **平台**：LeetCode
  
* **資料夾內容**：由於 LeetCode 僅需實作核心功能函式，且程式碼皆完整留存於個人帳號中，故本區不另外建立額外的 `.cpp` 檔案，每個題目資料夾僅包含一個 `README.md` 筆記。
  
* **筆記格式**：【題目描述】、 【解題邏輯】（推導關鍵與注意點）、【程式碼】（C++ 解法）與【參考資料】。

### On-Site_Examinations & Midterm_Exam ＆ Final_Exam

* **平台**：UVa Online Judge

* **資料夾內容**：由於 UVa 需要完整的標準輸入輸出（I/O）處理，因此每個題目獨立開設資料夾，內部標準配置包含三個檔案：

  * **題目.pdf** —— 原題題目敘述快取。

  * **main.cpp** —— 符合 ANSI C++ 標準、可直接編譯並通過 OJ 測試的完整原始碼。

  * **README.md** —— 詳細題解筆記，內容包含：【題目描述】、【解題邏輯】、【複雜度分析】、【陷阱提醒】、【程式碼】、【進階優化思考】與【參考資料】。


### 核心涵蓋主題一覽：
**1. I/O, EOF, absolute difference**

**2. Strings, formatting**

**3. Math + corner cases**

**4. Arrays + simulation**

**5. Sorting basics**

**6. Median / order statistics**

**7. Binary search**

**8. Prefix sums / difference arrays**

**9. Stack**

**10. Queue**

**11. Complete binary tree indexing + BST intro**

**12. 2D array + weak DP ramp**

**13. Heaps + seat reservation + set**

**14. Intervals + booking**

**15. Greedy + arrangement**

**16. Dynamic programming**

**[點此查看詳細資訊](./Problem/Problem.md)**


## 2. CPE 資料夾：CPE 一星題整理區

為應戰大學程式能力檢定（CPE），**CPE/One_Star/** 資料夾內完整整理了常考的 **49 題一星題**。

每個題目資料夾皆包含：

  * **題目.pdf** —— 原題題目敘述快取。

  * **main.cpp** —— 符合 ANSI C++ 標準、可直接編譯並通過 OJ 測試的完整原始碼。

  * **README.md** —— 詳細題解筆記，內容包含：【題目描述】、【解題邏輯】、【程式碼】與【參考資料】。

### 核心主題：

* **Basic Problems**
  
* **Characters and Strings**

* **Mathematical Computation**

* **Base Conversion**

* **Primes, Factors, and Multiples**

* **Geometry and Coordinates**

* **Sorting and Median**

* **Simulation**

  **[點此查看詳細資訊](./CPE/CPE.md)**


## 3. CodeBook：總結練習經驗與語法精華

**CodeBook.md** 是我在平日課程及課外刷題與檢定演練中整理出的常用工具。<br>
內容主要包含底層的 I/O 優化、緩衝區陷阱避免、高頻 STL 容器的核心操作與高階數學函式，旨在方便快速找尋所需及考前快速瀏覽。

### CodeBook 主要內容快查

* **萬用標頭檔與極速 I/O 架構**
  * 封裝 `ios::sync_with_stdio(false); cin.tie(0);` 解除流同步，使 C++ 輸入輸出流達到近乎 `printf/scanf` 的極致速度。

* **輸入流緩衝區地雷防範 (`cin >>` vs `getline`)**
  * 明確規範 `cin >>`（殘留換行符）與 `getline`（吞噬換行符）的切換細節，全面導入 `cin.ignore()` 防禦緩衝區讀取到空字串的經典 bug。

* **核心 STL 容器與複雜度**
  * `<vector>` / `<stack>` / `<queue>`：完整收錄先進先出、後進先出的動態記憶體維護操作。
  * `<map>` / `<set>`：掌握 $O(\log N)$ 內部紅黑樹自動排序與去重機制，用於高效率進行頻率統計及集合去重。

* **字串處理與流式切分 (`<sstream>`)**
  * 靈活調用 `stringstream` 實現未知欄位數的「整行空格切分技術」。
  * 導入 `stoll(s, nullptr, 2)` 位元字串轉十進位長整型、以及 ASCII 字元與數值的高效變換公式。

* **格式化輸出精準控制 (`<iomanip>`)**
  * 熟練運用 `fixed` 與 `setprecision(n)` 進行小數點後四捨五入的精確輸出，以及 `setw(n)` 的左右對齊（`left` / `right`）排版。

* **競賽級核心數學與底層優化函式**
  * **數論基礎**：內建高效輾轉相除法（`gcd`）範本、微秒級開根號質數判定法（`isPrime`）、以及位數翻轉演算法（`reverseNumber`）。
  * **C++17 數論庫**：直接整合 `<numeric>` 標頭檔中內建的 `std::gcd` 快取。
  * **硬體加速位元運算**：使用內建巨集 `__builtin_popcount(x)` 透過底層硬體指令集以 $O(1)$ 的驚人速度計算二進位中位元為 1 的個數。
 
    **[點此查看詳細資訊](./CodeBook.md)**
