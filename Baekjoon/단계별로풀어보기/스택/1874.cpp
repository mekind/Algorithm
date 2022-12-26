#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;
    queue<int> arr;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        arr.push(tmp);
    }
    vector<char> ans;
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        if (i < arr.front()) {
            v.push_back(i);

            ans.push_back('+');
        } else if (i == arr.front()) {
            ans.push_back('+');
            ans.push_back('-');
            arr.pop();

            while (!v.empty() && v.back() == arr.front()) {
                v.pop_back();
                arr.pop();
                ans.push_back('-');
            }
        } else
            v.push_back(i);
    }

    if (!arr.empty())
        cout << "NO";
    else {
        for (char i : ans) {
            cout << i << "\n";
        }
    }

    return 0;
}