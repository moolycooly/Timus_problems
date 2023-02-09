#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

const int MX = 10001;
main()
{
    int ans = 1;
    vector<int> p(MX,0);
    for(int q = 0; q < 10; q++) {
        int x;
        cin >> x;
        int n = x;
        for(int i = 2; i*i <= x && n > 1; i++) {
            while(!(n%i)) {
                p[i]++;
                n/=i;
            }
        }
        if(n>1) p[n]++;

    }
    for(int i = 0; i < MX; i++) {
        ans = ans*(p[i]+1)%10;
    }
    cout << ans;

}



