#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[510][510];
bool visited[510][510];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int ans;

bool pos(int a, int b)
{
    if (a < 0 || b < 0 || a >= n || b >= m)
        return false;
    else
        return true;
}

void sol(int a, int b, int cnt, int sum)
{
    if (!pos(a, b) || visited[a][b])
        return;
    if (cnt == 0)
    {
        ans = max(sum + arr[a][b], ans);
        // cout << a << " " << b << "  " << ans << "  ans  " << sum << "\n";
        return;
    }
    visited[a][b] = true;
    sum += arr[a][b];
    sol(a + 1, b, cnt - 1, sum);
    sol(a - 1, b, cnt - 1, sum);
    sol(a, b + 1, cnt - 1, sum);
    sol(a, b - 1, cnt - 1, sum);
    if (cnt == 2)
    {
        for (int i = 0; i < 4; i++)
            for (int j = i + 1; j < 4; ++j)
            {
                if (!pos(a + dx[i], b + dy[i]) || !pos(a + dx[j], b + dy[j]))
                    continue;
                if (visited[a + dx[i]][b + dy[i]] || visited[a + dx[j]][b + dy[j]])
                    continue;
                ans = max(ans, sum + arr[a + dx[i]][b + dy[i]] + arr[a + dx[j]][b + dy[j]]);
            }
    }
    visited[a][b] = false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> arr[i][j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            sol(i, j, 3, 0);
    cout << ans;
}