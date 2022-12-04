#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int x[3];
    cin >> x[0] >> x[1] >> x[2];
    sort(x, x + 3);

    if (x[0] == x[1] && x[1] == x[2])
    {
        cout << 1000 * x[0];
        return 0;
    }

    if (x[0] == x[1])
    {
        cout << 1000 + 100 * x[0];
        return 0;
    }

    if (x[1] == x[2])
    {
        cout << 1000 + 100 * x[1];
        return 0;
    }

    cout << 100 * x[2];
}