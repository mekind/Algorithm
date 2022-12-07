#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int M, N , ans_min, ans_sum;

int ch(int a){
    if (a==1 ) return 0;
    for(int i =2 ;i<min(a,100);++i){
        if(a%i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
        ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>M>>N;
    for(int i=M ; i<=N;++i) {
        if (ch(i)){
            if (!ans_min) ans_min= i;
            ans_sum+=i;
        }
    }
    if (!ans_min){
        cout<<"-1\n";
        return 0;
    }
    cout<<ans_sum<<"\n"<<ans_min;
    
}