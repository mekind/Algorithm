#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Drink
{
    long long E;
    long long C;
};

long long N, ans;
Drink drinks[5010];
bool drunk[5010];

void sol(long long left_count, long long total)
{
    if (left_count > N)
        return;

    long long ret = -10000000000LL;
    int idx = -1;
    for (long long i = 0; i < N; ++i)
    {
        if (drunk[i])
            continue;
        long long now = drinks[i].E - drinks[i].C * (left_count - 1LL);
        if (now > ret)
        {
            ret = now;
            idx = (int)i;
        }
        if (now == ret && drinks[i].C < drinks[idx].C)
        {
            idx = (int)i;
        }
        cout << left_count << " " << idx << " " << ret << "  dd\n";
    }
    if (idx == -1)
        return;

    drunk[idx] = true;

    ans = max(ans, ret + total);
    cout << left_count << "  " << ans << "  ans\n";
    sol(left_count + 1, ret + total);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; ++i)
        cin >> drinks[i].E;
    for (int i = 0; i < N; ++i)
        cin >> drinks[i].C;

    sol(1LL, 0LL);
    int
            cout
        << ans << "\n";
}