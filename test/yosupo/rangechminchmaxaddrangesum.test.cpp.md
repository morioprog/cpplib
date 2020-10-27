---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/segmenttree/segmenttreebeats.hpp
    title: Segment Tree Beats
  - icon: ':heavy_check_mark:'
    path: template/main.hpp
    title: template/main.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
  bundledCode: "#line 1 \"test/yosupo/rangechminchmaxaddrangesum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\n\
    \n#line 1 \"template/main.hpp\"\n#pragma region optimize\n// #pragma GCC optimize(\"\
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
    // clang-format off\n#pragma endregion\n#line 1 \"datastructure/segmenttree/segmenttreebeats.hpp\"\
    \n/**\n* @brief Segment Tree Beats\n* @docs docs/datastructure/segmenttree/segmenttreebeats.md\n\
    */\n\n// clang-format off\nstruct SegmentTreeBeats {\n    static const long long\
    \ INF = 1LL << 60;\n    struct Node {\n        Node *left, *right;\n        long\
    \ long max_v, smax_v, max_c;\n        long long min_v, smin_v, min_c;\n      \
    \  long long sum;\n        long long len, ladd, lval;\n\n        Node() : left(0),\
    \ right(0), ladd(0), lval(INF) {}\n\n        void init(long long x) {\n      \
    \      max_v = min_v = sum = x;\n            smax_v = -INF; smin_v = INF;\n  \
    \          max_c = min_c = 1;\n        }\n\n        void init_empty() {\n    \
    \        max_v = smax_v = -INF;\n            min_v = smin_v = INF;\n         \
    \   max_c = min_c = 0;\n        }\n\n        void update_max(long long x) {\n\
    \            sum += (x - max_v) * max_c;\n            /* */if (max_v ==  min_v)\
    \ max_v =  min_v = x;\n            else if (max_v == smin_v) max_v = smin_v =\
    \ x;\n            else                      max_v = x;\n            if (lval !=\
    \ INF and x < lval) lval = x;\n        }\n\n        void update_min(long long\
    \ x) {\n            sum += (x - min_v) * min_c;\n            /* */if (max_v ==\
    \  min_v) max_v =  min_v = x;\n            else if (max_v == smin_v) min_v = smax_v\
    \ = x;\n            else                      min_v = x;\n            if (lval\
    \ != INF and lval < x) lval = x;\n        }\n\n        void addall(long long x)\
    \ {\n            max_v += x;\n            if (smax_v != -INF) smax_v += x;\n \
    \           min_v += x;\n            if (smin_v != INF) smin_v += x;\n       \
    \     sum += len * x;\n            if (lval != INF) lval += x;\n            else\
    \             ladd += x;\n        }\n\n        void updateall(long long x) {\n\
    \            max_v = min_v = x;\n            smax_v = -INF; smin_v = INF;\n  \
    \          max_c = min_c = len;\n            sum = len * x;\n            lval\
    \ = x; ladd = 0;\n        }\n\n        void push() {\n            if (lval !=\
    \ INF) {\n                 left -> updateall(lval);\n                right ->\
    \ updateall(lval);\n                lval = INF;\n                return;\n   \
    \         }\n            if (ladd != 0) {\n                 left -> addall(ladd);\n\
    \                right -> addall(ladd);\n                ladd = 0;\n         \
    \   }\n            if (max_v < left -> max_v)   left -> update_max(max_v);\n \
    \           if (left -> min_v < min_v)   left -> update_min(min_v);\n        \
    \    if (max_v < right -> max_v) right -> update_max(max_v);\n            if (right\
    \ -> min_v < min_v) right -> update_min(min_v);\n        }\n\n        void update()\
    \ {\n            sum = left -> sum + right -> sum;\n            if (left -> max_v\
    \ < right -> max_v) {\n                max_v = right -> max_v;\n             \
    \   max_c = right -> max_c;\n                smax_v = max(left -> max_v, right\
    \ -> smax_v);\n            } else if (left -> max_v > right -> max_v) {\n    \
    \            max_v = left -> max_v;\n                max_c = left -> max_c;\n\
    \                smax_v = max(left -> smax_v, right -> max_v);\n            }\
    \ else {\n                max_v = left -> max_v;\n                max_c = left\
    \ -> max_c + right -> max_c;\n                smax_v = max(left -> smax_v, right\
    \ -> smax_v);\n            }\n            if (left -> min_v < right -> min_v)\
    \ {\n                min_v = left -> min_v;\n                min_c = left -> min_c;\n\
    \                smin_v = min(left -> smin_v, right -> min_v);\n            }\
    \ else if (left -> min_v > right -> min_v) {\n                min_v = right ->\
    \ min_v;\n                min_c = right -> min_c;\n                smin_v = min(left\
    \ -> min_v, right -> smin_v);\n            } else {\n                min_v = left\
    \ -> min_v;\n                min_c = left -> min_c + right -> min_c;\n       \
    \         smin_v = min(left -> smin_v, right -> smin_v);\n            }\n    \
    \    }\n    };\n\n    int n, n0;\n    Node *root;\n\n    void _update_min(long\
    \ long x, int a, int b, Node *nd, int l, int r) {\n        if (b <= l || r <=\
    \ a || nd -> max_v <= x) return;\n        if (a <= l && r <= b && nd -> smax_v\
    \ < x) {\n            nd -> update_max(x);\n            return;\n        }\n \
    \       nd -> push();\n        _update_min(x, a, b, nd ->  left, l, (l + r) >>\
    \ 1);\n        _update_min(x, a, b, nd -> right, (l + r) >> 1, r);\n        nd\
    \ -> update();\n    }\n\n    void _update_max(long long x, int a, int b, Node\
    \ *nd, int l, int r) {\n        if (b <= l || r <= a || x <= nd -> min_v) return;\n\
    \        if (a <= l && r <= b && x < nd -> smin_v) {\n            nd -> update_min(x);\n\
    \            return;\n        }\n        nd -> push();\n        _update_max(x,\
    \ a, b, nd ->  left, l, (l + r) >> 1);\n        _update_max(x, a, b, nd -> right,\
    \ (l + r) >> 1, r);\n        nd -> update();\n    }\n\n    void _add_val(long\
    \ long x, int a, int b, Node *nd, int l, int r) {\n        if (b <= l || r <=\
    \ a) return;\n        if (a <= l && r <= b) {\n            nd -> addall(x);\n\
    \            return;\n        }\n        nd -> push();\n        _add_val(x, a,\
    \ b, nd ->  left, l, (l + r) >> 1);\n        _add_val(x, a, b, nd -> right, (l\
    \ + r) >> 1, r);\n        nd -> update();\n    }\n\n    void _update_val(long\
    \ long x, int a, int b, Node *nd, int l, int r) {\n        if (b <= l || r <=\
    \ a) return;\n        if (a <= l && r <= b) {\n            nd -> updateall(x);\n\
    \            return;\n        }\n        nd -> push();\n        _update_val(x,\
    \ a, b, nd ->  left, l, (l + r) >> 1);\n        _update_val(x, a, b, nd -> right,\
    \ (l + r) >> 1, r);\n        nd -> update();\n    }\n\n    long long _query_max(int\
    \ a, int b, Node *nd, int l, int r) {\n        if (b <= l || r <= a) return -INF;\n\
    \        if (a <= l && r <= b) return nd -> max_v;\n        nd -> push();\n  \
    \      long long lv = _query_max(a, b, nd ->  left, l, (l + r) >> 1);\n      \
    \  long long rv = _query_max(a, b, nd -> right, (l + r) >> 1, r);\n        return\
    \ max(lv, rv);\n    }\n\n    long long _query_min(int a, int b, Node *nd, int\
    \ l, int r) {\n        if (b <= l || r <= a) return INF;\n        if (a <= l &&\
    \ r <= b) return nd -> min_v;\n        nd -> push();\n        long long lv = _query_min(a,\
    \ b, nd ->  left, l, (l + r) >> 1);\n        long long rv = _query_min(a, b, nd\
    \ -> right, (l + r) >> 1, r);\n        return min(lv, rv);\n    }\n\n    long\
    \ long _query_sum(int a, int b, Node *nd, int l, int r) {\n        if (b <= l\
    \ || r <= a) return 0;\n        if (a <= l && r <= b) return nd -> sum;\n    \
    \    nd -> push();\n        long long lv = _query_sum(a, b, nd ->  left, l, (l\
    \ + r) >> 1);\n        long long rv = _query_sum(a, b, nd -> right, (l + r) >>\
    \ 1, r);\n        return lv + rv;\n    }\n\n    SegmentTreeBeats(int n, long long\
    \ val = 0) : n(n) {\n        n0 = 1; while (n0 < n) n0 <<= 1;\n        Node *nds\
    \ = new Node[2 * n0];\n        root = nds;\n        nds[0].len = n0;\n       \
    \ for (int i = 0; i < n0 - 1; ++i) {\n            nds[i].left = &nds[2 * i + 1];\n\
    \            nds[i].right = &nds[2 * i + 2];\n            nds[2 * i + 1].len =\
    \ nds[2 * i + 2].len = nds[i].len >> 1;\n        }\n        for (int i = 0; i\
    \ <  n; ++i) nds[n0 - 1 + i].init(val);\n        for (int i = n; i < n0; ++i)\
    \ nds[n0 - 1 + i].init_empty();\n        for (int i = n0 - 2; i >= 0; i--) nds[i].update();\n\
    \    }\n\n    SegmentTreeBeats(const vector<long long> &v) : n((int)v.size())\
    \ {\n        n0 = 1; while (n0 < n) n0 <<= 1;\n        Node *nds = new Node[2\
    \ * n0];\n        root = nds;\n        nds[0].len = n0;\n        for (int i =\
    \ 0; i < n0 - 1; ++i) {\n            nds[i].left = &nds[2 * i + 1];\n        \
    \    nds[i].right = &nds[2 * i + 2];\n            nds[2 * i + 1].len = nds[2 *\
    \ i + 2].len = nds[i].len >> 1;\n        }\n        for (int i = 0; i <  n; ++i)\
    \ nds[n0 - 1 + i].init(v[i]);\n        for (int i = n; i < n0; ++i) nds[n0 - 1\
    \ + i].init_empty();\n        for (int i = n0 - 2; i >= 0; i--) nds[i].update();\n\
    \    }\n\n    void update_min(int a, int b, long long x) { _update_min(x, a, b,\
    \ root, 0, n0); }\n    void update_max(int a, int b, long long x) { _update_max(x,\
    \ a, b, root, 0, n0); }\n    void    add_val(int a, int b, long long x) {    _add_val(x,\
    \ a, b, root, 0, n0); }\n    void update_val(int a, int b, long long x) { _update_val(x,\
    \ a, b, root, 0, n0); }\n    long long query_max(int a, int b) { return _query_max(a,\
    \ b, root, 0, n0); }\n    long long query_min(int a, int b) { return _query_min(a,\
    \ b, root, 0, n0); }\n    long long query_sum(int a, int b) { return _query_sum(a,\
    \ b, root, 0, n0); }\n};\n// clang-format on\n#line 5 \"test/yosupo/rangechminchmaxaddrangesum.test.cpp\"\
    \n\nsigned main() {\n\n    int N, Q;\n    cin >> N >> Q;\n\n    using lint = long\
    \ long;\n    vector<lint> A(N);\n    for (auto& e: A) cin >> e;\n\n    SegmentTreeBeats\
    \ seg(A);\n\n    while (Q--) {\n        int q, l, r;  cin >> q >> l >> r;\n  \
    \      if (q == 0) {\n            lint b; cin >> b;\n            seg.update_min(l,\
    \ r, b);\n        } else if (q == 1) {\n            lint b; cin >> b;\n      \
    \      seg.update_max(l, r, b);\n        } else if (q == 2) {\n            lint\
    \ b; cin >> b;\n            seg.add_val(l, r, b);\n        } else {\n        \
    \    cout << seg.query_sum(l, r) << endl;\n        }\n    }\n\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n\n#include \"../../template/main.hpp\"\n#include \"../../datastructure/segmenttree/segmenttreebeats.hpp\"\
    \n\nsigned main() {\n\n    int N, Q;\n    cin >> N >> Q;\n\n    using lint = long\
    \ long;\n    vector<lint> A(N);\n    for (auto& e: A) cin >> e;\n\n    SegmentTreeBeats\
    \ seg(A);\n\n    while (Q--) {\n        int q, l, r;  cin >> q >> l >> r;\n  \
    \      if (q == 0) {\n            lint b; cin >> b;\n            seg.update_min(l,\
    \ r, b);\n        } else if (q == 1) {\n            lint b; cin >> b;\n      \
    \      seg.update_max(l, r, b);\n        } else if (q == 2) {\n            lint\
    \ b; cin >> b;\n            seg.add_val(l, r, b);\n        } else {\n        \
    \    cout << seg.query_sum(l, r) << endl;\n        }\n    }\n\n}\n"
  dependsOn:
  - template/main.hpp
  - datastructure/segmenttree/segmenttreebeats.hpp
  isVerificationFile: true
  path: test/yosupo/rangechminchmaxaddrangesum.test.cpp
  requiredBy: []
  timestamp: '2020-09-27 21:24:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/rangechminchmaxaddrangesum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/rangechminchmaxaddrangesum.test.cpp
- /verify/test/yosupo/rangechminchmaxaddrangesum.test.cpp.html
title: test/yosupo/rangechminchmaxaddrangesum.test.cpp
---
