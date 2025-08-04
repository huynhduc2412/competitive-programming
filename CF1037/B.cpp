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
    int n,k; cin>>n>>k;
    int a[n]; inp(a);
    int ans = 0;
    for(int i = 0 , j = 0 ; j < n ; j++){
        if(!a[j] && j - i + 1 == k){
            ans++; i = j + 2;
            j++;
        }else if(a[j]){
            i = j + 1;
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
