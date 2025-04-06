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
    map<int,int>mp;
    rep(i,0,n){
        int a,c; cin>>a>>c;
        if(mp.find(c) != mp.end()){
            mp[c] = min(mp[c],a);
        }else mp[c] = a;
    }
    int mx = 0;
    for(auto [a,b] : mp) mx = max(b,mx);
    cout<<mx;
    return 0;
}
