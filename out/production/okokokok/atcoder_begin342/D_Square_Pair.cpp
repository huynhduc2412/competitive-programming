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
vector<int>primes;
bool prime[mxN+1];
void sieve(int n){
    for(int i=2;i*i<=n;i++){
        if(prime[i]) continue;
        primes.push_back(i);
        for(int j=i*i;j<=n;j+=i) prime[j] = true;
    }
}
ll cnt[mxN+1];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    sieve(2e5);
    ll ans=0,cnt0=0;
    rep(i,0,n){
        int A; cin>>A;
        if(!A) cnt0++;
        else{
            for(int x:primes){
                if(x*x>A) break;
                while(A%(x*x)==0){
                    A/=(x*x);
                }
            }
            ans+=cnt[A]++;
        }
    }
    ll cnt = cnt0*(cnt0-1)/2;
    cout<<ans+(n-cnt0)*cnt0+cnt;
    return 0;
}