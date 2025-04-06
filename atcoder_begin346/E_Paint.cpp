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
bool row[mxN+1], col[mxN+1] ;
ll ans[mxN+1];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int h,w,m; cin>>h>>w>>m;
    array<int,3>a[m];
    rep(i,0,m) cin>>a[i][0]>>a[i][1]>>a[i][2];
    reverse(a,a+m);
    rep(i,0,m){
        auto [T,A,X] = a[i];
        if(T == 1){
            if(!row[A]){
                ans[X] += w;
                h--;
                row[A] = 1;
            }
        }else{
            if(!col[A]){
                ans[X] += h;
                w--;
                col[A] = 1;
            }
        }
    }
    if((ll)h*w > 0) ans[0] += (ll)w*h;
    int count = 0;
    rep(i,0,200001){
        if(!ans[i]) continue;
        count++;
    }
    cout<<count<<'\n';
    rep(i,0,200001){
        if(!ans[i]) continue;
        cout<<i<<" "<<ans[i]<<'\n';
    }
    return 0;
}
