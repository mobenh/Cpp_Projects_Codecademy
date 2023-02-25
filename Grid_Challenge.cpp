#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string ltrim(const string&);
string rtrim(const string&);

string gridChallenge(vector<string> grid) {

    for (int i = 0; i < grid.size(); i++) {
        sort(grid[i].begin(), grid[i].end());
    }
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid.size(); j++) {
            if (j + 1 < grid.size()) {
                if (grid[j][i] > grid[j + 1][i]) {
                    return "NO";
                }
            }
        }
    }
    return "YES";
}

int main()
{
  

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<string> grid(n);

        for (int i = 0; i < n; i++) {
            string grid_item;
            getline(cin, grid_item);

            grid[i] = grid_item;
        }

        string result = gridChallenge(grid);

        cout << result << "\n";
    }


    return 0;
}

string ltrim(const std::string& str) {
    return string(find_if(str.cbegin(), str.cend(), [](unsigned char ch) {return !isspace(ch); }), str.cend());
}

string rtrim(const string& str) {
    return string(str.cbegin(), std::find_if(str.crbegin(), str.crend(), [](unsigned char ch) {return !isspace(ch); }).base());
}