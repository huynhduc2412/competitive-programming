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
    int q; cin>>q;
    while(q--){
        int n,k; cin>>n>>k;
        ll a[n]; inp(a);
        ll dp[n+1][k+1];
        memset(dp,0x3f,sizeof(dp));
        dp[0][0]=0;
        rep(i,1,n+1){
            rep(j,0,k+1){
                ll mi=1e9+1;
                rep(c,0,k+1){
                    if(j+c<=k&&i+c<=n){
                        mi=min(mi,a[i+c-1]);
                        dp[i+c][j+c]=min(dp[i+c][j+c],dp[i-1][j]+mi*(c+1));
                    }else break;
                }
            }
        }
        cout<<*min_element(dp[n],dp[n]+k+1)<<'\n';
    }
    return 0;
}
