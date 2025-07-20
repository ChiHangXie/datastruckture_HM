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

int main()
{
    unsigned int m,n;
    while(1){
        cin >> m >> n;
        cout << "A(" << m << " ," << n << " ) = " << ackermann(m,n) << "\n";
    }
}
