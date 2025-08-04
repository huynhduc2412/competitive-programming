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
void solve(){
    int n; cin>>n;
    ll p[n] , s[n];
    inp(p); inp(s);
    ll a[n];
    rep(i,0,n) a[i] = lcm<ll>(p[i] , s[i]);
    ll gP = 0;
    rep(i,0,n){
        gP = gcd<ll>(a[i] , gP);
        if(gP != p[i]) {
            cout<<"no\n";
            return;
        }
    }
    ll gS = 0;
    repv(i,n-1,0){
        gS = gcd<ll>(a[i] , gS);
        if(gS != s[i]){
            cout<<"no\n";
            return;
        }
    }
    cout<<"yes\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
