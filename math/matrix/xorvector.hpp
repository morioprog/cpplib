/**
* @brief Xor Vector
* @docs docs/math/matrix/xorvector.md
*/

struct XorVector {
    bool dirty = false;
    int rank, N;
    vector<long long> span;
    XorVector(int N) : rank(0), N(N), span(N, 0) {}
    void emplace(ll num) {
        span[rank++] = num;
        dirty = true;
    }
    bool find(ll num) {
        if (num == 0) return true;
        if (dirty) gaussian_elimination();
        for (int i = 0; i < rank; ++i) {
            if (span[i] == 0LL) break;
            num = min(num, num ^ span[i]);
        }
        return num == 0LL;
    }
    void gaussian_elimination() {
        rank = 0;
        for (int col = 63; col >= 0; --col) {
            int pivot = -1;
            for (int row = rank; row < N; ++row) if (span[row] >> col & 1) { pivot = row; break; }
            if (pivot == -1) continue;
            swap(span[pivot], span[rank]);
            for (int row = 0; row < N; ++row) if (row != rank and span[row] >> col & 1) span[row] ^= span[rank];
            ++rank;
        }
        dirty = false;
    }
    void print() {
        for (int i = 0; i < rank; ++i) cerr << bitset<64>(span[i]) << endl;
        cerr << endl;
    }
};
