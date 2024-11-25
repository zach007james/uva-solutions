#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // testing input
    freopen("input.txt", "r", stdin);
    string line; int ll, w; bool pc;
    while(getline(cin, line))
    {

        pc = false;
        w = 0;

        for(char c : line)
        {
            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            {
                if(!pc) { pc = true; w++; }
            }
            else
            {
                pc = false;
            }
        }
        cout << w << '\n';
    }

    return 0;

}