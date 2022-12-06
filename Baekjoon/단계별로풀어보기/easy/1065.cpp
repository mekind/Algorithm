#include <iostream>
#include <algorithm>
using namespace std;

bool is_hansu(int a)
{
    int pre = -1;
    int dif = -100;
    while (1)
    {
        int now = a % 10;
        if (pre != -1)
        {
            if (dif != -100 && dif != pre - now)
            {
                return false;
            }
            else
            {
                dif = pre - now;
            }
        }
        pre = now;
        a /= 10;
        if (!a)
        {
            break;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        if (is_hansu(i))
        {
            cnt++;
            // cout << i << " hansu\n";
        }
    }

    cout << cnt;
}