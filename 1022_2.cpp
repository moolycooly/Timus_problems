#include <bits/stdc++.h>
using namespace std;

vector<int> result;
vector<int> used;
vector<vector<int>> g;


void top_sort(int v) {
    used[v] = 1;
    for(int i = 0; i < g[v].size(); i++) {

        int to = g[v][i];
        if(!used[to]) top_sort(to);
    }
    result.push_back(v);
}
main()
{
   int n;
   cin >> n;
   vector<int> deg;
   g.resize(n);
   deg.resize(n);
   used.resize(n);
   for(int i = 0; i < n; i++) {
        int x;
        while(cin>>x && x) {
          x--;
          g[i].push_back(x);
          deg[x]++;
        }
   }
   for(int i = 0; i < n; i++) {
    if(!deg[i]) {
        top_sort(i);
    }
   }

   reverse(result.begin(),result.end());
   for(int i = 0; i < n; i++) cout << result[i]+1 << " ";




}

