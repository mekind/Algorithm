#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int N, arr[100010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    int Q;

    cin >> Q;

    while (Q--) {
        int n, k;

        cin >> n >> k;

        if (n == 1) {
            int x;
            cin >> x;

            arr[k] = x;
        } else {
            cout << arr[k] << "\n";
        }
    }

    return 0;
}