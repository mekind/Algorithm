#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

using namespace std;
typedef long long ll;

int cnt;

int recursion(const char *s, int l, int r)
{
    cnt++;
    if (l >= r)
        return 1;
    else if (s[l] != s[r])
        return 0;
    else
        return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char *s)
{
    return recursion(s, 0, strlen(s) - 1);
}

int testcase;
char s[1010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> testcase;

    while (testcase--)
    {
        cin >> s;
        cnt = 0;
        cout << isPalindrome(s) << " " << cnt << "\n";
    }
}