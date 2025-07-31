# 多項式實作
## 程式架構
此實作把 polynomial 與 linklist 的程式模組化
> linklist 成員 :
>> 1. start指標  指向第一個node
>> 2. end指標  指向最後一個node
>> 3. insert(T)  在最後一項插入值
>> 4. delete(index)  刪除第index個節點

> polynomial 成員 :
>> 1. insert( polynomial_segment ) 方法 對this加入一項多項式
>> 2. Add( polynomial ) 方法 回傳 this + polynmial 
>> 3. Mult( polynomial ) 方法 回傳 this * polynmial
>> 4. Eval(int) 方法 回傳 this 帶入 int 的值
