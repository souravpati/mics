#include<bits/stdc++.h>
using namespace std;
#define max 1000000;
vector< vector< pair<int, int> > > adj(1000);
class graph{
	public:
	int v;

	//list<int >*wt;
	void addEdge(int v1,int v2,int wt1);
	int prims();
	graph(int v);
	
	};
 graph::graph(int v)
{
	this->v = v;
	vector< vector< pair<int, int> > >adj(v);
	//wt = new list<int>[v];
}
void graph::addEdge(int v1,int v2,int wt1)
{
	adj[v1].push_back(make_pair(v2,wt1));
	adj[v2].push_back(make_pair(v1,wt1));
	//wt[v1].push_back(wt1);
	//wt[v2].push_back(wt1);
}

int graph::prims()
{
	bool *visited;
	int *setmst,i,count,min,indx=0,last=0,j,sum=0;
	vector< pair<int, int> >::iterator it;
	visited = new bool[v];
	setmst = new int[v];
	for(i=0;i<v;i++)
	{setmst[i]=max;visited[i]=false;}
	
	setmst[0]=0;
	//visited[0]=true;
	for(i=1;i<=v;i++)
	{
		min= max;
		for(j=1;j<=v;j++)
		{
			if(min > setmst[j] && !visited[j])
			{
				indx = j;
				min = setmst[j];
			}
		}
		//printf("\n %d", indx);
		 visited[indx] = true;
		 for(it=adj[indx].begin();it!=adj[indx].end();it++)
		 {      //printf("\n %d %d",setmst[it->first],it->second);
		 	//cout <<indx <<" "<<*it <<" "<<setmst[*it] <<" " <<*itw<<endl;
		 	if(setmst[it->first] > it->second && !visited[it->first])
		 	{
		 		setmst[it->first] = it->second;
			}
		 }
		 
	}
	for(i=1;i<=v;i++)
	{//printf("\n %d",setmst[i]);
	sum = sum +setmst[i];}
	return sum;
}

int main() {
	
	graph *g;
	int n,m,i,v1,v2,t,j,wt;
   
	cin >>n>>m;
	g = new graph(n);

	 for(int i=1; i<=n; i++)
        {
           // SP[i] = inf;
            adj[i].clear();
        }
        
	 while(m--)
        {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            
            adj[a].push_back(make_pair(b, c));
            adj[b].push_back(make_pair(a, c));
        }
	cout << g->prims();
	
    
	return 0;
}
