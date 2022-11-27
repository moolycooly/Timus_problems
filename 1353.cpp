#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9+7;
const int mx = 1e7;
const int INF = 1e18;
int fact[mx];
//Template Functions..
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
int sum(int l, int r,vector<int>&a)
{
    if(l > r) return 0;
    if(!l) return a[r];
    return a[r]-a[l-1];

}
//
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
