/**
 * @brief 三分探索
 */

using T = double;
auto f_trn = [&](T c) -> T {
    $3
};

T l = ${1:0}, r = ${2:1e9};
for (int _ = 0; _ < 100; ++_) {
    T c1 = (l * 2 + r) / 3;
    T c2 = (l + r * 2) / 3;
    if (f_trn(c1) > f_trn(c2)) l = c1;
    else r = c2;
}
