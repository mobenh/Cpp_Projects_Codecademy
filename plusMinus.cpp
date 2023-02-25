#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);


void plusMinus(vector<int> arr) {
    double countp = 0, countn = 0, countz = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > 0) {
            countp++;
        }
        else if (arr[i] < 0) {
            countn++;
        }
        else {
            countz++;
        }
    }

    vector<double> v;
    v.push_back(countp);
    v.push_back(countn);
    v.push_back(countz);
    for (int i = 0; i < v.size(); i++) {
        cout << double(v[i] / arr.size()) << endl;
    }
}


int main(){
    string n_temp;
    getline(cin, n_temp);

    const auto n{ stoi(ltrim(rtrim(n_temp))) };

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);
        arr[i] = arr_item;
    }

    plusMinus(arr);
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