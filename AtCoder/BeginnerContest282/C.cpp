#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int testcase;
int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;

    cin >> N >> s;

    bool sstart = false;
    bool send = false;
    for (int i = 0; i < N; i++)
    {
        // cout << i << " " << sstart << " " << send << " dd\n";
        char now = s[i];
        if (now == '"')
        {
            if (!sstart)
            {
                sstart = true;
                continue;
            }

            if (!send)
            {
                send = true;
                continue;
            }

            if (sstart && send)
            {
                send = false;
                continue;
            }
        }
        if (!sstart && !send && now == ',')
            s[i] = '.';
        if (sstart && send && now == ',')
            s[i] = '.';
    }
    cout << s;
}