#include </bits/stdc++.h>

using namespace std;

int a[5001];
int ans =0;

int dfs(int v)
{
  if(v!=1 && a[v]==0)
    return 0;
  int left = dfs(2*v);
  int right = dfs(2*v+1);
  ans += abs(left-right);
  return (max(left,right)+a[v]);
}


void solve(int sz)
{
  dfs(1);
  cout<<ans;
}

int main()
{
  ios::sync_with_stdio(0);
  int i,j,k,m,t,s,e,n,u,v,w;
  cin>>n;
  int sz = 1<<(n+1);
  //cout<<sz<<endl;
  for(i=2;i<sz;i++)
  {
   cin>>a[i];
  }

  solve(sz);




} 