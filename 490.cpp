#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // for debugging purposes
    freopen("input.txt", "r", stdin);

    // grab input
    string line;
    vector<string> lines;
    int largest_size = 0, col_width = 0;
    while(getline(cin, line))
    {
        lines.push_back(line);
        if(line.size() > largest_size) { largest_size = line.size(); }
    }


    // print output
    for(int i = 0; i < largest_size; i++) // starts with the last string
    {
        for(int j = lines.size() - 1; j >= 0; j--) // starts with the first letter of the string
        {
            if(i < lines[j].size()) { cout << lines[j][i]; }
            else { cout << " "; }
        }
        cout << "\n";
    }

    return 0;

}