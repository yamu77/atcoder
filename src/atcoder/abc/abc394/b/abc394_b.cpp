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

/**
 * @brief 整数ベクトルを出力する関数
 * @param v 出力する整数ベクトル
 */
void print_vec(vec v)
{
    rep(i, (int)v.size())
    {
        cout << v.at(i);
    }
    cout << endl;
}

/**
 * @brief long long型ベクトルを出力する関数
 * @param v 出力するlong long型ベクトル
 */
void print_vecll(vecll v)
{
    rep(i, (int)v.size())
    {
        cout << v.at(i);
    }
    cout << endl;
}

/**
 * @brief 文字列を数字の配列に変換する関数
 * @param s 変換する文字列（各文字は数字）
 * @return 数字を表す整数の配列
 */
vec string_to_vec(string s)
{
    vec v(s.size());
    rep(i, (int)s.size())
    {
        v.at(i) = s.at(i) - '0';
    }
    return v;
}

/**
 * @brief 整数をアルファベット小文字に変換する関数
 * @param i 変換する整数（0-25）
 * @return 対応するアルファベット小文字
 */
char int_to_alphabet(int i)
{
    // i = 0 -> a
    // i = 25 -> z
    return i + 'a';
}

/**
 * @brief アルファベット小文字を整数に変換する関数
 * @param s 変換するアルファベット小文字
 * @return 対応する整数（0-25）
 */
int alphabet_to_int(char s)
{
    return s - 'a';
}

/**
 * @brief 負の数に対応した剰余演算（int型）
 * @param a 被除数
 * @param b 除数
 * @return 非負の剰余
 */
int mmod(int a, int b)
{
    a += (abs(a / b) + 1) * b;
    return a % b;
}

/**
 * @brief 負の数に対応した剰余演算（long long型）
 * @param a 被除数
 * @param b 除数
 * @return 非負の剰余
 */
ll mmod(ll a, ll b)
{
    a += (abs(a / b) + 1) * b;
    return a % b;
}

/**
 * @brief 文字列に特定の文字が含まれているか判定する関数
 * @param s 検索対象の文字列
 * @param c 検索する文字
 * @return 含まれていればtrue、そうでなければfalse
 */
bool s_contain(string s, char c)
{
    if (s.find(c) != string::npos)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 文字列の長さでソートするための関数
bool compare(string &s1, string &s2)
{
    return s1.size() < s2.size();
}

int main()
{
    // 入出力の高速化
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // 以下にメインの処理を記述
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n)
    {
        cin >> s.at(i);
    }
    sort(s.begin(), s.end(), compare);
    rep(i, n)
    {
        cout << s.at(i);
    }
    cout << endl;

    return 0;
}