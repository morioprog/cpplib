---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: datastructure/segmenttree/lazysegmenttree.hpp
    title: "\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':question:'
    path: template/main.hpp
    title: template/main.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/yosupo/rangeaffinerangesum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\n#line 1 \"template/main.hpp\"\
    \n#pragma region optimize\n// #pragma GCC optimize(\"Ofast\")\n// #pragma GCC\
    \ optimize(\"unroll-loops\")\n// #pragma GCC target(\"sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx\"\
    )\n#pragma endregion\n#include <bits/stdc++.h>\nusing namespace std;\n// #include\
    \ <atcoder/all>\n#pragma region boost multiprecision\n// #include <boost/multiprecision/cpp_dec_float.hpp>\n\
    // #include <boost/multiprecision/cpp_int.hpp>\n// using Bint       = boost::multiprecision::cpp_int;\n\
    // using Bfloat32   = boost::multiprecision::number<boost::multiprecision::cpp_dec_float<32>>;\n\
    // using Bfloat1024 = boost::multiprecision::number<boost::multiprecision::cpp_dec_float<1024>>;\n\
    #pragma endregion\n// #define int long long\n// #define endl '\\n'\n\n#pragma\
    \ region TEMPLATE\n// clang-format off\n/* TYPE */\ntypedef long long ll;    \
    \   typedef long double ld;\ntypedef pair<int, int> pii; typedef pair<ll, ll>\
    \ pll;\ntypedef vector<pii> vpii;   typedef vector<pll> vpll;\ntypedef vector<int>\
    \ vi;     typedef vector<ll> vl;\ntypedef vector<string> vst; typedef vector<bool>\
    \ vb;\ntypedef vector<ld> vld;     typedef vector<vector<int>> vvi;\ntemplate<typename\
    \ T, typename Cmp = less<>> using prique = priority_queue<T, vector<T>, Cmp>;\n\
    template<typename T> using prique_r = prique<T, greater<>>;\n/* CONSTANT */\n\
    #define ln '\\n'\nconst int INF = 1 << 30;    const ll INFF = 1LL << 60;  const\
    \ string ALPHABET = \"ABCDEFGHIJKLMNOPQRSTUVWXYZ\";\nconst int MOD = 1e9 + 7;\
    \    const int MODD = 998244353; const string alphabet = \"abcdefghijklmnopqrstuvwxyz\"\
    ;\nconst double EPS = 1e-9;    const ld PI = 3.14159265358979323846264338327950288;\n\
    const int dx[] = { 1, 0, -1,  0,  1, -1, -1, 1, 0 };\nconst int dy[] = { 0, 1,\
    \  0, -1, -1, -1,  1, 1, 0 };\n/* CONTAINER */\n#define PB              emplace_back\n\
    #define ALL(v)          (v).begin(), (v).end()\n#define RALL(v)         (v).rbegin(),\
    \ (v).rend()\n#define SORT(v)         sort(ALL(v))\n#define RSORT(v)        sort(RALL(v))\n\
    #define LESS(x, val)    (lower_bound(x.begin(), x.end(), val) - x.begin())\n#define\
    \ LEQ(x, val)     (upper_bound(x.begin(), x.end(), val) - x.begin())\n#define\
    \ GREATER(x, val) (int)(x).size() - LEQ((x), (val))\n#define GEQ(x, val)     (int)(x).size()\
    \ - LESS((x), (val))\n#define UNIQUE(v)       sort(ALL(v)); (v).erase(unique(ALL(v)),\
    \ (v).end())\ntemplate<typename T> vector<T> make_v(size_t a) { return vector<T>(a);\
    \ }\ntemplate<typename T, typename... Ts> auto make_v(size_t a, Ts... ts) { return\
    \ vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...)); }\ntemplate<typename\
    \ T, typename U, typename... V> enable_if_t<is_same<T, U>::value != 0> fill_v(U\
    \ &u, const V... v) { u = U(v...); }\ntemplate<typename T, typename U, typename...\
    \ V> enable_if_t<is_same<T, U>::value == 0> fill_v(U &u, const V... v) { for (auto\
    \ &e : u) fill_v<T>(e, v...); }\n/* LOOP */\n#define _overload3(_1, _2, _3, name,\
    \ ...) name\n#define _REP(i, n)      REPI(i, 0, n)\n#define REPI(i, a, b)   for\
    \ (ll i = (ll)a; i < (ll)b; ++i)\n#define REP(...)        _overload3(__VA_ARGS__,\
    \ REPI, _REP,)(__VA_ARGS__)\n#define _RREP(i, n)     RREPI(i, n, 0)\n#define RREPI(i,\
    \ a, b)  for (ll i = (ll)a; i >= (ll)b; --i)\n#define RREP(...)       _overload3(__VA_ARGS__,\
    \ RREPI, _RREP,)(__VA_ARGS__)\n#define EACH(e, v)      for (auto& e : v)\n#define\
    \ PERM(v)         sort(ALL(v)); for (bool c##p = true; c##p; c##p = next_permutation(ALL(v)))\n\
    /* INPUT */\ntemplate<typename T> void SSS(T& t) { cin >> t; }\ntemplate<typename\
    \ Head, typename... Tail> void SSS(Head&& head, Tail&&... tail) { cin >> head;\
    \ SSS(tail...); }\n#define SS(T, ...)      T __VA_ARGS__; SSS(__VA_ARGS__);\n\
    #define SV(T, v, n)     vector<T> v(n); for (auto& i : v) cin >> i;\n#define SVV(T,\
    \ v, n, m) vector<vector<T>> v(n, vector<T>(m)); for (auto& r : v) for (auto&\
    \ i : r) cin >> i;\n/* OUTPUT */\n// Yes / No\ninline int YES(bool x) { cout <<\
    \ (x ? \"YES\"  : \"NO\") << endl; return 0; }\ninline int Yes(bool x) { cout\
    \ << (x ? \"Yes\"  : \"No\") << endl; return 0; }\ninline int yes(bool x) { cout\
    \ << (x ? \"yes\"  : \"no\") << endl; return 0; }\ninline int yES(bool x) { cout\
    \ << (x ? \"yES\"  : \"nO\") << endl; return 0; }\ninline int Yay(bool x) { cout\
    \ << (x ? \"Yay!\" : \":(\") << endl; return 0; }\n// PROTOTYPE DECLARATION\n\
    template<typename T, typename U> ostream &operator<<(ostream &os, const pair<T,\
    \ U> &j);\ntemplate<typename... T> ostream &operator<<(ostream &os, const tuple<T...>\
    \ &t);\ntemplate<class C, enable_if_t<!is_same<C, string>::value, decltype(declval<const\
    \ C &>().begin(), nullptr)> = nullptr> ostream& operator<<(ostream &os, const\
    \ C &c);\ntemplate<typename T> ostream &operator<<(ostream &os, const stack<T>\
    \ &j);\ntemplate<typename T> ostream &operator<<(ostream &os, const queue<T> &j);\n\
    template<typename T, typename C, typename Cmp> ostream &operator<<(ostream &os,\
    \ const priority_queue<T, C, Cmp> &j);\n// IMPLEMENTATION\ntemplate<typename T,\
    \ typename U> ostream &operator<<(ostream &os, const pair<T, U> &j) { return os\
    \ << '{' << j.first << \", \" << j.second << '}'; }\ntemplate<size_t num = 0,\
    \ typename... T> enable_if_t<num == sizeof...(T)> PRINT_TUPLE(ostream &os, const\
    \ tuple<T...> &t) {}\ntemplate<size_t num = 0, typename... T> enable_if_t<num\
    \ <  sizeof...(T)> PRINT_TUPLE(ostream &os, const tuple<T...> &t) { os << get<num>(t);\
    \ if (num + 1 < sizeof...(T)) os << \", \"; PRINT_TUPLE<num + 1>(os, t); }\ntemplate<typename...\
    \ T> ostream &operator<<(ostream &os, const tuple<T...> &t) { PRINT_TUPLE(os <<\
    \ '{', t); return os << '}'; }\ntemplate<class C, enable_if_t<!is_same<C, string>::value,\
    \ decltype(declval<const C &>().begin(), nullptr)>> ostream& operator<<(ostream\
    \ &os, const C &c) { os << '{'; for (auto it = begin(c); it != end(c); it++) {\
    \ if (begin(c) != it) os << \", \"; os << *it; } return os << '}'; }\ntemplate<typename\
    \ T> ostream &operator<<(ostream &os, const stack<T> &j) { deque<T> d; for (auto\
    \ c = j; !c.empty(); c.pop()) d.push_front(c.top());  return os << d; }\ntemplate<typename\
    \ T> ostream &operator<<(ostream &os, const queue<T> &j) { deque<T> d; for (auto\
    \ c = j; !c.empty(); c.pop()) d.push_back(c.front()); return os << d; }\ntemplate<typename\
    \ T, typename C, typename Cmp> ostream &operator<<(ostream &os, const priority_queue<T,\
    \ C, Cmp> &j) { deque<T> d; for (auto c = j; !c.empty(); c.pop()) d.push_front(c.top());\
    \  return os << d; }\n// OUTPUT FUNCTION\ntemplate<typename T> int PV(T &v) {\
    \ int sz = v.size(); for (int i = 0; i < sz; ++i) cout << v[i] << \" \\n\"[i ==\
    \ sz - 1]; return 0; }\ninline int print() { cout << endl; return 0; }\ntemplate<typename\
    \ Head> int print(Head&& head){ cout << head; return print(); }\ntemplate<typename\
    \ Head, typename... Tail> int print(Head&& head, Tail&&... tail) { cout << head\
    \ << \" \"; return print(forward<Tail>(tail)...); }\n#ifdef LOCAL\ninline void\
    \ dump() { cerr << endl; }\ntemplate<typename Head> void dump(Head&& head) { cerr\
    \ << head; dump(); }\ntemplate<typename Head, typename... Tail> void dump(Head&&\
    \ head, Tail&&... tail) { cerr << head << \", \"; dump(forward<Tail>(tail)...);\
    \ }\n#define debug(...) do {cerr << __LINE__ << \":\\t\" << #__VA_ARGS__ << \"\
    \ = \"; dump(__VA_ARGS__); } while (false)\n#else\n#define dump(...)\n#define\
    \ debug(...)\n#endif\n/* OTHER */\n#define fi              first\n#define se \
    \             second\n#define MP              make_pair\n#define MT          \
    \    make_tuple\ntemplate<typename T, typename A, typename B> inline bool between(T\
    \ x, A a, B b) { return ((a <= x) && (x < b)); }\ntemplate<typename A, typename\
    \ B> inline bool chmax(A &a, const B &b) { if (a < b) { a = b; return true; }\
    \ return false; }\ntemplate<typename A, typename B> inline bool chmin(A &a, const\
    \ B &b) { if (a > b) { a = b; return true; } return false; }\ninline ll gcd(ll\
    \ a, ll b) { return b ? gcd(b, a % b) : a; }\ninline ll lcm(ll a, ll b) { return\
    \ a / gcd(a, b) * b; }\ninline ll POW(ll a, ll b) { ll r = 1; do { if (b & 1)\
    \  r *= a; a *= a; } while (b >>= 1); return r; }\nstruct abracadabra {\n    abracadabra()\
    \ {\n        cin.tie(nullptr); ios::sync_with_stdio(false);\n        cout << fixed\
    \ << setprecision(20);\n        cerr << fixed << setprecision(5);\n    };\n} ABRACADABRA;\n\
    // clang-format off\n#pragma endregion\n#line 1 \"datastructure/segmenttree/lazysegmenttree.hpp\"\
    \n/**\n* @brief \u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n* @docs docs/datastructure/segmenttree/lazysegmenttree.md\n\
    */\n\ntemplate <typename M, typename OM, typename F, typename G, typename H, typename\
    \ P>\nstruct LazySegmentTree {\n    int sz;\n    const M ID_M;\n    const OM ID_OM;\n\
    \    F f;\n    G g;\n    H h;\n    P p;\n    vector<M> dat;\n    vector<OM> laz;\n\
    \    LazySegmentTree(int n, M ID_M, OM ID_OM, F f, G g, H h, P p)\n        : ID_M(ID_M),\
    \ ID_OM(ID_OM), f(f), g(g), h(h), p(p) { build(n); }\n    LazySegmentTree(const\
    \ vector<M> &v, M ID_M, OM ID_OM, F f, G g, H h, P p)\n        : ID_M(ID_M), ID_OM(ID_OM),\
    \ f(f), g(g), h(h), p(p) {\n        int n = v.size();\n        build(n);\n   \
    \     for (int i = 0; i < n; ++i) dat[i + sz - 1] = v[i];\n        for (int i\
    \ = sz - 2; i >= 0; --i) dat[i] = f(dat[2 * i + 1], dat[2 * i + 2]);\n    }\n\
    \    void build(int n) {\n        sz = 1;\n        while (sz < n) sz <<= 1;\n\
    \        dat.assign(2 * sz - 1, ID_M);\n        laz.assign(2 * sz - 1, ID_OM);\n\
    \    }\n    void eval(int len, int k) {\n        if (laz[k] == ID_OM) return;\n\
    \        if (2 * k + 1 < 2 * sz - 1) {\n            laz[2 * k + 1] = h(laz[2 *\
    \ k + 1], laz[k]);\n            laz[2 * k + 2] = h(laz[2 * k + 2], laz[k]);\n\
    \        }\n        dat[k] = g(dat[k], p(laz[k], len));\n        laz[k] = ID_OM;\n\
    \    }\n    M update(int a, int b, OM x, int k, int l, int r) {\n        eval(r\
    \ - l, k);\n        if (r <= a or b <= l) return dat[k];\n        if (a <= l and\
    \ r <= b) {\n            laz[k] = h(laz[k], x);\n            return g(dat[k],\
    \ p(laz[k], r - l));\n        }\n        return dat[k] = f(update(a, b, x, 2 *\
    \ k + 1, l, (l + r) / 2),\n                          update(a, b, x, 2 * k + 2,\
    \ (l + r) / 2, r));\n    }\n    M update(int a, int b, OM x) {\n        return\
    \ update(a, b, x, 0, 0, sz);\n    }\n    M query(int a, int b, int k, int l, int\
    \ r) {\n        eval(r - l, k);\n        if (r <= a or b <= l) return ID_M;\n\
    \        if (a <= l and r <= b) return dat[k];\n        M vl = query(a, b, 2 *\
    \ k + 1, l, (l + r) / 2);\n        M vr = query(a, b, 2 * k + 2, (l + r) / 2,\
    \ r);\n        return f(vl, vr);\n    }\n    M query(int a, int b) {\n       \
    \ return query(a, b, 0, 0, sz);\n    }\n    M operator[](const int &k) {\n   \
    \     return query(k, k + 1);\n    }\n    void print() {\n        for (int i =\
    \ 0; i < sz; ++i) cerr << query(i, i + 1) << ' ';\n        cerr << endl;\n   \
    \ }\n};\n\ntemplate <typename M, typename OM, typename F, typename G, typename\
    \ H, typename P>\nauto make_segtree(int n, M ID_M, OM ID_OM, F f, G g, H h, P\
    \ p) {\n    return LazySegmentTree<M, OM, F, G, H, P>(n, ID_M, ID_OM, f, g, h,\
    \ p);\n}\ntemplate <typename M, typename OM, typename F, typename G, typename\
    \ H, typename P>\nauto make_segtree(vector<M> v, M ID_M, OM ID_OM, F f, G g, H\
    \ h, P p) {\n    return LazySegmentTree<M, OM, F, G, H, P>(v, ID_M, ID_OM, f,\
    \ g, h, p);\n}\n#line 5 \"test/yosupo/rangeaffinerangesum.test.cpp\"\n\nconstexpr\
    \ int MODULO = 998244353;\n\nsigned main() {\n\n    int N, Q;\n    cin >> N >>\
    \ Q;\n\n    using lint = long long;\n    vector<lint> A(N);\n    for (auto& e:\
    \ A) cin >> e;\n\n    using M = lint;\n    using OM = pair<lint, lint>;\n\n  \
    \  auto f = [](M a, M b) -> M {\n        return (a + b) % MODULO;\n    };\n  \
    \  auto g = [](M a, OM b) -> M {\n        return (b.first * a + b.second) % MODULO;\n\
    \    };\n    auto h = [](OM a, OM b) -> OM {\n        return OM((a.first * b.first)\
    \ % MODULO, (a.second * b.first + b.second) % MODULO);\n    };\n    auto p = [](OM\
    \ a, int n) -> OM {\n        return OM(a.first, (a.second * n) % MODULO);\n  \
    \  };\n\n    auto seg = make_segtree(A, M(0), OM(1, 0), f, g, h, p);\n\n    while\
    \ (Q--) {\n        int t, l, r;\n        cin >> t >> l >> r;\n        if (t ==\
    \ 0) {\n            lint b, c;  cin >> b >> c;\n            seg.update(l, r, OM(b,\
    \ c));\n        } else {\n            cout << seg.query(l, r) << endl;\n     \
    \   }\n    }\n\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include \"../../template/main.hpp\"\n#include \"../../datastructure/segmenttree/lazysegmenttree.hpp\"\
    \n\nconstexpr int MODULO = 998244353;\n\nsigned main() {\n\n    int N, Q;\n  \
    \  cin >> N >> Q;\n\n    using lint = long long;\n    vector<lint> A(N);\n   \
    \ for (auto& e: A) cin >> e;\n\n    using M = lint;\n    using OM = pair<lint,\
    \ lint>;\n\n    auto f = [](M a, M b) -> M {\n        return (a + b) % MODULO;\n\
    \    };\n    auto g = [](M a, OM b) -> M {\n        return (b.first * a + b.second)\
    \ % MODULO;\n    };\n    auto h = [](OM a, OM b) -> OM {\n        return OM((a.first\
    \ * b.first) % MODULO, (a.second * b.first + b.second) % MODULO);\n    };\n  \
    \  auto p = [](OM a, int n) -> OM {\n        return OM(a.first, (a.second * n)\
    \ % MODULO);\n    };\n\n    auto seg = make_segtree(A, M(0), OM(1, 0), f, g, h,\
    \ p);\n\n    while (Q--) {\n        int t, l, r;\n        cin >> t >> l >> r;\n\
    \        if (t == 0) {\n            lint b, c;  cin >> b >> c;\n            seg.update(l,\
    \ r, OM(b, c));\n        } else {\n            cout << seg.query(l, r) << endl;\n\
    \        }\n    }\n\n}\n"
  dependsOn:
  - template/main.hpp
  - datastructure/segmenttree/lazysegmenttree.hpp
  isVerificationFile: true
  path: test/yosupo/rangeaffinerangesum.test.cpp
  requiredBy: []
  timestamp: '2020-09-27 22:42:12+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/rangeaffinerangesum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/rangeaffinerangesum.test.cpp
- /verify/test/yosupo/rangeaffinerangesum.test.cpp.html
title: test/yosupo/rangeaffinerangesum.test.cpp
---
