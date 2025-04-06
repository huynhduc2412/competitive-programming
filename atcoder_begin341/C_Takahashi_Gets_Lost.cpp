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
    int h,w,n; cin>>h>>w>>n;
    string t; cin>>t;
    string a[h]; inp(a);
    function<int(int,int,int)>go=[&](int i,int j,int c)->int{
        if(i<0||j>=w||i>=h||j<0||a[i][j]=='#') return 0;
        if(c==n) return 1;
        if(t[c]=='L') return go(i,j-1,c+1);
        if(t[c]=='R') return go(i,j+1,c+1);
        if(t[c]=='U') return go(i-1,j,c+1);
        return go(i+1,j,c+1);
    };
    int ans=0;
    rep(i,0,h){
        rep(j,0,w){
            if(a[i][j]=='.') ans+=go(i,j,0);
        }
    }
    cout<<ans;
    return 0;
}
