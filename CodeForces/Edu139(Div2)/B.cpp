#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <unordered_map>

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
        unordered_map<string, int> um;
        int n;
        string s;
        cin >> n;
        cin >> s;
        bool ans = false;
        string pre = "";
        for (int i = 0; i < n - 1; ++i)
        {
            string now = s.substr(i, 2);
            if (um.find(now) != um.end() && pre != now)
            {
                ans = true;
                // cout << now << "  hi\n";
                break;
            }
            um[now] = 1;
            if (pre == now)
            {
                pre = "";
            }
            else
                pre = now;
        }
        if (ans)
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }
}

/*
예외처리가 문제
abab

aaaa
*/