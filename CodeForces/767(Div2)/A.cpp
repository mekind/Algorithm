#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> testcase;

    while (testcase--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            arr.push_back({tmp, -1});
        }

        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            arr[i].second = tmp;
        }

        sort(arr.begin(), arr.end());
        for (pair<int, int> i : arr) {
            if (i.first <= k) {
                k += i.second;
            } else {
                break;
            }
        }

        cout << k << "\n";
    }

    return 0;
}