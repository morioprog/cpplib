---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/maximumflow/dinic.hpp
    title: "Dinic\u6CD5"
  - icon: ':heavy_check_mark:'
    path: template/main.hpp
    title: template/main.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
  bundledCode: "#line 1 \"test/aoj/GRL_6_A.dinic.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\
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
    // clang-format off\n#pragma endregion\n#line 1 \"graph/maximumflow/dinic.hpp\"\
    \n/**\n* @brief Dinic\u6CD5\n* @docs docs/graph/maximumflow/dinic.md\n* @see http://yosupo.hatenablog.com/entry/2015/03/31/134336\n\
    * @note O(E * V ^ 2)\n*/\n\ntemplate <typename T>\nstruct Dinic {\n    struct\
    \ CapEdge {\n        int to, rev;\n        T cap;\n        CapEdge() {}\n    \
    \    CapEdge(int t, int r, T c)\n            : to(t), rev(r), cap(c) {}\n    \
    \    operator int() const { return to; }\n    };\n    const T INF;\n    vector<vector<CapEdge>>\
    \ graph;\n    vector<T> min_cst;\n    vector<int> itr;\n    Dinic(int n)\n   \
    \     : INF(numeric_limits<T>::max()), graph(n) {}\n    void add_arc(int a, int\
    \ b, T c) {\n        graph[a].emplace_back(b, (int)graph[b].size(), c);\n    \
    \    graph[b].emplace_back(a, (int)graph[a].size() - 1, 0);\n    }\n    void add_edge(int\
    \ a, int b, T c) {\n        graph[a].emplace_back(b, (int)graph[b].size(), c);\n\
    \        graph[b].emplace_back(a, (int)graph[a].size() - 1, c);\n    }\n    bool\
    \ bfs(int s, int t) {\n        queue<int> que;\n        min_cst.assign((int)graph.size(),\
    \ -1);\n        min_cst[s] = 0;\n        que.emplace(s);\n        while (not que.empty())\
    \ {\n            int idx = que.front();\n            que.pop();\n            for\
    \ (auto& nxt : graph[idx]) {\n                if (nxt.cap > 0 and min_cst[nxt]\
    \ == -1) {\n                    min_cst[nxt] = min_cst[idx] + 1;\n           \
    \         que.emplace(nxt);\n                }\n            }\n        }\n   \
    \     return min_cst[t] != -1;\n    }\n    T dfs(int idx, const int t, T flw)\
    \ {\n        if (idx == t) return flw;\n        for (int& i = itr[idx]; i < (int)graph[idx].size();\
    \ ++i) {\n            CapEdge& nxt = graph[idx][i];\n            if (nxt.cap >\
    \ 0 and min_cst[idx] < min_cst[nxt]) {\n                T d = dfs(nxt, t, min(flw,\
    \ nxt.cap));\n                if (d > 0) {\n                    nxt.cap -= d;\n\
    \                    graph[nxt][nxt.rev].cap += d;\n                    return\
    \ d;\n                }\n            }\n        }\n        return 0;\n    }\n\
    \    T max_flow(int s, int t) {\n        T ret = 0;\n        while (bfs(s, t))\
    \ {\n            itr.assign(graph.size(), 0);\n            for (T tmp; (tmp =\
    \ dfs(s, t, INF)) > 0;) ret += tmp;\n        }\n        return ret;\n    }\n};\n\
    #line 5 \"test/aoj/GRL_6_A.dinic.test.cpp\"\n\nsigned main() {\n\n    int V, E;\n\
    \    cin >> V >> E;\n\n    Dinic<int> dnc(V);\n    for (int i = 0; i < E; ++i)\
    \ {\n        int u, v, c;\n        cin >> u >> v >> c;\n        dnc.add_arc(u,\
    \ v, c);\n    }\n\n    cout << dnc.max_flow(0, V - 1) << endl;\n\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\
    \n\n#include \"../../template/main.hpp\"\n#include \"../../graph/maximumflow/dinic.hpp\"\
    \n\nsigned main() {\n\n    int V, E;\n    cin >> V >> E;\n\n    Dinic<int> dnc(V);\n\
    \    for (int i = 0; i < E; ++i) {\n        int u, v, c;\n        cin >> u >>\
    \ v >> c;\n        dnc.add_arc(u, v, c);\n    }\n\n    cout << dnc.max_flow(0,\
    \ V - 1) << endl;\n\n}\n"
  dependsOn:
  - template/main.hpp
  - graph/maximumflow/dinic.hpp
  isVerificationFile: true
  path: test/aoj/GRL_6_A.dinic.test.cpp
  requiredBy: []
  timestamp: '2020-09-27 21:24:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_6_A.dinic.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_6_A.dinic.test.cpp
- /verify/test/aoj/GRL_6_A.dinic.test.cpp.html
title: test/aoj/GRL_6_A.dinic.test.cpp
---