#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int N, M, arr[2][110][110];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                cin >> arr[i][j][k];
            }
        }
    }

    for (int j = 0; j < N; j++)
    {
        for (int k = 0; k < M; k++)
        {
            cout << arr[0][j][k] + arr[1][j][k] << " ";
        }
        cout << "\n";
    }
}