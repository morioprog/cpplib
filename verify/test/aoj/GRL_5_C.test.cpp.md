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


# :heavy_check_mark: test/aoj/GRL_5_C.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_5_C.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-31 22:25:19+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/graph/template.hpp.html">グラフテンプレート <small>(graph/template.hpp)</small></a>
* :heavy_check_mark: <a href="../../../library/graph/tree/hldecomposition.hpp.html">HL分解 <small>(graph/tree/hldecomposition.hpp)</small></a>
* :heavy_check_mark: <a href="../../../library/template/main.hpp.html">template/main.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C"

#include "../../template/main.hpp"
#include "../../graph/template.hpp"
#include "../../graph/tree/hldecomposition.hpp"

signed main() {

    int N;
    cin >> N;

    HLDecomposition<int> hld(N);
    for (int i = 0; i < N; ++i) {
        int K;  cin >> K;
        for (int j = 0; j < K; ++j) {
            int C; cin >> C;
            hld.add_edge(i, C);
        }
    }
    hld.build();

    int Q;
    cin >> Q;

    while (Q--) {
        int U, V;
        cin >> U >> V;
        cout << hld.lca(U, V) << endl;
    }

}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/GRL_5_C.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C"

#line 1 "template/main.hpp"
// #pragma GCC target ("avx")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
// #define int long long
// #define endl '\n'

#pragma region TEMPLATE

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
#define tmax(x, y, z)   max((x), max((y), (z)))
#define tmin(x, y, z)   min((x), min((y), (z)))
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

#pragma endregion
#line 1 "graph/template.hpp"
/**
* @brief グラフテンプレート
* @docs docs/graph/template.md
*/

template<typename T>
struct Edge {
    int frm, to, idx;   T cst;
    Edge() {}
    Edge(int f, int t, T c, int i = -1) : frm(f), to(t), cst(c), idx(i) {}
    operator int() const { return to; }
};

template<typename T>
constexpr T GINF = numeric_limits<T>::max() / 10;

template<typename T>
struct Graph {
    int V, E;
    vector<vector<Edge<T>>> mat;
    vector<vector<T>> wf;
    Graph() {}
    Graph(int v) : V(v), E(0), mat(v) {}
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
            if (need_cost) {
                int a, b;   T c;
                cin >> a >> b >> c;
                add_edge(a, b, c, margin);
            } else {
                int a, b;   T c(1);
                cin >> a >> b;
                add_edge(a, b, c, margin);
            }
        }
    }
    inline void input_arcs(int M, int margin = 0, bool need_cost = false) {
        for (int i = 0; i < M; ++i) {
            if (need_cost) {
                int a, b;   T c;
                cin >> a >> b >> c;
                add_arc(a, b, c, margin);
            } else {
                int a, b;   T c(1);
                cin >> a >> b;
                add_arc(a, b, c, margin);
            }
        }
    }
    inline bool is_bipartite() {
        bool isbi = true;
        vector<int> color(V, 0);
        auto dfs = [&](auto &&f, int i, int clr) -> void {
            if (color[i] != 0) return;
            color[i] = clr;
            for (auto& e: mat[i]) {
                /* */if (color[e.to] == 0)      f(f, e.to, -clr);
                else if (color[e.to] == clr)    isbi = false;
            }
        };
        dfs(dfs, 0, 1);
        return isbi;
        // int cnt = 0;
        // for (auto& e: color) if (e == 1) ++cnt;
        // return isbi ? -1 : cnt;
    }
};
#line 1 "graph/tree/hldecomposition.hpp"
/**
* @brief HL分解
* @docs docs/graph/tree/hldecomposition.md
*/

template<typename T>
struct HLDecomposition : Graph<T> {
    using Graph<T>::Graph;
    using Graph<T>::mat;
    using Graph<T>::V;
    vector<int> sub, dep, par, head, in, out, rev;
    vector<T> dst;
    void build(const int root = 0) {
        sub.assign(V, 0);
        dep.assign(V, 0);
        par.assign(V, 0);
        head.assign(V, 0);
        in.assign(V, 0);
        out.assign(V, 0);
        rev.assign(V, 0);
        dst.assign(V, T(0));
        dfs_sz(root, -1, 0, T(0));
        int t = 0;
        dfs_hld(root, -1, t);
    }
    int get(int u) const { return in[u]; }
    int lca(int u, int v) const {
        for (;; v = par[head[v]]) {
            // uよりもvを後に来るようにして, vを上に押し上げていく
            if (in[u] > in[v]) swap(u, v);
            if (head[u] == head[v]) return u;
        }
    }
    T dist(int u, int v) const {
        return dst[u] + dst[v] - 2 * dst[lca(u, v)];
    }
    pair<int, int> get_subtree(int u, bool isEdge = false) const {
        return make_pair(in[u] + isEdge, out[u]);
    }
    vector<pair<int, int>> get_path(int u, int v, bool isEdge = false) {
        vector<pair<int, int>> ret;
        for(;; v = par[head[v]]) {
			if (in[u] > in[v]) swap(u, v);
			if (head[u] == head[v]) break;
			ret.emplace_back(in[head[v]], in[v] + 1);
		}
		ret.emplace_back(in[u] + isEdge, in[v] + 1);
		return ret;
    }
    void dfs_sz(int cur, int prv, int depth, T weight) {
        sub[cur] = 1;
        dep[cur] = depth;
        par[cur] = prv;
        dst[cur] = weight;
        // 0番目をheavy-pathにするための比較対象を設定
        if (mat[cur].size() && mat[cur][0] == prv)
            swap(mat[cur][0], mat[cur].back());
        for (auto& nxt : mat[cur]) {
            if (nxt == prv) continue;
            dfs_sz(nxt, cur, depth + 1, weight + nxt.cst);
            sub[cur] += sub[nxt];
            if (sub[mat[cur][0]] < sub[nxt]) swap(mat[cur][0], nxt);
        }
    }
    void dfs_hld(int cur, int prv, int& times) {
        in[cur] = times++;
        rev[in[cur]] = cur;
        for (auto& nxt : mat[cur]) {
            if (nxt == prv) continue;
            // cur-nxtがheavy-path上ならheadは同じ
            head[nxt] = mat[cur][0] == nxt ? head[cur] : nxt;
            dfs_hld(nxt, cur, times);
        }
        out[cur] = times;
    }
};
#line 6 "test/aoj/GRL_5_C.test.cpp"

signed main() {

    int N;
    cin >> N;

    HLDecomposition<int> hld(N);
    for (int i = 0; i < N; ++i) {
        int K;  cin >> K;
        for (int j = 0; j < K; ++j) {
            int C; cin >> C;
            hld.add_edge(i, C);
        }
    }
    hld.build();

    int Q;
    cin >> Q;

    while (Q--) {
        int U, V;
        cin >> U >> V;
        cout << hld.lca(U, V) << endl;
    }

}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

