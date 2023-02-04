#include <bits/stdc++.h>
#define int long long

using namespace std;

main()
{
    int n,k=0;
    cin >> n;
    vector<int> result(n,0);
    for(int i = 0; i < n; i++)
    {
        int a,b;
        cin >> a >> b;
        result[i] = a+b;
    }
    for(int i = n-1; i >= 0; i--)
    {
        result[i] += k;
        k = result[i]/10;
        result[i] %= 10;
    }
    for(int i = 0; i < n; i++) cout << result[i];


}
