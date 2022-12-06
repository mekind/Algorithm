#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long X, tmp;
    int N;

    cin >> X >> N;
    tmp = 0LL;
    for (int i = 0; i < N; ++i)
    {
        long long a, b;
        cin >> a >> b;
        tmp += a * b;
        // cout << tmp << "\n";
    }

    if (tmp == X)
    {
        cout << "Yes";
    }
    else
        cout << "No";
}