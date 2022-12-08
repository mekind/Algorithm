#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

ll n;
ll arr[500010];
ll avg, mid, many, range;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for (ll i = 0LL; i < n; i++)
    {
        cin>>arr[i];
        avg+=arr[i];
    }

    sort(arr, arr+n);
    bool ch = false;
    if (avg < 0)
    {
        ch = true;
        avg = abs(avg);
    }
    
    avg = avg<<1;
    avg/=n;
    avg = (avg>>1) + (avg&1LL);
    if(ch)
        avg = 0LL- avg;
    
    ll mid_idx = n>>1;
    mid = arr[mid_idx];

    int many_cnt =0;
    bool two =true;
    for (ll i = 0; i < n; i++)
    {
        int now_cnt = 0;
        for (ll j = i; arr[j] ==arr[i]; j++)
        {
            now_cnt +=1;
        }
        i+=now_cnt-1;
        if (many_cnt == now_cnt && two){
            many = arr[i];
            two = false;
        }
        if(many_cnt < now_cnt){
            many = arr[i];
            many_cnt = now_cnt;
            two=true;
        }

    }
    

    range = arr[n-1] - arr[0];
    cout<<avg<<"\n";
    cout<<mid<<"\n";
    cout<<many<<"\n";
    cout<<range <<"\n";
};