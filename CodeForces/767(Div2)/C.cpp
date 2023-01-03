#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int cnt[200010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> testcase;

    while (testcase--) {
        int n;
        cin >> n;
        memset(cnt, 0, sizeof(cnt));

        vector<int> arr;

        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            cnt[tmp] += 1;
            arr.push_back(tmp);
        }

        int now_max = -1;

        for (int i = 0; i < n; i++) {
            if (!cnt[i]) {
                break;
            }
            now_max = i;
        }
        set<int> ch;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (now_max == -1) {
                ans.push_back(0);
                continue;
            }
            if (now_max < arr[i]) {
                continue;
            }
            ch.insert(arr[i]);
            cnt[arr[i]] -= 1;

            if (ch.find(arr[i]) != ch.end() && ch.size() >= now_max + 1) {
                // cout << " got you " << now_max << "  \n";
                ans.push_back(now_max + 1);
                ch.clear();
                now_max = -1;
                for (int j = 0; j < n; j++) {
                    if (!cnt[j]) {
                        break;
                    }
                    now_max = j;
                }
                // cout << now_max << " next " << i << "   drrrr\n";
            }
        }

        cout << ans.size() << "\n";
        for (int i : ans) {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}