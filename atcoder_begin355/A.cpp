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
    int a,b; cin>>a>>b;
    if(a == 1 && b == 2) cout<<3;
    else if(a == 2 && b == 3) cout<<1;
    else if(a == 2 && b == 1) cout<<3;
    else if(a == 1 && b == 3) cout<<2;
    else if(a == 3 && b == 1) cout<<2;
    else if(a == 3 && b == 2) cout<<1;
    else cout<<-1;
    return 0;
}
