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
vector<int>adj[5001];
ll dp1[5001],dp[5001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m; cin>>n>>m;
    rep(i,0,m){
        int u,v; cin>>u>>v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }
    int W[n]; inp(W);
    vector<int>id(n);
    iota(all(id),0);
    sort(all(id),[&](int a,int b){
        return W[a]<W[b];
    });
    rep(i,0,n){
        memset(dp1,0,sizeof(dp1));
        for(int x:adj[id[i]]){
            if(W[x]<W[id[i]]){
                for(int j=W[id[i]]-W[x]-1;j>=0;j--){
                    dp1[j+W[x]] = max(dp1[j+W[x]], dp1[j]+dp[x]);
                    dp[id[i]] = max(dp[id[i]],dp1[j+W[x]]);
                }
            }
        }
        dp[id[i]]++;
    }
    ll ans=0;
    rep(i,0,n){
        int x; cin>>x;
        ans+=dp[i]*x;
    }
    cout<<ans;
    return 0;
}
