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
#ifndef ATCODER_INTERNAL_BITOP_HPP
#define ATCODER_INTERNAL_BITOP_HPP 1

#ifdef _MSC_VER
#include <intrin.h>
#endif

#if __cplusplus >= 202002L
#include <bit>
#endif

namespace atcoder {

namespace internal {

#if __cplusplus >= 202002L

using std::bit_ceil;

#else

// @return same with std::bit::bit_ceil
unsigned int bit_ceil(unsigned int n) {
    unsigned int x = 1;
    while (x < (unsigned int)(n)) x *= 2;
    return x;
}

#endif

// @param n `1 <= n`
// @return same with std::bit::countr_zero
int countr_zero(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

// @param n `1 <= n`
// @return same with std::bit::countr_zero
constexpr int countr_zero_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}

}  // namespace internal

}  // namespace atcoder

#endif  // ATCODER_INTERNAL_BITOP_HPP
#ifndef ATCODER_SEGTREE_HPP
#define ATCODER_SEGTREE_HPP 1

namespace atcoder {

#if __cplusplus >= 201703L

template <class S, auto op, auto e> struct segtree {
    static_assert(std::is_convertible_v<decltype(op), std::function<S(S, S)>>,
                  "op must work as S(S, S)");
    static_assert(std::is_convertible_v<decltype(e), std::function<S()>>,
                  "e must work as S()");

#else

template <class S, S (*op)(S, S), S (*e)()> struct segtree {

#endif

  public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
        size = (int)internal::bit_ceil((unsigned int)(_n));
        log = internal::countr_zero((unsigned int)size);
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

} 
// namespace atcoder

#endif  // ATCODER_SEGTREE_HPP
using namespace atcoder;
struct DATA
{
    int f,s, val,val1;
};
DATA op(DATA a,DATA b){
    DATA res ={0,0,0,0}; 
    if(a.f == b.f){
        res.f = a.f;
        res.val1 += a.val1 + b.val1;
        if(a.s < b.s){
            res.s = b.s;
            res.val = b.val;
        }else if(a.s == b.s){
            res.s = a.s;
            res.val += a.val + b.val;
        }else if(a.s > b.s){
            res.s = a.s;
            res.val = a.val;
        }
    }else if(a.f > b.f){
        res.f = a.f;
        res.val1 = a.val1;
        if(a.s > b.f){
            res.s = a.s; res.val += a.val;
        }else if(a.s == b.f){
            res.s = a.s; res.val += a.val + b.val1;
        }else if(a.s < b.f){
            res.s = b.f; res.val += b.val1;
        }
    }else if(a.f < b.f){
        res.f = b.f;
        res.val1 = b.val1;
        if(b.s > a.f){
            res.s = b.s; res.val += b.val;
        }else if(b.s == a.f){
            res.s = b.s; res.val += a.val1 + b.val;
        }else if(b.s < a.f){
            res.s = a.f; res.val += a.val1;
        }
    }
    return res;
}
DATA e() {
    return {0,0,0,0};
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q; cin>>n>>q;
    vector<DATA>a(n);
    rep(i,0,n) {
        cin>>a[i].f;
        a[i].s = 0; a[i].val = 0;  a[i].val1 = 1;
    }
    segtree<DATA,op,e>seg(a);
    while(q--){
        int t; cin>>t;
        if(t==1){
            int p,x; cin>>p>>x;
            --p;
            seg.set(p,{x,0,0,1});
        }else{
            int l,r; cin>>l>>r; 
            --l;
            cout<<seg.prod(l,r).val<<'\n';
        }
    }
    return 0;
}
