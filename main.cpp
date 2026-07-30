#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, m;
    if(!(cin >> n >> m)) return 0;
    if(m <= 0){
        cout.setf(std::ios::fixed); cout<<setprecision(2)<<0.0<<"\n"; return 0;
    }
    if(m > n) m = n; // just in case, though constraints say m<=n
    long long T = n - m; // stop when remaining <= T
    vector<long double> G(n+1, 0.0L);
    vector<long double> prefix(n+1, 0.0L); // prefix[i] = sum_{r=0..i} G[r]
    // G[k] = 0 for k <= T
    for(long long k = max(1LL, T+1); k <= n; ++k){
        long double Skm1 = prefix[k-1];
        G[k] = 1.0L + Skm1 / (long double)k;
        prefix[k] = prefix[k-1] + G[k];
    }
    long double ans = G[n];
    cout.setf(std::ios::fixed);
    cout << setprecision(2) << (double)ans << "\n";
    return 0;
}
