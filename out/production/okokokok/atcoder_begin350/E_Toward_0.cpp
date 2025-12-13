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
    ll n,a,x,y; cin>>n>>a>>x>>y;
    cout<<fixed<<setprecision(15);
    map<ll,long double>dp;
    function<long double(ll)>f=[&](ll N)->long double{
        if(N == 0 ) return 0;
        if(dp.find(N) != dp.end()) return dp[N];
        long double op1 = x + f(N/a);
        long double op2 = y*1.2;
        rep(i,2,7) op2 += f(N/i)/5;
        return dp[N] = min(op2 , op1);
    };
    cout<<f(n);
    return 0;
}
