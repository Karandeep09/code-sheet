#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int Max=1e5+5;
int root[Max];
int size[Max];
int nodes,edges;

void initialize()
{
    for(int i = 0;i < Max;++i){
        root[i] = i;
        size[i]=1;
    }
}

int find_root(int x){
	if(root[x]!=x)
	root[x]=find_root(root[x]);
	return root[x];
}
void union_set(int u, int v){
int root_u=find_root(u);
int root_v=find_root(v);
if(root_u!=root_v){
if(size[root_u]<size[root_v]){
int temp=root_u; root_u=root_v; root_v=temp;
}
root[root_v]=root_u;
size[root_u]+=size[v];
}
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
