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
unordered_map<int,pair<int,int>>dp[2];
unordered_map<int,pair<bool,int>>mp;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,t; cin>>n>>t;
    vector<array<int,2>>a;
    rep(i,0,t){
        int x; cin>>x;
        a.push_back({x,i+1});
    }
    sort(all(a));
    int ans = 1e9;
    rep(i,0,t){
        if((a[i][0] - 1) % n != 0) dp[0][a[i][0]] = {dp[0][a[i][0] - 1].first + 1 , max(dp[0][a[i][0] - 1].second , a[i][1])};
        else dp[0][a[i][0]] = {1 , a[i][1]};
        dp[1][a[i][0]] = {dp[1][a[i][0] - n].first + 1 , max(dp[1][a[i][0] - n].second , a[i][1])};
        mp[a[i][0]] = {true , a[i][1]};
    }
    bool ch = true;
    int id = 0;
    rep(i,1,n+1){
        if(mp[n* (i - 1) + n - i + 1].first == false){
            ch = false ; break;
        }
        id = max(id , mp[n* (i - 1) + n - i + 1].second);
    }
    if(ch) ans = min(ans , id);
    ch = true , id = 0;
    rep(i,1,n+1){
        if(mp[n* (i - 1) + i].first == false){
            ch = false ; break;
        }
        id = max(id , mp[n* (i - 1) + i].second);
    }
    if(ch) ans = min(ans , id);
    rep(i,0,2){
        for(auto x : dp[i]){
            if(x.second.first == n) ans = min(ans , x.second.second);
        }
    }
    cout<<(ans >= 1e9 ? -1 : ans);
    return 0;
}
