#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int dp[1010];
int arr[1010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    int idx = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i] = 1;

        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
                if (dp[idx] < dp[i]) {
                    idx = i;
                }
            }
        }
    }
    vector<int> ans;
    while (dp[idx] != 1) {
        ans.push_back(idx);
        for (int i = idx - 1; i >= 0; i--) {
            if (arr[idx] > arr[i] && dp[idx] - 1 == dp[i]) {
                idx = i;
                break;
            }
        }
    }
    ans.push_back(idx);
    cout << ans.size() << "\n";

    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << arr[ans[i]] << " ";
    }

    return 0;
}