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
ll op(ll a,ll b){return a+b;}
ll e(){ return 0LL;}
using namespace atcoder;
bool id[mxN+1];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q; cin>>n>>q;
    lazy_segtree<ll,op,e,ll,op,op,e>seg(n+2),remove(n+2);
    seg.apply(1,n+1,LLONG_MIN);
    remove.apply(1,n+1,LLONG_MIN);
    int cnt = 0;
    while(q--){
        int x; cin>>x;
        if(id[x]){
             id[x] = 0; cnt--;
             remove.set(x,0LL);
        }else{
            if(seg.get(x) < 0)   seg.set(x,0LL);
            else{
                ll r = remove.get(x);
                if(r > 0) {
                    seg.set(x,seg.get(x) - r);
                    remove.set(x,LLONG_MIN);
                }
            }
            id[x] = 1; cnt++;
        }
        seg.apply(1,n+1,cnt);
        remove.apply(1,n+1,cnt);
    }
    rep(i,1,n+1){
        ll d = seg.get(i);
        ll r = remove.get(i);
        if(d < 0){
            cout<<0<<" ";
            continue;
        }
        if(r > 0) d-=r;
        cout<<d<<" ";
    }
    return 0;
}
