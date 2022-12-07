#include <iostream>
#include <algorithm>
using namespace std;

int N,ans;

int ch(int a){
    if (a==1 ) return 0;
    for(int i =2 ;i<a;++i){
        if(a%i == 0){
            return 0;
        }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    while(N--) {
        int a; 
        cin>>a;

        ans += ch(a);
    }
    cout<<ans;
    
}