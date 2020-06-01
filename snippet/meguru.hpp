/**
 * @brief めぐる式二分探索
 */

using T = long long;
auto check = [&](T mid) -> bool {
    $3
};

T ok = ${1:0}, ng = ${2:1e9};
// for (int _ = 0; _ < 1000; ++_) {
while (abs(ok - ng) > 1) {
    T mid = (ok + ng) / 2;
    (check(mid) ? ok : ng) = mid;
}
