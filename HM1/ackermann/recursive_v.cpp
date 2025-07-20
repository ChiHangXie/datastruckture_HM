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

int main()
{
    while(1){
        unsigned long int m,n;
        cin >> m >> n;
        cout << ackermann(m,n);
    }
    

    return 0;
}
