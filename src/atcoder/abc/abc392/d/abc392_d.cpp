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
#include <iomanip>

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

int main()
{
    // 入出力の高速化
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // 以下にメインの処理を記述
    int n;
    cin >> n;
    vector<vector<int>> dices(n);
    vector<map<int, ll>> count(n);
    rep(i, n)
    {
        int k;
        cin >> k;
        rep(j, k)
        {
            int tmp;
            cin >> tmp;
            dices[i].emplace_back(tmp);
            count[i][tmp]++;
        }
    }
    double ans = 0;
    rep(i, n)
    {
        krep(j, i + 1, n)
        {
            ll sum = 0;
            if (dices[i].size() < dices[j].size())
                rep(dice, dices[i].size())
                {
                    sum += count[j][dices[i][dice]];
                }
            else
                rep(dice, dices[j].size())
                {
                    sum += count[i][dices[j][dice]];
                }
            ans = max(ans, sum / (double)(dices[i].size() * (ll)dices[j].size()));
        }
    }
    cout << fixed << setprecision(15) << ans << endl;
    return 0;
}