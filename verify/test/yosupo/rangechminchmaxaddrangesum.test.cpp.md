---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :x: test/yosupo/rangechminchmaxaddrangesum.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/rangechminchmaxaddrangesum.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-25 17:20:34+09:00


* see: <a href="https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum">https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum</a>


## Depends on

* :x: <a href="../../../library/datastructure/segmenttree/segmenttreebeats.hpp.html">Segment Tree Beats <small>(datastructure/segmenttree/segmenttreebeats.hpp)</small></a>
* :question: <a href="../../../library/template/main.hpp.html">template/main.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"

#include "../../template/main.hpp"
#include "../../datastructure/segmenttree/segmenttreebeats.hpp"

signed main() {

    int N, Q;
    cin >> N >> Q;

    using lint = long long;
    vector<lint> A(N);
    for (auto& e: A) cin >> e;

    SegmentTreeBeats seg(A);

    while (Q--) {
        int q, l, r;  cin >> q >> l >> r;
        if (q == 0) {
            lint b; cin >> b;
            seg.update_min(l, r, b);
        } else if (q == 1) {
            lint b; cin >> b;
            seg.update_max(l, r, b);
        } else if (q == 2) {
            lint b; cin >> b;
            seg.add_val(l, r, b);
        } else {
            cout << seg.query_sum(l, r) << endl;
        }
    }

}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/rangechminchmaxaddrangesum.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"

#line 1 "template/main.hpp"
#pragma region optimize
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma endregion
#include <bits/stdc++.h>
using namespace std;
#pragma region boost multiprecision
// #include <boost/multiprecision/cpp_dec_float.hpp>
// #include <boost/multiprecision/cpp_int.hpp>
// using Bint       = boost::multiprecision::cpp_int;
// using Bfloat32   = boost::multiprecision::number<boost::multiprecision::cpp_dec_float<32>>;
// using Bfloat1024 = boost::multiprecision::number<boost::multiprecision::cpp_dec_float<1024>>;
#pragma endregion
// #define int long long
// #define endl '\n'

