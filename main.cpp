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
        int n;
        cin >> n;
        vector<int> dp(n,0);
        dp[0] = 2;
        dp[1] = 2;
        for(int i = 2; i < n; i++) dp[i] = dp[i-1] + dp[i-2];
        cout << dp[n-1];

    }


