#include <iostream>
using namespace std;

int main()
{
    // fast io

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);


    int n; // # of test cases
    int f; // # of farmers in test case 
    cin >> n;
    unsigned long long a, b, c;
    unsigned long long r;

    // iterate through number of test cases 
    for(int i = 0; i < n; i++)
    {
        int r = 0; // set / reset
        cin >> f;
        for(int j = 0; j < f; j++)
        {
            cin >> a >> b >> c;
            r += a * c;
        }
        cout << r << '\n';
        // (spacies single animal occupies on avg) * envrionment frendliness = pre animal premium
        // r = ^ * # of animals farmer owns 
    }
    return 0;
}