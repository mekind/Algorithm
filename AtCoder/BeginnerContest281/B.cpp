#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

bool check_upper(char a)
{
    if ('A' <= a && a <= 'Z')
        return true;

    return false;
}

bool check_num(char a, bool first)
{
    if (first)
    {
        if ('1' <= a && a <= '9')
            return true;
        else
            return false;
    }
    if ('0' <= a && a <= '9')
        return true;

    return false;
}

string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> s;

    char start = s[0];
    char last = s.back();
    int len = s.length();
    if (len != 8)
    {
        cout << "No";
        return 0;
    }
    if (check_upper(start) && check_upper(last))
    {
        string num = s.substr(1, len - 2);

        for (int i = 0; i < num.length(); i++)
        {
            bool first = false;
            if (i == 0)
                first = true;
            if (check_num(num[i], first))
                continue;
            else
            {
                cout << "No";
                return 0;
            }
        }

        cout << "Yes";
        return 0;
    }
    cout << "No";
    return 0;
}