#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N,M,R;
vector<int> edge[100010];

int ans[100010];
int cnt;

void sol(int now){
    queue<int> q;
    q.push(now);
    while(!q.empty()){
        now = q.front();
        q.pop();
        if(ans[now]) continue;
        
        ans[now] = cnt++;
        for (int i = 0; i < edge[now].size(); i++)
        {
            int next = edge[now][i];
            if(!ans[next]){
                q.push(next);
            }
        }
        
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>M>>R;

    for (int i = 0; i < M; i++)
    {
        int a,b;
        cin>>a>>b;

        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    for (int i = 1; i <= N; i++)
    {
        sort(edge[i].begin(), edge[i].end());
    }
    cnt=1;
    sol(R);

    for (int i = 1; i <= N; i++)
    {
        cout<<ans[i]<<"\n";
    }
    


}