#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string>
#include<functional>
#include<numeric>
#include <math.h>
#include <algorithm>
#include<bitset>
#include<unordered_map>
#include<ctime>
#include <cstring>
#define lowbit(x) (-x) & x
#define ll long long
#define MAX_N 6000

// const int N = 3e6;
using namespace std;    
const int mod = 1e9 + 7;
template<class A,class B>ostream&operator<<(ostream&out,const pair<A,B>&a){return out<<"("<<a.first<<","<<a.second<<")";}
template<class A>ostream&operator<<(ostream&out,const vector<A>&a){for(const A &it:a)out<<it<<" ";return out;}
template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}
ll __pow(ll x,ll y){
    ll res = 1;
    while(y){
        if(y&1)res = (res * x)%mod;
        y>>=1;
        x = (x * x)%mod;
    }
    return res;
}
ll cal(ll v1, ll v2){
    return v1*__pow(v2,mod-2)%mod;
}
ll C(int  x, int y){
    ll res = 1;
    for(int i = 1,j = x + 1; j <= y;j++, i++){
        res*=j;
        res/=i;
    }
    return res;
}
ll gcd(ll x, ll y){
    if(y == 0)return x;
    else return gcd(y, x%y);
}
struct node{
    int to, nxt, w;
}e[MAX_N << 2];
int head[MAX_N];
int tt = 0;
void add(int u, int v , int w){
    e[++tt].nxt = head[u];
    e[tt].to = v;
    e[tt].w = w;
    head[u] = tt;
}
vector<int>f;
int find(int x){
    if(x != f[x])return f[x] = find(f[x]);
    return f[x];
    
}   
void un(int u, int v){
    int fu = find(u);
    int fv = find(v);
    if(fu != fv)f[fu] = fv;
}
int dis[MAX_N];
int cnt[MAX_N];
bool SPFA(int s, int n){
    bool in_queue[MAX_N];
    memset(in_queue, 0, sizeof(in_queue));  
    queue<int>q;
    q.push(s);
    dis[s] = 0;
    while(!q.empty()){
        int u = q.front();
        if(cnt[u] > n)return false;
        q.pop();
        in_queue[u] = 0;
        for(int i = head[u]; i ; i = e[i].nxt){
            int v = e[i].to;
            int w = e[i].w;
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                if(!in_queue[v]){
                    in_queue[v] = 1;
                    cnt[v]++;
                    q.push(v);
                }
            } 
        }
    }
    return true;
}
void  solve(){  
    int n,m;
    cin>>n>>m;
    memset(dis, 127, sizeof(int) * (n + 1));
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0;  i < m ;++i){
        int u, v, w;
        cin>>u>>v>>w;
        add(v, u, w);
    }       
    for(int i = 1 ; i <= n; ++i){
        add(0, i, 0);
    }
    if(SPFA(0, n)){
        for(int i = 1; i <= n;++i)cout<<dis[i]<<" \n"[i == n];
        return ;
    }
    cout<<"NO"<<endl;
}   
int main(){ 
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int t;
    t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0 ;
}   
