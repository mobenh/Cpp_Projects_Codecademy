#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

/*
 * Complete the 'minimumBribes' function below.
 *
 * The function accepts INTEGER_ARRAY q as parameter.
 */

void minimumBribes(vector<int> q) {
    unsigned int min_bribes = 0;
    vector<int> tmp(q.size() + 1);
    tmp[0] = -1;
    for (int i = 1; i < tmp.size(); ++i)
        tmp[i] = i;

    for (int i = 0; i < q.size(); ++i) {
        const int bribe = tmp[q[i]] - i - 1;
        if (bribe > 2) {
            cout << "Too chaotic" << endl;
            return;
        }
        if (bribe > 0) {
            min_bribes += bribe;
            int iPrev = q[i] - 1;
            while (iPrev > 0 && tmp[iPrev] == -1) --iPrev;
            if (iPrev > 0) tmp[iPrev] += 1;
            if (2 == bribe) {
                iPrev -= 1;
                while (iPrev > 0 && tmp[iPrev] == -1) --iPrev;
                if (iPrev > 0) tmp[iPrev] += 1;
            }
        }
        tmp[q[i]] = -1; // mark handled
    }
    cout << min_bribes << endl;
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

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split(rtrim(q_temp_temp));

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(q);
    }

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
