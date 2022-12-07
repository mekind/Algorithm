#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int n;
int arr[10010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        arr[tmp] += 1;
    }

    for (int i = 1; i <= 10000; ++i)
    {
        for (int j = 0; j < arr[i]; j++)
        {
            cout << i << "\n";
        }
    }
}