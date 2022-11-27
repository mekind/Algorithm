#include <iostream>
#include <string>
using namespace std;

int testcase, n, a, b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> testcase;

    while (testcase--)
    {
        cin >> n >> a >> b;

        if (a > b)
        {
            cout << "1\n";
            continue;
        }
        if (n % a)
        {
            cout << n / a + 1 << "\n";
        }
        else
            cout << n / a << "\n";
    }

    return 0;
}
