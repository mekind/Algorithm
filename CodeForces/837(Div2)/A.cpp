#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

int testcase;
int arr[200010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> testcase;
    while (testcase--)
    {
        ll n;
        cin >> n;
        for (ll i = 0LL; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr, arr + n);

        int a = arr[0];
        int b = arr[n - 1];
        if (a == b)
        {
            cout << n * (n - 1) << "\n";
            continue;
        }
        ll cnt1 = 0LL, cnt2 = 0LL;

        for (int i = 0; i < n; i++)
        {
            if (a == arr[i])
            {
                cnt1++;
            }
            if (b == arr[i])
            {
                cnt2++;
            }
        }
        cout << cnt1 * cnt2 * 2LL << "\n";
    }
}