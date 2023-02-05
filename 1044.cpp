#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,ans;
vector<int> sums;
void cnt(int s, int q, int len) {
    if(len==n/2) {
        if(q==s) sums[s]++;
        return;
    }
    for(int i = 0; i < 10; i++) cnt(s,q+i,len+1);
}
void rec(int s,int len) {
    if(len==n/2) {
        if(!sums[s]) cnt(s,0,0);
        ans+=sums[s];
        return;
    }
    for(int i = 0; i < 10; i++) {
        rec(s+i,len+1);
    }

}
main()
{
    ans = 0;
    sums.resize(100,0);
    cin >> n;
    rec(0,0);
    cout << ans;
}
