#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll sol(ll a, ll b, ll c)
{
    // ax^2 + bx + c = 0の解
    ll l = 0, r = 600000001;
    while (r - l > 1)
    {
        ll mid = (l + r) / 2;
        if (a * mid * mid + b * mid + c <= 0)
            l = mid;
        else
            r = mid;
    }
    if (a * l * l + b * l + c == 0)
        return l;
    return -1;
}
int main()
{
    ll n;
    cin >> n;
    for (ll d = 1; d * d * d <= n; ++d)
    {
        // (k+d)^3 - k^3 = d^3 + 3*d^2k + 3*d*k^2 = n
        if (n % d != 0)
            continue;
        ll m = n / d; // =3*k^2 + 3*dk + d^2
        ll k = sol(3, 3 * d, d * d - m);
        if (k > 0)
        {
            cout << k + d << " " << k << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}