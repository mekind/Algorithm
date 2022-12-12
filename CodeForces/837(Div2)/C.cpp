#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;

int testcase;
vector<int> v;
bool ch[100005];
int arr[100010];

void pre()
{
    ch[0] = ch[1] = true;
    for (int i = 2; i <= 100000; i++)
    {
        if (ch[i])
            continue;
        v.push_back(i);
        for (int j = 2 * i; j <= 100000; j += i)
        {
            ch[j] = true;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    pre();

    cin >> testcase;
    while (testcase--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);

        bool ans = false;

        for (int j = 0; j < v.size() && arr[n - 1] >= v[j]; j++)
        {
            int now = v[j];
            // cout << now << "  nod \n";
            bool already = false;
            for (int i = 0; i < n; i++)
            {
                // cout << now << "  " << arr[i] << "  ddd\n";
                if (arr[i] % now)
                    continue;
                if (already)
                {
                    ans = true;
                    break;
                }
                // cout << now << "  " << arr[i] << "  ddd\n";
                while (arr[i] % now != 0)
                {
                    arr[i] /= now;
                }
                already = true;
            }
            if (ans)
                break;
        }
        for (int i = 1; i < n; i++)
        {
            if (arr[i] == arr[i - 1])
                ans = true;
        }

        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}