#pragma region TEMPLATE
// clang-format off
/* TYPE */
typedef long long ll;       typedef long double ld;
typedef pair<int, int> pii; typedef pair<ll, ll> pll;
typedef vector<pii> vpii;   typedef vector<pll> vpll;
typedef vector<int> vi;     typedef vector<ll> vl;
typedef vector<string> vst; typedef vector<bool> vb;
typedef vector<ld> vld;     typedef vector<vector<int>> vvi;
template<typename T, typename Cmp = less<>> using prique = priority_queue<T, vector<T>, Cmp>;
template<typename T> using prique_r = prique<T, greater<>>;
/* CONSTANT */
#define ln '\n'
const int INF = 1 << 30;    const ll INFF = 1LL << 60;  const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int MOD = 1e9 + 7;    const int MODD = 998244353; const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const double EPS = 1e-9;    const ld PI = 3.14159265358979323846264338327950288;
const int dx[] = { 1, 0, -1,  0,  1, -1, -1, 1, 0 };
const int dy[] = { 0, 1,  0, -1, -1, -1,  1, 1, 0 };
/* CONTAINER */
#define PB              emplace_back
#define ALL(v)          (v).begin(), (v).end()
#define RALL(v)         (v).rbegin(), (v).rend()
#define SORT(v)         sort(ALL(v))
#define RSORT(v)        sort(RALL(v))
#define LESS(x, val)    (lower_bound(x.begin(), x.end(), val) - x.begin())
#define LEQ(x, val)     (upper_bound(x.begin(), x.end(), val) - x.begin())
#define GREATER(x, val) (int)(x).size() - LEQ((x), (val))
#define GEQ(x, val)     (int)(x).size() - LESS((x), (val))
#define UNIQUE(v)       sort(ALL(v)); (v).erase(unique(ALL(v)), (v).end())
template<typename T> vector<T> make_v(size_t a) { return vector<T>(a); }
template<typename T, typename... Ts> auto make_v(size_t a, Ts... ts) { return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...)); }
template<typename T, typename U, typename... V> enable_if_t<is_same<T, U>::value != 0> fill_v(U &u, const V... v) { u = U(v...); }
template<typename T, typename U, typename... V> enable_if_t<is_same<T, U>::value == 0> fill_v(U &u, const V... v) { for (auto &e : u) fill_v<T>(e, v...); }
/* LOOP */
#define _overload3(_1, _2, _3, name, ...) name
#define _REP(i, n)      REPI(i, 0, n)
#define REPI(i, a, b)   for (ll i = (ll)a; i < (ll)b; ++i)
#define REP(...)        _overload3(__VA_ARGS__, REPI, _REP,)(__VA_ARGS__)
#define _RREP(i, n)     RREPI(i, n, 0)
#define RREPI(i, a, b)  for (ll i = (ll)a; i >= (ll)b; --i)
#define RREP(...)       _overload3(__VA_ARGS__, RREPI, _RREP,)(__VA_ARGS__)
#define EACH(e, v)      for (auto& e : v)
#define PERM(v)         sort(ALL(v)); for (bool c##p = true; c##p; c##p = next_permutation(ALL(v)))
/* INPUT */
template<typename T> void SSS(T& t) { cin >> t; }
template<typename Head, typename... Tail> void SSS(Head&& head, Tail&&... tail) { cin >> head; SSS(tail...); }
#define SS(T, ...)      T __VA_ARGS__; SSS(__VA_ARGS__);
#define SV(T, v, n)     vector<T> v(n); for (auto& i : v) cin >> i;
#define SVV(T, v, n, m) vector<vector<T>> v(n, vector<T>(m)); for (auto& r : v) for (auto& i : r) cin >> i;
/* OUTPUT */
// Yes / No
inline int YES(bool x) { cout << (x ? "YES"  : "NO") << endl; return 0; }
inline int Yes(bool x) { cout << (x ? "Yes"  : "No") << endl; return 0; }
inline int yes(bool x) { cout << (x ? "yes"  : "no") << endl; return 0; }
inline int yES(bool x) { cout << (x ? "yES"  : "nO") << endl; return 0; }
inline int Yay(bool x) { cout << (x ? "Yay!" : ":(") << endl; return 0; }
// PROTOTYPE DECLARATION
template<typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &j);
template<typename... T> ostream &operator<<(ostream &os, const tuple<T...> &t);
template<class C, enable_if_t<!is_same<C, string>::value, decltype(declval<const C &>().begin(), nullptr)> = nullptr> ostream& operator<<(ostream &os, const C &c);
template<typename T> ostream &operator<<(ostream &os, const stack<T> &j);
template<typename T> ostream &operator<<(ostream &os, const queue<T> &j);
template<typename T, typename C, typename Cmp> ostream &operator<<(ostream &os, const priority_queue<T, C, Cmp> &j);
// IMPLEMENTATION
template<typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &j) { return os << '{' << j.first << ", " << j.second << '}'; }
template<size_t num = 0, typename... T> enable_if_t<num == sizeof...(T)> PRINT_TUPLE(ostream &os, const tuple<T...> &t) {}
template<size_t num = 0, typename... T> enable_if_t<num <  sizeof...(T)> PRINT_TUPLE(ostream &os, const tuple<T...> &t) { os << get<num>(t); if (num + 1 < sizeof...(T)) os << ", "; PRINT_TUPLE<num + 1>(os, t); }
template<typename... T> ostream &operator<<(ostream &os, const tuple<T...> &t) { PRINT_TUPLE(os << '{', t); return os << '}'; }
template<class C, enable_if_t<!is_same<C, string>::value, decltype(declval<const C &>().begin(), nullptr)>> ostream& operator<<(ostream &os, const C &c) { os << '{'; for (auto it = begin(c); it != end(c); it++) { if (begin(c) != it) os << ", "; os << *it; } return os << '}'; }
template<typename T> ostream &operator<<(ostream &os, const stack<T> &j) { deque<T> d; for (auto c = j; !c.empty(); c.pop()) d.push_front(c.top());  return os << d; }
template<typename T> ostream &operator<<(ostream &os, const queue<T> &j) { deque<T> d; for (auto c = j; !c.empty(); c.pop()) d.push_back(c.front()); return os << d; }
template<typename T, typename C, typename Cmp> ostream &operator<<(ostream &os, const priority_queue<T, C, Cmp> &j) { deque<T> d; for (auto c = j; !c.empty(); c.pop()) d.push_front(c.top());  return os << d; }
// OUTPUT FUNCTION
template<typename T> int PV(T &v) { int sz = v.size(); for (int i = 0; i < sz; ++i) cout << v[i] << " \n"[i == sz - 1]; return 0; }
inline int print() { cout << endl; return 0; }
template<typename Head> int print(Head&& head){ cout << head; return print(); }
template<typename Head, typename... Tail> int print(Head&& head, Tail&&... tail) { cout << head << " "; return print(forward<Tail>(tail)...); }
#ifdef LOCAL
inline void dump() { cerr << endl; }
template<typename Head> void dump(Head&& head) { cerr << head; dump(); }
template<typename Head, typename... Tail> void dump(Head&& head, Tail&&... tail) { cerr << head << ", "; dump(forward<Tail>(tail)...); }
#define debug(...) do {cerr << __LINE__ << ":\t" << #__VA_ARGS__ << " = "; dump(__VA_ARGS__); } while (false)
#else
#define dump(...)
#define debug(...)
#endif
/* OTHER */
#define fi              first
#define se              second
#define MP              make_pair
#define MT              make_tuple
template<typename T, typename A, typename B> inline bool between(T x, A a, B b) { return ((a <= x) && (x < b)); }
template<typename A, typename B> inline bool chmax(A &a, const B &b) { if (a < b) { a = b; return true; } return false; }
template<typename A, typename B> inline bool chmin(A &a, const B &b) { if (a > b) { a = b; return true; } return false; }
inline ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
inline ll POW(ll a, ll b) { ll r = 1; do { if (b & 1)  r *= a; a *= a; } while (b >>= 1); return r; }
struct abracadabra {
    abracadabra() {
        cin.tie(nullptr); ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
        cerr << fixed << setprecision(5);
    };
} ABRACADABRA;
// clang-format off
#pragma endregion
#line 1 "datastructure/segmenttree/segmenttreebeats.hpp"
/**
* @brief Segment Tree Beats
* @docs docs/datastructure/segmenttree/segmenttreebeats.md
*/

