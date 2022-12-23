#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;

        if (tmp)
            v.push_back(tmp);
        else
            v.pop_back();
    }

    int ans = 0;
    for (int i : v) ans += i;

    cout << ans;
}