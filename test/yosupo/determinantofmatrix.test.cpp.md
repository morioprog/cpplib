---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/matrix/matrix.hpp
    title: "Matrix (\u884C\u5217)"
  - icon: ':heavy_check_mark:'
    path: math/modint.hpp
    title: ModInt
  - icon: ':heavy_check_mark:'
    path: template/main.hpp
    title: template/main.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/matrix_det
    links:
    - https://judge.yosupo.jp/problem/matrix_det
  bundledCode: "#line 1 \"test/yosupo/determinantofmatrix.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/matrix_det\"\n\n#line 1 \"template/main.hpp\"\
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
    // clang-format off\n#pragma endregion\n#line 1 \"math/modint.hpp\"\n/**\n * @brief\
    \ ModInt\n * @docs docs/math/modint.md\n */\n\ntemplate <int MODULO>\nstruct ModInt\
    \ {\n    using i32 = int;\n    using i64 = long long;\n    using u32 = unsigned\
    \ int;\n    using u64 = unsigned long long;\n    u64 x;\n    ModInt()\n      \
    \  : x(0) {}\n    ModInt(i64 y)\n        : x(set(y % MODULO + MODULO)) {}\n  \
    \  static u64 set(const i64 &y) { return (y < MODULO) ? y : y - MODULO; }\n  \
    \  ModInt operator+(const ModInt &m) const { return ModInt(set(x + m.x)); }\n\
    \    ModInt operator-(const ModInt &m) const { return ModInt(set(x + MODULO -\
    \ m.x)); }\n    ModInt operator*(const ModInt &m) const { return ModInt(x * m.x\
    \ % MODULO); }\n    ModInt operator/(const ModInt &m) const { return ModInt(x)\
    \ * ~ModInt(m.x); }\n    ModInt &operator+=(const ModInt &m) { return *this =\
    \ *this + m; }\n    ModInt &operator-=(const ModInt &m) { return *this = *this\
    \ - m; }\n    ModInt &operator*=(const ModInt &m) { return *this = *this * m;\
    \ }\n    ModInt &operator/=(const ModInt &m) { return *this = *this / m; }\n \
    \   ModInt &operator^=(const u64 &y) { return *this = *this ^ y; }\n    ModInt\
    \ operator~() const { return *this ^ (MODULO - 2); }\n    ModInt operator-() const\
    \ { return ModInt(set(MODULO - x)); }\n    ModInt operator++() { return *this\
    \ = ModInt(set(x + 1)); }\n    ModInt operator--() { return *this = ModInt(set(x\
    \ + MODULO - 1)); }\n    bool operator<(const ModInt &m) const { return x < m.x;\
    \ }\n    bool operator>(const ModInt &m) const { return x > m.x; }\n    bool operator==(const\
    \ ModInt &m) const { return x == m.x; }\n    bool operator!=(const ModInt &m)\
    \ const { return x != m.x; }\n    bool operator<=(const ModInt &m) const { return\
    \ x <= m.x; }\n    bool operator>=(const ModInt &m) const { return x >= m.x; }\n\
    \    explicit operator u64() const { return x; }\n    ModInt operator^(i64 y)\
    \ const { return pow(x, y); }\n    static ModInt pow(i64 x, i64 y) {\n       \
    \ bool neg = false;\n        if (y < 0) y = -y, neg = true;\n        ModInt u(1),\
    \ t(x);\n        while (y) {\n            if (y & 1) u *= t;\n            t *=\
    \ t;\n            y >>= 1;\n        }\n        return neg ? ModInt(1) / u : u;\n\
    \    }\n    friend ostream &operator<<(ostream &os, const ModInt<MODULO> &m) {\
    \ return os << m.x; }\n    friend istream &operator>>(istream &is, ModInt<MODULO>\
    \ &m) {\n        u64 y;\n        is >> y;\n        m = ModInt(y);\n        return\
    \ is;\n    }\n};\nconstexpr int MODULO = (int)1e9 + 7;\nusing modint         =\
    \ ModInt<MODULO>;\n#line 1 \"math/matrix/matrix.hpp\"\n/**\n* @brief Matrix (\u884C\
    \u5217)\n* @docs docs/math/matrix/matrix.md\n*/\n\ntemplate <typename T>\nstruct\
    \ Matrix {\n    vector<vector<T>> A;\n    Matrix() {}\n    Matrix(size_t n, size_t\
    \ m)\n        : A(n, vector<T>(m, 0)) {}\n    Matrix(size_t n)\n        : A(n,\
    \ vector<T>(n, 0)) {}\n    size_t height() const { return A.size(); }\n    size_t\
    \ width() const {\n        assert(height() > 0);\n        return A[0].size();\n\
    \    }\n    inline const vector<T> &operator[](int k) const { return A.at(k);\
    \ }\n    inline vector<T> &operator[](int k) { return A.at(k); }\n    static Matrix\
    \ I(size_t n) {\n        Matrix mat(n);\n        for (int i = 0; i < n; ++i) mat[i][i]\
    \ = 1;\n        return mat;\n    }\n    Matrix &operator+=(const Matrix &B) {\n\
    \        size_t n = height(), m = width();\n        assert(n == B.height() and\
    \ m == B.width());\n        for (int i = 0; i < n; ++i)\n            for (int\
    \ j = 0; j < m; ++j)\n                (*this)[i][j] += B[i][j];\n        return\
    \ *this;\n    }\n    Matrix &operator-=(const Matrix &B) {\n        size_t n =\
    \ height(), m = width();\n        assert(n == B.height() and m == B.width());\n\
    \        for (int i = 0; i < n; ++i)\n            for (int j = 0; j < m; ++j)\n\
    \                (*this)[i][j] -= B[i][j];\n        return *this;\n    }\n   \
    \ Matrix &operator*=(const Matrix &B) {\n        size_t n = height(), m = B.width(),\
    \ p = width();\n        assert(p == B.height());\n        vector<vector<T>> C(n,\
    \ vector<T>(m, 0));\n        for (int i = 0; i < n; ++i)\n            for (int\
    \ j = 0; j < m; ++j)\n                for (int k = 0; k < p; ++k)\n          \
    \          C[i][j] += (*this)[i][k] * B[k][j];\n        A.swap(C);\n        return\
    \ *this;\n    }\n    Matrix &operator^=(long long k) {\n        Matrix B = Matrix::I(height());\n\
    \        while (k > 0) {\n            if (k & 1) B *= *this;\n            *this\
    \ *= *this;\n            k >>= 1LL;\n        }\n        A.swap(B.A);\n       \
    \ return *this;\n    }\n    Matrix operator+(const Matrix &B) const { return (Matrix(*this)\
    \ += B); }\n    Matrix operator-(const Matrix &B) const { return (Matrix(*this)\
    \ -= B); }\n    Matrix operator*(const Matrix &B) const { return (Matrix(*this)\
    \ *= B); }\n    Matrix operator^(const long long k) const { return (Matrix(*this)\
    \ ^= k); }\n    friend istream &operator>>(istream &is, Matrix &p) {\n       \
    \ size_t n = p.height(), m = p.width();\n        for (int i = 0; i < n; ++i) {\n\
    \            for (int j = 0; j < m; ++j) {\n                is >> p[i][j];\n \
    \           }\n        }\n        return is;\n    }\n    friend ostream &operator<<(ostream\
    \ &os, Matrix &p) {\n        size_t n = p.height(), m = p.width();\n        for\
    \ (int i = 0; i < n; ++i) {\n            os << '[';\n            for (int j =\
    \ 0; j < m; ++j) {\n                os << p[i][j] << (j + 1 == m ? \"]\\n\" :\
    \ \", \");\n            }\n        }\n        return os;\n    }\n    T determinant()\
    \ {\n        Matrix B(*this);\n        assert(width() == height());\n        T\
    \ ret = 1;\n        for (int i = 0; i < width(); ++i) {\n            int idx =\
    \ -1;\n            for (int j = i; j < width(); ++j)\n                if (B[j][i]\
    \ != 0) idx = j;\n            if (idx == -1) return T(0);\n            if (i !=\
    \ idx) {\n                ret *= -1;\n                swap(B[i], B[idx]);\n  \
    \          }\n            ret *= B[i][i];\n            T vv = B[i][i];\n     \
    \       for (int j = 0; j < width(); ++j) B[i][j] /= vv;\n            for (int\
    \ j = i + 1; j < width(); ++j) {\n                T a = B[j][i];\n           \
    \     for (int k = 0; k < width(); ++k) B[j][k] -= B[i][k] * a;\n            }\n\
    \        }\n        return ret;\n    }\n};\n#line 6 \"test/yosupo/determinantofmatrix.test.cpp\"\
    \n\nusing mint = ModInt<998244353>;\n\nsigned main() {\n\n    int N;\n    cin\
    \ >> N;\n    \n    Matrix<mint> mat(N);\n    cin >> mat;\n\n    cout << mat.determinant()\
    \ << endl;\n\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\n\n#include\
    \ \"../../template/main.hpp\"\n#include \"../../math/modint.hpp\"\n#include \"\
    ../../math/matrix/matrix.hpp\"\n\nusing mint = ModInt<998244353>;\n\nsigned main()\
    \ {\n\n    int N;\n    cin >> N;\n    \n    Matrix<mint> mat(N);\n    cin >> mat;\n\
    \n    cout << mat.determinant() << endl;\n\n}\n"
  dependsOn:
  - template/main.hpp
  - math/modint.hpp
  - math/matrix/matrix.hpp
  isVerificationFile: true
  path: test/yosupo/determinantofmatrix.test.cpp
  requiredBy: []
  timestamp: '2020-09-27 21:24:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/determinantofmatrix.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/determinantofmatrix.test.cpp
- /verify/test/yosupo/determinantofmatrix.test.cpp.html
title: test/yosupo/determinantofmatrix.test.cpp
---
