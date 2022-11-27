#include <iostream>
#include <string>
#include <string.h>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
long long ans, tmp;
long long my_min;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    my_min = 10000000000LL;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> tmp;
            ans += tmp;

            if (i + j == n + 1)
            {
                my_min = min(my_min, tmp);
            }
        }
    }

    cout << ans - my_min << "\n";

    return 0;
}
