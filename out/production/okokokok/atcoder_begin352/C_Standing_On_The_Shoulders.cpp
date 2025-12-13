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
    int n; cin>>n;
    array<ll,2>a[n];
    ll s = 0;
    rep(i,0,n){
        cin>>a[i][0]>>a[i][1];
        s += a[i][0];
    }
    ll mx = 0;
    rep(i,0,n){
        mx = max(mx , s - a[i][0] + a[i][1]);
    }
    cout<<mx;
    return 0;
}
