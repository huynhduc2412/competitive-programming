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
    int n,m; cin>>n>>m;
    array<int,2>a[n+m];
    rep(i,0,n){
        cin>>a[i][0];
        a[i][1] = 0;
    }
    rep(i,n,m+n){
        cin>>a[i][0];
        a[i][1] = 1;
    }
    sort(a,a+n+m,[&](array<int,2>c,array<int,2>d){
        if(c[0] == d[0]) return c[1] < d[1];
        return c[0] < d[0];
    });
    rep(i,1,n+m){
        if(!a[i][1] && !a[i-1][1]) {
            cout<<"Yes"; return 0;
        }
    }
    cout<<"No";
    return 0;
}
