# 作業題一：阿克曼函數

## 題目說明

題目要求實作遞迴與迴圈版的阿克曼函數

### 程式思路

程式主要難處是如何把原本就是遞迴的函數用迴圈重現。
程式裡使用了堆疊來模擬遞迴堆疊，其作用在每次處裡最上面的而 m!=0、n!=0 時會多推入額外的 m-1 然後再其 m=0 時順著堆疊往下遞增的值。

## 程式實作

### interative version
```cpp
#include <iostream>
#include <stack>
using namespace std;

int ackermann(unsigned int m,unsigned int n){
    
    stack<unsigned int>stk; // 宣告一個"stk" 裝uint的stack
    stk.push(m);
    
    while(!stk.empty()){
        
        m=stk.top();
        stk.pop();
        
        if(m==0){
            n+=1;
        }else if(n==0){
            stk.push(m-1);
            n=1;
        }else{
            stk.push(m-1);
            stk.push(m);
            n-=1;
        }
    }
    return n;
}
```

### recrusive version

```cpp
#include <iostream>
using namespace std;

unsigned long int ackermann(unsigned long int m,unsigned long int n){
    
    if(m==0){
        return n+1;
    }else if(n==0){
        return ackermann(m-1,1);
    }else{
        return ackermann(m-1,ackermann(m,n-1));
    }
}
```

## 效能分析

由於阿克曼函數有兩個引數所以下面是每個 m 對 n 的效能分析。
* m = 0 時效能是 O(n)。
* m = 1 時效能是 O(n)。
* m = 2 時效能是 O(n)。
* m = 3 時效能是 O(2<sup>n</sup>)。
* m = 4 時效能已經到了 O(2<sup>…<sup>2</sup></sup>) 省略是表示 2 平方 n 次。
* m = 5 時效能已經成為了天文數字硬要計算會是 Ω(2<sup>…<sup>2</sup></sup>) 省略是表示 2 平方 n 次。
效能成長的不可思議的速度同時包夸了時間、堆疊所需位置等 m = 5 幾乎不可算。
