#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;
typedef long long ll;

int arr[25];

int fibo(int a)
{
    int &ret = arr[a];
    if (ret != -1)
        return ret;

    return ret = fibo(a - 1) + fibo(a - 2);
}

int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    memset(arr, -1, sizeof(arr));
    arr[0] = 0;
    arr[1] = 1;
    cout << fibo(n);
}