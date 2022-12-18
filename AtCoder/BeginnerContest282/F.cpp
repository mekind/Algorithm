#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int testcase;
int N, Q, L, R;
vector<pair<int, int>> v;

void pre(int n)
{
    for (int i = 1; i <= N; i *= 2)
    {
        for (int j = 1; j + i - 1 <= N; j++)
        {
            v.push_back({j, j + i - 1});
        }
    }
}

void sol(int l, int r)
{
    int start = 0, des = 0;
    int dis = 0;

    for (int i = 0; l + (1 << i) - 1 <= r; i++)
    {
        dis = i;
    }
    int cnt = 0;
    for (int i = 0; i < dis; i++)
    {
        cnt += N - (1 << i) + 1;
    }

    cout << cnt + l << " " << cnt + r - (1 << dis) + 1 << "\n";
    cout << flush;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;

    pre(N);

    cout << v.size() << "\n";

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second << "\n";
    }
    cout << flush;

    cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        int L, R;

        cin >> L >> R;

        sol(L, R);
    }

    return 0;
}