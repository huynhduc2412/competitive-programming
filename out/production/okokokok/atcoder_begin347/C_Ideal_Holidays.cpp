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
    int n,a,b; cin>>n>>a>>b;
    vector<int> d(n); inp(d);
    int w = a + b;
    rep(i,0,n) d[i] %= w;
    sort(all(d));
    d.push_back(d[0] + a +b);
    rep(i,0,sz(d)-1) if(d[i+1] - d[i] > b){
        cout<<"Yes"; return 0;
    }
    cout<<"No";
    return 0;
}