#include </bits/stdc++.h>
using namespace std;

#define pp pair<int,int>
#define pb push_back

vector<pp> ver[3004];
int dis[3004];

void solve(int n, int s)
{
	priority_queue <pp, vector<pp>, greater<pp>> pq;
	int i,u,d;
	for(i=0;i<=n;i++){
		dis[i] = INT_MAX;
	}
	dis[s] = 0;
	pq.push({0,s});
	while(!pq.empty()){
		pp t = pq.top();
		pq.pop();
		u = t.second;
		d = t.first;
		if(dis[u]<d)
      		continue;
    	for(i=0;i<ver[u].size();i++)
    	{
      		int v = ver[u][i].second;
      		int w = ver[u][i].first;
      		if(d+w>dis[v])
        		continue;
      		dis[v] = d+w;
      		pq.push({dis[v],v});
      	}

	}
	for(i=1;i<=n;i++){
		if(i!=s){
			if(dis[i]==INT_MAX)
				cout<<-1<<" ";
			else
				cout<<dis[i]<<" ";
		}
	
	}
	cout<<"\n";
}


int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0);

	int t,n,m,i,u,v,w,s;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(i=0;i<=n;i++)
			ver[i].clear();
		for(i=0;i<m;i++){
			cin>>u>>v>>w;

			ver[u].pb({w,v});
			ver[v].pb({w,u});
		}
		cin>>s;
		solve(n,s);	
	}

	return 0;
}