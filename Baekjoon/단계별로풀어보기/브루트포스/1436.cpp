#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

using namespace std;
typedef long long ll;

int cnt;
int ans;

bool jongmal(int a)
{
    int cont = 0;
    bool ret = false;
    while (a)
    {
        int tmp = a % 10;
        a /= 10;
        if (tmp == 6)
        {
            if (++cont == 3)
            {
                ret = true;
            }
        }

        else
            cont = 0;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 666; i <= 10000000 && cnt != n; ++i)
    {
        if (jongmal(i))
        {
            cnt++;
            ans = i;
        }
    }
    cout << ans;
}