#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int testcase;
int N, M;
bool arr[35][35];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        string s;

        cin >> s;
        for (int j = 0; j < M; j++)
        {
            if (s[j] == 'o')
                arr[i][j] = true;
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
    {

        for (int j = i + 1; j < N; j++)
        {
            int cnt = 0;

            for (int k = 0; k < M; k++)
            {
                if (arr[i][k] || arr[j][k])
                    cnt++;
            }
            if (cnt == M)
                ans++;
        }
    }
    cout << ans;
}