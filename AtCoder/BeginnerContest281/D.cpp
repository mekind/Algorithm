#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

using namespace std;
typedef long long ll;

int N, K, D;

ll arr[110];
ll dp[105][105][105];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K >> D;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < K; j++)
        {
            for (int k = 0; k < D; k++)
            {
                if (dp[i][j][k] == -1)
                    continue;
                dp[i + 1]
            }
        }
    }
}