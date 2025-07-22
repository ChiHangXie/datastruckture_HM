#include <iostream>
#include <string>

using namespace std;

void cbn(string& a, int digit,string& current){
    
    if(digit==a.length()){
        cout << current << '\n';
        return;
    }
    
    //digit exit
    current+=a[digit];
    cbn(a,digit+1,current);
    
    //digit un-exit
    current.pop_back();
    cbn(a,digit+1,current);
}

void conbination(string a){
    string b;
    cbn(a, 0, b);
}

int main()
{
    string Str;
    cin >> Str;
    cout << "conbination: \n";
    conbination(Str);
}
