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
    array<int,2>a[n];
    rep(i,0,n){
        cin>>a[i][0];
        a[i][1] = i;
    }
    sort(a,a+n);
    int mi = 1e9;
    set<pair<int,int>>ss;
    for(int i = 0 , j = 0 ; i < n ; i++){
        while(j < n && sz(ss) < k){
            if(!j) ss.insert({a[j][1],j});
            else if(a[j][0] - a[j-1][0] == 1) ss.insert({a[j][1],j});
            else{
                ss.clear();
                ss.insert({a[j][1],j});
                i = j - 1 , j++; break;
            }
            j++;
        }
        if(sz(ss) == k){
            mi = min(mi , ss.rbegin()->first - ss.begin()->first);
            ss.erase({a[i][1],i});
        }
    }
    cout<<mi;
    return 0;
}