// clang-format off
struct SegmentTreeBeats {
    static const long long INF = 1LL << 60;
    struct Node {
        Node *left, *right;
        long long max_v, smax_v, max_c;
        long long min_v, smin_v, min_c;
        long long sum;
        long long len, ladd, lval;

        Node() : left(0), right(0), ladd(0), lval(INF) {}

        void init(long long x) {
            max_v = min_v = sum = x;
            smax_v = -INF; smin_v = INF;
            max_c = min_c = 1;
        }

        void init_empty() {
            max_v = smax_v = -INF;
            min_v = smin_v = INF;
            max_c = min_c = 0;
        }

        void update_max(long long x) {
            sum += (x - max_v) * max_c;
            /* */if (max_v ==  min_v) max_v =  min_v = x;
            else if (max_v == smin_v) max_v = smin_v = x;
            else                      max_v = x;
            if (lval != INF and x < lval) lval = x;
        }

        void update_min(long long x) {
            sum += (x - min_v) * min_c;
            /* */if (max_v ==  min_v) max_v =  min_v = x;
            else if (max_v == smin_v) min_v = smax_v = x;
            else                      min_v = x;
            if (lval != INF and lval < x) lval = x;
        }

        void addall(long long x) {
            max_v += x;
            if (smax_v != -INF) smax_v += x;
            min_v += x;
            if (smin_v != INF) smin_v += x;
            sum += len * x;
            if (lval != INF) lval += x;
            else             ladd += x;
        }

