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
ll gcd(ll a,ll b){
    while(a){
        ll t = a%b;
        a = b;
        b = t;
    }
    return a;
}
ll lcm(int a, int b){
    return (a / gcd(a, b)) * b;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,m,k; cin>>n>>m>>k;
    ll l = min(n,m), r = 2e18;
    while(l<=r){
        ll mid = (l+r)/2;
        ll cnt = mid/n + mid/m - 2LL*(mid/lcm(n,m));
        if(cnt < k) l = mid+1;
        else r = mid-1;
    }
    cout<<l;
    return 0;
}
