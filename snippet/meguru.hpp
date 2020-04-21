/**
 * @brief めぐる式二分探索
 */

auto check = [&](long long mid) -> bool {
    $3
};

long long ok = $1, ng = $2;
while (abs(ok - ng) > 1) {
    long long mid = (ok + ng) >> 1;
    (check(mid) ? ok : ng) = mid;
}
