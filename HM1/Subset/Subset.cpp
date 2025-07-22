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
    string Str;
    cin >> Str;
    cout << "conbination: \n";
    subseu(Str);
}
