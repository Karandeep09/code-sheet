#include <bits/stdc++.h>
using namespace std;
typedef pair<int ,int>PII;
const int Max=1e6+5;
bool visit[Max];
vector<PII>adj[Max];
int nodes,edges;

void Prim_Algorithm(int x){
priority_queue<PII>q;
int minimum_cost=0;
q.push({0,x});
while(!q.empty()){
PII curr_node=q.top();
q.pop();
int u=curr_node.second;
if(visit[u]==true)
continue;
visit[u]=true;
minimum_cost+=(-1*curr_node.first);
for(int i=0;i<adj[u].size();i++){
int x=adj[u][i].first;
int y=adj[u][i].second;
if(visit[x]==false)
q.push({-1*y,x});
}
}
cout<<minimum_cost;
}

int main() {
ios_base::sync_with_stdio(0); cin.tie(0);
cin>>nodes>>edges;
for(int i=0;i<edges;i++){
int u,v,weight;
cin>>u>>v>>weight;
adj[u].push_back({v,weight});
adj[v].push_back({u,weight});
}
Prim_Algorithm(1);
return 0;
}