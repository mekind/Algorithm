#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string a,b;

int ci(char a){
    return a - '0';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>b;

    int aa,bb;

    aa = ci(a[0]) + ci(a[1])*10 + ci(a[2])*100;
    bb = ci(b[0]) + ci(b[1])*10 + ci(b[2])*100;

    cout<<max(aa,bb);
    
}