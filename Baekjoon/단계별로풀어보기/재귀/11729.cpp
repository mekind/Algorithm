#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

int N, K;
vector<pair<int, int>> ans;

void sol(int start, int des, int total)
{
    if (total == 1)
    {
        ans.push_back({start, des});
        return;
    }
    int mid = -1;
    for (int i = 1; i < 4; ++i)
    {
        if (i != start && i != des)
            mid = i;
    }
    sol(start, mid, total - 1);
    ans.push_back({start, des});
    sol(mid, des, total - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    sol(1, 3, N);
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
};