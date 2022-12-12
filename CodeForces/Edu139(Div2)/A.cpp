#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

using namespace std;
typedef long long ll;

int testcase;

int arr[1000000];

bool is_ex(int a)
{
    int cnt = 0;
    while (a)
    {
        int now = a % 10;
        a /= 10;
        if (now)
        {
            cnt++;
        }
    }
    return cnt < 2;
}

void pre()
{
    for (int i = 1; i <= 999999; ++i)
    {
        if (is_ex(i))
        {
            arr[i] = arr[i - 1] + 1;
        }
        else
            arr[i] = arr[i - 1];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> testcase;
    pre();
    while (testcase--)
    {
        int n;
        cin >> n;
        cout << arr[n] << "\n";
    }
}