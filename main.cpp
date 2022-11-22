#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e18+7;
const int max_size = 1e5+1;
const int INF = 1e9+7;
int fact[max_size];
int binpow(int a,int n)
{

    if(!n) return 1;
    if(n==1) return a;
    if(n%2==1) return a*binpow(a,n-1);
    else
    {
        int t = binpow(a,n/2);
        return t*t;
    }
}
int inverse(int x)
{
    return binpow(x,mod-2);
}
int div_mod(int a, int b)
{
    return a*inverse(b)%mod;
}
int cnk(int n, int k)
{
    if(n<k) return 0;
    return div_mod(fact[n],fact[k]*fact[n-k]%mod);
}

int gcd(int a, int b)
{
    if(!b)return a;
    return gcd(b,a%b);
}
main()
{
    //    ios_base::sync_with_stdio(false);
    //    cin.tie(NULL);
    //
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<double > >  dp(m+2,vector<double >(n+2,1e9));
    vector<vector<double> > d(m+2,vector<double >(n+2,1e9));
    dp[1][1] = 0;
    for(int i = 0; i < k; i++)
    {
        int x,y;
        cin >> x >> y;
        d[y+1][x+1] = 100*sqrt(2);

    }
    for(int i = 1; i <=m+1; i++)
        for(int j = 1; j <= n+1; j++)
            dp[i][j] = min(dp[i][j],min(dp[i][j-1]+100,min(dp[i-1][j]+100,dp[i-1][j-1] + d[i][j])));


    cout << round(dp[m+1][n+1]);

}


