#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int N, ans[1000010];
vector<pair<int, int>> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;

        if (arr.empty() || arr.back().first >= tmp)
            arr.push_back({tmp, i});
        else {
            while (!arr.empty() && arr.back().first < tmp) {
                ans[arr.back().second] = tmp;
                arr.pop_back();
            }
            arr.push_back({tmp, i});
        }
    }
    while (!arr.empty()) {
        ans[arr.back().second] = -1;
        arr.pop_back();
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}