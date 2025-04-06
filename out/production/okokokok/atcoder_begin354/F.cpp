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
void solve(){
    int n; cin>>n;
    int a[n]; inp(a);
    int L[n],R[n];
    rep(i,0,n) L[i] = R[i] = 0;
    vector<int>Ldp,Rdp;
    rep(i,0,n){
        int it = lower_bound(all(Ldp),a[i]) - Ldp.begin();
        if(it == sz(Ldp)) Ldp.push_back(a[i]);
        else Ldp[it] = a[i];
        L[i] = it;
    }
    for(int &x : a) x = -x;
    reverse(a,a+n);
    rep(i,0,n){
        int it = lower_bound(all(Rdp),a[i]) - Rdp.begin();
        if(it == sz(Rdp)) Rdp.push_back(a[i]);
        else Rdp[it] = a[i];
        R[i] = it;
    }
    reverse(R,R+n);
    int LIS = 0;
    rep(i,0,n) LIS = max(LIS , L[i]);
    vector<int>ans;
    rep(i,0,n) if(L[i] + R[i] == LIS) ans.push_back(i+1);
    cout<<sz(ans)<<'\n';
    vt_out(ans);
    cout<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}