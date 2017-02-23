// Program to print BFS traversal from a given source vertex. BFS(int s) 
// traverses vertices reachable from s.
#include<iostream>
#include <list>
#include <vector>

#define pb push_back

using namespace std;

vector<int> ver[1004];
bool visited[1004];
int dis[1004];

void solve(int n, int s)
{
	list<int> que;
	for(int i=0; i<=n; i++)
	{
		visited[i]= false;
		dis[i] = -1;
	}
	visited[s] = true;
	dis[s] = 0;
	que.pb(s);
	while(!que.empty())
	{
		int t = que.front();
		que.pop_front();
		
		
		for(int i=0; i<ver[t].size(); i++)
		{
			int x = ver[t][i];
			if(!visited[x])
			{
				visited[x]=true;
				dis[x] = dis[t] + 6;
//				cout<<x<<" "<<dis[x]<<"\n";
				que.pb(x);
			}
		}
	}
	for(int i=1; i<=n; i++)
	{
		if(i!=s)
		cout<<dis[i]<<" ";
	}
	cout<<"\n";
}
	


int main()
{
	ios::sync_with_stdio(0);

	int i,t,u,v,s,n,m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(i=0;i<=n;i++)
			ver[i].clear();
		
		for(i=0;i<m;i++)
		{
			cin>>u>>v;
			
			ver[u].pb(v);
			ver[v].pb(u);
		}
		
		cin>>s;
		solve(n,s);
	}
	return 0;
}