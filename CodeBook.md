## C++ Code Book

#### 萬用標頭檔與 I/O 優化
```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 
}
```

#### 邏輯運算子
* and : `&&`
* or : `||`

#### 流程控制
* continue 與 break 的區別
  * break：直接跳出並終止整個迴圈。
  * continue：跳過本次迴圈剩下的程式碼，直接進入下一次的迴圈迭代。

#### 輸入讀取差異
| 讀取方式 | 讀取行為 | 對空白 / 換行符號（`\n`）的處理 |
| :--- | :--- | :--- |
| `cin >> x;` | 讀取一個變數 | 自動跳過開頭的空白或換行，讀到下一個空白或換行前結束。換行符號會留在緩衝區。 |
| `getline(cin, s);` | 讀取整行字串 | 讀取到換行符號為止（包含空白），並直接將換行符號從緩衝區拿走且丟棄。 |
| `cin.get(ch);` | 讀取單個字元 | 什麼都讀（包含空白、\n、\t 等）。不會跳過任何東西。 |

若先用 `cin >> x;` 接著要用 getline(cin, s);，中間必須加一行 cin.ignore(); 或是用 cin.get() 處理留在緩衝區的 `\n`，否則 getline 會讀到空字串。

#### 資料型態
* `unsigned char` : 若輸入的字元不是單純的英文或數字時需要用到。
* `int` 範圍 : 約 $\pm 2 \times 10^9$（精確值為 $-2147483648$ 到 $2147483647$）。
* `long long` 範圍 : 約 $\pm 9 \times 10^{18}$ 。<br>
若測資更大則須用 `string` 讀取。

#### 字元與字串處理 ( `<string>` , `<cctype>` , `<sstream>` )

##### `<string>` :
* `.length()` 與 `.size()` : 獲取字串長度。
  
* `.find()` 與 `string::npos`： `.find()` 用於尋找子字串或字元，如果找不到會回傳 `string::npos`。
```cpp
string s = "Hello World";
int pos = s.find("World");
if (pos != string::npos) {
    cout << "找到子字串，起始索引在: " << pos << "\n";
}
```

* `to_string()` : 數字轉字串。
```cpp
int num = 123;
string s_num = to_string(num);
```

* `stoll()` : 將二進位字串轉為 long long 十進位整數。
```cpp
string binary_str = "1010";
long long dec_num = stoll(binary_str, nullptr, 2); //10
```

* 字元與數字的 ASCII 轉換
```cpp
char c = 'C';
// 字元轉數字
int index = c - 'A'; // 'C' - 'A' = 2
// 數字轉字元
char new_c = char(index + 'A'); // char(2 + 'A') = 'C'
```

##### `<cctype>` :
* 字元判斷與轉換
```cpp
#include <cctype>

char c = 'a';
if (isalpha(c)) { ... } // 判斷是否為英文字母 (A-Z 或 a-z)
char upper = toupper(c); // 轉大寫 'A'
char lower = tolower(upper); // 轉小寫 'a'
```

##### `<sstream>` :
* 字串切分 : 處理整行讀入但需要以空格分開各個單字/數字的狀況。
```cpp
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

string input = "apple 123 banana 456";
stringstream ss(input);
string word;
// ss 會像 cin 一樣，自動用空白、換行切分字串
while (ss >> word) {
    cout << word << "\n"; 
}
```

#### 容器與宣告 ( `<array>, <vector>, <map>` )
##### `<array>` 靜態陣列 :
```cpp
#include <array>

// 宣告一個大小為 5 的 int 陣列，並初始化
array<int, 5> arr = {1, 2, 3, 4, 5};
int arr[] = {1, 2, 3, 4, 5};
int arr[5] = {1, 2, 3, 4, 5};
int arr[5] ={0}; // 初始化為 0

// 常用操作
int first = arr[0];
int total_size = arr.size(); // 取得陣列大小
```

##### `<vector>` 動態陣列 :
```cpp
#include <vector>

// 1. 宣告空 vector
vector<int> v1; 

// 2. 宣告大小為 5 的 vector，預設值皆為 0
vector<int> v2(5); 

// 3. 宣告大小為 5 的 vector，並將所有元素初始化為 -1
vector<int> v3(5, -1); 

// 4. 使用初始化清單
vector<int> v4 = {1, 2, 3, 4, 5}; 

// 常用操作
v1.push_back(10); // 在尾端加入元素 10
if (!v1.empty()) { // 檢查是否為空，.empty() 適用於 vector, map, string 等所有 STL 容器
    v1.pop_back(); // 移出尾端元素
}
```

##### `<map>` : 會自動依據 Key 排序（由小到大），搜尋、插入皆為 $O(\log N)$。
```cpp
#include <map>
#include <string>

// 宣告一個 Key 為 string，Value 為 int 的 map
map<string, int> mp;

// 常用操作
mp["apple"] = 10; // 插入或修改
mp["banana"] = 5;

// 尋找元素
if (mp.find("apple") != mp.end()) {
    // 找到了
}

// 遍歷 map
for (auto const& it : mp) {
    cout << it.first << " " << it.second << "\n";
}
```

#### 格式化輸出 ( `<iomanip>` )
##### `<iomanip>` : 
```cpp
#include <iostream>
#include <iomanip>
using namespace std;

double pi = 3.1415926535;
// 1. 固定小數點輸出後 4 位
cout << fixed << setprecision(4) << pi << "\n"; // 輸出: 3.1416 (會自動四捨五入)

// 2. 設定輸出欄位寬度為 5，預設右對齊，空格補白
cout << setw(5) << 42 << "\n"; // 輸出: "   42"

// 3. 切換成左對齊 (輸出 42 + 3 個空格)
cout << left << setw(5) << 42 << "!\n"; // 輸出: "42   !"
```

#### 數學與演算法 ( `<cmath>, <algorithm>, <numeric>` )
##### `<cmath>` : 
* `pow(base, exp)` : 計算 $base^{exp}$，回傳值為浮點數（double）。
* `sqrt(x)`: 計算 $\sqrt{x}$。
* `floor(x)` : 無條件捨去（無條件下高斯符號 $\lfloor x \rfloor$）。
* `abs(x)` : 計算絕對值。
* `PI($\pi$)` 的宣告方式 :
```cpp
const double PI = acos(-1.0);
```

##### `<algorithm>` :
* `reverse(begin, end)` : 翻轉容器。
* `swap(a, b)` : 交換兩個變數的值。
```cpp
#include <algorithm>
#include <vector>
#include <string>

string s = "abc";
reverse(s.begin(), s.end()); // s 變成 "cba"

int x = 5, y = 10;
swap(x, y); // x 變成 10, y 變成 5
```

##### `<numeric>  (C++17)`
* `std::gcd(a, b)`：計算最大公因數。
```cpp
#include <numeric>
int g = std::gcd(12, 18); // g = 6
```

##### 內建位元函式 (GCC 內建)
* __builtin_popcount(x)：以 $O(1)$ 的硬體加速計算整數 x 在二進位表示下，有幾個位元是 1。
```cpp
int num = 7; // 二進位 0111
int cnt = __builtin_popcount(num); // cnt = 3
```

#### GCD 函式
```cpp
// 最大公因數 (輾轉相除法)
long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}
```

#### 質數判斷
```cpp
bool isPrime(long long n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}
```

#### 翻轉數字
```cpp
long long reverseNumber(long long n) {
    long long rev = 0;
    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}
```
