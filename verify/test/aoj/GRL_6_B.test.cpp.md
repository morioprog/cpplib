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


# :heavy_check_mark: test/aoj/GRL_6_B.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_6_B.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-25 17:20:34+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/graph/minimumcostflow/primaldual.hpp.html">Primal Dual <small>(graph/minimumcostflow/primaldual.hpp)</small></a>
* :heavy_check_mark: <a href="../../../library/template/main.hpp.html">template/main.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B"

#include "../../template/main.hpp"
#include "../../graph/minimumcostflow/primaldual.hpp"

signed main() {

    int V, E, F;
    cin >> V >> E >> F;

    PrimalDual<int, int> pd(V);
    for (int i = 0; i < E; ++i) {
        int u, v, cap, cst;
        cin >> u >> v >> cap >> cst;
        pd.add_arc(u, v, cst, cap);
    }

    cout << pd.min_cost_flow(0, V - 1, F) << endl;

}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/GRL_6_B.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B"

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
#line 1 "graph/minimumcostflow/primaldual.hpp"
/**
* @brief Primal Dual
* @docs docs/graph/minimumcostflow/primaldual.md
* @see http://www.prefield.com/algorithm/graph/primal_dual.html
* @note O(FE\log V)
*/

template <typename Cst, typename Cap>
struct PrimalDual {
    struct CapEdge {
        int to, rev;
        Cst cst;
        Cap cap;
        CapEdge() {}
        CapEdge(int t, int r, Cst cst, Cap cap)
            : to(t), rev(r), cst(cst), cap(cap) {}
        operator int() const { return to; }
    };
    using P = pair<Cst, int>;
    const Cst INF;
    int V;
    vector<vector<CapEdge>> graph;
    vector<Cst> pot, min_cst;
    vector<int> prv_v, prv_e;
    PrimalDual(int V)
        : INF(numeric_limits<Cst>::max()), V(V), graph(V) {}
    void add_arc(int a, int b, Cst cst, Cap cap) {
        graph[a].emplace_back(b, (int)graph[b].size(), cst, cap);
        graph[b].emplace_back(a, (int)graph[a].size() - 1, -cst, 0);
    }
    Cst min_cost_flow(int s, int t, Cap flw) {
        pot.assign(V, 0);
        prv_e.assign(V, -1);
        prv_v.assign(V, -1);
        Cst ret = 0;
        priority_queue<P, vector<P>, greater<P>> pq;
        while (flw > 0) {
            min_cst.assign(V, INF);
            pq.push(P(0, s));
            min_cst[s] = 0;
            while (not pq.empty()) {
                Cst cst;
                int idx;
                tie(cst, idx) = pq.top();
                pq.pop();
                if (min_cst[idx] < cst) continue;
                for (int i = 0; i < (int)graph[idx].size(); ++i) {
                    CapEdge &nxt = graph[idx][i];
                    int nxt_cst  = min_cst[idx] + nxt.cst + pot[idx] - pot[nxt];
                    if (nxt.cap > 0 and min_cst[nxt] > nxt_cst) {
                        min_cst[nxt] = nxt_cst;
                        prv_v[nxt] = idx, prv_e[nxt] = i;
                        pq.push(P(min_cst[nxt], nxt));
                    }
                }
            }
            if (min_cst[t] == INF) return -1;
            for (int v = 0; v < V; ++v) pot[v] += min_cst[v];
            Cap add_flw = flw;
            for (int v = t; v != s; v = prv_v[v]) {
                add_flw = min(add_flw, graph[prv_v[v]][prv_e[v]].cap);
            }
            flw -= add_flw;
            ret += add_flw * pot[t];
            for (int v = t; v != s; v = prv_v[v]) {
                CapEdge &e = graph[prv_v[v]][prv_e[v]];
                e.cap -= add_flw;
                graph[v][e.rev].cap += add_flw;
            }
        }
        return ret;
    }
};
#line 5 "test/aoj/GRL_6_B.test.cpp"

signed main() {

    int V, E, F;
    cin >> V >> E >> F;

    PrimalDual<int, int> pd(V);
    for (int i = 0; i < E; ++i) {
        int u, v, cap, cst;
        cin >> u >> v >> cap >> cst;
        pd.add_arc(u, v, cst, cap);
    }

    cout << pd.min_cost_flow(0, V - 1, F) << endl;

}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
