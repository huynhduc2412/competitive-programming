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
vector<array<ll,5>>adj[mxN+1];
ll dis[mxN+1];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m; cin>>n>>m;
    rep(i,0,m){
        ll a,b,c,d,e,f; cin>>a>>b>>c>>d>>e>>f;
        --e,--f;
        adj[f].push_back({a,b,c,d,e});
    }
    rep(i,0,n) dis[i] = -1;
    priority_queue<array<ll,2>,vector<array<ll,2>>>pq;
    dis[n-1] = LLONG_MAX;
    pq.push({LLONG_MAX,n-1});
    while(!pq.empty()){
        auto c = pq.top(); pq.pop();
        if(dis[c[1]]>c[0]) continue;
        for(auto x:adj[c[1]]){
            if(c[0]==LLONG_MAX){
                dis[x[4]] = (x[2]-1)*x[1]+x[0];
                pq.push({dis[x[4]],x[4]});
            }else{
                ll k = (c[0]-x[3]-x[0])/x[1];
                if(k<0) continue;
                ll t =k*x[1]+x[0];
                if(k>=x[2]) t=(x[2]-1)*x[1]+x[0];
                if(dis[x[4]]>t) continue;
                dis[x[4]] = t;
                pq.push({dis[x[4]],x[4]});
            }
        }
    }
    rep(i,0,n-1){
        if(dis[i]!=-1) cout<<dis[i]<<'\n';
        else cout<<"Unreachable\n";
    }
    return 0;
}
