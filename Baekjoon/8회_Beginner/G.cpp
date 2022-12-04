#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <string.h>
using namespace std;

typedef struct Node
{
    int num;
    int nei_num;
};

int ans[100010];
int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    memset(ans, -1, sizeof(ans));

    for (int i = 0; i < N; ++i)
    {
        Node a, b;
        cin >> a.num >> b.num;

        a.nei_num = b.num;
        b.nei_num = a.num;
        a.nei.insert(b);
        b.nei.insert(a);
        Nodes.push(a);
        Nodes.push(b);
    }
    while (1)
    {
        if (Nodes.size() < 3)
            break;
        Node tmp[3];
        for (int i = 0; i < 3; ++i)
        {
            tmp[i] = Nodes.top();
            cout << tmp[i].nei_num << " ";
            Nodes.pop();
        }
        cout << "hi \n";

        if (tmp[2].nei_num != 1)
        {
            ans[0] = tmp[0].num;
            ans[1] = tmp[1].num;
            ans[2] = tmp[2].num;
        }
    }
}