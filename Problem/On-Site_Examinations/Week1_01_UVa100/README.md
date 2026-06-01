# UVa 100 - The 3n+1 Problem

## Problem Description

**題目簡述：**

對於任意正整數 $n$：

- 如果 $n$ 是偶數，則將其除以 2（$n -> n/2$）
  
- 如果 $n$ 是奇數，則將其乘 3 加 1（$n -> 3n+1$）

重複上述過程，最後會得到 1，而從原來的數字變到 1 所經過的數字總個數，稱之為「循環長度」（Cycle length）。

**輸入與輸出講解：**

- **輸入：** 每一行包含一對整數 $i$ 和 $j$，程式需要處理多筆測資，直到讀取到檔案結尾（EOF）為止。
- **輸出：** 計算出介於 $i$ 和 $j$ 之間（包含 $i$ 與 $j$）所有整數中，**最大的循環長度**。

  輸出的格式必須依序印出：`原始輸入的 i`、`原始輸入的 j`、`最大循環長度`，三個數字之間以空白隔開。

**題目連結：**[UVa 100](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=36)

### Key Insights
- **陷阱題意（順序問題）：** 題目沒有保證先輸入的數字一定比較小。因此在計算區間時必須重新比較大小，但在**最終輸出**時，又必須按照「原輸入順序」印出，這份程式碼利用原本的 `n1` 與 `n2` 變數保存原順序，並在 `for` 迴圈中動態取極值，是非常正確且簡潔的做法。
- **變數隔離：** 必須使用 `temp` 來替代 `i` 進行 3n+1 的運算，否則會破壞外層 `for` 迴圈的計數器 `i`。

## Code Structure
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n1,n2;	
	while(cin>>n1>>n2){ // 當(條件)符合就不斷執行 
		int max_count=0;
		for(int i=min(n1,n2);i<=max(n1,n2);i++){
			int temp=i;
			int count=1;
			while(temp!=1){	
				if(temp%2==0){
					temp=temp/2;
				}
				else{	
					temp=3*temp+1;
				}
				count++;
			} 
			// 用 while 才能重複執行
			if(count>max_count){
				max_count=count;
			}
		}
		cout<<n1<<" "<<n2<<" "<<max_count<<endl;
	}
	return 0;
}
