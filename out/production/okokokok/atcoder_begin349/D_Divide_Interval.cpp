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
vector<pair<ll,ll>>ans;
void dfs(ll L , ll R , ll l = 0 , ll r = 1LL<<60){
    if(L >= r || R <= l) return;
    if(L <= l && r <= R){
        ans.push_back({l,r}); return;
    }
    ll mid = (l+r) >> 1 ;
    dfs(L,R,l,mid);
    dfs(L,R,mid,r);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll L,R; cin>>L>>R;
    dfs(L,R);
    cout<<sz(ans)<<"\n";
    for(auto [l , r] : ans) cout<<l<<" "<<r<<"\n";
    return 0;
}
