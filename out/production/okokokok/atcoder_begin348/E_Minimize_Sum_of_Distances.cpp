#include <bits/stdc++.h>
#define ll long long
#define all(x) begin(x), end(x)
#define allr(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define vt_out(x) for(auto y:(x)) cout<<y<<" "
#define inp(a) for(auto &x:a) cin>>x
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
const int mxN=1e5;
using namespace std;
vector<int>adj[mxN+1];
ll s,f[mxN+1],c[mxN+1],cnt[mxN+1];
int n;
ll ans;
void dfs(int u = 1, int p = 0){
    cnt[u] = c[u];
    for(int x : adj[u]){
        if(x == p) continue;
        dfs(x,u);
        cnt[u] += cnt[x];
        f[u] +=  cnt[x] + f[x];
    }
}
void dfs2(int u = 1,int p = 0){
    for(int x : adj[u]){
        if(x == p) continue;
        f[x] = f[u] - cnt[x] + (s - cnt[x]);
        ans = min(ans,f[x]);
        dfs2(x,u);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    rep(i,0,n-1){
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    rep(i,1,n+1) cin>>c[i] , s+=c[i];
    dfs();
    ans = f[1];
    dfs2();
    cout<<ans;
    return 0;
}
