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
ll pref[mxN+1][2],suff[mxN+1][2];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    string t; cin>>t;
    ll c[n]; inp(c);
    suff[n-1][0] = 0;
    suff[n-1][1] = c[n-1];
    for(int i = n-2;i>=0;i--){
        if(t[i] == t[i+1]){
            suff[i][0] += suff[i+1][1];
            suff[i][1] += suff[i+1][0] + c[i];
        }else{
            suff[i][0] = suff[i+1][0];
            suff[i][1] = suff[i+1][1] + c[i];
        }   
    }
    pref[0][0] = 0;
    pref[0][1] = c[0];
    rep(i,1,n){
        if(t[i] == t[i-1]){
            pref[i][0] += pref[i-1][1];
            pref[i][1] += pref[i-1][0] + c[i];
        }else{
            pref[i][0] += pref[i-1][0];
            pref[i][1] += pref[i-1][1] + c[i];
        }
    }

    ll ans = LLONG_MAX;
    rep(i,0,n-1){
        if(t[i] == t[i+1]){
            ans = min(ans,pref[i][0] + suff[i+1][0]);
            ans = min(ans,pref[i][1] + suff[i+1][1]);
        }else{
            ans = min(ans,pref[i][0] + suff[i+1][1]);
            ans = min(ans,pref[i][1] + suff[i+1][0]);
        }
    }
    cout<<ans;
    return 0;
}