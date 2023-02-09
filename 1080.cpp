#include <bits/stdc++.h>
#define int long long
using namespace std;

bool f;

vector<vector<int> > g;
vector<int> used;
vector<int> ans;

void dfs(int v, int p) {
    used[v] = 1;
    for(int i = 0; i < g[v].size(); i++) {
        int to =g[v][i];
        if(to==p) continue;
        if(used[to] && ans[v]==ans[to]) {
            f=false;
            return;
        }
        if(!used[to]) {
            ans[to] = 1-ans[v];
            dfs(to,v);
        }

    }
}
main()
{
   int n;
   cin >> n;
   used.resize(n);
   ans.resize(n);
   g.resize(n);
   for(int i = 0; i < n; i++) {
    int x;
    while(cin>>x && x) {
        x--;
        g[i].push_back(x);
        g[x].push_back(i);
    }
   }
   f = true;
   dfs(0,-1);
   if(!f) {
    cout << -1;
    return 0;
   }
   for(int i = 0; i < n; i++) cout << ans[i];



}
