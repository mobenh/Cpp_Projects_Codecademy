
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

int diagonalDifference(vector<vector<int>> arr) {
    int primal_diagonal = 0;
    int secondary_diagonal = 0;

    int n = arr.size();

    for (int i = 0; i < n; i++) {
        primal_diagonal += arr[i][i];
        secondary_diagonal += arr[n - 1 - i][i];
    }

    return abs(primal_diagonal - secondary_diagonal);
}


int main() {
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i].resize(n);

        string arr_row_temp_temp;
        getline(cin, arr_row_temp_temp);

        vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int arr_row_item = stoi(arr_row_temp[j]);

            arr[i][j] = arr_row_item;
        }
    }

    cout << diagonalDifference(arr);
    return 0;
}

string ltrim(const std::string& str) {
    return string(find_if(str.cbegin(), str.cend(), [](unsigned char ch) {return !isspace(ch); }), str.cend());
}

string rtrim(const string& str) {
    return string(str.cbegin(), std::find_if(str.crbegin(), str.crend(), [](unsigned char ch) {return !isspace(ch); }).base());
}

vector<string> split(const string& str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}




/*
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
Enter your code here. Read input from STDIN. Print output to STDOUT
int matrix[100][100];
int i;
cin >> i;
for (int x = 0; x < i; x++) {
    for (int y = 0; y < i; y++) {
        cin >> matrix[x][y];
    }
}
int diag1, diag2;
diag1 = 0; diag2 = 0;
for (int x = 0; x < i; x++)
{
    diag1 = diag1 + matrix[x][x];
}
for (int x = i - 1; x > -1; x--)
{

    diag2 = (diag2 + matrix[i - x - 1][x]);
}
int diff = diag1 - diag2;
if (diff < 0) {
    cout << -(diff);
}
else
cout << diff;

return 0;
}

*/