#include <bits/stdc++.h>
#define ll long long
#define all(x) begin(x), end(x)
#define allr(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define vt_out(x) for(auto y:(x)) cout<<y<<" "
#define inp(a) for(auto &x:a) cin>>x
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
const int mxN=1e6;
using namespace std;
struct node
{
    int child[26];
    int val[26];
}nodes[mxN+550];
int curr;
ll ans;
void insert(string t){
    int pos = 0;
    for(char x : t){
        if(nodes[pos].child[x-'a'] == -1){
            nodes[pos].child[x-'a'] = (++curr);
        }
        ans += nodes[pos].val[x-'a']++;
        pos = nodes[pos].child[x-'a'];
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    string a[n]; inp(a);
    rep(i,0,1e6){
        memset(nodes[i].child,-1,sizeof(nodes[i].child));
        memset(nodes[i].val,0,sizeof(nodes[i].val));
    }
    rep(i,0,n) insert(a[i]);
    cout<<ans;
    return 0;
}
// a ab abc