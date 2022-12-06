#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string s;
int cnt, l;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> s;

    l = s.length();

    for (int i = 0; i < l; i++)
    {
        char now = s[i];

        if (now == 'c')
        {
            if (i == l - 1)
                cnt++;
            else if (s[i + 1] == '-' || s[i + 1] == '=')
            {
                cnt++;
                i += 1;
            }
            else
                cnt++;
        }
        else if (now == 'd')
        {
            if (i == l - 1)
                cnt++;
            else if (s[i + 1] == '-')
            {
                cnt++;
                i += 1;
            }
            else if (i < l - 2 && s[i + 1] == 'z' && s[i + 2] == '=')
            {
                cnt++;
                i += 2;
            }
            else
                cnt++;
        }
        else if (i < l - 1)
        {
            char next = s[i + 1];
            if (now == 'l' && next == 'j')
            {
                cnt++;
                i += 1;
            }
            else if (now == 'n' && next == 'j')
            {
                cnt++;
                i += 1;
            }
            else if (now == 's' && next == '=')
            {
                cnt++;
                i += 1;
            }
            else if (now == 'z' && next == '=')
            {
                cnt++;
                i += 1;
            }
            else
                cnt++;
        }
        else
            cnt++;
        // cout << now << "  " << cnt << "  hi" << i << "\n";
    }
    cout << cnt;
}