        void updateall(long long x) {
            max_v = min_v = x;
            smax_v = -INF; smin_v = INF;
            max_c = min_c = len;
            sum = len * x;
            lval = x; ladd = 0;
        }

        void push() {
            if (lval != INF) {
                 left -> updateall(lval);
                right -> updateall(lval);
                lval = INF;
                return;
            }
            if (ladd != 0) {
                 left -> addall(ladd);
                right -> addall(ladd);
                ladd = 0;
            }
            if (max_v < left -> max_v)   left -> update_max(max_v);
            if (left -> min_v < min_v)   left -> update_min(min_v);
            if (max_v < right -> max_v) right -> update_max(max_v);
            if (right -> min_v < min_v) right -> update_min(min_v);
        }

        void update() {
            sum = left -> sum + right -> sum;
            if (left -> max_v < right -> max_v) {
                max_v = right -> max_v;
                max_c = right -> max_c;
                smax_v = max(left -> max_v, right -> smax_v);
            } else if (left -> max_v > right -> max_v) {
                max_v = left -> max_v;
                max_c = left -> max_c;
                smax_v = max(left -> smax_v, right -> max_v);
            } else {
                max_v = left -> max_v;
                max_c = left -> max_c + right -> max_c;
                smax_v = max(left -> smax_v, right -> smax_v);
            }
            if (left -> min_v < right -> min_v) {
                min_v = left -> min_v;
                min_c = left -> min_c;
                smin_v = min(left -> smin_v, right -> min_v);
            } else if (left -> min_v > right -> min_v) {
                min_v = right -> min_v;
                min_c = right -> min_c;
                smin_v = min(left -> min_v, right -> smin_v);
            } else {
                min_v = left -> min_v;
                min_c = left -> min_c + right -> min_c;
                smin_v = min(left -> smin_v, right -> smin_v);
            }
        }
    };

    int n, n0;
    Node *root;

    void _update_min(long long x, int a, int b, Node *nd, int l, int r) {
        if (b <= l || r <= a || nd -> max_v <= x) return;
        if (a <= l && r <= b && nd -> smax_v < x) {
            nd -> update_max(x);
            return;
        }
        nd -> push();
        _update_min(x, a, b, nd ->  left, l, (l + r) >> 1);
        _update_min(x, a, b, nd -> right, (l + r) >> 1, r);
        nd -> update();
    }

    void _update_max(long long x, int a, int b, Node *nd, int l, int r) {
        if (b <= l || r <= a || x <= nd -> min_v) return;
        if (a <= l && r <= b && x < nd -> smin_v) {
            nd -> update_min(x);
            return;
        }
        nd -> push();
        _update_max(x, a, b, nd ->  left, l, (l + r) >> 1);
        _update_max(x, a, b, nd -> right, (l + r) >> 1, r);
        nd -> update();
    }

