#include <bits/stdc++.h>
#include <atcoder/segtree>
#define ll long long
#define all(x) begin(x), end(x)
#define allr(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define vt_out(x) for(auto y:(x)) cout<<y<<" "
#define inp(a) for(auto &x:a) cin>>x
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
const int mxN=5e5;
using namespace std;
using namespace atcoder;
int op(int a,int b) {return max(a,b);}
int e() {return 0;}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,d; cin>>n>>d;
    int x;
    segtree<int,op,e>seg(mxN+1);
    rep(_,0,n){
        cin>>x;
        int l=max(x-d,1);
        int r=min(x+d+1,mxN+1);
        seg.set(x,seg.prod(l,r)+1);
    }
    cout<<seg.all_prod();
    return 0;
}
