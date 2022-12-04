#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string s;
bool ans;
int pos;
int point = -1; // corner 0 1 center 2

void check_ans()
{
    if (point == -1 && pos > 20)
        ans = true;
    if (point == 0 && pos > 11)
        ans = true;
    if ((point == 1 && pos > 6))
        ans = true;
    if (point == 2 && pos > 3)
        ans = true;
}

void check_point()
{
    if (point == -1 && pos == 5)
    {
        pos = 0;
        point = 0;
    }
    if (point == -1 && pos == 10)
    {
        pos = 0;
        point = 1;
    }
    if ((point == 0 && pos == 3))
    {
        pos = 0;
        point = 2;
    }
}

int what(string a)
{
    int cnt = 0;
    for (int i = 0; i < 4; i++)
        if (s[i] == '0')
            cnt += 1;
    if (!cnt)
        return 5;
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int cnt = 0;

    while (cnt < 10)
    {
        while (1)
        {
            bool one_more = false;
            cin >> s;
            int now = what(s);
            pos += now;
            check_point();
            check_ans();

            if (now == 5 || now == 4)
                one_more = true;

            if (!one_more)
                break;
        }
        cnt += 1;
    }
    if (ans)
        cout << "WIN\n";
    else
        cout << "LOSE\n";
}