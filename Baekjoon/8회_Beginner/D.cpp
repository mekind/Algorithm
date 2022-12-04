#include <iostream>
#include <algorithm>
#define DIV 1000000007
using namespace std;

int N;
long long arr[200010][5], ans;

void sol(int now)
{
    if (now > N)
        return;

    arr[now][1] = arr[now - 1][0] + arr[now - 1][3] + arr[now - 1][4];
    arr[now][2] = arr[now - 1][0] + arr[now - 1][4];
    arr[now][3] = arr[now - 1][0] + arr[now - 1][1];
    arr[now][4] = arr[now - 1][0] + arr[now - 1][1] + arr[now - 1][2];
    arr[now][0] = arr[now - 1][1] + arr[now - 1][2] + arr[now - 1][3] + arr[now - 1][4];

    for (int i = 0; i < 5; ++i)
    {
        arr[now][i] %= DIV;
    }
    sol(now + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    arr[1][0] = 1LL;
    arr[1][1] = 1LL;
    arr[1][2] = 1LL;
    arr[1][3] = 1LL;
    arr[1][4] = 1LL;
    sol(2);

    for (int i = 0; i < 5; ++i)
    {
        ans += arr[N][i];
    }

    cout << ans % DIV << "\n";
}