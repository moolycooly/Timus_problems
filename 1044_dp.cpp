#include <bits/stdc++.h>
#define int long long
using namespace std;

main()
{
   int n,ans=0;
   cin >> n;
   n = n/2;
   vector<vector<int> > dp(n+1,vector<int>(9*n+1,0));
   dp[0][0] = 1;
   for(int i = 1; i <= n; i++)
        for(int k = 0; k <=9*n; k++)
            for(int j = 0; j <= min(k,9ll); j++)
                dp[i][k] += dp[i-1][k-j];


   for(int k = 0; k <=9*n; k++)
        ans += dp[n][k]*dp[n][k];

   cout << ans;
}
