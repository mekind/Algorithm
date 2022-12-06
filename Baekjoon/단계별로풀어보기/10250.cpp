#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int testcase;
int H, W, N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> testcase;

    while (testcase--)
    {
        cin >> H >> W >> N;

        int ho = (N - 1) / H + 1;
        int level = (N - 1) % H + 1;

        string ans = "";

        if (level / 10)
        {
            ans.push_back('0' + level / 10);
        }
        ans.push_back('0' + level % 10);

        if (ho < 10)
        {
            ans.push_back('0');
            ans.push_back('0' + ho);
        }
        else
        {
            if (ho / 10)
            {
                ans.push_back('0' + ho / 10);
            }
            ans.push_back('0' + ho % 10);
        }

        cout << ans << "\n";
    }
}