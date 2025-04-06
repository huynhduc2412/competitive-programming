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
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int dis[61][61][61][61];
priority_queue<pair<int,array<vector<int>,2>>,vector<pair<int,array<vector<int>,2>>>,greater<pair<int,array<vector<int>,2>>>>q;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    string a[n]; inp(a);
    vector<int>start,end;
    rep(i,0,n){
        rep(j,0,sz(a[i])) if(a[i][j]=='P'){
            if(start.empty()) start={i,j};
            else end={i,j};
        } 
    }
    memset(dis,0xf,sizeof(dis));
    dis[start[0]][start[1]][end[0]][end[1]]=0;
    q.push({0,{start,end}});
    while(!q.empty()){
        auto  c = q.top(); q.pop();
        if(c.second[0][0]==c.second[1][0]&&c.second[1][1]==c.second[0][1]){
            cout<<c.first;
            return 0;
        }
        int a1=c.second[0][0],b=c.second[0][1],d=c.second[1][0],e=c.second[1][1];
        if(c.first>dis[a1][b][d][e]) continue;
        rep(z,0,4){
            int x=dx[z]+a1,y=dy[z]+b;
            int x1=dx[z]+d,y1=dy[z]+e;
            if(x<0||y<0||x>=n||y>=n||a[x][y]=='#'){
                x=a1,y=b;
            }
            if(x1<0||y1<0||x1>=n||y1>=n||a[x1][y1]=='#'){
                x1=d,y1=e;
            }
            if(x==a1&&y==b&&x1==d&&y1==e) continue;
            if(dis[x][y][x1][y1]>dis[a1][b][d][e]+1){
                dis[x][y][x1][y1]=dis[a1][b][d][e]+1;
                vector<int>c1={x,y},d1={x1,y1};
                q.push({dis[x][y][x1][y1],{c1,d1}});
            }
        }
    }
    cout<<-1;
    return 0;
}
