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
ll val[mxN+1];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m; cin>>n>>m;
    unordered_map<ll,int>mp;
    mp[0]+=n;
    while(m--){
        int a,b; cin>>a>>b;
        if(mp.find(val[a])!=mp.end()){
            mp[val[a]]--;
            if(!mp[val[a]]) mp.erase(val[a]);
        }
        val[a]+=b;
        mp[val[a]]++;
        cout<<sz(mp)<<'\n';
    }
    return 0;
}
