#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void bfs(int p, int n, int A[][8])
{
    cout<<p<<" ";
    int visited[n];
    for(int i=0; i<n; i++)
      visited[i]=0;
    visited[p]=1;
    queue<int>q;
    q.push(p);
    while(!q.empty())
    {
        int r = q.front();
        q.pop();
        for(int v=1; v<n; v++)
        {
            if(A[r][v]==1 && visited[v]==0)
            {
                cout<<v<<" ";
                visited[v]=1;
                q.push(v);
            }
        }
    }
}


void dfs(int p, int n, int A[][8])
{
    static int visited[8] = {0};
    if(visited[p]==0)
    {
        cout<<p<<" ";
        visited[p]=1;
        for(int i=1; i<n; i++)
        {
            if(A[p][i]==1)
                dfs(i,n,A);
        }
    }
}

int main()
{
    int A[8][8] = {
          {0,0,0,0,0,0,0,0},
          {0,0,1,1,1,0,0,0},
          {0,1,0,1,0,0,0,0},
          {0,1,1,0,1,1,0,0},
          {0,1,0,1,0,1,0,0},
          {0,0,0,1,1,0,1,1},
          {0,0,0,0,0,1,0,1},
          {0,0,0,0,0,1,0,0}
        };
    dfs(1,8,A);
    return 0;
}