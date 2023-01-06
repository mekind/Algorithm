#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int N,M;
queue<int> q;
int ld[110], sn[110];
int arr[110];

void sol(int now){
    q.push(now);

    while(!q.empty()){
        now = q.front();
        q.pop();

        for (int i = 1; i < 7; i++)
        {
            int next = now+i;
            if(next>100) break;

            if(ld[next]){
                next = ld[next];
            }
            if(sn[next]){
                next = sn[next];
            }

            if(arr[next] > arr[now] + 1 ){
                q.push(next);
                arr[next] =arr[now] + 1;
            }
        }
        if(arr[100] != 100) break;
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>M;
    for (int i = 0; i < 101; i++)
    {
        arr[i] = 100;
    }
    
    for (int i = 1; i <= N; i++)
    {   
        int a,b;
        cin>>a>>b;
        ld[a] = b;
    }

    for (int i = 0; i < M; i++)
    {   
        int a,b;
        cin>>a>>b;
        sn[a] = b;
    }

    arr[1]=0;
    sol(1);

    cout<<arr[100];
}
