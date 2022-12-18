#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int testcase;
ll N, M;
vector<int> edge[200010];
set<int> family[200010];
bool visited[200010];
vector<pair<int, int>> resp;
ll alone;
bool pos;

void sol(int now, bool side, int r1, int r2)
{
    visited[now] = true;

    if (side)
        family[r1].insert(now);
    else
        family[r2].insert(now);

    for (int i = 0; i < edge[now].size(); i++)
    {
        int next = edge[now][i];
        if (!visited[next])
            sol(next, !side, r1, r2);
        else
        {
            if (side && family[r1].find(next) != family[r1].end())
            {
                pos = true;
            }
            if (!side && family[r2].find(next) != family[r2].end())
            {
                pos = true;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b;

        cin >> a >> b;

        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            if (edge[i].empty())
            {
                visited[i] = true;
                alone += 1;
                continue;
            }
            sol(i, true, i, edge[i][0]);
            resp.push_back({i, edge[i][0]});
        }
    }

    if (pos)
    {
        cout << "0";
        return 0;
    }

    ll ans = 0LL;
    ans += (N - 1) * alone;
    for (int i = 0; i < resp.size(); ++i)
    {
        int a1 = resp[i].first;
        int b1 = resp[i].second;

        ll tmp1 = family[a1].size();
        ll tmp2 = family[b1].size();

        ans += tmp1 * (N - tmp1);
        ans += tmp2 * (N - tmp2);
    }
    ans >>= 1;
    ans -= M;
    cout << ans;
}