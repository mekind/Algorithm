#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

long long n, m, ans;
multiset<long long> ms;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        long long tmp;
        cin >> tmp;
        ms.insert(tmp);
    }

    for (auto iter = ms.end(); iter != ms.end(); iter++)
    {
        if (*iter + *ms.begin() > m)
        {
            ans += 2 * (*iter);
            ms.erase(*iter);
        }
        else
            break;
    }
    long long tmp = 0LL;
    while (1)
    {
        auto now = ms.upper_bound(m - tmp);

        ans += *(now - 1);
        tmp = *now;
    }

    return 0;
}
