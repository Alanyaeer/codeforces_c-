#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;
const int N = 1e4 + 7, M = 3e5 + 7;
int idx = 1;
struct node{
    ll w, next, to;
}e[M];
int s, t;
int n,m;
int head[N], d[N];
int cur[N];
ll mf[N];
void add(int u, int v, ll w){
  e[++idx].next = head[u];
  e[idx].to = v;
  e[idx].w = w;
  head[u] = idx;
}
bool bfs(){
  memset(d, 0, sizeof(d));
  queue<int>q;
  q.push(s);
  d[s] = 1;
  while(q.size()){
    int u = q.front();
    q.pop();
    for(int i = head[u]; i ; i = e[i].next){
      int v = e[i].to;
      if(d[v] == 0 && e[i].w){
        d[v] = d[u] + 1;
        q.push(v);
        if(v == t)return true;
      }
    }
  }
  return false;
}
ll dfs(int u, ll mf){
  if(u == t)return mf;
  ll sum = 0;
  for(int i = cur[u]; i; i = e[i].next){
    cur[u] = i;
    int v = e[i].to;
    if(d[u] + 1 == d[v] && e[i].w){
      ll re = dfs(v, min(mf, e[i].w));
      e[i].w -= re;
      e[i ^ 1].w += re;
      sum += re;
      mf  -= re;
      if(mf == 0)break;
    }
  }
  if(sum == 0)d[u] = 0;
  return sum;
} 
ll Dinic(){
  ll flows = 0;
  while(bfs()){
    memcpy(cur, head, sizeof(head));
    flows += dfs(s, 1e9);
  }
  return flows;
}
int main(){
  cin>>n>>m>>s>>t;
  for(int i = 0; i < m;++i){
    ll u,v,w;
    cin>>u>>v>>w;
    add(u, v, w);
    add(v, u, 0);
  }
  cout<<Dinic();
  return 0;
}
