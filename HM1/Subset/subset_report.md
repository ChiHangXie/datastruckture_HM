# 作業題二：所有子集合

## 題目說明

題目要求給定一個字串，輸出字串的所有子集合。

### 程式思路

每一次呼叫函式時會遞迴呼叫兩次，分別是<ins>遞迴層數</ins>對應的<ins>字串值</ins>存在子集合中和不存在子集合中兩次。
函數執行時會把該次<ins>遞迴層數</ins>對應的<ins>字串值</ins>加入預輸出字串。
如果遞迴層數等於本來字串的常度便會把預輸出字串輸出。

## 程式實作

程式主體在sus(**Su**b**S**et)但用subset打包成更易用的一個引數的函式。

```cpp
#include <iostream>
#include <string>

using namespace std;

void sus(string& a, int digit,string& current){ //程式主體
    
    if(digit==a.length()){
        cout << current << '\n';
        return;
    }
    
    //digit exit
    current+=a[digit];
    sus(a,++digit,current);  //第一次遞迴呼叫
    
    //digit un-exit
    current.pop_back();
    sus(a,digit,current);    //第二次遞迴呼叫
}

void subset(string a){ // 函式打包
    string b;
    sus(a, 0, b);
}
```

## 效能分析
### 複雜度分析

如果有字串有n項，會遞迴呼叫 2<sup>(n+1)</sup> - 1 次其中一半是輸出用的呼叫所以其實分成結構建置的 2<sup>n</sup> - 1 和輸出發生的 2<sup>n</sup> 。
建置結構時用到 if , += , pop_back 算 O(1) 所以結構建置的複雜度是 O(1/*2<sup>n</sup> - 1)。
輸出時要輸出 0 到 n 長度的字串算最壞取 n 乘上先前的 2<sup>n</sup> 輸出的複雜度是 O(n/*2<sup>n</sup>)。
兩者取大的所以複雜度是 O(n/*2<sup>n</sup>)。

#### 時間複雜度分析

| 測試案例 | 字串長度 $n$ | 平均花費時間 |
|----------|--------------|----------|
| 測試一   | $n = 2$      | 0.0055 seconds |
| 測試二   | $n = 3$      | 0.0069 seconds |
| 測試三   | $n = 4$      | 0.0106 seconds |
| 測試四   | $n = 5$      | 0.0145 seconds |
| 測試五   | $n = 6$      | 0.0216 seconds |

#### 空間複雜度分析

由於整個程式的引數用的都是 string 的指標並沒有額外複製字串所以空間複雜度是 O(1)。
