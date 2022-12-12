#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;
typedef long long ll;

int N, M, K;
multiset<ll> L, R;
ll arr[200010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    ll sum = 0;
    ll tmp[M];
    for (int i = 0; i < M; i++)
    {
        tmp[i] = arr[i];
    }

    sort(tmp, tmp + M);
    for (int i = 0; i < M; i++)
    {
        if (i < K)
        {
            sum += tmp[i];
            L.insert(tmp[i]);
        }
        else
        {
            R.insert(tmp[i]);
        }
    }
    cout << sum << " ";

    for (int start = 1; start < N - M + 1; ++start)
    {
        int pre = start - 1;
        int next = start + M - 1;
        // cout << "\n dd" << pre << " " << arr[pre] << "   pre\n";
        // cout << next << " " << arr[next] << "   next\n";
        if (L.find(arr[pre]) != L.end())
        {
            // cout << "1\n";
            L.erase(L.find(arr[pre]));
            sum -= arr[pre];
            // cout << "\n pre " << arr[pre] << "  next  " << arr[next] << " sum " << sum << "  \n";
            L.insert(arr[next]);
            sum += arr[next];
            // cout << "\n pre " << arr[pre] << "  next  " << arr[next] << " sum " << sum << "  \n";
        }
        else
        {
            // cout << "2\n";
            R.erase(R.find(arr[pre]));
            R.insert(arr[next]);
        }

        ll a1 = *(L.rbegin());
        ll a2 = *(R.begin());
        if (!R.empty() && a1 > a2)
        {
            // cout << a1 << "  " << a2 << "  a1\n";

            L.erase(--L.end());
            R.erase(R.begin());
            L.insert(a2);
            sum -= a1;
            sum += a2;

            R.insert(a1);
        }
        cout << sum << " ";
    }
}
