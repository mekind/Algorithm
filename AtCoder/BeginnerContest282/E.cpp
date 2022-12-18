#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int testcase;
int N, M;
int node[510];
ll arr[510];
priority_queue<pair<ll, pair<int, int>>> pq;

ll calculate(ll x, ll y)
{
    if (y == 0LL)
    {
        return 1LL;
    }
    if (y == 1)
    {
        return x;
    }
    ll ret = 0LL;
    ll nextx = (x * x) % M;
    if (y % 2)
        ret = calculate(nextx, y / 2) * x;
    else
        ret = calculate(nextx, y / 2);

    return ret % M;
}

void pre(int a)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = i + 1; j < a; j++)
        {
            ll xy = calculate(arr[i], arr[j]);
            ll yx = calculate(arr[j], arr[i]);
            ll dis = (xy + yx) % M;
            pq.push({dis, {i, j}});
            // cout << arr[i] << "   " << arr[j] << "  dadfasdf\n";
            // cout << xy << " " << yx << "  dddd\n";
            // cout << dis << "hiih\n";
        }
    }
}

ll my_find(ll a)
{
    if (node[a] == a)
        return a;
    if (node[a] == -1)
        return node[a] = a;

    return node[a] = my_find(node[a]);
}

bool my_union(ll a, ll b)
{
    ll pa = my_find(a);
    ll pb = my_find(b);

    if (pa == pb)
        return false;

    ll newp = min(pa, pb);
    ll newc = max(pa, pb);

    node[newc] = newp;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    memset(node, -1, sizeof(node));
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    pre(N);

    ll ans = 0;
    while (!pq.empty())
    {
        ll dis = pq.top().first;
        ll xx = pq.top().second.first;
        ll yy = pq.top().second.second;
        // cout << dis << "   " << xx << "  " << yy << "  dajdfh\n";
        pq.pop();
        if (my_union(xx, yy))
        {
            ans += dis;
        }
    }

    cout << ans;
}