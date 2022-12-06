#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int N;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;

    int ans = 1;
    int now = 1;
    int add = 6;
    for (int i = 1; i < 100000; ++i)
    {
        if (now >= N)
            break;
        now += add;
        add += 6;
        ans += 1;
    }
    cout << ans;
}