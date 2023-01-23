#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9+9;
bool prime(int n) {
    for(int i = 2; i*i <= n; i++) {
        if(n%i==0)return 0;
    }
    return 1;

}
main()
{   int n;
    cin >> n;
    vector<vector<vector<int> > > dp(n+1,vector<vector<int> >(10,vector<int>(10,0)));
    for(int i = 100; i < 1000; i++){
        if(prime(i)){
            dp[3][i/100][(i/10)%10]++;
        }
    }

    for(int i = 4; i <= n; i++) {

        for(int a = 1; a < 10; a++) {
            for(int b = 1; b < 10; b++) {
                for(int c = 1; c < 10; c++) {
                    if(prime(a*100+b*10+c)) {
                        dp[i][a][b] = (dp[i][a][b] + dp[i-1][b][c])%mod;
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i < 10; i++) {
        for(int j = 0; j < 10; j++) ans = (ans + dp[n][i][j])%mod;
    }
    cout << ans;


}
