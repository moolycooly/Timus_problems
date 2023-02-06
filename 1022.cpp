#include <bits/stdc++.h>
using namespace std;

vector<int> deg;
vector<vector<int>> g;


vector<int> topological_sort(vector<int> deg, vector<vector<int> > g, int n) {
    vector<int> result;

    stack<int> s;
    for(int i = 0; i < n; i++) {

        if(!deg[i]) s.push(i);
    }
    while(!s.empty()) {
        int v = s.top();
        result.push_back(v);
        s.pop();
        for(int i = 0; i < g[v].size(); i++) {
            int to = g[v][i];
            deg[to]--;
            if(!deg[to]) s.push(to);
        }
    }
    return result;

}
main()
{
   int n;
   cin >> n;
   g.resize(n);
   deg.resize(n);
   for(int i = 0; i < n; i++) {
        int x;
        while(cin>>x && x) {
          x--;
          g[i].push_back(x);
          deg[x]++;
        }
   }

   auto result = topological_sort(deg,g,n);
   for(int i = 0; i < n; i++) cout << result[i]+1 << " ";




}

