#include <bits/stdc++.h>
#define int long long
using namespace std;


main()
{
    int N,ans=0;
    cin >> N;
    vector<vector<int> > dp(N+1,vector<int>(N+1,0));
    for(int i =0 ; i <= N;i++) dp[i][i]=1;
    for(int n = 1; n <= N; n++)
    {
        for(int h = 1; h < n; h++)
        {
            for(int t = 0; t < h; t++)
            {
                dp[n][h] += dp[n-h][t];
            }
        }
    }
    for(int i = 1; i < N; i++) ans += dp[N][i];
    cout << ans;


}
