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
    int N,K;
    unsigned int X;
    cin >> N >> K >> X;
    vector<string> S(N);
    rep(i,N){
        cin >> S[i];
    }
    vector<string> ans = S;
    rep(i, K-1){
        vector<string> tmp(0);
        rep(j, ans.size()){
            rep(k, S.size()){
                tmp.push_back(ans[j]+S[k]);
            }
        }
        ans = tmp;
        sort(ans.begin(), ans.end());
        if(ans.size() > X+1){
            ans.erase(ans.begin()+X+1,ans.end());
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans[X-1] << endl;
    return 0;
}