#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool arr[110][110];
int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        for (int j = x + 1; j < x + 11; j++)
        {
            for (int k = y + 1; k < y + 11; k++)
            {
                arr[j][k] = true;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= 100; ++i)
    {
        for (int j = 1; j <= 100; j++)
        {
            if (arr[i][j])
                ans += 1;
        }
    }
    cout << ans;
}