#include <bits/stdc++.h>
#define ll long long
#define all(x) begin(x), end(x)
#define allr(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define vt_out(x) for(auto y:(x)) cout<<y<<" "
#define inp(a) for(auto &x:a) cin>>x
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define repv(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
const int mxN=1e6;
using namespace std;
ll cnt[mxN + 550];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    rep(_,0,n){
        int x; cin>>x;
        cnt[x]++;
    }
    rep(i,1,mxN + 1) cnt[i] += cnt[i - 1];
    ll ans = 0;
    rep(i,1,mxN + 1){
        ll count = cnt[i] - cnt[i - 1];
        if(count == 0) continue;
        for(int k = 1 ; k * i <= mxN ; k++){
            ans += (cnt[min((k + 1) * i - 1,mxN)] - cnt[k * i - 1])*k*count;
            if(k == 1) ans -= count*count;
        }
        ans += ((count - 1) * count / 2); 
    }
    cout<<ans;
    return 0;
}
