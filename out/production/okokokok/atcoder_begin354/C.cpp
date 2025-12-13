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
    int n; cin>>n;
    array<int,3>a[n];
    rep(i,0,n) {
        cin>>a[i][0]>>a[i][1];
        a[i][2] = i;
    }
    sort(a,a+n,[&](array<int,3> c , array<int,3> d){
        return c[0] < d[0];
    });
    vector<int>st;
    rep(i,0,n){
        while(!st.empty() && a[st.back()][0] < a[i][0] && a[st.back()][1] > a[i][1]) st.pop_back();
        st.push_back(i);
    }
    sort(all(st),[&](int c,int d){
        return a[c][2] < a[d][2];
    });
    cout<<sz(st)<<'\n';
    for(int x : st) cout<<a[x][2]+1<<" ";
    return 0;
}
