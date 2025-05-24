#pragma GCC optimize("Ofast")

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// よく使用する型のエイリアス
#define ll long long
#define vec vector<int>
#define vecd vector<double>
#define vecll vector<ll>
#define Graph vector<vector<int>>   // 隣接リスト表現のグラフ
#define wGraph vector<vector<Edge>> // 重み付きグラフ

// 基本的なループマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)     // 0からn-1まで
#define krep(i, k, n) for (int i = k; i < (int)(n); i++) // kからn-1まで
#define prep(i, n) for (int i = 1; i <= (int)(n); i++)   // 1からnまで
#define irep(i, n) for (int i = (int)n - 1; i >= 0; i--) // n-1から0まで

#define all(v) v.begin(), v.end() // イテレータの範囲指定

// 無限大を表す定数
#define INF INT_MAX
#define LINF LLONG_MAX

// グリッド探索用の4方向の移動ベクトル
const int dx[4] = {1, 0, -1, 0}; // 右、上、左、下
const int dy[4] = {0, 1, 0, -1};

// 10のべき乗を格納した配列（int型）
vec pow_vec{1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

// 10のべき乗を格納した配列（long long型）
vecll pow_vecll{1, 10, 100, 1000, 10000, 100000, 1000000,
                10000000, 100000000, 1000000000, 10000000000, 100000000000, 1000000000000};

int main()
{
    // 入出力の高速化
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // 以下にメインの処理を記述
    using namespace std;
    unsigned H, W;
    cin >> H >> W;
    vector<vector<unsigned long>> A(H, vector<unsigned long>(W));
    for (auto &&row : A)
        for (auto &&a : row)
            cin >> a;
    // HW ビットの整数でドミノが置かれたマスを管理する
    vector<unsigned> possible_domino{0}; // はじめは何も置かれていない盤面だけ
    const unsigned domino_vertical = (1U << W) + 1, domino_horizontal = 3;
    for (unsigned i = 0, bit = 0; i < H; ++i)
        for (unsigned j = 0; j < W; ++j, ++bit)
        { // 各マスについて
            vector<unsigned> tmp;
            for (const auto b : possible_domino)
            {
                // 縦に置けるなら置いたものを追加する
                if (j + 1 < W && !(b & domino_horizontal << bit))
                    tmp.emplace_back(b | domino_horizontal << bit);
                // 横に置けるなら置いたものを追加する
                if (i + 1 < H && !(b & domino_vertical << bit))
                    tmp.emplace_back(b | domino_vertical << bit);
            }
            move(tmp.begin(), tmp.end(), back_inserter(possible_domino));
        }
    unsigned long ans = 0;
    for (const auto b : possible_domino)
    { // 各ドミノの置き方について
        unsigned long now = 0;
        for (unsigned i = 0, bit = 0; i < H; ++i)
            for (unsigned j = 0; j < W; ++j, ++bit)
                if (1 & ~b >> bit)  // ドミノが置かれてないマスに
                    now ^= A[i][j]; // 書かれた整数の xor を求める
        ans = max(ans, now);        // 大きければ更新
    }
    cout << ans << endl;
    return 0;
}