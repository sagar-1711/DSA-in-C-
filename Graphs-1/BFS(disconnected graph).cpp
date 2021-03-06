#include<iostream>
#include<queue>
using namespace std;
void BFShelper(int**edges,int n,int sv,bool*visited)
{
  queue<int> q;
  q.push(sv);
  visited[sv]=true;
  while(!q.empty())
  {
      int node=q.front();
      cout<<node<<" ";
      q.pop();
      for(int i=0;i<n;i++)
      {
          if(edges[node][i]==1 && visited[i]==false)
          {
              q.push(i);
              visited[i]=true;
          }
      }
    }
}
void BFS(int**edges,int n,bool*visited)
{
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
            BFShelper(edges,n,i,visited);
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    int**edges=new int*[n];
    for(int i=0;i<n;i++)
    {
        edges[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            edges[i][j]=0;
        }
    }
    int f,s;
    for(int i=0;i<e;i++)
    {
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    bool*visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    BFS(edges,n,visited);
}
