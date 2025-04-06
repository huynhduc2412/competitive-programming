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
    int n,k; cin>>n>>k;
    ll s = (1+k)*k/2;
    set<ll>set;
    rep(i,0,n){
        ll x; cin>>x;
        if(x > k ) continue;
        if(set.find(x) != set.end()) continue;
        set.insert(x);
        s-=x;
    }
    cout<<s;
    return 0;
}
