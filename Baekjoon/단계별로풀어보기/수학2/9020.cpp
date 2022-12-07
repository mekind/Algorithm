#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

int n, testcase;
vector<int> v;
int arr[10010];

void pre()
{

    for (int i = 2; i <= 10000; ++i)
    {
        if (!arr[i])
            continue;
        if (arr[i] == -1)
        {
            v.push_back(i);
            arr[i] = 1;
        }

        for (int j = i * 2; j <= 10000; j += i)
            arr[j] = 0;
    }

    arr[1] = 0;
    arr[0] = 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> testcase;
    memset(arr, -1, sizeof(arr));
    pre();

    sort(v.begin(), v.end());
    while (testcase--)
    {
        cin >> n;
        int ans = 0;
        for (int i = 0; i < v.size(); ++i)
        {
            int now = v[i];
            int now1 = n - v[i];
            if (now > now1)
                break;
            if (arr[now1] == 1)
            {
                ans = max(ans, now);
            }
        }
        cout << ans << " " << n - ans << "\n";
    }
}