//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{

    // fast io
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    unsigned long long a, b;

    // terminated by 'End of File'
    while(cin >> a >> b)
    {
        cout << ((b > a) ? (b - a) : (a - b)) << '\n';
    }

    return 0;
}