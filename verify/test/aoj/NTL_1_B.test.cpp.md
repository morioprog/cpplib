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


# :heavy_check_mark: test/aoj/NTL_1_B.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/NTL_1_B.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-22 15:52:26+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/math/modint.hpp.html">ModInt <small>(math/modint.hpp)</small></a>
* :heavy_check_mark: <a href="../../../library/template/main.hpp.html">template/main.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"

#include "../../template/main.hpp"
#include "../../math/modint.hpp"

signed main() {

    int M, N;   cin >> M >> N;
    cout << (modint(M) ^ N) << endl;

}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/NTL_1_B.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"

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
inline ll POW(ll a, ll b)                    { ll r = 1; do { if (b & 1)  r *= a;        a *= a; }       while (b >>= 1); return r; }
inline ll MOP(ll a, ll b, const ll &m = MOD) { ll r = 1; do { if (b & 1) (r *= a) %= m; (a *= a) %= m; } while (b >>= 1); return r; }
struct abracadabra {
    abracadabra() {
        cin.tie(nullptr); ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
        cerr << fixed << setprecision(5);
    };
} ABRACADABRA;

#pragma endregion
#line 1 "math/modint.hpp"
/**
 * @brief ModInt
 * @docs docs/math/modint.md
 */

template< int MODULO > struct ModInt {
    using i32 = int;
    using i64 = long long;
    using u32 = unsigned int;
    using u64 = unsigned long long;
    u64 x; ModInt() : x(0) {}
    ModInt(i64 y) : x(set(y % MODULO + MODULO)) {}
    static u64 set(const i64 &y) { return (y < MODULO) ? y : y - MODULO; }
    ModInt operator+(const ModInt &m) const { return ModInt(set(x + m.x)); }
    ModInt operator-(const ModInt &m) const { return ModInt(set(x + MODULO - m.x)); }
    ModInt operator*(const ModInt &m) const { return ModInt(x * m.x % MODULO); }
    ModInt operator/(const ModInt &m) const { return ModInt(x) * ~ModInt(m.x); }
    ModInt &operator+=(const ModInt &m) { return *this = *this + m; }
    ModInt &operator-=(const ModInt &m) { return *this = *this - m; }
    ModInt &operator*=(const ModInt &m) { return *this = *this * m; }
    ModInt &operator/=(const ModInt &m) { return *this = *this / m; }
    ModInt &operator^=(const u64 &y) { return *this = *this ^ y; }
    ModInt operator~ () const { return *this ^ (MODULO - 2); }
    ModInt operator- () const { return ModInt(set(MODULO - x)); }
    ModInt operator! () const { return getFact(u32(*this)); }
    ModInt operator& () const { return getFinv(u32(*this)); }
    ModInt operator++() { return *this = ModInt(set(x + 1)); }
    ModInt operator--() { return *this = ModInt(set(x + MODULO - 1)); }
    bool operator==(const ModInt &m) const { return x == m.x; }
    bool operator!=(const ModInt &m) const { return x != m.x; }
    bool operator< (const ModInt &m) const { return x <  m.x; }
    bool operator<=(const ModInt &m) const { return x <= m.x; }
    bool operator> (const ModInt &m) const { return x >  m.x; }
    bool operator>=(const ModInt &m) const { return x >= m.x; }
    explicit operator u64() const { return x; }
    ModInt operator^(u64 y) const {
        u64 t = x, u = 1;
        while (y) { if (y & 1) (u *= t) %= MODULO; (t *= t) %= MODULO; y >>= 1; }
        return ModInt(u);
    }
    friend ostream &operator<<(ostream &os, const ModInt< MODULO > &m) { return os << m.x; }
    friend istream &operator>>(istream &is, ModInt< MODULO > &m) { u64 y; is >> y; m = ModInt(y); return is; }
    static vector< ModInt > fact, finv, invs;
    static void init(u32 n) {
        u32 m = fact.size();
        if (n < m) return;
        fact.resize(n + 1, 1);
        finv.resize(n + 1, 1);
        invs.resize(n + 1, 1);
        if (m == 0) m = 1;
        for (u32 i = m; i <= n; ++i) fact[i] = fact[i - 1] * ModInt(i);
        finv[n] = ModInt(1) / fact[n];
        for (u32 i = n; i >= m; --i) finv[i - 1] = finv[i] * ModInt(i);
        for (u32 i = m; i <= n; ++i) invs[i] = finv[i] * fact[i - 1];
    }
    static ModInt getFact(u32 n) { init(n); return fact[n]; }
    static ModInt getFinv(u32 n) { init(n); return finv[n]; }
    static ModInt getInvs(u32 n) { init(n); return invs[n]; }
    static ModInt C(i64 n, i64 r) {
        if (r == 0) return ModInt(1);
        if (r <  0) return ModInt(0);
        if (n <  0) return ModInt(r & 1 ? MODULO - 1 : 1) * C(-n + r - 1, r);
        if (n == 0 || n < r) return ModInt(0);
        init(n);
        return fact[n] * finv[n - r] * finv[r];
    }
    static ModInt P(i64 n, i64 r) {
        if (n < r || r < 0) return ModInt(0);
        init(n);
        return fact[n] * finv[n - r];
    }
    static ModInt H(i64 n, i64 r) {
        if (n < 0 || r < 0) return ModInt(0);
        if (!n && !r) return ModInt(1);
        init(n + r - 1);
        return C(n + r - 1, r);
    }
    static ModInt montmort(u32 n) {
        ModInt res;
        init(n);
        for (u32 k = 2; k <= n; ++k) {
            if (k & 1) res -= finv[k];
            else res += finv[k];
        }
        return res *= fact[n];
    }
    static ModInt LagrangePolynomial(vector<ModInt> &y, i64 t) {
        u32 n = y.size() - 1;
        if (t <= n) return y[t];
        init(n + 1);
        ModInt res, num(1);
        for (int i = 0; i <= n; ++i) num *= ModInt(t - i);
        for (int i = 0; i <= n; ++i) {
            ModInt tmp = y[i] * num / (ModInt(t - i)) * finv[i] * finv[n - i];
            if ((n - i) & 1) res -= tmp;
            else res += tmp;
        }
        return res;
    }
};
template< int MODULO > vector<ModInt< MODULO >> ModInt< MODULO >::fact = vector<ModInt< MODULO >>();
template< int MODULO > vector<ModInt< MODULO >> ModInt< MODULO >::finv = vector<ModInt< MODULO >>();
template< int MODULO > vector<ModInt< MODULO >> ModInt< MODULO >::invs = vector<ModInt< MODULO >>();
constexpr int MODULO = (int)1e9 + 7;
using modint = ModInt< MODULO >;
#line 5 "test/aoj/NTL_1_B.test.cpp"

signed main() {

    int M, N;   cin >> M >> N;
    cout << (modint(M) ^ N) << endl;

}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

