#include <bits/stdc++.h>
#define ll long long
#define all(x) begin(x), end(x)
#define allr(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define vt_out(x) for(auto y:(x)) cout<<y<<" "
#define inp(a) for(auto &x:a) cin>>x
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
const int mxN=2e5;
using namespace std;
bool vis[mxN+1];
vector<int>adj[mxN+1];
ll v;
ll dfs(int u){
    v++;
    vis[u] = 1;
    ll res = sz(adj[u]);
    for(int x : adj[u]){
        if(vis[x]) continue;
        res += dfs(x);
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m; cin>>n>>m;
    rep(_,0,m){
        int u,v; cin>>u>>v;
         --u,--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll ans = 0;
    rep(i,0,n){
        if(!vis[i]){
            v = 0;
            ll ed = dfs(i);
            ans += (v*(v-1))/2  - ed /2  - ed % 2;
        }
    }
    cout<<ans;
    return 0;
}
