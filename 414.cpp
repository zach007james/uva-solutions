#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); // No need to tie cout if not necessary
    // freopen("input.txt", "r", stdin); // Removed to read from standard input
    freopen("input.txt", "r", stdin);

    int N;

    while(cin >> N)
    {
        // cout << "\ntook in N as " << N << endl; // Debug statement removed

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> left(N), right(N);
        vector<int> sum;    // Initialize sum as empty
        sum.reserve(N);     // Optional: reserve space for efficiency

        string line;
        bool zerocase = true; // Assume all rows have no spaces initially
        int result = 0;

        // end case
        if(N == 0) { 
            // cout << "End case of N = 0 hit" << endl; // Debug statement removed
            break; 
        }

        // iterate through the rows of this image
        for(int i = 0; i < N; i++)
        {
            getline(cin, line); // grab the line input
            // cout << "\ngrabbed the line input of:\n" << line << endl; // Debug statement removed

            // Left pass: Find the first space
            bool current_row_has_space = false;
            for(int c = 0; c < 25; c++) // from left pass
            {
                if(line[c] == 'B' || line[c] == ' ') // Assuming 'B' represents spaces in your test input
                {
                    left.at(i) = c;
                    cout << "Counted " << c << " X's on the left." << endl; 
                    if(c != 24) { // If space is found before the last column
                        zerocase = false; // At least one row has spaces
                    }
                    break; // Exit the loop after finding the first space
                }
            }

            // Right pass: Find the first space from the right
            for(int r = 24; r >=0; r--) // from right pass
            {
                if(line[r] == 'B' || line[r] == ' ') // Assuming 'B' represents spaces in your test input
                {
                    right.at(i) = 24 - r;
                    cout << "Counted " << 24 - r << " X's on the right" << endl;
                    break; // Exit the loop after finding the first space
                }
            }
        }

        // have grabbed the numbers into the two arrays at this point

        if(zerocase)
        {
            // cout << "Zero case hit!" << endl; // Debug statement removed
            cout << "0\n"; // Output 0 followed by a newline
            continue;
        }

        // summ array
        int l_sum = 0, l_index = 0, n_sum = 0;

        for(int s = 0; s < N; s++)
        {
            n_sum = left.at(s) + right.at(s);
            sum.emplace_back(n_sum); // Correctly adds to the empty sum vector
            cout << "n_sum " << n_sum << " at index " << s << endl; // Debug statement removed or comment out
            if(n_sum > l_sum)
            {
                // cout << "\n l_sum updated from " << l_sum; // Debug statement removed
                l_sum = n_sum; 
                l_index = s;
                // cout << " to " << l_sum << endl; // Debug statement removed
            }
        }

        for(int f = 0; f < l_index; f++)
        {
            result += l_sum - sum.at(f);
        }

        if(l_index != N - 1)
        {
            for(int g = l_index + 1; g < N; g++)
            {
                result += l_sum - sum.at(g);
            }
        }

        // cout << "End of this loop. The result is: " << result << endl; // Debug statement removed

        cout << result << '\n'; // Output the result followed by a newline
    }

    return 0;
}
