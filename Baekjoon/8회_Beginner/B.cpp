#include <iostream>
#include <algorithm>
#include <numeric>
#define ll long long
using namespace std;

typedef struct alarm
{
    ll start;
    ll sneeze;
};

ll N, D;
ll a, b;
ll ans;

ll sneeze_cnt_range(long long start, long long end, long long st)
{
    start += (start % st ? st - start % st : 0LL);
    if (start > end)
        return 0LL;
    ll aa = start / st;
    ll bb = end / st;
    return bb - aa + 1LL;
}

alarm alarms[1010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> D;

    for (int j = 0; j < N; ++j)
        cin >> alarms[j].start >> alarms[j].sneeze;

    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; j++)
        {
            ll nowa = sneeze_cnt_range(alarms[i].start, D, alarms[i].sneeze);
            ll nowb = sneeze_cnt_range(alarms[j].start, D, alarms[j].sneeze);
            ll nowc = sneeze_cnt_range(max(alarms[i].start, alarms[j].start), D, lcm(alarms[i].sneeze, alarms[j].sneeze));

            if (ans < nowa + nowb - nowc)
            {
                ans = nowa + nowb - nowc;
                // cout << nowa << " " << nowb << "  " << nowc << "   " << i << " " << j << "\n";
                a = i + 1;
                b = j + 1;
            }
        }
    }

    cout << a << " " << b << " \n";
    cout << ans << "\n";

    return 0;
}