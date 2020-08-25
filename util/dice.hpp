/**
* @brief サイコロ
* @docs docs/util/dice.md
*/

// 下にy, 右にx
enum { R,
       U,
       L,
       D };
const int ddx[] = { 1, 0, -1, 0 };
const int ddy[] = { 0, -1, 0, 1 };

struct Dice {
    int T, N, E, S, W, B;
    int table[6][6] = {
        { 0, 3, 5, 2, 4, 0 },
        { 4, 0, 1, 6, 0, 3 },
        { 2, 6, 0, 0, 1, 5 },
        { 5, 1, 0, 0, 6, 2 },
        { 3, 0, 6, 1, 0, 4 },
        { 0, 4, 2, 5, 3, 0 }
    };
    Dice(int T, int S)
        : T(T), S(S) { build(); }
    void build() {
        E            = table[T - 1][S - 1];
        tie(N, W, B) = make_tuple(7 - S, 7 - E, 7 - T);
        // swap(E, W);  // もう1種類のサイコロの場合
    }
    void rot(int dir) {
        if (dir == R) tie(T, S) = make_pair(W, S);
        if (dir == U) tie(T, S) = make_pair(S, B);
        if (dir == L) tie(T, S) = make_pair(E, S);
        if (dir == D) tie(T, S) = make_pair(N, T);
        // 1行で書くなら
        // tie(T, S) = (vector<pair<int, int>>){{W, S}, {S, B}, {E, S}, {N, T}}[dir];
        build();
    }
    int get(int m) {
        return (vector<int>){ E, N, W, S, T, B }[m];
    }
};
