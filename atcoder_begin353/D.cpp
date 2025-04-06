#include <bits/stdc++.h>
#include <atcoder/modint>
#define ll long long
#define all(x) begin(x), end(x)
#define allr(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define vt_out(x) for(auto y:(x)) cout<<y<<" "
#define inp(a) for(auto &x:a) cin>>x
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
const int mxN=2e5;
using namespace std;
using mint = atcoder::modint998244353;
int cnt[11];
mint ps[11];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    ll a[n]; inp(a);
    rep(i,0,n){
        cnt[sz(to_string(a[i]))]++;
    }
    mint ans = 0;
    ps[0] = 1; 
    rep(i,1,11) ps[i] = mint(ps[i-1]*10);
    rep(i,0,n){
        cnt[sz(to_string(a[i]))]--;
        rep(j,1,11){
            ans += mint(ps[j]*a[i]*cnt[j]);
        }
        ans += mint(i*a[i]);
    }
    cout<<ans.val();
    return 0;
}
