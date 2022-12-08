#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

string s;
int arr[15];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> s;
    int len = s.size();
    for (int i = 0; i < len; i++)
    {
        int now = s[i] - '0';
        arr[i] = now;
    }

    sort(arr, arr + len);

    for (int i = len - 1; i >= 0; --i)
    {
        cout << arr[i];
    }
}