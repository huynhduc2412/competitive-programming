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
    int n,K; cin>>n>>K;
    array<int,3>a[n];
    rep(i,0,n) cin>>a[i][0]>>a[i][1]>>a[i][2];
    sort(a , a + n , [&](array<int,3> x , array<int,3> y){
        if(x[2] == y[2]){
            if(x[1] == y[1]) return x[0] < y[0];
            return x[1] < y[1];
        }
        return x[2] < y[2];
    });
    int ans = K;
    rep(i,0,n){
        if(ans >= a[i][2]) continue;
        if(a[i][0] > ans || a[i][1] < ans) continue;
        ans = a[i][2];
    }
    cout<<ans<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
