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
vector<int>adj[mxN+1];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    ll a[n]; inp(a);
    ll s[n],t[n];
    rep(i,0,n) cin>>s[i]>>t[i];
    rep(i,0,n){
        ll x = a[i]/s[i];
        a[i+1]+=x*t[i];
    }
    cout<<a[n-1];
    return 0;
}
