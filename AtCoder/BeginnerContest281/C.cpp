#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

ll N, T;
ll arr[100010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> T;

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];

        arr[i] += arr[i - 1];
        // cout << arr[i] << " ";
    }

    T %= arr[N];
    int idx = 0;
    // cout << "\n"
    //      << T << "  dd\n";

    for (int i = 1; i <= N; i++)
    {
        if (arr[i - 1] < T && T < arr[i])
        {
            idx = i;
            T -= arr[i - 1];
            break;
        }
    }

    cout << idx << " " << T;
}