#include <bits/stdc++.h>
#define int uint64_t
using namespace std;

const int mod = 1e9+7;

main()
{
 int n;
 cin >> n;
 string a,b;
 cin >> a >> b;
 int p_ = 257;
 vector<pair<int,int> > p(n,{1,1});
 vector<pair<int,int> > a_pref(n);
 vector<pair<int,int> > b_pref(n);

 for(int i = 1; i < n; i++) {
    p[i].first = (p[i-1].first*p_)%mod;
    p[i].second = p[i-1].second*p_;
 }
 a_pref[0].first = a[0];
 a_pref[0].second = a[0];

 b_pref[0].first = b[0];
 b_pref[0].second = b[0];
 for(int i = 1; i < n; i++) {
    a_pref[i].first = (a_pref[i-1].first*p_%mod + a[i])%mod;
    b_pref[i].first = (b_pref[i-1].first*p_%mod + b[i])%mod;
    a_pref[i].second = a_pref[i-1].second*p_ + a[i] + INT64_MAX;
    b_pref[i].second = b_pref[i-1].second*p_ + b[i] + INT64_MAX;
 }
 int l = 0, r=n+1,pos=-1;
 while(r-l > 1) {

    int m = (r+l)/2;
    map<pair<int,int>,int> mp;
    bool f = 0;
    for(int i = m-1; i < n; i++) {
        // hash [i+1-m,i]
        if(i==m-1) {
            mp[{a_pref[i].first,a_pref[i].second}]++;
            continue;
        }
        mp[{(a_pref[i].first-a_pref[i-m].first*p[m].first%mod + mod)%mod, (a_pref[i].second-a_pref[i-m].second*p[m].second) + INT64_MAX}]++;
    }
    for(int i = m-1; i < n; i++) {
        if(i==m-1){
            if(mp[{b_pref[i].first,b_pref[i].second}]) {
                pos=i;
                f=1;
                break;
            }
        }
        if(mp[{(b_pref[i].first-b_pref[i-m].first*p[m].first%mod + mod)%mod, (b_pref[i].second-b_pref[i-m].second*p[m].second) + INT64_MAX}]) {
            pos = i;
            f=1;break;
        }
    }
    if(f) {
        l = m;
    }
    else r = m;
 }
 if(l) {

    for(int i=pos-l+1; i <= pos; i++) {
        cout << b[i];
    }
 }




}
