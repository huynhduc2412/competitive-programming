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
int a[3][3];
vector<vector<int>>grid;
bool check(int val ,int i,int j){
    if(i == j && grid[0][0] == val && grid[1][1] == val && grid[2][2] == val) return true;
    if(i + j == 2 && grid[0][2] == val && grid[1][1] == val && grid[2][0] == val) return true;
    if(grid[i][1] == val && grid[i][2] == val && grid[i][0] == val && grid[i][j] == val) return true;
    if(grid[1][j] == val && grid[0][j] == val && grid[2][j] == val && grid[i][j] == val) return true;
    return false;
}
map<vector<vector<int>>,bool>dp;
bool dfs(int ch){
    if(ch == 9){
        long s = 0;
        rep(i,0,3) rep(j,0,3){
            if(grid[i][j] == 2) s += a[i][j];
            else s -= a[i][j];
        }
        return s < 0;
    }
    if(dp.find(grid) != dp.end()) return dp[grid];
    bool win = false;
    rep(i,0,3) rep(j,0,3) if(!grid[i][j]){
        if(ch % 2 == 0){
            grid[i][j] = 2;
            if(check(2,i,j)){
                grid[i][j] = 0;
                return dp[grid] = true;
            }
        }else{
            grid[i][j] = 1;
            if(check(1,i,j)){
                grid[i][j] = 0;
                return dp[grid] = true;
            }
        }
        if(!dfs(ch+1)) win = true;
        grid[i][j] = 0;
    }
    return dp[grid] = win;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    grid.resize(3);
    rep(i,0,3) rep(j,0,3){
        cin>>a[i][j];
        grid[i].resize(3);
    }
    cout<<((dfs(0)) ? "Takahashi" : "Aoki");
    return 0;
}
