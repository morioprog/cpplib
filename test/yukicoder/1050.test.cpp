#define PROBLEM "https://yukicoder.me/problems/no/1050"

#include "../../template/main.hpp"
#include "../../math/modint.hpp"
#include "../../math/matrix/matrix.hpp"

signed main() {

    int M, K;
    cin >> M >> K;

    Matrix<modint> mat(M);

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            ++mat[i][(i * j) % M];
            ++mat[i][(i + j) % M];
        }
    }

    mat ^= K;
    cout << mat[0][0] << endl;
    
}
