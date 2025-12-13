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
    string s; cin>>s;
    int l=0,r=0,e=0;
    for(int x:s){
        l += (x=='<');
        r += (x=='>');
        e += (x=='=');
    }
    if(!l || !r || l>1 || r>1 || (e+2) != sz(s)) cout<<"No";
    else cout<<"Yes";
    return 0;
}
