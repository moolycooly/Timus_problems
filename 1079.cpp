#include <bits/stdc++.h>
#define int long long
using namespace std;

main()
{
    int n = 1e5;
    vector<int> a(n,0);
    vector<int> mx(n,0);

    a[0] = 0;
    a[1] = 1;
    for(int i = 2; i < n; i++)
        a[i] = a[i/2] + a[i/2 + 1]*(i%2);

    for(int i = 1; i < n; i++)
        mx[i]=max(mx[i-1],a[i]);

    while(true) {
        int x;
        cin >> x;
        if(!x) {
            return 0;
        }
        cout << mx[x] << '\n';

    }
}
