#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int n[10];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        cin >> n[i];
        sum += n[i];
    }

    sort(n, n + 5);

    cout << sum / 5 << "\n";
    cout << n[2] << "\n";
}