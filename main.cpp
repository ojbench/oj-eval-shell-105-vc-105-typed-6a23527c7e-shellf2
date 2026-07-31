// Portable includes for better compatibility on OJ environments
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstdint>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    if (!(cin >> n >> m)) return 0;

    if (m <= 0) {
        cout.setf(std::ios::fixed);
        cout << setprecision(2) << 0.0 << '\n';
        return 0;
    }
    if (m > n) m = n; // safe-guard; constraints ensure m<=n

    long long T = n - m; // stop once remaining apples <= T
    vector<long double> G(n + 1, 0.0L);
    vector<long double> prefix(n + 1, 0.0L); // prefix[i] = sum_{r=0..i} G[r]

    for (long long k = std::max(1LL, T + 1); k <= n; ++k) {
        size_t km1 = static_cast<size_t>(k - 1);
        size_t ks = static_cast<size_t>(k);
        long double Skm1 = prefix[km1];
        G[ks] = 1.0L + Skm1 / static_cast<long double>(k);
        prefix[ks] = prefix[km1] + G[ks];
    }

    long double ans = G[static_cast<size_t>(n)];
    cout.setf(std::ios::fixed);
    cout << setprecision(2) << static_cast<double>(ans) << '\n';
    return 0;
}
