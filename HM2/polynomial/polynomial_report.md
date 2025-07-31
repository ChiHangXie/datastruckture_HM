# 多項式實作
## 程式架構
此實作把 polynomial 與 linklist 的程式模組化  <br>
node 成員 : 
1. next指標
2. value  存值 是泛型變數  <br>

linklist 成員 :
1. start指標  指向第一個node
2. end指標  指向最後一個node
3. insert(T)  在最後一項插入值
4. delete(index)  刪除第index個節點
5. ~linklist()  解構函數  <br>

polynomial_segment :  <br>
1. \_exp  多項式指數值exp與韓式庫裡的東西打架所以加上\_
3. coef  多項式係數值

polynomial 成員 :
1. insert( polynomial_segment ) 方法 對this加入一項多項式
2. Add( polynomial ) 方法 回傳 this + polynmial 
3. Mult( polynomial ) 方法 回傳 this * polynmial
4. Eval(int) 方法 回傳 this 帶入 int 的值

## polynomial成員函數效能分析
1. insert :  <br>
時間複雜度 : O(n) | n = 串列長度  <br>
因要處理同指數的多項式項所以最糟糕的情況會從頭跑道尾端，所以複雜度計 O(n)。  <br>
空間複雜度 : O(1)
沒有會成長的空間需求。 <br> <br>
2. Add :  <br>
時間複雜度 : O(n<sup>2</sup>) | n = 串列長度  <br>
Add 要把相加的兩個串列都過一遍，由於使用了 insert 所以要考慮第二個串列加入時最差的情況。  <br>
insert 會在每個項加入時從頭到尾跑一遍於是加入兩個串列的複雜度是 n+2n<sup>2</sup> 整體複雜度計 O(n<sup>2</sup>)。  <br>
空間複雜度 : O(n) | 串列長度 <br>
Add 要求了一個新的 polynomial 佔存相加結果，最多要求 2n 複雜度計 O(n)。 <br> <br>
3. Mult :  <br>
時間複雜度 : O(n<sup>3</sup>) | n = 串列長度  <br>
Mult 用雙重迴圈把每一種組合都跑過了一遍，而每一個項都是用 insert 加入的考慮最極端的情況複雜度會是 n<sup>2</sup>(雙重迴圈)*n(insert) 整體複雜度計 O(n<sup>3</sup>)。  <br>
空間複雜度 : O(n<sup>2</sup>) | n = 串列長度  <br>
Mult 同 Add 宣告了一個佔存的 polynomial 而多項式相乘最多會有 n<sup>2</sup> 項，於是整體複雜度計 O(n<sup>2</sup>)。  <br>  <br>
4.Eval :  <br>
時間複雜度 : O(n) | n = 串列長度  <br>
Eval 把串列重頭到尾過一遍所以，所以複雜度計 O(n)。  <br>
空間複雜度 : O(1)  <br>
空間複雜度要求的空間只有一個指標與一個浮點數並不會變動所以複雜度是 O(1)。

