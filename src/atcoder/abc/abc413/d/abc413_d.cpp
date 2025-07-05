#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    using namespace std;
    unsigned T;
    cin >> T;
    for (unsigned t{}; t < T; ++t) cout << ([]{
        unsigned N;
        cin >> N;
        vector<long> A(N);
        for (auto&& a : A)
            cin >> a;

        // すべて同じ値なら、Yes
        if (ranges::count(A, A[0]) == N)
            return true;

        // 先頭とその -1 倍しかなく、それぞれ ceil(N/2) 個と floor(N/2) 個なら、Yes
        if (const auto p_cnt{ranges::count(A, A[0])}, n_cnt{ranges::count(A, -A[0])}; p_cnt + n_cnt == N && min(p_cnt, n_cnt) == N / 2)
            return true;

        // 絶対値の降順にソートしておく
        ranges::sort(A, greater{}, [](const auto a){ return abs(a); });

        // 公比の絶対値が 1 でないなら、絶対値でソートしたときに等比数列である必要がある
        for (unsigned i{}; i + 2 < N; ++i)
            if (A[i] * A[i + 2] != A[i + 1] * A[i + 1])
                return false;
        return true;
    }() ? "Yes" : "No") << endl;
    return 0;
}
