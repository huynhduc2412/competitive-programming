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
    int a[n+1];
    rep(i,0,n){
        int x; cin>>x;
        a[x] = i;
    }
    int q; cin>>q;
    rep(_,0,q){
        int c,d; cin>>c>>d;
        if(a[c]<a[d]) cout<<c;
        else cout<<d;
        cout<<'\n';
    }
    return 0;
}
