#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
vector<int> prm;
bool ch[4000005];

void pre() {
    for (int i = 2; i < 4000002; i++) {
        if (!ch[i]) {
            prm.push_back(i);
            for (int j = i * 2; j < 4000002; j += i) {
                ch[j] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    pre();

    int N;

    cin >> N;

    int l = 0, r = 0;
    int p_size = prm.size();
    int ans = 0;
    int sum = prm[0];

    while (l <= r && r < p_size) {
        if (sum < N) {
            sum += prm[++r];
        } else if (sum > N) {
            sum -= prm[l++];
        } else {
            ans += 1;
            sum += prm[++r];
        }
    }

    cout << ans;
    return 0;
}