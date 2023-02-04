#include <bits/stdc++.h>
#define int long long
using namespace std;

main()
{
    //Solution
    int s,ans;
    cin >> s;
    vector<vector<int> > dp(10,vector<int>(100,0));
    for(int i = 1; i <= 9; i++) dp[1][i]=1;
    for(int i = 2; i <= 9; i++) {
        for(int j = 1; j <= 82; j++) {
            for(int num = 0; num <= 9; num++) dp[i][j+num] += dp[i-1][j];
        }
    }
    s==1?ans=1:ans=0;
    for(int i=1; i <= 9; i++) ans += dp[i][s];
    cout << ans;
}
