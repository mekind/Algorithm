#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

#define MAX 123456

using namespace std;

int arr[300000];
int n;

void pre()
{

    for (int i = 2; i <= 2 * MAX; ++i)
    {
        if (!arr[i])
            continue;
        if (arr[i] == -1)
            arr[i] = 1;

        for (int j = i * 2; j <= 2 * MAX; j += i)
            arr[j] = 0;
    }

    arr[1] = 0;
    arr[0] = 0;
    for (int i = 2; i <= MAX * 2; ++i)
    {
        arr[i] += arr[i - 1];
    }

    // for (int i = 0; i <= 1000000; ++i)
    // {
    //     cout << i << "  " << arr[i] << "\n";
    // }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(arr, -1, sizeof(arr));

    pre();
    while (1)
    {
        cin >> n;
        if (!n)
            break;
        // cout << arr[n * 2] << " " << arr[n] << "   hi\n";
        cout << arr[n * 2] - arr[n] << "\n";
    }
}