/**
* @brief BitMatrix
* @docs docs/math/matrix/bitmatrix.md
* @see https://drken1215.hatenablog.com/entry/2019/03/20/202800
*/

template <int H, int W = H>
struct BitMatrix {
    bitset<W> mat[H];
    BitMatrix() {}
    size_t height() const { return H; }
    size_t width() const { return W; }
    inline const bitset<W> &operator[](int idx) const { return mat[idx]; }
    inline bitset<W> &operator[](int idx) { return mat[idx]; }
    BitMatrix &operator&=(const BitMatrix &m) {
        for (int i = 0; i < height(); ++i) (*this)[i] &= m[i];
        return *this;
    }
    BitMatrix &operator|=(const BitMatrix &m) {
        for (int i = 0; i < height(); ++i) (*this)[i] |= m[i];
        return *this;
    }
    BitMatrix operator&(const BitMatrix &m) const { return (BitMatrix(*this) &= m); }
    BitMatrix operator|(const BitMatrix &m) const { return (BitMatrix(*this) |= m); }
    int gaussian_elimination(bool is_extended = false) {
        int rnk = 0;
        for (int j = 0; j < width(); ++j) {
            if (is_extended and j == width() - 1) break;
            int piv = -1;
            for (int i = rnk; i < height(); ++i) {
                if ((*this)[i][j]) {
                    piv = i;
                    break;
                }
            }
            if (piv == -1) continue;
            swap((*this)[piv], (*this)[rnk]);
            for (int i = 0; i < height(); ++i)
                if (i != rnk and (*this)[i][j]) (*this)[i] ^= (*this)[rnk];
            ++rnk;
        }
        return rnk;
    }
    int linear_equation(vector<int> b, vector<int> &res) {
        const int r = height(), c = width();
        BitMatrix<r, c + 1> m;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                m[i][j] = (*this)[i][j];
            }
            m[i][c] = b[i];
        }
        int rnk = gaussian_elimination(true);
        for (int i = rnk; i < r; ++i)
            if (m[i][c]) return -1;
        res.assign(c, 0);
        for (int i = 0; i < rnk; ++i) res[i] = m[i][c];
        return rnk;
    }
    template <int A, int B, int C>
    friend BitMatrix<A, C> operator*(const BitMatrix<A, B> &m1, const BitMatrix<B, C> &m2) {
        BitMatrix<A, C> ret;
        BitMatrix<C, B> tmp;
        for (int i = 0; i < C; ++i)
            for (int j = 0; j < B; ++j)
                tmp[i][j] = m2[j][i];
        for (int i = 0; i < A; ++i)
            for (int j = 0; j < C; ++j)
                ret[i][j] = (m1[i] & tmp[j]).count() & 1;
        return ret;
    }
    template <int A>
    friend BitMatrix<A> bmat_pow(BitMatrix<A> m, unsigned long long n) {
        BitMatrix<A> ret;
        for (int i = 0; i < ret.height(); ++i) ret[i][i] = 1;
        while (n > 0) {
            if (n & 1) ret = ret * m;
            m = m * m;
            n >>= 1;
        }
        return ret;
    }
    friend ostream &operator<<(ostream &os, const BitMatrix &m) {
        for (int i = 0; i < m.height(); ++i) {
            for (int j = 0; j < m.width(); ++j) {
                if (j > 0) os << ", ";
                os << m[i][j];
            }
            os << endl;
        }
        return os;
    }
};
