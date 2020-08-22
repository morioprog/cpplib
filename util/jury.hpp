/**
* @brief インタラクティブ問題
* @docs docs/util/jury.md
*/

template<typename T, typename R, int QMX>
struct Jury {
    int query_cnt;
    map<T, R> memo;
    T N;
    Jury() : query_cnt(0) {
        // N = rand();
#ifdef LOCAL
        cerr << "N : " << N << endl;
#endif
    }
    Jury(T _N) : query_cnt(0) {
        N = _N;
#ifdef LOCAL
        cerr << "N : " << N << endl;
#endif
    }
    R query(T X) {
        if (memo.count(X)) return memo[X];
        if (++query_cnt > QMX) {
            cerr << "Query Limit Exceeded" << endl;
            exit(1);
        }
#ifdef LOCAL
        cerr << query_cnt << " : " << X << endl;
        // return memo[n] = ...;
#else
        // cout << "? " << X << endl;
        // int rsp;  cin >> rsp;
        // return memo[n] = rsp;
#endif
    }
    void answer(T X) {
#ifdef LOCAL
        if (X == N) {
            cerr << "AC : " << X << endl;
        } else {
            cerr << "WA : " << X << " " << N << endl;
        }
        // exit(0);
#else
        // cout << "! " << X << endl;
        exit(0);
#endif
    }
};
