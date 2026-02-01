#include <bits/stdc++.h>
#define ll long long
#define all(x) begin(x), end(x)
#define allr(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define vt_out(x) for(auto y:(x)) cout<<y<<" "
#define inp(a) for(auto &x:a) cin>>x
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define repv(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
const int mxN=2e5;
using namespace std;
int n,q;
int col[mxN + 1] , parent[mxN + 1];
ll total;
ll val[mxN + 1];
map<int,ll>sameColor[mxN + 1];
vector<array<int,2>>adj[mxN + 1];
void dfs(int u , int p = -1) {
    for(auto[v , c] : adj[u]) {
        if(v == p) continue;
        dfs(v , u);
        if(col[u] != col[v]) total += c;
        val[v] = c;
        sameColor[u][col[v]] += c;
        parent[v] = u;  
    }
}
void update(int x , int color) {
    if(x != 1) {
        if(col[parent[x]] == color && col[x] != color) total -= val[x];
        if(col[parent[x]] == col[x] && color != col[x]) total += val[x];
        sameColor[parent[x]][col[x]] -= val[x];
        sameColor[parent[x]][color] += val[x];
    }
    if(col[x] != color) {
        total -= sameColor[x][color];
        total += sameColor[x][col[x]];
    }
    col[x] = color;
}
void solve(){
    total = 0;
    rep(i,1,n + 1) {
        adj[i].clear();
        sameColor[i].clear();
        parent[i] = -1;
    }
    cin>>n>>q;
    rep(i,0,n) cin>>col[i + 1];
    rep(i,0,n-1) {
        int u,v,c; cin>>u>>v>>c;
        adj[u].push_back({v , c});
        adj[v].push_back({u , c});
    }
    dfs(1);
    while(q--) {
        int u,c; cin>>u>>c;
        update(u , c);
        cout<<total<<'\n';
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt; cin>>tt;
    while(tt--) solve();
    return 0;
}