#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

main()
{

 double p,q;
 cin >> p >> q;
 for(int x = 1; x <= 100000; x++) {
    double a = x*p/100, b = x*q/100;
    int a1=a+1,b1=b;
    if((b1 < b && b1 > a)|| (a1 > a && a1 < b)) {
        cout << x;
        return 0;
    }
 }

 }



