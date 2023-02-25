#include <cmath>
#include <cstdio>
#include <cctype>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

int findmedian(vector<int> arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    if (n % 2 != 0)
        return (int)arr[n / 2];
    return 0;
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
    cout << findmedian(arr);
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
FROM GEEKS FOR GEEKS
// CPP program to find median
#include <bits/stdc++.h>
using namespace std;

// Function for calculating median
double findMedian(int a[], int n)
{
    // First we sort the array
    sort(a, a + n);

    // check for even case
    if (n % 2 != 0)
        return (double)a[n / 2];

    return (double)(a[(n - 1) / 2] + a[n / 2]) / 2.0;
}

// Driver program
int main()
{
    int a[] = { 1, 3, 4, 2, 7, 5, 8, 6 };
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Median = " << findMedian(a, n) << endl;
    return 0;
}
*/
