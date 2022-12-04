#include <iostream>
#include <algorithm>
using namespace std;

int arr[110], cnt;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, v;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    cin >> v;

    for (int i = 0; i < N; i++)
    {
        if (v == arr[i])
            cnt++;
    }

    cout << cnt;
}