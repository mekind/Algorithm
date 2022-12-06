#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

int N, ans;
bool visited[30];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        string s;
        cin >> s;
        bool ch = true;
        memset(visited, false, sizeof(visited));
        for (int j = 0; j < s.length(); ++j)
        {
            char now = s[j];
            if (visited[now - 'a'] && s[j - 1] != now)
                ch = false;
            visited[now - 'a'] = true;
        }
        if (ch)
            ans++;
    }

    cout << ans;
}