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
int dp[101][101];
int m,n;
string t;
vector<string>a[101];
int dfs(int ch,int i){
    if(ch == m) return 0;
    if(i == n) return INT_MAX/2;
    if(dp[ch][i] != -1) return dp[ch][i];
    int ans = INT_MAX/2;
    ans = min(dfs(ch,i+1),ans);
    rep(j,0,sz(a[i])){
        string d = a[i][j];
        int cx = 0, cy = ch;
        while(cy<m&&cx<sz(d)&&d[cx] == t[cy]) cx++,cy++;
        if(cx == sz(d)){
            ans = min(ans,1+dfs(cy,i+1));
        }
    }
    return dp[ch][i] = ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    m = sz(t);
    cin>>n;
    rep(i,0,n){
        int l; cin>>l;
        a[i].resize(l);
        inp(a[i]);
    }
    memset(dp,-1,sizeof(dp));
    int ans = dfs(0,0);
    cout<<((ans>=INT_MAX/2)?-1:ans);
    return 0;
}
