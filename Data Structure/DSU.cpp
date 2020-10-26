#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int Max=1e5+5;
int root[Max];
int nodes,edges;

void initialize()
{
    for(int i = 0;i < Max;++i)
        root[i] = i;
}

int find_root(int x){
	if(root[x]!=x)
	root[x]=find_root(root[x]);
	return root[x];
}
void union_set(int u, int v){
int root_u=find_root(u);
int root_v=find_root(v);
if(root_u!=root_v)
root[root_u]=root_v;
}

int main() {
ios_base::sync_with_stdio(0); cin.tie(0);
initialize();
cin>>nodes>>edges;
for(int i=1;i<=edges;i++){
int u,v;
cin>>u>>v;
union_set(u,v);
}
for(int i=1;i<=nodes;i++)
cout<<root[i]<<" ";

return 0;
}
