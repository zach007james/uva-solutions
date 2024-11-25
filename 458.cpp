#include <iostream>
using namespace std;

int main()
{
    // fast io
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // for testing
    freopen("input.txt", "r", stdin);
    
    int line_size;
    string line;
    while(getline(cin, line))
    {
        line_size = line.length();
        for(int i = 0; i < line_size; i++)
        {
            cout << (char)(line[i] - 7);
        }
        cout << '\n';
    }
    return 0;
}