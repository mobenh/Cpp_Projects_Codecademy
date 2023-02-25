#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);


string caesarCipher(string s, int k) {
    k = k % 26;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 65 && s[i] <= 90)
        {
            if (s[i] + k > 90)
                s[i] -= 26;
            s[i] += k;
        }
        else if (s[i] >= 97 && s[i] <= 122)
        {
            if (s[i] + k > 122)
                s[i] -= 26;
            s[i] += k;
        }
    }
    return s;
}

int main(){

    string n_temp;
    getline(cin, n_temp);
    int n = stoi(ltrim(rtrim(n_temp)));
    string s;
    getline(cin, s);

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));
    string result = caesarCipher(s, k);

    cout << result << "\n";

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