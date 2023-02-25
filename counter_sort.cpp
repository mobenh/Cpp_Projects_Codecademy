#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

vector<int> countingSort(vector<int> arr) {
    vector<int> counter(100);

    for (const int& index : arr) counter[index] += 1;

    return counter;
}



int main() {
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> result = countingSort(arr);

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << " ";
        }
    }

    cout << "\n";

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
