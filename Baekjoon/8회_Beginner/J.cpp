#include <iostream>
#include <algorithm>
using namespace std;

int L, N, T, ans;
int S[110];
bool C[110]; // R true    , L false

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> L >> N >> T;

    for (int i = 0; i < N; ++i)
    {
        char a;
        cin >> S[i] >> a;
        if (a == 'R')
            C[i] = true;
        else
            C[i] = false;
    }

    for (int t = 0; t <= T; ++t)
    {
        for (int i = 0; i <= L; ++i)
        {
            int x = -1;
            int y = -1;
            for (int j = 0; j < N; ++j)
            {
                if (S[j] == i && x == -1)
                    x = j;
                else if (S[j] == i)
                    y = j;
            }
            if (x != -1 && y != -1)
            {
                ans += 1;
                C[x] = !C[x];
                C[y] = !C[y];
            }
            else if (x != -1 && (i == 0 || i == L))
            {
                C[x] = !C[x];
            }
        }
        for (int i = 0; i < N; ++i)
        {
            if (C[i])
                S[i] += 1;
            else
                S[i] -= 1;
        }
    }

    cout << ans << "\n";
}