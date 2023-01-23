#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int n;
    cin >> n;
    vector<int> dp(n+1,1e9);
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j*j <= i; j++) {
            dp[i] = min(dp[i],dp[i-j*j]+1);
        }
    }
    cout << dp[n];

}
