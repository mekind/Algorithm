#include<iostream>
#include<vector>
#include<string.h>
#include<queue>
#include<algorithm>

using namespace std;

int testcase;
int V,E;
int arr[20010];
bool ans;

void sol(int now, vector<vector<int>> &edge, int ch){
    if(arr[now]!=-1) return;

    arr[now] =ch;

    for (int i = 0; i < edge[now].size(); i++)
    {
        int next = edge[now][i];
        if(arr[next] == ch) {
            ans = false;
            continue;
        }
        if(arr[next] == -1)
            sol(next, edge, 1-ch);
    }
    
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>testcase;

    while(testcase--){
        cin>>V>>E;
        memset(arr, -1,sizeof(arr));
        ans = true;
        vector<vector<int>> edge(V+1 , vector<int> (0, V+1));

        
        for (int i = 0; i < E; i++)
        {
            int u,v;
            cin>>u>>v;
            
            edge[u].push_back(v);
            edge[v].push_back(u);
        }

        for (int i = 1; i <= V; i++)
        {
            sol(i, edge, 1);
        }

        if(ans){
            cout<<"YES\n";
        }
        else   
            cout<<"NO\n";
        
    }
    
}
