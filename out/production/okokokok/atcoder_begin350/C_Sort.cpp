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
    rep(i,1,n+1) cin>>a[i];
    int i = 1;
    vector<pair<int,int>>ans;
    while(i <= n){
        if(a[i]  != i){
            ans.push_back({i,a[i]});
            swap(a[i],a[a[i]]);
        }else i++;
    }
    cout<<sz(ans)<<'\n';
    for(auto [f,s] : ans) cout<<f<<" "<<s<<'\n';
    return 0;
}