    void _add_val(long long x, int a, int b, Node *nd, int l, int r) {
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            nd -> addall(x);
            return;
        }
        nd -> push();
        _add_val(x, a, b, nd ->  left, l, (l + r) >> 1);
        _add_val(x, a, b, nd -> right, (l + r) >> 1, r);
        nd -> update();
    }

    void _update_val(long long x, int a, int b, Node *nd, int l, int r) {
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            nd -> updateall(x);
            return;
        }
        nd -> push();
        _update_val(x, a, b, nd ->  left, l, (l + r) >> 1);
        _update_val(x, a, b, nd -> right, (l + r) >> 1, r);
        nd -> update();
    }

    long long _query_max(int a, int b, Node *nd, int l, int r) {
        if (b <= l || r <= a) return -INF;
        if (a <= l && r <= b) return nd -> max_v;
        nd -> push();
        long long lv = _query_max(a, b, nd ->  left, l, (l + r) >> 1);
        long long rv = _query_max(a, b, nd -> right, (l + r) >> 1, r);
        return max(lv, rv);
    }

    long long _query_min(int a, int b, Node *nd, int l, int r) {
        if (b <= l || r <= a) return INF;
        if (a <= l && r <= b) return nd -> min_v;
        nd -> push();
        long long lv = _query_min(a, b, nd ->  left, l, (l + r) >> 1);
        long long rv = _query_min(a, b, nd -> right, (l + r) >> 1, r);
        return min(lv, rv);
    }

    long long _query_sum(int a, int b, Node *nd, int l, int r) {
        if (b <= l || r <= a) return 0;
        if (a <= l && r <= b) return nd -> sum;
        nd -> push();
        long long lv = _query_sum(a, b, nd ->  left, l, (l + r) >> 1);
        long long rv = _query_sum(a, b, nd -> right, (l + r) >> 1, r);
        return lv + rv;
    }

    SegmentTreeBeats(int n, long long val = 0) : n(n) {
        n0 = 1; while (n0 < n) n0 <<= 1;
        Node *nds = new Node[2 * n0];
        root = nds;
        nds[0].len = n0;
        for (int i = 0; i < n0 - 1; ++i) {
            nds[i].left = &nds[2 * i + 1];
            nds[i].right = &nds[2 * i + 2];
            nds[2 * i + 1].len = nds[2 * i + 2].len = nds[i].len >> 1;
        }
        for (int i = 0; i <  n; ++i) nds[n0 - 1 + i].init(val);
        for (int i = n; i < n0; ++i) nds[n0 - 1 + i].init_empty();
        for (int i = n0 - 2; i >= 0; i--) nds[i].update();
    }

    SegmentTreeBeats(const vector<long long> &v) : n((int)v.size()) {
        n0 = 1; while (n0 < n) n0 <<= 1;
        Node *nds = new Node[2 * n0];
        root = nds;
        nds[0].len = n0;
        for (int i = 0; i < n0 - 1; ++i) {
            nds[i].left = &nds[2 * i + 1];
            nds[i].right = &nds[2 * i + 2];
            nds[2 * i + 1].len = nds[2 * i + 2].len = nds[i].len >> 1;
        }
        for (int i = 0; i <  n; ++i) nds[n0 - 1 + i].init(v[i]);
        for (int i = n; i < n0; ++i) nds[n0 - 1 + i].init_empty();
        for (int i = n0 - 2; i >= 0; i--) nds[i].update();
    }

    void update_min(int a, int b, long long x) { _update_min(x, a, b, root, 0, n0); }
    void update_max(int a, int b, long long x) { _update_max(x, a, b, root, 0, n0); }
    void    add_val(int a, int b, long long x) {    _add_val(x, a, b, root, 0, n0); }
    void update_val(int a, int b, long long x) { _update_val(x, a, b, root, 0, n0); }
    long long query_max(int a, int b) { return _query_max(a, b, root, 0, n0); }
    long long query_min(int a, int b) { return _query_min(a, b, root, 0, n0); }
    long long query_sum(int a, int b) { return _query_sum(a, b, root, 0, n0); }
};
// clang-format on
#line 5 "test/yosupo/rangechminchmaxaddrangesum.test.cpp"

signed main() {

    int N, Q;
    cin >> N >> Q;

    using lint = long long;
    vector<lint> A(N);
    for (auto& e: A) cin >> e;

    SegmentTreeBeats seg(A);

    while (Q--) {
        int q, l, r;  cin >> q >> l >> r;
        if (q == 0) {
            lint b; cin >> b;
            seg.update_min(l, r, b);
        } else if (q == 1) {
            lint b; cin >> b;
            seg.update_max(l, r, b);
        } else if (q == 2) {
            lint b; cin >> b;
            seg.add_val(l, r, b);
        } else {
            cout << seg.query_sum(l, r) << endl;
        }
    }

}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

