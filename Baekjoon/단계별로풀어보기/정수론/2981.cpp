#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int N, arr[110];

void get_soinsu(int n) {
    int nn = sqrt(n);
    vector<int> ans;
    for (int i = 1; i <= nn; i++) {
        if (n % i == 0) {
            int ii = n / i;
            ans.push_back(i);
            if (i != ii) ans.push_back(ii);
        }
    }
    sort(ans.begin(), ans.end());

    for (int i : ans) {
        if (i == 1) {
            continue;
        }
        cout << i << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<int> v;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            v.push_back(abs(arr[i] - arr[j]));
        }
    }

    //  sort(v.begin(), v.end());
    int gg = v[0];

    for (int i = 1; i < v.size(); i++) {
        gg = gcd(gg, v[i]);
    }

    get_soinsu(gg);
}