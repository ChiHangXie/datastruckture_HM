#include <iostream>
#include <string>

using namespace std;

void arg(string a, string mark, string current){
    if(current.length() == a.length()) {
        cout << current << endl;
        return;
    }
    
    for(int i = 0; i < a.length(); i++){
        if(mark[i] == '0'){
            mark[i] = '1';
            arg(a, mark, current + a[i]);
            mark[i] = '0'; // backtrack
        }
    }
}

void arrangment(string a){
    string mark(a.length(), '0');
    arg(a, mark, "");
}

int main()
{
    string Str;
    cin >> Str;
    cout << "arrangement: \n";
    arrangment(Str);
}
