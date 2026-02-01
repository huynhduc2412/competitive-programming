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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    double t; cin>>n>>t;
    string s; cin>>s;
    t += double(0.1);
    vector<array<int,2>>P(n);
    rep(i,0,n){
        cin>>P[i][0];
        P[i][1] = int(s[i] - '0');
    }
    sort(all(P));
    queue<int>pos;
    ll ans = 0;
    rep(i,0,n){
        if(P[i][1] == 0) {
            while(!pos.empty()){
                double T = double(abs(P[i][0] - pos.front()) / 2.0);
                if(T >= t) {
                    pos.pop();
                }else{
                    break;
                }
            }
            ans += sz(pos);
        }else{
            pos.push(P[i][0]);
        }
    }
    cout<<ans;
    return 0;
}
