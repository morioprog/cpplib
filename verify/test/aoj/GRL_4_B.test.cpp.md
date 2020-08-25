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


# :heavy_check_mark: test/aoj/GRL_4_B.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_4_B.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-25 17:20:34+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/graph/other/topological_sort.hpp.html">トポロジカルソート <small>(graph/other/topological_sort.hpp)</small></a>
* :heavy_check_mark: <a href="../../../library/graph/template.hpp.html">グラフテンプレート <small>(graph/template.hpp)</small></a>
* :heavy_check_mark: <a href="../../../library/template/main.hpp.html">template/main.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B"

#include "../../template/main.hpp"
#include "../../graph/template.hpp"
#include "../../graph/other/topological_sort.hpp"

signed main() {

    int V, E;
    cin >> V >> E;

    Graph<int> g(V);
    g.input_arcs(E);

    auto tp = topological_sort(g);
    for (auto& e: tp) cout << e << endl;

}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/GRL_4_B.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B"

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
#line 1 "graph/template.hpp"
/**
* @brief グラフテンプレート
* @docs docs/graph/template.md
*/

template <typename T>
struct Edge {
    int frm, to, idx;
    T cst;
    Edge() {}
    Edge(int f, int t, T c, int i = -1)
        : frm(f), to(t), idx(i), cst(c) {}
    operator int() const { return to; }
};

template <typename T>
constexpr T GINF = numeric_limits<T>::max() / 10;

template <typename T>
struct Graph {
    int V, E;
    vector<vector<Edge<T>>> mat;
    vector<vector<T>> wf;
    Graph() {}
    Graph(int v)
        : V(v), E(0), mat(v) {}
    inline void add_edge(int a, int b, T c = 1, int margin = 0) {
        a -= margin, b -= margin;
        mat[a].emplace_back(a, b, c, E++);
        mat[b].emplace_back(b, a, c, E++);
    }
    inline void add_arc(int a, int b, T c = 1, int margin = 0) {
        a -= margin, b -= margin;
        mat[a].emplace_back(a, b, c, E++);
    }
    inline void input_edges(int M, int margin = 0, bool need_cost = false) {
        for (int i = 0; i < M; ++i) {
            int a, b;
            T c(1);
            cin >> a >> b;
            if (need_cost) cin >> c;
            add_edge(a, b, c, margin);
        }
    }
    inline void input_arcs(int M, int margin = 0, bool need_cost = false) {
        for (int i = 0; i < M; ++i) {
            int a, b;
            T c(1);
            cin >> a >> b;
            if (need_cost) cin >> c;
            add_arc(a, b, c, margin);
        }
    }
};
#line 1 "graph/other/topological_sort.hpp"
/**
* @brief トポロジカルソート
* @docs docs/graph/other/topological_sort.md
*/

template <typename T>
vector<int> topological_sort(const Graph<T> &g) {
    vector<int> order, color(g.V, 0);
    auto rec = [&](auto &&f, int v) -> bool {
        color[v] = 1;
        for (auto &e : g.mat[v]) {
            if (color[e] == 2) continue;
            if (color[e] == 1) return false;
            if (not f(f, e)) return false;
        }
        order.push_back(v);
        color[v] = 2;
        return true;
    };
    for (int i = 0; i < g.V; ++i)
        if (not color[i] and not rec(rec, i)) return vector<int>();
    reverse(order.begin(), order.end());
    return order;
}
#line 6 "test/aoj/GRL_4_B.test.cpp"

signed main() {

    int V, E;
    cin >> V >> E;

    Graph<int> g(V);
    g.input_arcs(E);

    auto tp = topological_sort(g);
    for (auto& e: tp) cout << e << endl;

}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

