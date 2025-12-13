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
    int n,k; cin>>n>>k;
    int s = 0;
    int cnt = 0;
    rep(_,0,n){
        int x; cin>>x;
        if(s + x > k){
            cnt++;
            s = 0;
        }
        s += x;
    }
    if(s) cnt++;
    cout<<cnt;
    return 0;
}
