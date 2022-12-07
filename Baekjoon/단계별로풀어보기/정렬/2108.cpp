#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;
ll n, arr[500010];
ll sum = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    for (ll i = 0LL; i < n; i++)
    {
        cin >> arr[i];

        sum += arr[i];
    }
    sort(arr, arr + n);

    bool p = false;
    if (sum < 0)
        p = true;
    sum = abs(sum);
    ll avg = sum << 1;
    avg /= n;
    ll da = 0LL;

    if (avg & 1)
        avg = (avg >> 1) + 1LL;
    else
        avg = (avg >> 1);
    if (p)
        avg = 0 - avg;
    int cnt = 0;
    bool two = false;

    for (int i = 0; i < n; ++i)
    {
        ll now = arr[i];
        int now_cnt = 0;
        for (ll j = i;; j++)
        {

            if (now != arr[j])
                break;
            now_cnt += 1;
        }
        if (now_cnt == now)
        {
            if (two)
            {
                da = now;
                two = false;
            }
        }
        if (now_cnt > now)
        {
            cnt = now_cnt;
            da = now;
            two = true;
        }
    }

    cout << avg << "\n";
    cout << arr[(int)(n >> 1)] << "\n";
    cout << da << "\n";
    cout << arr[n - 1] - arr[0] << "\n";
}