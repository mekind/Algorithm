#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int N;
ll arr[55];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    cout << arr[0] * arr[N - 1];
}