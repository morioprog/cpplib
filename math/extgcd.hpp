/**
* @brief 拡張ユークリッドの互除法
* @docs docs/math/extgcd.md
*/

long long extgcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
