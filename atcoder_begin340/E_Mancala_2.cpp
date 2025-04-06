#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
#define ll long long
#define all(x) begin(x), end(x)
#define allr(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define vt_out(x) for(auto y:(x)) cout<<y<<" "
#define inp(a) for(auto &x:a) cin>>x
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
const int mxN=2e5;
using namespace std;
using namespace atcoder;
ll op(ll f,ll x){return f+x;}
ll e(){return 0LL;}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m; cin>>n>>m;
    vector<ll>a(2*n,0);
    rep(i,0,n) cin>>a[i];
    lazy_segtree<ll,op,e,ll,op,op,e>seg(a);
    rep(_,0,m){
        int x; cin>>x;
        ll c=seg.get(x);
        ll c1=seg.get(x+n);
        seg.apply(x,x+1,-c);
        seg.apply(x+n,x+n+1,-c1);
        c+=c1;
        seg.apply(0,n,c/(ll)n);
        c%=n;
        int l=x+1;
        int r=c+x;
        seg.apply(l,r+1,1LL);
    }
    a.assign(n,0);
    rep(i,0,2*n) a[i%n]+=seg.get(i);
    rep(i,0,n) cout<<a[i]<<" ";
    return 0;
}
