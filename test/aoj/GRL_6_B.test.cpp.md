---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/minimumcostflow/primaldual.hpp
    title: Primal Dual
  - icon: ':question:'
    path: template/main.hpp
    title: template/main.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B
  bundledCode: "#line 1 \"test/aoj/GRL_6_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B\"\
    \n\n#line 1 \"template/main.hpp\"\n#pragma region optimize\n// #pragma GCC optimize(\"\
    Ofast\")\n// #pragma GCC optimize(\"unroll-loops\")\n// #pragma GCC target(\"\
    sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx\")\n#pragma endregion\n#include <bits/stdc++.h>\n\
    using namespace std;\n// #include <atcoder/all>\n#pragma region boost multiprecision\n\
    // #include <boost/multiprecision/cpp_dec_float.hpp>\n// #include <boost/multiprecision/cpp_int.hpp>\n\
    // using Bint       = boost::multiprecision::cpp_int;\n// using Bfloat32   = boost::multiprecision::number<boost::multiprecision::cpp_dec_float<32>>;\n\
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
    // clang-format off\n#pragma endregion\n#line 1 \"graph/minimumcostflow/primaldual.hpp\"\
    \n/**\n* @brief Primal Dual\n* @docs docs/graph/minimumcostflow/primaldual.md\n\
    * @see http://www.prefield.com/algorithm/graph/primal_dual.html\n* @note O(FE\\\
    log V)\n*/\n\ntemplate <typename Cst, typename Cap>\nstruct PrimalDual {\n   \
    \ struct CapEdge {\n        int to, rev;\n        Cst cst;\n        Cap cap;\n\
    \        CapEdge() {}\n        CapEdge(int t, int r, Cst cst, Cap cap)\n     \
    \       : to(t), rev(r), cst(cst), cap(cap) {}\n        operator int() const {\
    \ return to; }\n    };\n    using P = pair<Cst, int>;\n    const Cst INF;\n  \
    \  int V;\n    vector<vector<CapEdge>> graph;\n    vector<Cst> pot, min_cst;\n\
    \    vector<int> prv_v, prv_e;\n    PrimalDual(int V)\n        : INF(numeric_limits<Cst>::max()),\
    \ V(V), graph(V) {}\n    void add_arc(int a, int b, Cst cst, Cap cap) {\n    \
    \    graph[a].emplace_back(b, (int)graph[b].size(), cst, cap);\n        graph[b].emplace_back(a,\
    \ (int)graph[a].size() - 1, -cst, 0);\n    }\n    Cst min_cost_flow(int s, int\
    \ t, Cap flw) {\n        pot.assign(V, 0);\n        prv_e.assign(V, -1);\n   \
    \     prv_v.assign(V, -1);\n        Cst ret = 0;\n        priority_queue<P, vector<P>,\
    \ greater<P>> pq;\n        while (flw > 0) {\n            min_cst.assign(V, INF);\n\
    \            pq.push(P(0, s));\n            min_cst[s] = 0;\n            while\
    \ (not pq.empty()) {\n                Cst cst;\n                int idx;\n   \
    \             tie(cst, idx) = pq.top();\n                pq.pop();\n         \
    \       if (min_cst[idx] < cst) continue;\n                for (int i = 0; i <\
    \ (int)graph[idx].size(); ++i) {\n                    CapEdge &nxt = graph[idx][i];\n\
    \                    int nxt_cst  = min_cst[idx] + nxt.cst + pot[idx] - pot[nxt];\n\
    \                    if (nxt.cap > 0 and min_cst[nxt] > nxt_cst) {\n         \
    \               min_cst[nxt] = nxt_cst;\n                        prv_v[nxt] =\
    \ idx, prv_e[nxt] = i;\n                        pq.push(P(min_cst[nxt], nxt));\n\
    \                    }\n                }\n            }\n            if (min_cst[t]\
    \ == INF) return -1;\n            for (int v = 0; v < V; ++v) pot[v] += min_cst[v];\n\
    \            Cap add_flw = flw;\n            for (int v = t; v != s; v = prv_v[v])\
    \ {\n                add_flw = min(add_flw, graph[prv_v[v]][prv_e[v]].cap);\n\
    \            }\n            flw -= add_flw;\n            ret += add_flw * pot[t];\n\
    \            for (int v = t; v != s; v = prv_v[v]) {\n                CapEdge\
    \ &e = graph[prv_v[v]][prv_e[v]];\n                e.cap -= add_flw;\n       \
    \         graph[v][e.rev].cap += add_flw;\n            }\n        }\n        return\
    \ ret;\n    }\n};\n#line 5 \"test/aoj/GRL_6_B.test.cpp\"\n\nsigned main() {\n\n\
    \    int V, E, F;\n    cin >> V >> E >> F;\n\n    PrimalDual<int, int> pd(V);\n\
    \    for (int i = 0; i < E; ++i) {\n        int u, v, cap, cst;\n        cin >>\
    \ u >> v >> cap >> cst;\n        pd.add_arc(u, v, cst, cap);\n    }\n\n    cout\
    \ << pd.min_cost_flow(0, V - 1, F) << endl;\n\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B\"\
    \n\n#include \"../../template/main.hpp\"\n#include \"../../graph/minimumcostflow/primaldual.hpp\"\
    \n\nsigned main() {\n\n    int V, E, F;\n    cin >> V >> E >> F;\n\n    PrimalDual<int,\
    \ int> pd(V);\n    for (int i = 0; i < E; ++i) {\n        int u, v, cap, cst;\n\
    \        cin >> u >> v >> cap >> cst;\n        pd.add_arc(u, v, cst, cap);\n \
    \   }\n\n    cout << pd.min_cost_flow(0, V - 1, F) << endl;\n\n}\n"
  dependsOn:
  - template/main.hpp
  - graph/minimumcostflow/primaldual.hpp
  isVerificationFile: true
  path: test/aoj/GRL_6_B.test.cpp
  requiredBy: []
  timestamp: '2020-09-27 21:24:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_6_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_6_B.test.cpp
- /verify/test/aoj/GRL_6_B.test.cpp.html
title: test/aoj/GRL_6_B.test.cpp
---
