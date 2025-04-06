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
int n,h,w;
array<int,2>a[11];
bool grid[11][11];
bool solve(int ch){
    bool ans = 1;
    int tx,ty;
    rep(i,0,h){
            rep(j,0,w) if(!grid[i][j]){
            ans = 0;
            tx = i , ty = j;
            break;
        }
        if(!ans) break;
    }
    if(ans) return 1;
    if(ch == n) return 0;
    rep(_,0,2){
        bool ans1 = 1;
        if(tx+a[ch][0] <= h && ty+a[ch][1] <= w){
            rep(x,tx,tx+a[ch][0]){
                rep(y,ty,ty+a[ch][1]){
                    if(grid[x][y]){
                        ans1 = 0; break;
                    }
                }
                if(!ans1) break;
            }
            if(ans1){
                rep(x,tx,tx+a[ch][0]){
                    rep(y,ty,ty+a[ch][1]) grid[x][y] = 1;
                }
                ans |= solve(ch+1);
                if(ans) return ans;
                rep(x,tx,tx+a[ch][0]){
                    rep(y,ty,ty+a[ch][1]) grid[x][y] = 0;
                }
            }
        }
        swap(a[ch][0],a[ch][1]);
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>h>>w;
    rep(i,0,n) cin>>a[i][0]>>a[i][1];
    sort(a,a+n);
    do
    {   memset(grid,0,sizeof(grid));
        // rep(i,0,n) cout<<a[i][0]<<" "<<a[i][1]<<endl;
        // cout<<endl;
        if(solve(0)){
            cout<<"Yes"; return 0;
        }

    }while(next_permutation(a,a+n));
    cout<<"No";
    return 0;
}
