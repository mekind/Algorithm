#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
ll arr[3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (1) {
        cin >> arr[0] >> arr[1] >> arr[2];
        if (!arr[0] && !arr[1] && !arr[2]) return 0;

        sort(arr, arr + 3);

        if (arr[2] * arr[2] == arr[1] * arr[1] + arr[0] * arr[0])
            cout << "right\n";
        else
            cout << "wrong\n";
    }
}