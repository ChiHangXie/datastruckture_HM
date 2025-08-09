# 多項式實作
## 成果截圖
以下是 main 裡的程式
```cpp
int main(){
    int x;
    Polynomial a,b;
    std::cout << "輸入 A :\n";
    std::cin >> a;
    std::cout << "輸入 B :\n";
    std::cin >> b;
    std::cout << "\nA + B = " << a+b << "\nA - B = " << a-b << "\nA * B = " << a*b << "\n請輸入x";
    std::cin >> x;
    std::cout << "A(x) = " << a.Evaluate(x);
}
```
以下為執行結果 : 
![image](https://github.com/ChiHangXie/datastruckture_HM/blob/main/HM3/polynomial/%E8%9E%A2%E5%B9%95%E6%93%B7%E5%8F%96%E7%95%AB%E9%9D%A2%202025-08-10%20031421.png)

## polynomial成員函數效能分析
1. \>> 運算子 :  <br>
時間複雜度 : O(n<sup>2</sup>) | n = 最終串列長度  <br>
因要處理同指數的多項式項所以最糟糕的情況會從頭跑道尾端，所以複雜度計 O(n<sup>2</sup>)。  <br>
空間複雜度 : O(1)
沒有會成長的空間需求。 <br> <br>
2. << 運算子 :  <br>
時間複雜度 : O(n) | n = 串列長度  <br>
<< 運算子沒有額外多呼叫其他函式所以沒有更多消耗時間成長故整體複雜度計 O(n)。  <br>
空間複雜度 : O(1)
沒有會成長的空間需求。 <br> <br>
3. \= 運算子 :  <br>
時間複雜度 : O(n) | n = 串列長度  <br>
\= 運算子中雖有額外呼叫 releaseAll 與 getNode 但兩個函式都是 O(1) 所以複雜度是 O(n) 根據串列長度成長。  <br>
空間複雜度 : O(n) | n = 串列長度  <br>
最差的情況每一項都要要求一個 Node 的空間所以複雜度是 O(n) 根據串列長度成長。 <br> <br>
4. \+ 運算子 :  <br>
時間複雜度 : O(n<sup>2</sup>) | n = 最終串列長度  <br>
\+ 運算子有額外呼叫 insertOrCombine O(n) 又因為它複雜度 O(n) 的迴圈裡面所以在所以複雜度計 O(n<sup>2</sup>)。  <br>
空間複雜度 : O(n) | n = 串列長度  <br>
最差的情況每一項都要要求一個 Node 的空間所以複雜度是 O(2n) 省略2複雜度計做 O(n)。 <br> <br>
5. \- 運算子 :  <br>
時間複雜度 : O(n<sup>3</sup>) | n = 最長串列長度  <br>
\* 運算子同 \+ 運算子額外呼叫 insertOrCombine O(n) 又因為它的複雜度是 O(n) 的迴圈裡面所以複雜度計 O(n<sup>2</sup>)。  <br>
空間複雜度 : O(n) | n = 串列長度  <br>
最差的情況每一項都要要求一個 Node 的空間所以複雜度是 O(n<sup>3</sup>) 省略2複雜度計做 O(n)。 <br> <br>
6. \* 運算子 :  <br>
時間複雜度 :  O(n<sup>3</sup>) | n = 最長串列長度  <br>
\* 運算子一樣有有額外呼叫 insertOrCombine O(n) 又因為它複雜度 O(n<sup>2</sup>) 的迴圈裡面所以複雜度計 O(n<sup>3</sup>)。  <br>
空間複雜度 : O(n<sup>3</sup>) | n = 最長串列長度  <br>
最差的情況每一項都要要求一個 Node 的空間所以複雜度是 O(n<sup>3</sup>)。 <br> <br>
7. Evaluate 方法 :  <br>
時間複雜度 :  O(n) | n = 串列長度  <br>
每一項都做一樣的動作所以複雜度計 O(n)。  <br>
空間複雜度 : O(1)  <br>
沒有額外要求空間。 <br> <br>
8. 包含 freeNode、 getNode、 releaseAll 的 available link list 管理函式 :  <br>
時間複雜度 : O(1)  <br>
這一些管理函示都只有固定步驟所以複雜度是 O(1)。
空間複雜度 : O(1)  <br>
這一些函式沒有會成長的空間需求。
9. insertOrCombine 方法 : <br>
時間複雜度 : O(n) | n = 串列長度 <br>
這個函示最差的情況會把串列重頭到尾跑一遍 O(n)。
空間複雜度 : O(1)  
此函式沒有會成長的空間需求。
