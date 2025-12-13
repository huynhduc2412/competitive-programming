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
int teeth[1001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q;cin>>n>>q;
    rep(i,1,n+1) teeth[i] = 1;
    rep(_,0,q){
        int t; cin>>t;
        if(teeth[t]){
            teeth[t]--;
            n--;
        }
        else{
            teeth[t]++; n++;
        }
    }
    cout<<n;
    return 0;
}
