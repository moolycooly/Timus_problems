#include <bits/stdc++.h>
#define int long long
using namespace std;

bool check(int x, int y, int x0, int y0, int x1, int y1) {

    if((x-x0)*(y0-y1) == (y-y0)*(x0-x1)) return 1;
    return 0;
}
main()
{
  int n,ans=0;
  cin >> n;
  vector<pair<int,int> > p;
  for(int i=0; i < n; i++) {
    int x,y;
    cin >> x >> y;
    p.push_back({x,y});
  }
  for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
        int cnt = 0;
        for(int k = 0; k < n; k++) {
            cnt += check(p[k].first,p[k].second,p[i].first,p[i].second,p[j].first,p[j].second);
        }
        ans = max(ans,cnt);
    }
  }
  cout << ans;



}
