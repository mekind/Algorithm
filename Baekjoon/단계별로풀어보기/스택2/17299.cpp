#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int N, cnt[1000010], ans[1000010];
vector<pair<int, int>> arr;
vector<int> arr2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        cnt[tmp] += 1;
        arr2.push_back(tmp);
    }

    for (int i = 0; i < N; i++) {
        int now = arr2[i];

        if (arr.empty() || cnt[arr.back().first] >= cnt[now])
            arr.push_back({now, i});
        else {
            while (!arr.empty() && cnt[arr.back().first] < cnt[now]) {
                ans[arr.back().second] = now;
                arr.pop_back();
            }
            arr.push_back({now, i});
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