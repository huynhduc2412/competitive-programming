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
    array<int,2>a[n];
    rep(i,0,n) cin>>a[i][0]>>a[i][1];
    sort(a,a+n,[&](array<int,2>c , array<int,2>d){
        if(c[0] == d[0]) return c[1] < d[1];
        return c[0] < d[0];
    });
    ll ans = 0;
    rep(i,0,n){
        int l = i + 1 , r = n - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(a[mid][0] > a[i][1]) r = mid - 1;
            else l = mid + 1;
        }
        if(l > i) ans += (l - i - 1);
    }
    cout<<ans;
    return 0;
}
