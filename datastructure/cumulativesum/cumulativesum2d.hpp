/**
* @brief 2次元累積和
* @docs docs/datastructure/cumulativesum/cumulativesum2d.md
*/

template<class T> struct CumulativeSum2D {
    int H, W;
    vector<vector<T>> data;
    CumulativeSum2D(const vector<vector<T>> &v) {
        H = v.size();
        W = (H == 0) ? 0 : v[0].size();
        data.assign(H + 1, vector<T>(W + 1, 0));
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                data[i + 1][j + 1] = v[i][j] + data[i + 1][j] + data[i][j + 1] - data[i][j];
            }
        }
    }
    T query(int sx, int sy, int gx, int gy) {
        return data[gx][gy] - data[sx][gy] - data[gx][sy] + data[sx][sy];
    }
};
