#include <bits/stdc++.h>
#define ll long long
#define all(x) begin(x), end(x)
#define allr(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define vt_out(x) for(auto y:(x)) cout<<y<<" "
#define inp(a) for(auto &x:a) cin>>x
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
const int mxN=2e5;
ll T[mxN*4],a[mxN+1],delta[mxN*4];
void Build(int node,int l,int r){
    if(l==r){
        T[node]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    Build(node*2,l,mid);
    Build(node*2+1,mid+1,r);
    T[node]=T[node*2]+T[node*2+1];
}
void Update(int node,int l,int r,int u,int v,int w){
    if(r<u||l>v) return;
    if(l>=u&&v>=r){
        delta[node]+=w;
        T[node]+=w;
        return;
    }
    int mid=(l+r)>>1;
    Update(node*2,l,mid,u,v,w);
    Update(node*2+1,mid+1,r,u,v,w);
    T[node]=T[node*2]+T[node*2+1]+delta[node];
}
ll Get(int node,int l,int r,int u,int v){
    if(r<u||l>v) return LLONG_MAX;
    if(l>=u&&v>=r) return T[node];
    int mid=(l+r)>>1;
    ll L=Get(node*2+1,mid+1,r,u,v);
    ll R=Get(node*2,l,mid,u,v);
    return min(L,R)+delta[node];
}

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m; cin>>n>>m;
    rep(i,0,n) cin>>a[i];
    Build(1,0,n-1);
    rep(i,0,m){
        int x; cin>>x;
        int l=min((x+1)%n,(x+(int)a[x])%n);
        int r=max((x+1)%n,(x+(int)a[x])%n);
        Update(1,0,n-1,l,r,1LL);
    }
    rep(i,0,n) cout<<Get(1,0,n-1,i,i)<<" ";
    return 0;
}
