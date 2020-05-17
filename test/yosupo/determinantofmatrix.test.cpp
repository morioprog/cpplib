#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include "../../template/main.hpp"
#include "../../math/modint.hpp"
#include "../../math/matrix/matrix.hpp"

using mint = ModInt<998244353>;

signed main() {

    int N;
    cin >> N;
    
    Matrix<mint> mat(N);
    cin >> mat;

    cout << mat.determinant() << endl;

}
