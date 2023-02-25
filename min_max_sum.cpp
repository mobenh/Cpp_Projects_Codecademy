#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);


void miniMaxSum(vector<int> arr) {

    sort(arr.begin(), arr.end());
    int n = arr.size();
    long sum = 0;
    for (int i = 1; i < n - 1; i++) {
        sum += arr[i];
    }
    cout << sum + arr[0] << " " << sum + arr[n - 1];
}

int main(){
    string arr_temp_temp;
    getline(cin, arr_temp_temp);
    vector<string> arr_temp = split(rtrim(arr_temp_temp));
    vector<int> arr(5);
    for (int i = 0; i < 5; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }
    miniMaxSum(arr);
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