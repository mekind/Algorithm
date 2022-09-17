// 단순한 문제 (Small)
#include <iostream>

using namespace std;

int T, a, b, c;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while (T--)
    {
        int cnt = 0;
        cin >> a >> b >> c;
        for (int i = 1; i <= a; ++i)
        {
            for (int j = 1; j <= b; ++j)
            {
                for (int k = 1; k <= c; ++k)
                {
                    if (i % j == j % k && j % k == k % i)
                        cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
}