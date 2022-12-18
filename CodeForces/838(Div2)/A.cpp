#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int testcase;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> testcase;

    while (testcase--)
    {
        int n;
        cin >> n;
        int my_min = 30;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            sum += tmp;

            int cnt = 0;
            if (tmp % 2)
            {
                while (tmp % 2)
                {
                    tmp /= 2;
                    cnt++;
                }
            }
            else
            {
                while (tmp % 2 == 0)
                {
                    tmp /= 2;
                    cnt++;
                }
            }

            my_min = min(my_min, cnt);
        }

        if (sum % 2)
            cout << my_min << "\n";
        else
            cout << "0\n";
    }
}