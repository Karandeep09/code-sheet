#include <bits/stdc++.h>
using namespace std;
vector<int> adj[10001];
int ii;
void dfs(int v, int par){
	cout<<v<<" ";
	for(auto u: adj[v])
	 { 	if (u == par) continue;
		 dfs(u, v);
	 }
}
int main() {
	int n,u,v;
	cin>>n;  
	for(int i=0;i<n-1;i++)
	{ cin>>u>>v;
	  adj[u].push_back(v);
	  adj[v].push_back(u);
	} 
	dfs(1,-1);
	return 0;
}