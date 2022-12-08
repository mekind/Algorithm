#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

int N;
vector<string> words[55];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string tmp;
        cin >> tmp;
        int l = tmp.length();
        words[l].push_back(tmp);
    }

    for (int i = 1; i < 55; i++)
    {
        sort(words[i].begin(), words[i].end());
        string pre = "";
        for (int j = 0; j < words[i].size(); j++)
        {
            if (pre == words[i][j])
                continue;
            cout << words[i][j] << "\n";
            pre = words[i][j];
        }
    }
}