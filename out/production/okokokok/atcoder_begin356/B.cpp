#include <bits/stdc++.h>
#define ll long long
#define all(x) begin(x), end(x)
#define allr(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define vt_out(x) for(auto y:(x)) cout<<y<<" "
#define inp(a) for(auto &x:a) cin>>x
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define repv(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
const int mxN=2e5;
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m; cin>>n>>m;
    int a[m]; inp(a);
    int b[m];
    rep(i,0,m) b[i] = 0;
    rep(i,0,n){
        int x; 
        rep(j,0,m) { cin>>x;b[j] += x;}
    }
    rep(i,0,m) if(a[i] > b[i]){
        cout<<"No"; return 0;
    }
    cout<<"Yes";
    return 0;
}
