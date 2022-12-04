#include <iostream>
#include <algorithm>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int N, M, ans;
char arr[2010][2010];
bool visited[2010][2010];

pair<int, int> start;
pair<int, int> end_point;

void input()
{
    cin >> N >> M;
    start.first = start.second = -1;
    end_point.first = end_point.second = -1;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> arr[i][j];
            if (i == 0 || j == 0 || i == N - 1 || j == M - 1)
            {
                if (arr[i][j] == '.')
                {
                    if (start.first == -1)
                    {
                        start.first = i;
                        start.second = j;
                    }
                    else
                    {
                        end_point.first = i;
                        end_point.second = j;
                    }
                }
            }
        }
    }
}

bool is_bound(int x, int y)
{
    if (x < 0 || x >= N || y < 0 || y >= M)
        return false;

    return true;
}

bool sol(int x, int y, int path_len)
{
    // cout << x << "   " << y << " now\n";
    if (x == end_point.first && y == end_point.second)
    {
        visited[x][y] = true;
        return true;
    }
    visited[x][y] = true;
    bool suc = false;
    for (int i = 0; i < 4; i++)
    {
        int nextx = x + dx[i];
        int nexty = y + dy[i];

        if (is_bound(nextx, nexty) && !visited[nextx][nexty] && arr[nextx][nexty] == '.')
        {
            suc |= sol(nextx, nexty, path_len + 1);
        }
    }
    if (suc)
    {
        return suc;
    }
    arr[x][y] = '@';
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    sol(start.first, start.second, 0);

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (!visited[i][j] && arr[i][j] == '.')
            {
                cout << "@";
            }
            else
                cout << arr[i][j];
        }
        cout << "\n";
    }
}