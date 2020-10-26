#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int Max = 1e5 + 5;
pair <ll, pair<int, int> > p[Max];
int root[Max];
int size[Max];
int nodes, edges;

void initialize(){
    for(int i = 0;i < Max;++i){
        root[i] = i;
        size[i]=1;
    }
}

int find_root(int x){
    if(root[x] != x)
      root[x]=find_root(root[x]);

    return root[x];
}

void union_set(int u, int v){
    int root_u = find_root(u);
    int root_v = find_root(v);
    if(root_u!=root_v){
   if(size[root_u]<size[root_v]){
   int temp=root_u; root_u=root_v; root_v=temp;
}
  root[root_v]=root_u;
  size[root_u]+=size[v];
}
}

ll kruskal_Algo()
{
    int u, v;
    ll cost, minimum_Cost = 0;
    for(int i = 0;i < edges;++i){
        u = p[i].second.first;
        v = p[i].second.second;
        cost = p[i].first;
        if(find_root(u) != find_root(v)){
            minimum_Cost += cost;
            union_set(u, v);
        }    
    }
    
    cout<<minimum_Cost<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    initialize();
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i){
         int x, y;
        ll weight;
        cin >> x >> y >> weight;
        p[i] = make_pair(weight, make_pair(x, y));
    }
    sort(p, p + edges);
    kruskal_Algo();
    return 0;
}