#include <bits/stdc++.h>
#define int long long
using namespace std;

main()
{
   int n;
   cin >> n;
   int len = 0;
   map<int,pair<int,int> > a;
   for(int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if(!a[x].first) a[x].first = i;
    a[x].second = i;
    }
    vector<vector<int> > dp(a.size(),vector<int>(2,1e18));
    int last = -1,idx = 0;
    for(auto&i:a) {
        if(last==-1) {
            dp[idx][0] = 2*i.second.second - i.second.first;
            dp[idx][1] = i.second.second-1;
            idx++;
            last = i.first;
            continue;
        }
        int len = i.second.second - i.second.first;
        dp[idx][0] = min(dp[idx-1][0] + abs(a[last].first-i.second.second) + len, dp[idx-1][0] + abs(a[last].first-i.second.first) + 2*len);
        dp[idx][0] = min(dp[idx][0],min(dp[idx-1][1]+abs(a[last].second - i.second.second) + len, dp[idx-1][1]+abs(a[last].second - i.second.first) + 2*len));
        dp[idx][1] = min(dp[idx-1][1] + abs(a[last].second-i.second.first) + len, dp[idx-1][1] + abs(a[last].second - i.second.second)  + 2*len);
        dp[idx][1] = min(dp[idx][1],min(dp[idx-1][0] + abs(a[last].first - i.second.first)+ len, dp[idx-1][0] + abs(a[last].first-i.second.second) + 2*len));
        last = i.first;
        idx++;


    }
    cout << min(dp[a.size()-1][0], dp[a.size()-1][1]) + n;



}
