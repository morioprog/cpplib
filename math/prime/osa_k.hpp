/**
* @brief osa_k法
* @docs docs/math/prime/osa_k.hpp
* @see https://qiita.com/rsk0315_h4x/items/ff3b542a4468679fb409
*/

struct osa_k {
    int N;
    vector<int> min_prime;
    osa_k(int _N)
        : N(_N + 1), min_prime(N) {
        iota(min_prime.begin(), min_prime.end(), 0);
        for (int p = 2; p * p <= N; ++p) {
            if (min_prime[p] != p) continue;
            for (int i = 2 * p; i <= N; i += p) {
                if (min_prime[i] != i) continue;
                min_prime[i] = p;
            }
        }
    }
    bool is_prime(int x) {
        assert(x <= N);
        if (x <= 1) return false;
        return min_prime[x] == x;
    }
    map<int, int> prime_factor(int x) {
        assert(x <= N);
        map<int, int> pf;
        while (x > 1) {
            pf[min_prime[x]]++;
            x /= min_prime[x];
        }
        return pf;
    }
};
