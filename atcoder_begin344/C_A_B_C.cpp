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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,l; cin>>n;
    ll a[n]; inp(a);
    cin>>m; 
    ll b[m]; inp(b);
    cin>>l; 
    ll c[l]; inp(c);
    set<ll>s;
    rep(i,0,n){
        rep(j,0,m){
            rep(z,0,l){
                s.insert(a[i]+b[j]+c[z]);
            }
        }
    }
    int q; cin>>q;
    rep(i,0,q){
        ll x; cin>>x;
        cout<<((s.find(x)!=s.end())?"Yes":"No")<<'\n';
    }
    return 0;
}
