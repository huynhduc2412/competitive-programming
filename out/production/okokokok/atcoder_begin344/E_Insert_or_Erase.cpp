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
int a[mxN+100];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    rep(i,1,n+1) cin>>a[i];
    map<int,int>prev,next;
    rep(i,1,n+1){
        prev[a[i]] = a[i-1];
        next[a[i]] = a[i+1];
    }
    int q; cin>>q;
    while(q--){
        int t; cin>>t;
        if(t == 1){
            int x,y; cin>>x>>y;
            next[y] = next[x];
            prev[next[x]] = y;
            next[x] = y;
            prev[y] = x;
        }else{
            int x; cin>>x;
            int p = prev[x] , nxt = next[x];
            if(!p){
                a[1] = nxt;
            }
            next[p] = nxt;
            prev[nxt] = p;
            prev.erase(x); next.erase(x);
        }
    }
    int h = a[1];
    while(h){
        cout<<h<<" ";
        h = next[h];
    }
    return 0;
}
