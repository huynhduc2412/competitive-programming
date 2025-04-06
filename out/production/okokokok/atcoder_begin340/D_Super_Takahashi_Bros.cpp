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
vector<pair<int,int>>adj[mxN+1];
ll dis[mxN+1];
priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    rep(i,0,n-1){
        int a,b,c; cin>>a>>b>>c;
        --c;
        adj[i].push_back({i+1,a});
        adj[i].push_back({c,b});
    }
    memset(dis,0x3f,sizeof(dis));
    dis[0]=0;
    pq.push({0,0});
    while(!pq.empty()){
        ll c = pq.top().first; 
        int r = pq.top().second;
        pq.pop();
        if(dis[r]<c) continue;
        if(r==n-1){
            cout<<c;
            break;
        }
        for(auto x : adj[r]){
            if(dis[x.first]>x.second+c){
                dis[x.first]=c+x.second;
                pq.push({dis[x.first],x.first});
            }
        }
    }
    return 0;
}
