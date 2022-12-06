#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int arr[6] = {1, 1, 2, 2, 2, 8};
    int a[6];
    for (int i = 0; i < 6; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < 6; ++i)
    {
        cout << arr[i] - a[i] << " ";
    }
    cout << "\n";
}