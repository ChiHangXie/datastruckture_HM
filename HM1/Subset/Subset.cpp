#include<time.h>
#include <iostream>
#include <string>

using namespace std;

void sus(string& a, int digit,string& current){
    
    if(digit==a.length()){
        cout << current << '\n';
        return;
    }
    
    //digit exit
    current+=a[digit];
    sus(a,++digit,current);
    
    //digit un-exit
    current.pop_back();
    sus(a,digit,current);
}

void subset(string a){
    string b;
    sus(a, 0, b);
}

int main()
{
    int i=100;
    clock_t a,b,avg_time;
    string Str={"12345"};
    while(--i){
    cout << "conbination: \n";
    a=clock();
    subset(Str);
    b=clock();
    avg_time+=b-a;
    }
    avg_time = avg_time/100;
    cout << "time cause :" << avg_time/1000 << "." << avg_time%1000 << "s";
}
