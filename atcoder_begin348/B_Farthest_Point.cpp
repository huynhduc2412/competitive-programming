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
    array<int,2>a[n];
    rep(i,0,n) cin>>a[i][0]>>a[i][1];
    rep(i,0,n){
        double mx = 0,id = -1;
        rep(j,0,n){
            if(i == j) continue;
            auto [x,y] = a[i];
            auto [x1,y1] = a[j];
            double dis = sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1));
            if(dis > mx){
                id = j;
                mx = dis;
            }
        }
        cout<<id+1<<"\n";
    }
    return 0;
}
