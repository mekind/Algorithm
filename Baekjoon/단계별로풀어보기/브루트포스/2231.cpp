#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

int N;

int sol(int a)
{
    int tmp = a;
    int ret = 0;
    while (tmp)
    {
        ret += (tmp % 10);
        tmp /= 10;
    }

    return a + ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    int ans = 0;
    for (int i = 1; i <= 1000000; ++i)
    {
        if (N == sol(i))
        {
            ans = i;
            break;
        }
    }

    cout << ans << "\n";
}