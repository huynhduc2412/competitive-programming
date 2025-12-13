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
    int w,b; cin>>w>>b;
    string t = "wbwbwwbwbwbw";
    string s = "wbwbwwbwbwbw";
    rep(i,0,99) s += t;
    rep(i,0,sz(s)){
        int cntw = 0 , cntb = 0;
        rep(j,i,i+w+b){
            cntw += (s[j]=='w');
            cntb += (s[j]=='b');
        }
        if(cntw == w && cntb == b){
            cout<<"Yes"; return 0;
        }
    }
    cout<<"No";
    return 0;
}