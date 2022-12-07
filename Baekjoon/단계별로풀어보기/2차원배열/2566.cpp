#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int tmp;
int ans, a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> tmp;
            if (ans < tmp)
            {
                a = i;
                b = j;
                ans = tmp;
            }
        }
    }
    cout << ans << "\n";
    cout << a + 1 << " " << b + 1 << "\n";
}