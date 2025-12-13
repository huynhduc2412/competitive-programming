#include <bits/stdc++.h>
#define ll long long
#define all(x) begin(x), end(x)
#define allr(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define vt_out(x) for(auto y:(x)) cout<<y<<" "
#define inp(a) for(auto &x:a) cin>>x
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define skip continue
const int mxN=2e5;
using namespace std;
int E[201][201],a[201][201];
int h,w,n,sx,sy,ex,ey;
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};
int dis[201][201];
void bfs(){
    rep(i,0,h) rep(j,0,w) dis[i][j] = -1e9;
    priority_queue<array<int,3>>q;
    dis[sx][sy] = 0;
    q.push({0,sx,sy});
    while(!q.empty()){
        auto [e,c,d] = q.top(); q.pop();
        if(dis[c][d] > e) skip;
        if(c == ex && d == ey) return;
        if(E[c][d]){
            rep(i,0,4){
                int x = dx[i] + c, y = dy[i] + d;
                if(x < 0 || y < 0 || h == x || y == w || a[x][y] == 1 || E[c][d] - 1 < 0 || e - 1 >= E[c][d] - 1 || E[c][d] - 1 <= dis[x][y] ) skip;
                dis[x][y] = E[c][d] - 1;
                q.push({E[c][d] - 1,x,y});
            }
        }
        if(e > 0){
            rep(i,0,4){
                int x = dx[i] + c, y = dy[i] + d;
                if(x < 0 || y < 0 || h == x || y == w || a[x][y] == 1 || e - 1 <= dis[x][y]) skip;
                dis[x][y] = e - 1;
                q.push({dis[x][y],x,y});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>h>>w;
    rep(i,0,h){
        rep(j,0,w){
            char x; cin>>x;
            if(x == 'S') sx=i,sy=j;
            if(x == '#') a[i][j]=1;
            if(x == 'T') ex=i,ey=j;
        }
    }
    cin>>n;
    rep(i,0,n){
        int x,y,e; cin>>x>>y>>e;
        E[x-1][y-1] = e;
    }
    if(!E[sx][sy]){
        cout<<"No"; return 0;
    }
    bfs();
    if(dis[ex][ey] >= 0){
        cout<<"Yes";
    }else cout<<"No";
    return 0;
}
