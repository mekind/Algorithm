#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int A, B, C;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> A >> B >> C;

    if (B >= C)
    {
        cout << "-1";
        return 0;
    }

    int dif = C - B;

    int ans = A / dif + 1;

    cout << ans;
}