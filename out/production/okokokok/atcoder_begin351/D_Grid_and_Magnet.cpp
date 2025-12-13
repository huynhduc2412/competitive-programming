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
bool vis[1001][1001];
char a[1001][1001];
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};
int h,w;
vector<array<int,2>>adj(int i,int j){
    vector<array<int,2>>res;
    rep(z,0,4){
        int x = dx[z] + i , y = dy[z] + j;
        if(x < 0 || y < 0 || y == w || x == h) continue;
        res.push_back({x,y});
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>h>>w;
    rep(i,0,h) rep(j,0,w) cin>>a[i][j];
    rep(i,0,h) rep(j,0,w){
        if(a[i][j] == '#') continue;
        for(auto [x,y] : adj(i,j)){
            if(a[x][y] == '#'){
                a[i][j] = '*'; break;
            }
        }
    }
    int ans = 1;
    set<pair<int,int>>set;
    queue<pair<int,int>>q;
    rep(i,0,h) rep(j,0,w){
        if(a[i][j] != '.' || vis[i][j] ) continue;
        int cnt = 1;
        set.clear();
        q.emplace(i,j);
        vis[i][j] = 1;
        while(!q.empty()){
            auto [c,d] = q.front(); q.pop();
            for(auto [e,f] : adj(c,d)){
                if(a[e][f] == '*'){
                    set.emplace(e,f);
                    continue;
                }
                if(a[e][f] == '#' || vis[e][f]) continue;
                vis[e][f] = 1;
                cnt++; q.emplace(e,f);
            } 
        }
        ans = max(ans,cnt + sz(set));
    }
    cout<<ans;
    return 0;
}