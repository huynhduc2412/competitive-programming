#include <bits/stdc++.h>
#define ll long long
#define all(x) begin(x), end(x)
#define allr(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define vt_out(x) for(auto y:(x)) cout<<y<<" "
#define inp(a) for(auto &x:a) cin>>x
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define repv(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
const int mxN=2e5;
using namespace std;
void solve(){
    int n,K; cin>>n>>K;
    --K;
    int h[n]; inp(h);
    int H = h[K];
    sort(h , h+n);
    ll water = 1;
    rep(i,0,n){
        if(h[i] > H){
            water += abs(h[i] - H);
            if(water > h[i] || water - 1 > H){
                cout<<"no\n";
                return;
            }
            H = h[i];
        }
        
    }
    cout<<"yes\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
